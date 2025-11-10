import QtQuick 2.15
import QtQuick.Controls 2.15
import QDBus 1.0   // 👈 the name we registered above

ApplicationWindow {
    visible: true
    width: 400
    height: 200
    title: "QDBus Client Example"

    HelloClient {
        id: client
        Component.onCompleted: {
            console.log("Connecting to D-Bus signal...");
            client.connectToSignal();
            client.callSayHello("Girish");
        }
    }

    Column {
        anchors.centerIn: parent
        spacing: 10

        Text {
            id: outputText
            text: "Waiting for message..."
            font.pointSize: 14
        }

        Button {
            text: "Say Hello"
            onClicked: {
                client.callSayHello("From QML");
            }
        }
    }

    Connections {
        target: client
        function onHelloReceived(message) {
            outputText.text = message;
            console.log("Signal received from D-Bus:", message);
        }
    }
}
