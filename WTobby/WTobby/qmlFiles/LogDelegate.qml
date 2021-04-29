import QtQuick 2.3
import QtQml 2.15

Rectangle {
        required property string mtype
        required property string message
        height: 25
        width: 200
        Text { text: parent.mtype + " : " + parent.message}
    }