import QtQuick 2.3
import QtQml.Models 2.15

ListModel {
    id: testModel
    ListElement {name: "A" value: 1}
    ListElement {name: "B" value: 2}
    ListElement {name: "C" value: 3}
}

Component {
        id: testDelegate
        Row {
            spacing: 10
            Text { text: 'name' + name }
            Text { text: 'value' + cost }
        }
}