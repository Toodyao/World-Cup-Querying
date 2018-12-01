import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2

SharedPage {
    id: match_detail_page
    banner_text: qsTr("比赛详情")


    Rectangle {
        id: match_box
        x: 37
        y: 86
        width: 513
        height: 241
        color: "#ffffff"

        Rectangle {
            id: goal_box
            anchors.centerIn: parent
            width: 150
            height: 85
            color: "#ffffff"

            Text {
                id: goal_slash
                anchors.centerIn: parent
                text: qsTr("-")
                font.bold: true
                font.pixelSize: 30
            }

            Text {
                id: away_goal
                text: selected_match.away_goal
                font.bold: true
                anchors.top: parent.top
                anchors.right: parent.right
                font.pixelSize: 40
                anchors.topMargin: 25
                anchors.rightMargin: 25
            }

            Text {
                id: home_goal
                text: selected_match.home_goal
                font.bold: true
                anchors.top: parent.top
                anchors.left: parent.left
                font.pixelSize: 40
                anchors.topMargin: 25
                anchors.leftMargin: 25
            }
        }

        Text {
            id: match_index
            text: selected_match.index + 1
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 31
            font.pixelSize: 19
        }

        Rectangle {
            id: home_name_box
            anchors.left: parent.left
            anchors.right: goal_box.left
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            Label {
                id: home_team_name
                x: 38
                y: 105
                width: 150
                text: selected_match.home_team
                horizontalAlignment: Text.AlignHCenter
                anchors.centerIn: parent
                wrapMode: Text.WordWrap
                font.pixelSize: 40
            }

            Column {
                id: column
                x: 43
                y: 36
                width: 200
                height: 400
            }
        }

        Rectangle {
            id: away_name_box
            anchors.left: goal_box.right
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            Label {
                id: away_team_name
                x: 369
                y: 105
                width: 150
                text: selected_match.away_team
                horizontalAlignment: Text.AlignHCenter
                anchors.centerIn: parent
                wrapMode: Text.WordWrap
                font.pixelSize: 40
            }
        }


    }

    ListView {
        id: selected_event_list_view
        x: 575
        y: 147
        width: 370
        height: 372
        anchors.right: parent.right
        anchors.rightMargin: 15
        clip: true
        delegate: EventDelegate {
            id: list_view
            //            event_list_width: parent.width
        }
        model: selected_event
    }

    Rectangle {
        id: rectangle
        x: 271
        y: 86
        width: selected_event_list_view.width
        height: 50
        color: "#ffffff"
        anchors.horizontalCenterOffset: 280
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
                x: 169
                text: "类型"
                anchors.verticalCenterOffset: 0
                anchors.rightMargin: 169
                anchors.right: parent.right
                anchors.verticalCenter: parent.verticalCenter
                font.pointSize: 12
            }
            Text {
                text: "球员"
                anchors.right: parent.right
                anchors.rightMargin: 0.11 * parent.width
                anchors.verticalCenterOffset: 0
                anchors.verticalCenter: parent.verticalCenter
                font.pointSize: 12
            }
            Text {
                text: "国家"
                anchors.verticalCenterOffset: 0
                anchors.left: parent.left
                anchors.leftMargin: 0.19 * parent.width
                anchors.verticalCenter: parent.verticalCenter
                font.pointSize: 12
            }
            Text {
                text: "时间"
                anchors.left: parent.left
                anchors.leftMargin: 0.048 * parent.width
                anchors.verticalCenterOffset: 0
                anchors.verticalCenter: parent.verticalCenter
                font.pointSize: 12
            }
        }
    }

    Text {
        id: text2
        x: 282
        y: 347
        text: qsTr("评论区")
        font.pixelSize: 12
    }

    Text {
        id: no_comment
        x: 276
        y: 395
        text: selected_comments.length === 0 ? qsTr("暂无评论") : qsTr("")
        font.pixelSize: 12
    }

    ListView {
        id: comment_list_view
        x: 37
        y: 375
        width: 513
        height: 157
        anchors.right: parent.right
        clip: true
        anchors.rightMargin: 410
        delegate: comments_box
        model: selected_comments
    }

    Component {
        id: comments_box
//                x: 37
//                y: 375
//                width: 513
//                height: 89
//                color: "#ffffff"

        Rectangle {
            id: comments_box_rect
            width: 513
            height: 89
            color: "#ffffff"

            Text {
                id: comment_name
                x: 8
                y: 18
                text: modelData.name
                font.pixelSize: 15
            }

            Text {
                id: comment_content
                x: 8
                y: 55
                text: modelData.comment
                font.pixelSize: 14
            }

            Text {
                id: comment_time
                x: 377
                y: 18
                text: modelData.time
                font.pixelSize: 15
            }
        }
    }


}
