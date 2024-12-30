import QtQuick
import components
import constants
import utilities

Window {
    width: Constants.windowWidth
    height: Constants.windowHeight
    visible: true
    title: qsTr("QML Modules Project Organization")

    Column {
        x: 10
        y: 10
        spacing: 20

        MButton {
            buttonText: "Button1"
            onButtonClicked: {
                Utils.buttonAlert(buttonText)
            }
        }

        MButton {
            buttonText: "Button2"
            onButtonClicked: {
                Utils.buttonAlert(buttonText)
            }
        }

        ImageButton {}
    }
}
