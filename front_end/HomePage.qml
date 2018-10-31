import QtQuick 2.9
import QtQuick.Controls 2.2
import BackEndQml 1.0

Item {
    id: homepage
    width: 1024
    height: 600

    property bool isTimelineChanged: false
    property bool hasMatch: be.has_match()

    Label {
        id: match_status
        text: qsTr("正在进行的比赛：")
        font.pointSize: 18
        anchors.left: parent.left
        anchors.leftMargin: 137
        anchors.top: parent.top
        anchors.topMargin: 107
        font.weight: Font.Light
    }
    BackEndQml {
        id: be
        onTimelineChanged: {
            console.log("timeline changed", timeline)
            hasMatch = be.has_match();
            console.log("hasMatch: ", hasMatch)
            text1.text = be.get_match_index()
            match_status.text = hasMatch ? qsTr("正在进行的比赛：") : qsTr("即将开始的比赛:")
        }
    }

    Rectangle {
        id: match_panel
        x: 59
        y: 161
        width: 348
        height: 218
        color: "#ffffff"

        Text {
            id: text1
            text: be.get_match_index()
            anchors.top: parent.top
            anchors.topMargin: 100
            anchors.left: parent.left
            anchors.leftMargin: 50
            font.pixelSize: 12
        }
    }

    TextField {
        id: timeline_box
        x: 142
        y: 446
        width: 182
        height: 40
        text: "2018-06-14T15:00:00Z"

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
        x: 779
        y: 107
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
        x: 779
        y: 400
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
        x: 779
        y: 251
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
