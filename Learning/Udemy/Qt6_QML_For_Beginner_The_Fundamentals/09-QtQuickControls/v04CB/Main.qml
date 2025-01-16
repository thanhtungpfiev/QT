import QtQuick
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Check Box")

    Column {
        spacing: 20
        anchors.horizontalCenter: parent.horizontalCenter

        CheckBox {
            text: "Option1"
            checked: true
            onCheckedChanged: function() {
                if (checked) {
                    console.log("Option1 checked")
                } else {
                    console.log("Option1 unchecked")
                }
            }
        }

        CheckBox {
            text: "Option2"
        }

        CheckBox {
            text: "Option3"
            checked: true
            enabled: false        }
    }
}
