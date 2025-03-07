import QtQuick
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Slider")

    Column {
        width: parent.width
        spacing: 20

        Slider {
            id: sliderId
            anchors.horizontalCenter: parent.horizontalCenter
            width: parent.width
            from: 1
            to: 100
            value: 40
        }

        ProgressBar {
            id: progressBarId
            anchors.horizontalCenter: parent.horizontalCenter
            width: parent.width
            from: 1
            to: 100
            value: sliderId.value
        }
    }
}
