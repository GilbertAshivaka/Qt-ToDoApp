import QtQuick
import QtQuick.Window
import QtQuick.Controls.Material
import QtQuick.Layouts
import ToDo 1.0

ColumnLayout{
    Frame {
        Layout.fillWidth: true

        ListView{
            implicitWidth: 250
            implicitHeight: 250
            clip:  true
            spacing: 10
            anchors.fill: parent

            model:ToDoModel{
                list: toDoList
            }

            delegate:RowLayout{
                width: parent.width
                CheckBox{
                    checked: model.done
                }
                TextField{
                    Layout.fillWidth: true
                    text: model.description
                }
            }
        }
    }

    RowLayout{
        Button{
            text: "Add Item"
            Layout.fillWidth: true

            onClicked: {
                toDoList.appendItem()
            }
        }

        Button{
            text: "Remove Completed Items"
            Layout.fillWidth: true

            onClicked: {
                toDoList.removeCompletedItems()
            }
        }
    }
}











