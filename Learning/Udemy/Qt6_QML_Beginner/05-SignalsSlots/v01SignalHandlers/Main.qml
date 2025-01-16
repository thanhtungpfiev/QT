import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        id: rectId
        width: 150
        height: 150
        color: "red"

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true

            onClicked: {
                console.log("Clicked on the rectangle")
            }

            onDoubleClicked: {
                console.log("Double clicked on the rectangle")
            }

            onEntered: {
                console.log("You are in!")
            }

            onExited: {
                console.log("You are out!")
            }

            onWheel: function (wheel) {
                console.log("Wheel: " + wheel.x)
            }

            onReleased: mouse => {
                            console.log(
                                "Released at x: " + mouse.x + ", y: " + mouse.y)
                        }

            onPressAndHold: mouse => {
                                console.log("Was held: " + mouse.wasHeld)
                            }

            onPositionChanged: mouse => {
                                   console.log(
                                       "Position changed, x: " + mouse.x + ", y: " + mouse.y)
                               }
        }
    }
}
