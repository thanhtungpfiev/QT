import QtQuick
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("GroupBox, RadioButton and CheckBox")

    Column {
        spacing: 10
        anchors.fill: parent

        // RadioButton controls
        Label {
            width: parent.width
            wrapMode: Label.Wrap
            horizontalAlignment: Qt.AlignHCenter
            text: "A GroupBox wrapping around RadioButtons"
            color: "black"
        }

        GroupBox {
            title: "Choose bonus"
            anchors.horizontalCenter: parent.horizontalCenter
            Column {
                RadioButton {
                    text: "Coke"
                    onCheckedChanged: function () {
                        if (checked) {
                            console.log("Coke button checked")
                        } else {
                            console.log("Coke button NOT checked")
                        }
                    }
                }

                RadioButton {
                    text: "Green Tea"
                }

                RadioButton {
                    text: "Ice Cream"
                }
            }
        }

        //Checkbox controls
        Label {
            width: parent.width
            wrapMode: Label.Wrap
            horizontalAlignment: Qt.AlignHCenter
            text: "A GroupBox wrapping around CheckBoxes"
            color: "black"
        }

        GroupBox {
            title: "Choose a Qt supported desktop platform"
            anchors.horizontalCenter: parent.horizontalCenter
            Column {
                CheckBox {
                    text: "Windows"
                    onCheckedChanged: function () {
                        if (checked) {
                            console.log("Windows button checked")
                        } else {
                            console.log("Windows button NOT checked")
                        }
                    }
                }

                CheckBox {
                    text: "Mac"
                }

                CheckBox {
                    text: "Linux"
                }
            }
        }

        //Disable and enable a groupbox
        Label {
            width: parent.width
            wrapMode: Label.Wrap
            horizontalAlignment: Qt.AlignHCenter
            text: "A GroupBox that can enabled and disabled"
            color: "black"
        }

        GroupBox {
            anchors.horizontalCenter: parent.horizontalCenter
            label: CheckBox {
                id: checkBox
                checked: true
                text: checked ? "Disable" : "Enable"
                onCheckedChanged: function () {
                    console.log("Status: " + text + "d")
                }
            }

            Column {
                enabled: checkBox.checked
                CheckBox {
                    text: "Item1"
                }

                CheckBox {
                    text: "Item2"
                }

                CheckBox {
                    text: "Item3"
                }
            }
        }
    }
}
