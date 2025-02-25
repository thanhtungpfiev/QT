import QtQuick
import thanhtungpfiev.errorlevel

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Enums")

    Component.onCompleted: {
        console.log(ErrorLevel.MESSAGE)
    }
}
