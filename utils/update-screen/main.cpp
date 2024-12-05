#include "UpdateScreen.hpp"
#include <hyprutils/string/VarList.hpp>
#include <print>
#include <qapplication.h>
#include <qqmlapplicationengine.h>
#include <qquickstyle.h>
#include <qtenvironmentvariables.h>
#include <QQmlContext>

using namespace Hyprutils::String;

int main(int argc, char* argv[]) {
    // disable logs to not trash the stdout
    qputenv("QT_LOGGING_RULES", QByteArray("*.debug=false;qml=false"));

    auto dialog = new CUpdateScreen();

    for (int i = 1; i < argc; ++i) {
        std::string_view arg = argv[i];

        if (arg == "--new-version") {
            if (i + 1 >= argc) {
                std::println(stderr, "--new-version requires a parameter");
                return 1;
            }

            dialog->newVersion = argv[i + 1];

            i++;
            continue;
        }

        std::println(stderr, "invalid arg {}", argv[i]);
        return 1;
    }

    if (dialog->newVersion.isEmpty()) {
        std::println(stderr, "missing --new-version");
        return 1;
    }

    QApplication app(argc, argv);
    app.setApplicationName("Hyprland Updated!");
    app.setApplicationDisplayName("Hyprland Updated");

    if (qEnvironmentVariableIsEmpty("QT_QUICK_CONTROLS_STYLE"))
        QQuickStyle::setStyle("org.kde.desktop");

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("updateScreen", dialog);
    engine.load("qrc:/qt/qml/org/hyprland/update-screen/main.qml");

    return app.exec();
}
