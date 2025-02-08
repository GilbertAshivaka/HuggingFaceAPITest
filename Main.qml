import QtQuick 2.15
import QtQuick.Controls 2.15
import MyAPI 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hugging Face API Test")

    // Create an instance of the C++ backend class.
    HuggingFaceAPI {
        id: hfApi
        onResultReady: (result) =>{
            console.log("Result: " + result)
            resultText.text = result
        }
        onErrorOccurred: (error) => {
            console.log("Error: " + error)
            resultText.text = "Error: " + error
        }
    }

    Column {
        height: 200
        anchors{
            top: parent.top
            topMargin: 20
            left: parent.left
            leftMargin: 10
            right: parent.right
            rightMargin: 10
        }
        spacing: 10

        TextField {
            id: inputField
            width: parent.width * 0.8
            height: 50
            verticalAlignment: "AlignBottom"
            placeholderText: "Enter your prompt"
        }

        Button {
            text: "Generate"
            onClicked: {
                hfApi.generateText(inputField.text)
            }
        }

        Text {
            id: resultText
            text: "Result will appear here..."
            wrapMode: Text.WordWrap
            width: parent.width * 0.8
        }
    }
}
