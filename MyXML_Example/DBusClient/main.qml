import QtQuick
import QtQuick.Controls

ApplicationWindow {
    visible: true
    width: 400
    height: 200
    title: "D-Bus Calculator Client"

    Column {
        anchors.centerIn: parent
        spacing: 10

        TextField { id: aField; placeholderText: "Enter A" }
        TextField { id: bField; placeholderText: "Enter B" }
        Label { id: resultLabel; text: "Result: " }

        Button {
            text: "Add via D-Bus"
            onClicked: {
                let result = dbusCaller.callAdd(parseInt(aField.text),
                                                parseInt(bField.text))
                resultLabel.text = "Result: " + result
            }
        }
    }
}
