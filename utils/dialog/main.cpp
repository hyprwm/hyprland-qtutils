#include "Dialog.hpp"
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

    QString appTitle;
    auto dialog = new CDialog();

    for (int i = 1; i < argc; ++i) {
        std::string_view arg = argv[i];

        if (arg == "--title") {
            if (i + 1 >= argc) {
                std::print(stderr, "--title requires a parameter\n");
                return 1;
            }

            dialog->title = argv[i + 1];

            i++;
            continue;
        }

        if (arg == "--apptitle") {
            if (i + 1 >= argc) {
                std::print(stderr, "--apptitle requires a parameter\n");
                return 1;
            }

            appTitle = argv[i + 1];

            i++;
            continue;
        }

        if (arg == "--text") {
            if (i + 1 >= argc) {
                std::print(stderr, "--text requires a parameter\n");
                return 1;
            }

            dialog->text = argv[i + 1];

            i++;
            continue;
        }

        if (arg == "--buttons") {
            if (i + 1 >= argc) {
                std::print(stderr, "--buttons requires a parameter\n");
                return 1;
            }

            CVarList buttonz(argv[i + 1], 0, ';', true);

            for (auto& b : buttonz) {
                dialog->buttons.emplace_back(b.c_str());
            }

            i++;
            continue;
        }

        std::print(stderr, "invalid arg {}\n", argv[i]);
        return 1;
    }

    QApplication app(argc, argv);
    app.setApplicationName(appTitle.isEmpty() ? dialog->title : appTitle);

    if (qEnvironmentVariableIsEmpty("QT_QUICK_CONTROLS_STYLE"))
        QQuickStyle::setStyle("org.kde.desktop");

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("dialog", dialog);
    engine.load("qrc:/qt/qml/org/hyprland/dialog/main.qml");

    return app.exec();
}
