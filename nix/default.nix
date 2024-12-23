{
  lib,
  stdenv,
  cmake,
  pkg-config,
  hyprutils,
  pciutils,
  qt6,
  version ? "0",
}: let
  inherit (lib.sources) cleanSource cleanSourceWith;
  inherit (lib.strings) hasSuffix makeBinPath;
in
  stdenv.mkDerivation {
    pname = "hyprland-qtutils";
    inherit version;

    src = cleanSourceWith {
      filter = name: _type: let
        baseName = baseNameOf (toString name);
      in
        ! (hasSuffix ".nix" baseName);
      src = cleanSource ../.;
    };

    nativeBuildInputs = [
      cmake
      pkg-config
      qt6.wrapQtAppsHook
    ];

    buildInputs = [
      hyprutils
      qt6.qtbase
      qt6.qtsvg
      qt6.qtwayland
    ];

    preFixup = ''
      qtWrapperArgs+=(--prefix PATH : "${makeBinPath [pciutils]}")
    '';

    meta = {
      description = "Hyprland QT/qml utility apps";
      homepage = "https://github.com/hyprwm/hyprland-qtlibs";
      license = lib.licenses.bsd3;
      maintainers = [lib.maintainers.fufexan];
      platforms = lib.platforms.linux;
    };
  }
