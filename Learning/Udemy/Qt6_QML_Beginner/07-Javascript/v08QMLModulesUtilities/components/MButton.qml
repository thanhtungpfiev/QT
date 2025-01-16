import QtQuick 2.15

Item {
    id: rootId
    property alias buttonText: buttonTextId.text
    width: containerRectId.width
    height: containerRectId.height

    signal buttonClicked

    Rectangle {
        id: containerRectId
        width: buttonTextId.implicitWidth + 20
        height: buttonTextId.implicitHeight + 20
        color: "red"
        border.width: 3
        border.color: "blue"

        Text {
            id: buttonTextId
            text: "Button"
            anchors.centerIn: parent
            onTextChanged: {
                console.log("Text changed to: " + buttonTextId.text)
            }
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                rootId.buttonClicked()
            }
        }
    }
}
