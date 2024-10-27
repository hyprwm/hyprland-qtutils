#include "Dialog.hpp"
#include <print>
#include <hyprutils/string/String.hpp>
using namespace Hyprutils::String;

CDialog::CDialog(QObject* parent) : QObject(parent) {
    ;
}

void CDialog::onButtonPress(QString buttonName) {
    std::print("{}\n", trim(buttonName.toStdString()));
    exit(0);
}
