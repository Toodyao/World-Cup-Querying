import QtQuick 2.9
import QtQuick.Controls 2.2
import BackEndQml 1.0

Item {
    id: homepage
    width: 960
    height: 540

    property bool   isTimelineChanged: false
    property bool   hasMatch
    property int    matchIndex

    property int    homeGoal
    property int    awayGoal
    property string homeName
    property string awayName


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
    BackEndQml {
        id: be
        onTimelineChanged: {
            console.log("timeline changed", timeline)
            hasMatch = be.has_match();
            console.log("hasMatch: ", hasMatch)
            matchIndex = be.get_match_index()
            homeName = be.get_home_name();
            awayName = be.get_away_name();
            homeGoal = be.get_home_goal();
            awayGoal = be.get_away_goal();
        }
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


    }

    TextField {
        id: timeline_box
        x: 142
        y: 442
        width: 182
        height: 40
        text: "2018-06-14T15:00:01Z"

        Button {
            id: timeline_confirm
            x: 201
            y: 0
            text: qsTr("确认")
            onPressed: {
                be.timeline = timeline_box.text
            }
        }
    }

    Rectangle {
        id: group_rect
        x: 721
        y: 83
        width: 168
        height: 86
        color: "#ffffff"

        Text {
            id: group_text
            x: 46
            y: 30
            text: qsTr("小组赛")
            font.pixelSize: 25
        }
    }

    Rectangle {
        id: goal_rank_rect
        x: 721
        y: 376
        width: 168
        height: 86
        color: "#ffffff"
        Text {
            id: goal_rank_text
            x: 46
            y: 30
            text: qsTr("射手榜")
            font.pixelSize: 25
        }
    }

    Rectangle {
        id: knockout_rect
        x: 721
        y: 227
        width: 168
        height: 86
        color: "#ffffff"
        Text {
            id: knockout_text
            x: 46
            y: 30
            text: qsTr("淘汰赛")
            font.pixelSize: 25
        }
    }


}
