import QtQuick 2.0

Component {
    id: event_delegate
    //        x: 180
    //        y: 139
//            width: 370
//            height: 50
    Rectangle{
        width: 370
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
                text: convert_event_type1(modelData.type)
                anchors.left: parent.left
                anchors.leftMargin: 170
                //                    text: "132333"
                anchors.verticalCenter: parent.verticalCenter
                font.pointSize: 12
            }
            Text {
                text: modelData.name
                anchors.left: parent.left
                anchors.leftMargin: 250
                //                    text: "132333"
                anchors.verticalCenterOffset: 0
                anchors.verticalCenter: parent.verticalCenter
                font.pointSize: 12
            }
            Text {
                text: modelData.country
                //                    text: "132333"
                anchors.verticalCenterOffset: 0
                anchors.left: parent.left
                anchors.leftMargin: 62
                anchors.verticalCenter: parent.verticalCenter
                font.pointSize: 12
            }
            Text {
                text: modelData.time
                //                    text: "132333"
                anchors.verticalCenterOffset: 0
                anchors.left: parent.left
                anchors.leftMargin: 15
                anchors.verticalCenter: parent.verticalCenter
                font.pointSize: 12
            }
        }
    }
}
