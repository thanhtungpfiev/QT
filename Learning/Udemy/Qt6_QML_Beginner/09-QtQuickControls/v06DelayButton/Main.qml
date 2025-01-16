import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Delay Button")

    ColumnLayout {
        width: parent.width
        spacing: 40

        Label {
            width: parent.width
            wrapMode: Label.Wrap
            Layout.fillWidth: true
            text: "Delayed Button. Use it when you want to prevent accidental clicks."
            font.pointSize: 15
        }

        DelayButton {
            property bool activated: false
            text: "Delay Button"
            Layout.fillWidth: true
            delay: 1000

            onPressed: function() {
                if (activated) {
                    console.log("Button pressed")
                    activated = false
                } else {
                    console.log("Button not activated")
                }
            }

            onActivated: function() {
                console.log("Button activated")
                activated = true
            }

            onProgressChanged: function() {
                console.log("Progress changed: " + progress)
            }
        }
    }
}
