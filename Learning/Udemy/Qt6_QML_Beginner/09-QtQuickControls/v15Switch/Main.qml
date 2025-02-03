import QtQuick
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Switch")

    Column {
        width: parent.width
        spacing: 20

        Switch {
            anchors.horizontalCenter: parent.horizontalCenter
            text: "Wifi"
            checked: true
        }

        Switch {
            anchors.horizontalCenter: parent.horizontalCenter
            text: "Bluetooth"
        }

        Switch {
            anchors.horizontalCenter: parent.horizontalCenter
            text: "NFC"
            enabled: false
        }
    }
}
