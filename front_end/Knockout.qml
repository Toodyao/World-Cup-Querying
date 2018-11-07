import QtQuick 2.9
import QtQuick.Controls 2.2

Item {
    id: knockout
    width: 960
    height: 540

    Label {
        id: knockout_banner
        x: 449
        y: 31
        text: qsTr("淘汰赛")
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
