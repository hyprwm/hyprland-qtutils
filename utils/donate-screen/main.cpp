#include "DonateScreen.hpp"
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

    auto dialog = new CDonateScreen();

    QApplication app(argc, argv);
    app.setApplicationName("Support Hyprland");
    app.setApplicationDisplayName("Support Hyprland");

    if (qEnvironmentVariableIsEmpty("QT_QUICK_CONTROLS_STYLE"))
        QQuickStyle::setStyle("org.kde.desktop");

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("donateScreen", dialog);
    engine.load("qrc:/qt/qml/org/hyprland/donate-screen/main.qml");

    return app.exec();
}
