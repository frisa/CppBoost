import QtQuick 2.3
import QtQml 2.15

Rectangle {
        required property string modelData
        height: 25
        width: 100
        Text { text: parent.modelData }
    }