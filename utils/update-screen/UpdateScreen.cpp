#include "UpdateScreen.hpp"

#include <print>
#include <QDesktopServices>

#include <hyprutils/string/String.hpp>
#include <hyprutils/os/Process.hpp>
using namespace Hyprutils::String;

CUpdateScreen::CUpdateScreen(QObject* parent) : QObject(parent) {
    ;
}

void CUpdateScreen::onButtonPress(QString buttonName) {
    if (buttonName == "quit")
        exit(0);
    if (buttonName == "donate")
        QDesktopServices::openUrl(QUrl("https://hyprland.org/support"));
}
