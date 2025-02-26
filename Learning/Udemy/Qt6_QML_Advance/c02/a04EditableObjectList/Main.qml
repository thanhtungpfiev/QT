import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import a04EditableObjectList

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Editable object list model")
    ListView{
        id : mListView
        anchors.fill: parent
        model : personModel
        delegate: Rectangle {
            height: 90
            radius: 10
            color : "gray"
            border.color: "cyan"
            width: parent.width
            RowLayout{
                anchors.fill: parent
                anchors.margins: 20
                TextField{
                    text : name
                    Layout.fillWidth: true
                    background: Rectangle{
                        color : "white"
                    }

                    onEditingFinished: {
                        Wrapper.setName(index,text)
                    }
                }
                SpinBox{
                    editable: true
                    value : age
                    Layout.fillWidth: true
                    background : Rectangle{
                        color : "white"
                    }

                    onValueChanged: {
                        if( value === model.age){

                        }else{
                            Wrapper.setAge(index,value)
                        }
                    }
                }
                Rectangle{
                    width : 50
                    height: 50
                    color: favoriteColor
                }
            }
        }
    }

    Button{
        id : mButton
        width: parent.width
        anchors.bottom: parent.bottom
        height: 50
        text : "Add Person"
        onClicked: {
            Wrapper.addPerson()
        }
    }
}
