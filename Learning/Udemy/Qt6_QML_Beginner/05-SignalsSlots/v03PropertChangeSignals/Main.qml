import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        id: rectId
        width: 300
        height: width + 50 // Property binding
        color: "dodgerblue"

        // Custom property
        property string description: "A rectangle to play with"

        // Property change handlers
        onWidthChanged: {
            console.log("Width changed to: " + rectId.width)
        }

        onHeightChanged: {
            console.log("Height changed to: " + rectId.height)
        }

        onColorChanged: {

        }

        onVisibleChanged: {
            console.log("Width changed to: " + rectId.width)
        }

        onDescriptionChanged: {
            console.log("Description changed to: " + rectId.description)
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                rectId.width += 20
                rectId.description = "New data"
            }
        }
    }
}
