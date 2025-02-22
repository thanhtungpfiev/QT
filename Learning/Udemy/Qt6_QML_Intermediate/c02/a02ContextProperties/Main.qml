import QtQuick
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Calling C++ from QML")

    Column {
        spacing: 10
        Row {
            spacing: 10
            Text {
                text: "regularMethod"
            }
            Button {
                text: "Call C++ method"
                onClicked: {
                    BWorker.regularMethod()
                }
            }
        }
        Row {
            spacing: 10
            Text {
                text: "cppSlot"
            }
            Button {
                text: "Call C++ slot"
                onClicked: {
                    BWorker.cppSlot()
                }
            }
        }
        Row {
            spacing: 10
            Text {
                id: returnTextId
                text: qsTr("return")
            }
            Text {
                text: "regularMethodWithReturn("
            }
            TextField {
                id: nameFieldId
                placeholderText: qsTr("name")
                text: qsTr("John")
            }
            Text {
                text: qsTr(",")
            }
            TextField {
                id: ageFieldId
                placeholderText: qsTr("age")
                inputMethodHints: Qt.ImhDigitsOnly
                text: qsTr("25")
            }
            Text {
                text: qsTr(")")
            }

            Button {
                text: "Call C++ method with return"
                onClicked: {
                    if (nameFieldId.text !== null && ageFieldId.text !== null) {
                        returnTextId.text = BWorker.regularMethodWithReturn(
                                    nameFieldId.text, parseInt(ageFieldId.text))
                    } else {
                        console.log("One of the two required fields is empty")
                    }
                }
            }
        }
    }

    Other {}
}
