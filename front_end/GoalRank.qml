import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2

Item {
    id: goalRank
    width: 960
    height: 540
    Label {
        id: goal_rank_banner
        x: 449
        y: 31
        text: qsTr("射手榜")
        anchors.horizontalCenter: parent.horizontalCenter
        font.pointSize: 18
    }

    Button {
        id: button
        x: 896
        y: 492
        text: qsTr("Button")
        onClicked: {
            for (var goal_rank_i = 0; goal_rank_i < goal_rank.length; goal_rank_i++) {
                console.log(goal_rank[goal_rank_i].name)
            }
        }
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

    Rectangle {
        id: list_header
        x: 52
        y: 73
        width: 856
        height: 44
        Rectangle {
            width: parent.width/3
            height: parent.height
            Text {
                anchors.centerIn: parent
                text: qsTr("国家")
                font.pointSize: 14
            }
        }
        Rectangle {
            id: rectangle
            width: parent.width/3
            height: parent.height
            anchors.left: parent.left
            anchors.leftMargin: width
            Text {
                anchors.centerIn: parent
                text: qsTr("球员")
                font.pointSize: 14
            }
        }
        Rectangle {
            width: parent.width/3
            height: parent.height
            anchors.right: parent.right
            anchors.rightMargin: 0
            Text {
                anchors.centerIn: parent
                text: qsTr("进球数")
                font.pointSize: 14
            }
        }
    }

    ListView {
        id: listView
        x: 52
        y: 123
        width: 856
        height: 363
        clip: true
        // header: goal_rank_header
        delegate: goal_rank_box
        model: goal_rank
    }

    Component {
        id: goal_rank_box
        Row {
            width: listView.width
            Rectangle {
                width: parent.width/3
                height: 66
                Text {
                    anchors.centerIn: parent
                    font.pointSize: 14
                    text: modelData.country
                }
            }
            Rectangle {
                width: parent.width/3
                height: 66
                Text {
                    anchors.centerIn: parent
                    font.pointSize: 14
                    text: modelData.name
                }
            }
            Rectangle {
                width: parent.width/3
                height: 66
                Text {
                    anchors.centerIn: parent
                    font.pointSize: 14
                    text: modelData.goal
                }
            }
        }
    }



}
