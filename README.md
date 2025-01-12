# Hyprland QT utils

This repo houses some qt/qml utilities that might be used by various hypr* apps.

## Dependencies

This depends on qt6 and qt6-qml, as well as hyprland-qt-support.

## Building

You can build it with this command:
```sh
cmake --no-warn-unused-cli -DCMAKE_BUILD_TYPE:STRING=Release -DCMAKE_INSTALL_PREFIX:PATH=/usr -S . -B ./build
cmake --build ./build --config Release --target all -j`nproc 2>/dev/null || getconf NPROCESSORS_CONF`
```
