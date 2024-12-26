import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Custom Signals")

    Rectangle {
        id: rectId
        width: 300
        height: 300
        color: "dodgerblue"

        // Setup the signal
        signal greet(string message)

        // The signal handler
        onGreet: message => {
                     console.log("Greeting with message: " + message)
                 }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                //Fire(trigger) the signal
                rectId.greet("The sky is blue")
            }
        }
    }
}
