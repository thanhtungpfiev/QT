import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Buton")

    ColumnLayout {
        anchors.left: parent.left
        anchors.right: parent.right

        Button {
            id: button1
            text: "Button 1"
            Layout.fillWidth: true
            onClicked: console.log("Button 1 clicked")
        }

        Button {
            id: button2
            text: "Button 2"
            Layout.fillWidth: true
            onClicked: console.log("Button 2 clicked")
        }
    }
}
