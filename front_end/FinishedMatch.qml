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
        text: qsTr("历史比赛")
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
        id: history_list_view
        x: 52
        y: 97
        width: 500
        height: 389
        anchors.horizontalCenter: parent.horizontalCenter
        clip: true
        delegate: history_delegate
        model: finished_match
        spacing: 5
        ScrollBar.vertical :ScrollBar {}
    }

    Component {
        id: history_delegate
//                        x: 52
//                        y: 97
//                        width: history_list_view.width
//                        height: 100
//                        anchors.horizontalCenterOffset: 0
//                        anchors.horizontalCenter: parent.horizontalCenter
        Rectangle {
            id: rectangle
            width: history_list_view.width
            height: 100

            Rectangle {
                id: history_goal_box
                anchors.centerIn: parent
                width: 150
                height: 85
                color: "#ffffff"

                Text {
                    id: history_goal_slash
                    anchors.centerIn: parent
                    text: qsTr("-")
                    font.bold: true
                    font.pixelSize: 30
                }

                Text {
                    id: history_away_goal
                    text: modelData.away_goal
                    font.bold: true
                    anchors.top: parent.top
                    anchors.right: parent.right
                    font.pixelSize: 40
                    anchors.topMargin: 25
                    anchors.rightMargin: 25
                }

                Text {
                    id: history_home_goal
                    text: modelData.home_goal
                    font.bold: true
                    anchors.top: parent.top
                    anchors.left: parent.left
                    font.pixelSize: 40
                    anchors.topMargin: 25
                    anchors.leftMargin: 25
                }
            }

            Rectangle {
                id: history_home_name_box
                anchors.left: parent.left
                anchors.leftMargin: 0
                width: 150
                height: parent.height
                Label {
                    id: history_home_team_name
                    y: 105
                    width: 50
                    anchors.verticalCenter: parent.verticalCenter
                    text: modelData.home_team
                    anchors.left: parent.left
                    anchors.leftMargin: 50
                    horizontalAlignment: Text.AlignHCenter
                    wrapMode: Text.WordWrap
                    font.pixelSize: 20
                }
            }

            Rectangle {
                id: history_away_name_box
                anchors.right: parent.right
                anchors.rightMargin: 0
                width: 150
                height: parent.height
                Label {
                    id: history_away_team_name
                    x: 67
                    y: 105
                    width: 50
                    anchors.verticalCenter: parent.verticalCenter
                    text: modelData.away_team
                    anchors.right: parent.right
                    anchors.rightMargin: 33
                    horizontalAlignment: Text.AlignHCenter
                    wrapMode: Text.WordWrap
                    font.pixelSize: 20
                }
            }

            Label {
                id: history_time
                x: 180
                y: 80
                text: modelData.time
                //            text: qsTr("2017-07-01T15:00:00Z")
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 6
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Label {
                id: history_index
                x: 188
                y: 8
                text: modelData.index
                anchors.horizontalCenterOffset: 0
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 78
                anchors.horizontalCenter: parent.horizontalCenter
            }

            MouseArea {
                width: history_list_view.width
                height: 100
                onClicked: {
                    selected_match = {
                        index: modelData.index,
                        home_goal: modelData.home_goal,
                        away_goal: modelData.away_goal,
                        home_team: modelData.home_team,
                        away_team: modelData.away_team
                    }
                    selected_event = be.get_event_by_index(modelData.index)
                    selected_comments = be.get_comments_by_index(modelData.index)
                    stack.push("MatchDetail.qml")
                }
            }
        }
    }
}
