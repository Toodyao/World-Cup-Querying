import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Window 2.3

Item {
    id: homepage
    width: 960
    height: 540

    Label {
        id: match_status
        text: hasMatch ? qsTr("正在进行的比赛：") : qsTr("即将开始的比赛:")
        font.pointSize: 18
        anchors.left: parent.left
        anchors.leftMargin: 69
        anchors.top: parent.top
        anchors.topMargin: 83
        font.weight: Font.Light
    }

    Rectangle {
        id: match_box
        x: 69
        y: 139
        width: 527
        height: 250
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
                text: awayGoal
                font.bold: true
                anchors.top: parent.top
                anchors.right: parent.right
                font.pixelSize: 40
                anchors.topMargin: 25
                anchors.rightMargin: 25
            }

            Text {
                id: home_goal
                text: homeGoal
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
            text: "-1"
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
                text: homeName
                horizontalAlignment: Text.AlignHCenter
                anchors.centerIn: parent
                wrapMode: Text.WordWrap
                font.pixelSize: 40
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
                text: awayName
                horizontalAlignment: Text.AlignHCenter
                anchors.centerIn: parent
                wrapMode: Text.WordWrap
                font.pixelSize: 40
            }
        }

        MouseArea {
            id: mouseArea
            anchors.fill: parent
            onClicked: {
                stack.push("TeamEvents.qml")
            }
        }
    }

    TextField {
        id: timeline_box
        x: 142
        y: 442
        width: 182
        height: 40
        text: "2018-07-14T15:00:01Z"
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 58

        Button {
            id: timeline_confirm
            x: 201
            y: 0
            text: qsTr("确认")
            anchors.bottom: parent.bottom
            anchors.bottomMargin: -8
            onPressed: {
                be.timeline = timeline_box.text
            }
        }
    }

    Button {
        id: group_rect
        x: 721
        y: 83
        width: 168
        height: 86
        anchors.right: parent.right
        anchors.rightMargin: 71

        Text {
            id: group_text
            x: 46
            y: 30
            text: qsTr("小组赛")
            font.pixelSize: 25
        }
        onClicked: {
            stack.push("GroupMatch.qml")
        }
    }

    Button {
        id: goal_rank_rect
        x: 721
        y: 376
        width: 168
        height: 86
        anchors.right: parent.right
        anchors.rightMargin: 71
        Text {
            id: goal_rank_text
            x: 46
            y: 30
            text: qsTr("射手榜")
            font.pixelSize: 25
        }
        onClicked: {
            stack.push("qrc:/GoalRank.qml")
        }
    }

    Button {
        id: knockout_rect
        x: 721
        y: 227
        width: 168
        height: 86
        anchors.right: parent.right
        anchors.rightMargin: 71
        Text {
            id: knockout_text
            x: 46
            y: 30
            text: qsTr("淘汰赛")
            font.pixelSize: 25
        }
        onClicked: {
            stack.push("Knockout.qml")
        }
    }

    Button {
        id: button
        x: 8
        y: 327
        width: 55
        height: 62
        Text {
            width: parent.width
            anchors.centerIn: parent
            text: qsTr("已完成的比赛")
            wrapMode: Text.WordWrap
        }
        onClicked: {
            stack.push("FinishedMatch.qml")
        }
    }

    Button {
        id: button1
        x: 609
        y: 341
        text: qsTr("预告")
    }

    Label {
        id: label
        x: 188
        y: 499
        text: qsTr("第")
        font.pointSize: 14
    }

    TextField {
        id: index_box
        x: 213
        y: 492
        width: 40
        height: 40
        horizontalAlignment: TextInput.AlignHCenter
        text: be.matchIndex + 1
    }

    Label {
        id: label1
        x: 259
        y: 499
        text: qsTr("场")
        font.pointSize: 14
    }

    Button {
        id: index_confirm
        x: 343
        y: 484
        text: qsTr("确认")
        anchors.bottomMargin: 8
        anchors.bottom: parent.bottom
        onPressed: {
            be.matchIndex = index_box.text - 1
        }
    }
}
