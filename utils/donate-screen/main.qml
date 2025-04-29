pragma ComponentBehavior: Bound

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import './'

ApplicationWindow {
    id: window

    FontMetrics { id: fontMetrics }

    property var windowPaddingH: 30
    property var windowPaddingV: 3

    minimumWidth: Math.max(fontMetrics.height * 9, mainLayout.Layout.minimumWidth) + mainLayout.anchors.margins * 2 + windowPaddingH * 2
    minimumHeight: Math.max(fontMetrics.height * 9, mainLayout.Layout.minimumHeight) + mainLayout.anchors.margins * 2 + windowPaddingV * 2
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
            text: "Support Hyprland"
            Layout.alignment: Qt.AlignHCenter
        }

        HSeparator {}

        Text {
            color: system.windowText
            text: "Hyprland is maintained by volunteers, and led by one person in their free time.<br/>Your support is valuable, and helps fund Hyprland's continued existence.<br/><br/>You can donate once, or monthly, and it takes less than 5 minutes."
            Layout.alignment: Qt.AlignHCenter
            horizontalAlignment: Text.AlignHCenter
            textFormat: TextEdit.RichText
            onLinkActivated: Qt.openUrlExternally(link)
        }

        Rectangle {
            color: "transparent"
            Layout.minimumHeight: 4
            Layout.fillHeight: true
        }

        RowLayout {
            spacing: 6
            Layout.leftMargin: 20
            Layout.alignment: Qt.AlignRight

            Button {
                icon.color: "transparent"
                icon.source: "qrc:/assets/heart.svg"
                icon.height: 18
                icon.width: 18
                text: "Donate"
                onClicked: (e) => {
                    donateScreen.onButtonPress("donate");
                }
            }

            Button {
                text: "No thanks"
                onClicked: (e) => {
                    donateScreen.onButtonPress("quit");
                }
            }
        }
    }
}
