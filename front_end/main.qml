import QtQuick 2.9
import QtQuick.Controls 2.2

ApplicationWindow {
    id: window
    visible: true
    width: 1024
    height: 600
    title: qsTr("World Cup Querying System")



    StackView {
        id: stackView
        initialItem: "HomePage.qml"
        anchors.fill: parent
    }
}
