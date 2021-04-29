import QtQuick 2.3

Item {
    width: ListView.view.width;
    height: 40
    Column {
        Text { text: '<b>Type:</b> ' + type }
        Text { text: '<b>Message:</b> ' + message }
        }
   }