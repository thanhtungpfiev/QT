import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Text {
        id: txtHello
        anchors.centerIn: parent
        text: qsTr("Dao Thanh Tung")
        color: "red"
        font.pointSize: 30
    }
}
