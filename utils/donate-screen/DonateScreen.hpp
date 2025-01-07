#pragma once

#include <QObject>
#include <QQmlApplicationEngine>
#include <QPixmap>
#include <QIcon>
#include <qcontainerfwd.h>
#include <qqmlintegration.h>
#include <qtmetamacros.h>

class CDonateScreen : public QObject {
    Q_OBJECT;
    QML_NAMED_ELEMENT(DonateScreen);
    QML_SINGLETON;

  public:
    explicit CDonateScreen(QObject* parent = nullptr);

    Q_INVOKABLE void onButtonPress(QString buttonName = "");
};
