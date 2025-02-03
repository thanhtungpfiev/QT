import QtQuick
import QtQuick.Controls
import QtQuick.Dialogs

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("File Dialog")

    Column {
        spacing: 20
        anchors.centerIn: parent

        Button {
            text: "Choose file"
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: function () {
                fileDialogId.open()
            }
        }

        Text {
            id: textId
            text: "User hasn't chosen file yet."
            wrapMode: Text.Wrap
        }

        FileDialog {
            id: fileDialogId
            title: "Choose filse"
            nameFilters: ["Text files (*.txt)", "HTML files (*.html *.htm)", "Images (*.jpg *.png)"]
            fileMode: FileDialog.OpenFiles
            onAccepted: function () {
                textId.text = currentFile
            }
            onRejected: function () {
                console.log("Dialog rejected")
            }
        }
    }
}
