import QtQuick 2.15
import QtQuick.Window 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

import "qrc:/qml/qmlFiles"

ApplicationWindow {
    visible: true
    width: 790
    height: 480
    title: qsTr("WTobby Application")
    menuBar: MenuBar {
                        Menu { title: qsTr("&File")
                                Action { text: qsTr("&New")}
                                Action { text: qsTr("&Open")}
                                Action { text: qsTr("&Save")}
                                Action { text: qsTr("&Quit")}
                        }
                        Menu { title: qsTr("&Edit")}
                        Menu { title: qsTr("&Help")}
            }
    header: ToolBar {
            id: headerBar
            RowLayout{
                ToolButton {
                     icon.source: "qrc:/icons/assets/new.png"
                     icon.color: "transparent"
                }
            }
    }
    StackLayout{
        anchors.fill: parent
        currentIndex: bar.currentIndex
        Item{
            Rectangle{
                anchors.fill: parent
                color: 'red'
            }
        }
        Item{
            Rectangle{
                anchors.fill: parent
                color: 'green'
            }
        }
        Item{
            Rectangle{
                anchors.fill: parent
                color: 'blue'
            }
        }
    }
    footer: TabBar {
        id: bar
        width: parent.width
        TabButton {
            text: qsTr("Processes")
        }
        TabButton {
            text: qsTr("Green")
        }
        TabButton {
            text: qsTr("Blue")
        }
    }
}

