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
        text: qsTr("当前比赛事件：")
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

    ListView {
        id: event_list_view
        x: 180
        y: 128
        width: 600
        height: 356
        anchors.horizontalCenter: parent.horizontalCenter
        clip: true
        delegate: event_delegate
        model: curr_event
    }

    Component {
        id: event_delegate
//        x: 180
//        y: 139
//        width: event_list_view.width
//        height: 50
        Rectangle{
            width: event_list_view.width
            height: 50
            anchors.horizontalCenter: parent.horizontalCenter

            Rectangle {
                id: home_event
                y: 0
                width: parent.width
                height: parent.height
                color: "#ffffff"
                anchors.left: parent.left
                anchors.leftMargin: 0
                Text {
                    text: modelData.type
//                    text: "132333"
                    anchors.right: parent.right
                    anchors.rightMargin: 20
                    anchors.verticalCenter: parent.verticalCenter
                    font.pointSize: 12
                }
                Text {
                    text: modelData.name
//                    text: "132333"
                    anchors.verticalCenterOffset: 0
                    anchors.horizontalCenterOffset: 56
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    font.pointSize: 12
                }
                Text {
                    text: modelData.country
//                    text: "132333"
                    anchors.verticalCenterOffset: 0
                    anchors.left: parent.left
                    anchors.leftMargin: 172
                    anchors.verticalCenter: parent.verticalCenter
                    font.pointSize: 12
                }
                Text {
                    text: modelData.time
//                    text: "132333"
                    anchors.verticalCenterOffset: 0
                    anchors.left: parent.left
                    anchors.leftMargin: 25
                    anchors.verticalCenter: parent.verticalCenter
                    font.pointSize: 12
                }
            }
        }
    }

    Rectangle {
        id: rectangle
        x: 271
        y: 72
        width: event_list_view.width
        height: 50
        color: "#ffffff"
        anchors.horizontalCenter: parent.horizontalCenter
        Rectangle {
            id: rectangle1
            y: 0
            width: parent.width
            height: parent.height
            color: "#ffffff"
            anchors.left: parent.left
            anchors.leftMargin: 0
            Text {
                text: "类型"
                anchors.right: parent.right
                anchors.rightMargin: 20
                anchors.verticalCenter: parent.verticalCenter
                font.pointSize: 12
            }
            Text {
                text: "球员"
                anchors.verticalCenterOffset: 0
                anchors.horizontalCenterOffset: 57
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                font.pointSize: 12
            }
            Text {
                text: "国家"
                anchors.verticalCenterOffset: 0
                anchors.left: parent.left
                anchors.leftMargin: 174
                anchors.verticalCenter: parent.verticalCenter
                font.pointSize: 12
            }
            Text {
                text: "时间"
                anchors.left: parent.left
                anchors.leftMargin: 29
                anchors.verticalCenterOffset: 0
                anchors.verticalCenter: parent.verticalCenter
                font.pointSize: 12
            }
        }
    }




}
