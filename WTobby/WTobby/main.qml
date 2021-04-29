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
    footer: TabBar {
        width: parent.width
        TabButton {
            text: qsTr("System")
            width: implicitWidth
        }
    }
    StackView {
        id: mainStackView
        anchors.fill: parent
        initialItem: systemView
    }
    ListModel {
            id: nameModel
            ListElement { name: "Alice" }
            ListElement { name: "Bob" }
            ListElement { name: "Jane" }
            ListElement { name: "Harry" }
            ListElement { name: "Wendy" }
    }
    Component {
        id: systemView
        ListView{
            anchors.fill: parent
            model: logModel
            delegate: LogDelegate{}
        }
    }
}

