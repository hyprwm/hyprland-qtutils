pragma ComponentBehavior: Bound

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    id: window

    FontMetrics { id: fontMetrics }

    property var windowPadding: 10

    minimumWidth: Math.max(fontMetrics.height * 10, mainLayout.Layout.minimumWidth) + mainLayout.anchors.margins * 2 + windowPadding * 2
    minimumHeight: Math.max(fontMetrics.height * 10, mainLayout.Layout.minimumHeight) + mainLayout.anchors.margins * 2 + windowPadding * 2
    maximumWidth: minimumWidth
    maximumHeight: minimumHeight
    visible: true

    component Separator: Rectangle {
        color: Qt.darker(system.windowText, 1.5)
    }

    component VSeparator: Separator {
        implicitWidth: 1
        Layout.fillHeight: true
        Layout.topMargin: fontMetrics.height
        Layout.bottomMargin: fontMetrics.height
    }

    component HSeparator: Separator {
        implicitHeight: 1
        Layout.fillWidth: true
        Layout.leftMargin: fontMetrics.height * 8
        Layout.rightMargin: fontMetrics.height * 8
    }

    SystemPalette {
        id: system
        colorGroup: SystemPalette.Active
    }

    ColumnLayout {
        id: mainLayout
        spacing: fontMetrics.height

        anchors {
            fill: parent
            margins: 4
        }

        Text {
            font.pointSize: fontMetrics.height
            color: system.windowText
            text: "Hyprland updated to " + updateScreen.newVersion + "!"
            Layout.alignment: Qt.AlignHCenter
        }

        HSeparator {}

        Text {
            color: system.windowText
            text: "Hyprland has been updated! <span style=\"font-family: 'Noto Color Emoji';\">😁</span><br/><br/>Please check the release notes on GitHub: <a href=\"https://github.com/hyprwm/Hyprland/releases\">https://github.com/hyprwm/Hyprland/releases</a><br/><br/>Every release may come with breaking changes, so if you get any config errors, try checking the latest release notes."
            Layout.alignment: Qt.AlignHCenter
            horizontalAlignment: Text.AlignHCenter
            textFormat: TextEdit.RichText
            onLinkActivated: Qt.openUrlExternally(link)
        }

        Rectangle {
            color: "transparent"
            Layout.minimumHeight: 10
            Layout.fillHeight: true
        }

        RowLayout {
            spacing: 6
            Layout.leftMargin: 20
            Layout.alignment: Qt.AlignRight

            Button {
                text: "Don't show this when I update"
                onClicked: (e) => {
                    updateScreen.onButtonPress("dontshow");
                }
            }

            Button {
                text: "Thanks!"
                onClicked: (e) => {
                    updateScreen.onButtonPress("quit");
                }
            }
        }
    }
}
