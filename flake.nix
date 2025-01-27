{
  description = "Hyprland QT/qml utility apps";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    systems.url = "github:nix-systems/default-linux";

    hyprlang = {
      url = "github:hyprwm/hyprlang";
      inputs.nixpkgs.follows = "nixpkgs";
      inputs.systems.follows = "systems";
    };

    hyprutils.follows = "hyprlang/hyprutils";

    hyprland-qt-support = {
      url = "github:hyprwm/hyprland-qt-support";
      inputs.hyprlang.follows = "hyprlang";
      inputs.nixpkgs.follows = "nixpkgs";
      inputs.systems.follows = "systems";
    };
  };

  outputs = {
    self,
    nixpkgs,
    systems,
    ...
  } @ inputs: let
    inherit (nixpkgs) lib;
    eachSystem = lib.genAttrs (import systems);
    pkgsFor = eachSystem (
      system:
        import nixpkgs {
          localSystem = system;
          overlays = [self.overlays.default];
        }
    );
  in {
    overlays = import ./nix/overlays.nix {inherit inputs self lib;};

    packages = eachSystem (system: {
      default = self.packages.${system}.hyprland-qtutils;
      inherit (pkgsFor.${system}) hyprland-qtutils;
    });

    devShells = eachSystem (system: {
      default = import ./nix/shell.nix {
        pkgs = pkgsFor.${system};
        inherit (pkgsFor.${system}) hyprland-qtutils;
      };
    });
  };
}
