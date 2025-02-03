import QtQuick
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("ProgressBar")

    Column {
        width: parent.width
        spacing: 20

        Button {
            text: "Start"
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: function () {
                progressBarId1.value = 75
            }
        }

        Dial {
            id: dialId
            from: 1
            to: 100
            value: 40
            anchors.horizontalCenter: parent.horizontalCenter
        }

        ProgressBar {
            id: progressBarId
            from: 1
            to: 100
            value: dialId.value
            anchors.horizontalCenter: parent.horizontalCenter
        }

        ProgressBar {
            id: progressBarId1
            from: 1
            to: 100
            indeterminate: true
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}
