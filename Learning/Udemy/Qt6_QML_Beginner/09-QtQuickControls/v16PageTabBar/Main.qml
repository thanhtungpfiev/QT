import QtQuick
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Page and TabBar")

    Page {
        id: page
        anchors.fill: parent

        header: Rectangle {
            width: parent.width
            height: 50
            color: "yellowgreen"
            Text {
                anchors.centerIn: parent
                text: "Some header text"
            }
        }

        SwipeView {
            id: swipeViewId
            anchors.fill: parent
            currentIndex: tabBarId.currentIndex

            Image {
                fillMode: Image.PreserveAspectFit
                source: "images/1.png"
            }

            Image {
                fillMode: Image.PreserveAspectFit
                source: "images/2.png"
            }

            Image {
                fillMode: Image.PreserveAspectFit
                source: "images/3.png"
            }
        }

        footer: TabBar {
            id: tabBarId
            currentIndex: swipeViewId.currentIndex

            TabButton {
                text: "First"
            }

            TabButton {
                text: "Second"
            }

            TabButton {
                text: "Third"
            }
        }

    }
}
