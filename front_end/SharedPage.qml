import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2

Item {
    id: shared_page
    width: 960
    height: 540

    property var banner_text: "null"

    Label {
        id: shared_banner
        x: 449
        y: 31
        text: banner_text
        anchors.horizontalCenter: parent.horizontalCenter
        font.pointSize: 18
    }

    Button {
        id: back
        x: 16
        y: 19
        text: qsTr("返回")
        font.pointSize: 16
        onClicked: {
            stack.pop()
        }
    }
}
