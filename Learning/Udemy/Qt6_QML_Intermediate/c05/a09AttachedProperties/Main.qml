import QtQuick
import a09AttachedProperties

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Attached Properties")

    Person {
        name: "Johnson"
        age: 20

        Timer.running: false
        Timer.interval: 1000
        Timer.onTimeout: function () {
            console.log("Timeout for person object")
        }
    }

    Rectangle {
        id: rectId
        width: 200
        height: 200
        color: "lightgray"

        Timer.running: false
        Timer.interval: 500
        Timer.onTimeout: function () {
            console.log("Timer out for rect")
        }
    }
}
