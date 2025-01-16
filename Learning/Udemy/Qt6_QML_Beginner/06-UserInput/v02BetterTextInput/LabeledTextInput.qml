import QtQuick

Item {
    readonly property alias text: textInputId.text
    property alias label: labelId.text
    property alias placeHolderText: placeHolderId.text

    signal editingFinished

    Row {
        spacing: 20

        Rectangle {
            id: labelRectId
            width: labelId.implicitWidth + 20
            height: labelId.implicitHeight + 20
            color: "dodgerblue"

            Text {
                id: labelId
                anchors.centerIn: parent
                text: "First name: "
            }
        }

        Rectangle {
            id: textInputRectId
            width: placeHolderId.implicitWidth + textInputId.implicitWidth + 20
            height: placeHolderId.implicitHeight + 20
            color: "dodgerblue"

            Text {
                id: placeHolderId
                anchors.fill: parent
                anchors.centerIn: parent

                //The text element will only be visilble if the text input element doesn't contain any text
                // or if we're not typing text in the textinput element
                visible: !textInputId.text && !textInputId.inputMethodComposing
                verticalAlignment: TextInput.AlignVCenter
            }

            TextInput {
                id: textInputId
                anchors.fill: parent
                anchors.centerIn: parent
                focus: true
                verticalAlignment: TextInput.AlignVCenter
            }
        }

        Component.onCompleted: {
            //Connecting a signal to a signal
            textInputId.editingFinished.connect(editingFinished)
        }
    }
}
