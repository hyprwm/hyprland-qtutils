#pragma once

#include <QObject>
#include <QQmlApplicationEngine>
#include <QPixmap>
#include <QIcon>
#include <qcontainerfwd.h>
#include <qqmlintegration.h>
#include <qtmetamacros.h>

class CUpdateScreen : public QObject {
    Q_OBJECT;
    QML_NAMED_ELEMENT(UpdateScreen);
    QML_SINGLETON;
    Q_PROPERTY(QString newVersion MEMBER newVersion CONSTANT);

  public:
    explicit CUpdateScreen(QObject* parent = nullptr);

    QString          newVersion;

    Q_INVOKABLE void onButtonPress(QString buttonName = "");
};
