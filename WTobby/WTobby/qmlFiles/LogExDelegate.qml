import QtQuick 2.3

Text {
        required property string type
        required property string message
        text: "Log: " + type + ", " + message
      }