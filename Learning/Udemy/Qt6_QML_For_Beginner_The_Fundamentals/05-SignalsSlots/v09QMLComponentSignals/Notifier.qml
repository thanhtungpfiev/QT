import QtQuick

Item {
    id: rootId
    width: notifierRectId.width
    height: notifierRectId.height

    property string rectColor: "red"
    property int count: 0

    required property Receiver target

    onTargetChanged: {
        rootId.notify.connect(target.receiveInfo)
    }

    signal notify(string count)

    Rectangle {
        id: notifierRectId
        width: 200
        height: 200
        color: rootId.rectColor

        Text {
            id: displayTextId
            anchors.centerIn: parent
            font.pointSize: 20
            text: rootId.count
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                rootId.count++
                rootId.notify(rootId.count)
            }
        }
    }
}
