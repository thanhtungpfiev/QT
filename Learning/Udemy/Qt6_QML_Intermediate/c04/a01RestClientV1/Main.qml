import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import a01RestClientV1

Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Rest Client V1")

    ColumnLayout {
        anchors.fill: parent
        spacing: 10

        ListView {
            id: mListView
            model: myModel
            delegate: Rectangle {
                width: root.width
                height: textId.implicitHeight + 30
                color: "beige"
                border.color: "yellowgreen"
                radius: 5

                Text {
                    id: textId
                    width: parent.width
                    height: parent.height
                    anchors.centerIn: parent
                    text: modelData
                    font.pointSize: 13
                    wrapMode: Text.WordWrap
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
            }

            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        Button {
            id: button1Id
            text: "Fetch"
            Layout.fillWidth: true
            onClicked: {
                Wrapper.fetchPosts()
            }
        }

        Button {
            id: button2Id
            text: "RemoveLast"
            Layout.fillWidth: true
            onClicked: {
                Wrapper.removeLast()
            }
        }
    }
}
