import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("ComboBox")

    ColumnLayout {
        width: parent.width
        height: parent.height

        // Non Editable ComboBox

        Label {
            text: "Non Editable ComboBox"
            wrapMode: Label.Wrap
            Layout.fillWidth: true
        }

        ComboBox {
            id: noEditableComboId
            model: ["One", "Two", "Three", "Four"]
            Layout.fillWidth: true
            onActivated: function() {
                console.log("[" + currentIndex + "] " + currentText + " activated")
            }
        }

        // Editable ComboBox
        Label {
            text: "Editable ComboBox"
            wrapMode: Label.Wrap
            Layout.fillWidth: true
        }

        ComboBox {
            id: editableComboId
            editable: true
            textRole: "text"
            Layout.fillWidth: true
            model: ListModel {
                id: model
                ListElement {
                    text: "Dog"
                    location: "Kigali"
                    favorite_food: "Meat"
                }
                ListElement {
                    text: "Chicken"
                    location: "Nairobi"
                    favorite_food: "Rice"
                }
                ListElement {
                    text: "Cat"
                    location: "Mumbai"
                    favorite_food: "Fish"
                }
            }

            onActivated: function() {
                console.log("[" + currentIndex + "] " + currentText + " activated")
            }

            onAccepted: function() {
                if (find(editText) === -1) {
                    model.append({text: editText, location: "Unknown", favorite_food: "Unknown"})
                }
            }
        }

        Button {
            text: "Capture current element"
            Layout.fillWidth: true
            onClicked: function() {
                console.log(model.get(editableComboId.currentIndex).text + ", " + model.get(editableComboId.currentIndex).location + ", " + model.get(editableComboId.currentIndex).favorite_food)
            }
        }

        Item {
            id: separator
            Layout.fillWidth: true
            Layout.fillHeight: true
        }
    }
}
