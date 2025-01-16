import QtQuick 2.15

Item {
    width: imageRect.width
    height: imageRect.height

    Image {
        id: imageRect
        width: 100
        height: 100
        source: "images/LearnQt.png"
    }
}
