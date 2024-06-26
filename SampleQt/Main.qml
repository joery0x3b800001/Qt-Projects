import QtQuick
import QtQuick.Controls

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Column {
        id: column
        width: 125
        height: 75
        anchors.centerIn: parent

        TextField {
            id: textField
            // color: "black"
            placeholderText: "Enter some text"
        }

        Button {
            id: button
            text: "Click To open popup"

            onClicked: {
                myPopup.open()
            }
        }

        Popup {
            id: myPopup
            anchors.centerIn: parent
            width: 150
            height: 75
            closePolicy: "CloseOnEscape"

            Column {
                anchors.centerIn: parent
                spacing: 10
                Text {
                    text: textField.text
                    // color: "white"
                }

                Button {
                    text: "close"
                    width: 100
                    onClicked:
                    {
                        myPopup.close()
                    }
                }
            }
        }
    }
}
