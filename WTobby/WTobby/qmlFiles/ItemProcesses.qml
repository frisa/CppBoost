import QtQuick 2.3
import "qrc:/qml/qmlFiles"

Item{
    id: processesView
    ListView{
        anchors.fill: parent
        model: logModel
        delegate: LogExDelegate{}
        highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
        focus: true
    }
}