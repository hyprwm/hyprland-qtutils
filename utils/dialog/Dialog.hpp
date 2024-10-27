#pragma once

#include <QObject>
#include <QQmlApplicationEngine>
#include <QPixmap>
#include <QIcon>
#include <qcontainerfwd.h>
#include <qqmlintegration.h>
#include <qtmetamacros.h>

class CDialog : public QObject {
    Q_OBJECT;
    QML_NAMED_ELEMENT(Dialog);
    QML_SINGLETON;
    Q_PROPERTY(QString dialogTitle MEMBER title CONSTANT);
    Q_PROPERTY(QString dialogText MEMBER text CONSTANT);
    Q_PROPERTY(QVector<QString> dialogButtons MEMBER buttons CONSTANT);

  public:
    explicit CDialog(QObject* parent = nullptr);

    QString          title, text;
    QVector<QString> buttons;

    Q_INVOKABLE void onButtonPress(QString buttonName = "");
};
