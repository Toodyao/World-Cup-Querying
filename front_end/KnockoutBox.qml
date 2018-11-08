import QtQuick 2.0
import QtQuick.Controls 2.2

Rectangle {
    id: rectangle
    property int    home_goal_v
    property int    away_goal_v
    property string home_name_v
    property string away_name_v
    property bool   match_valid

    width: 133
    height: 69
    color: "#ffffff"
    Rectangle {
        id: home
        width: parent.width/2
        height: parent.height
        anchors.left: parent.left
        anchors.leftMargin: 0
        Label {
            id: home_goal
            text: home_goal_v
            anchors.verticalCenterOffset: -10
            font.pointSize: 14
            anchors.centerIn: parent
            anchors.horizontalCenterOffset: 0
        }

        Label {
            id: home_name
            text: home_name_v
            width: 40
            font.pointSize: 10
            anchors.verticalCenterOffset: 13
            anchors.horizontalCenterOffset: 0
            anchors.centerIn: parent
            wrapMode: Text.WordWrap
        }

    }

    Rectangle {
        id: separate
        anchors.centerIn: parent
        Text {
            anchors.centerIn: parent
            text: qsTr(":")
            anchors.verticalCenterOffset: -12
            anchors.horizontalCenterOffset: 0
            font.pointSize: 14
        }
    }

    Rectangle {
        id: away
        width: parent.width/2
        height: parent.height
        anchors.right: parent.right
        anchors.rightMargin: 0
        Label {
            id: away_goal
            text: away_goal_v
            anchors.horizontalCenterOffset: 0
            font.pointSize: 14
            anchors.centerIn: parent
            anchors.verticalCenterOffset: -10
        }

        Label {
            id: away_name
            text: away_name_v
            anchors.rightMargin: 52
            width: 40
            font.pointSize: 10
            anchors.verticalCenterOffset: 13
            anchors.horizontalCenterOffset: 0
            anchors.centerIn: parent
            wrapMode: Text.WordWrap
        }
    }

    Rectangle {
        id: not_start
        x: 0
        y: 0
        width: parent.width
        height: 35
        visible: !match_valid
        Text {
            anchors.centerIn: parent
            text: qsTr("尚未开始")
        }
        color: "#ffffff"
    }
}
