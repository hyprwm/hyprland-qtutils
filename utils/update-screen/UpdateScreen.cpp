#include "UpdateScreen.hpp"
#include <print>
#include <hyprutils/string/String.hpp>
#include <hyprutils/os/Process.hpp>
using namespace Hyprutils::String;

CUpdateScreen::CUpdateScreen(QObject* parent) : QObject(parent) {
    ;
}

void CUpdateScreen::onButtonPress(QString buttonName) {
    if (buttonName == "dontshow") {
        Hyprutils::OS::CProcess proc("hyprland-dialog", {"--title", "Information", "--text", "If you wish to disable this dialog, set ecosystem:no_update_news to true in your Hyprland config.", "--buttons", "ok"});
        proc.runAsync();
    } else if (buttonName == "quit")
        exit(0);
}
