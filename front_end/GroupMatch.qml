import QtQuick 2.9
import QtQuick.Controls 2.2

Item {
    id: groupMatch
    width: 960
    height: 540

    Label {
        id: group_match_banner
        x: 449
        y: 31
        text: qsTr("小组赛")
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

    Column {
        id: group_a
        x: 63
        y: 113
        width: 162
        height: 140

        Rectangle {
            width: parent.width
            height: parent.height/4
            Label {
                text: group_a_data[0].country
                anchors.left: parent.left
                anchors.leftMargin: 0
            }
            Label {
                text: group_a_data[0].points
                anchors.right: parent.right
                anchors.rightMargin: 0
            }
        }
        Rectangle {
            width: parent.width
            height: parent.height/4
            Label {
                text: group_a_data[1].country
                anchors.left: parent.left
                anchors.leftMargin: 0
            }
            Label {
                text: group_a_data[1].points
                anchors.right: parent.right
                anchors.rightMargin: 0
            }
        }
        Rectangle {
            width: parent.width
            height: parent.height/4
            Label {
                text: group_a_data[2].country
                anchors.left: parent.left
                anchors.leftMargin: 0
            }
            Label {
                text: group_a_data[2].points
                anchors.right: parent.right
                anchors.rightMargin: 0
            }
        }
        Rectangle {
            width: parent.width
            height: parent.height/4
            Label {
                text: group_a_data[3].country
                anchors.left: parent.left
                anchors.leftMargin: 0
            }
            Label {
                text: group_a_data[3].points
                anchors.right: parent.right
                anchors.rightMargin: 0
            }
        }

    }

    Column {
        id: group_b
        x: 295
        y: 113
        width: 162
        height: 140

        Rectangle {
            width: parent.width
            height: parent.height/4
            Label {
                text: group_b_data[0].country
                anchors.left: parent.left
                anchors.leftMargin: 0
            }
            Label {
                text: group_b_data[0].points
                anchors.right: parent.right
                anchors.rightMargin: 0
            }
        }
        Rectangle {
            width: parent.width
            height: parent.height/4
            Label {
                text: group_b_data[1].country
                anchors.left: parent.left
                anchors.leftMargin: 0
            }
            Label {
                text: group_b_data[1].points
                anchors.right: parent.right
                anchors.rightMargin: 0
            }
        }
        Rectangle {
            width: parent.width
            height: parent.height/4
            Label {
                text: group_b_data[2].country
                anchors.left: parent.left
                anchors.leftMargin: 0
            }
            Label {
                text: group_b_data[2].points
                anchors.right: parent.right
                anchors.rightMargin: 0
            }
        }
        Rectangle {
            width: parent.width
            height: parent.height/4
            Label {
                text: group_b_data[3].country
                anchors.left: parent.left
                anchors.leftMargin: 0
            }
            Label {
                text: group_b_data[3].points
                anchors.right: parent.right
                anchors.rightMargin: 0
            }
        }

    }

    Column {
        id: group_c
        x: 522
        y: 113
        width: 162
        height: 140

        Rectangle {
            width: parent.width
            height: parent.height/4
            Label {
                text: group_c_data[0].country
                anchors.left: parent.left
                anchors.leftMargin: 0
            }
            Label {
                text: group_c_data[0].points
                anchors.right: parent.right
                anchors.rightMargin: 0
            }
        }
        Rectangle {
            width: parent.width
            height: parent.height/4
            Label {
                text: group_c_data[1].country
                anchors.left: parent.left
                anchors.leftMargin: 0
            }
            Label {
                text: group_c_data[1].points
                anchors.right: parent.right
                anchors.rightMargin: 0
            }
        }
        Rectangle {
            width: parent.width
            height: parent.height/4
            Label {
                text: group_c_data[2].country
                anchors.left: parent.left
                anchors.leftMargin: 0
            }
            Label {
                text: group_c_data[2].points
                anchors.right: parent.right
                anchors.rightMargin: 0
            }
        }
        Rectangle {
            width: parent.width
            height: parent.height/4
            Label {
                text: group_c_data[3].country
                anchors.left: parent.left
                anchors.leftMargin: 0
            }
            Label {
                text: group_c_data[3].points
                anchors.right: parent.right
                anchors.rightMargin: 0
            }
        }

    }

    Column {
        id: group_d
        x: 755
        y: 113
        width: 162
        height: 140

        Rectangle {
            width: parent.width
            height: parent.height/4
            Label {
                text: group_d_data[0].country
                anchors.left: parent.left
                anchors.leftMargin: 0
            }
            Label {
                text: group_d_data[0].points
                anchors.right: parent.right
                anchors.rightMargin: 0
            }
        }
        Rectangle {
            width: parent.width
            height: parent.height/4
            Label {
                text: group_d_data[1].country
                anchors.left: parent.left
                anchors.leftMargin: 0
            }
            Label {
                text: group_d_data[1].points
                anchors.right: parent.right
                anchors.rightMargin: 0
            }
        }
        Rectangle {
            width: parent.width
            height: parent.height/4
            Label {
                text: group_d_data[2].country
                anchors.left: parent.left
                anchors.leftMargin: 0
            }
            Label {
                text: group_d_data[2].points
                anchors.right: parent.right
                anchors.rightMargin: 0
            }
        }
        Rectangle {
            width: parent.width
            height: parent.height/4
            Label {
                text: group_d_data[3].country
                anchors.left: parent.left
                anchors.leftMargin: 0
            }
            Label {
                text: group_d_data[3].points
                anchors.right: parent.right
                anchors.rightMargin: 0
            }
        }
    }

    Column {
        id: group_e
        x: 63
        y: 312
        width: 162
        height: 140

        Rectangle {
            width: parent.width
            height: parent.height/4
            Label {
                text: group_e_data[0].country
                anchors.left: parent.left
                anchors.leftMargin: 0
            }
            Label {
                text: group_e_data[0].points
                anchors.right: parent.right
                anchors.rightMargin: 0
            }
        }
        Rectangle {
            width: parent.width
            height: parent.height/4
            Label {
                text: group_e_data[1].country
                anchors.left: parent.left
                anchors.leftMargin: 0
            }
            Label {
                text: group_e_data[1].points
                anchors.right: parent.right
                anchors.rightMargin: 0
            }
        }
        Rectangle {
            width: parent.width
            height: parent.height/4
            Label {
                text: group_e_data[2].country
                anchors.left: parent.left
                anchors.leftMargin: 0
            }
            Label {
                text: group_e_data[2].points
                anchors.right: parent.right
                anchors.rightMargin: 0
            }
        }
        Rectangle {
            width: parent.width
            height: parent.height/4
            Label {
                text: group_e_data[3].country
                anchors.left: parent.left
                anchors.leftMargin: 0
            }
            Label {
                text: group_e_data[3].points
                anchors.right: parent.right
                anchors.rightMargin: 0
            }
        }
    }

    Column {
        id: group_f
        x: 295
        y: 312
        width: 162
        height: 140

        Rectangle {
            width: parent.width
            height: parent.height/4
            Label {
                text: group_f_data[0].country
                anchors.left: parent.left
                anchors.leftMargin: 0
            }
            Label {
                text: group_f_data[0].points
                anchors.right: parent.right
                anchors.rightMargin: 0
            }
        }
        Rectangle {
            width: parent.width
            height: parent.height/4
            Label {
                text: group_f_data[1].country
                anchors.left: parent.left
                anchors.leftMargin: 0
            }
            Label {
                text: group_f_data[1].points
                anchors.right: parent.right
                anchors.rightMargin: 0
            }
        }
        Rectangle {
            width: parent.width
            height: parent.height/4
            Label {
                text: group_f_data[2].country
                anchors.left: parent.left
                anchors.leftMargin: 0
            }
            Label {
                text: group_f_data[2].points
                anchors.right: parent.right
                anchors.rightMargin: 0
            }
        }
        Rectangle {
            width: parent.width
            height: parent.height/4
            Label {
                text: group_f_data[3].country
                anchors.left: parent.left
                anchors.leftMargin: 0
            }
            Label {
                text: group_f_data[3].points
                anchors.right: parent.right
                anchors.rightMargin: 0
            }
        }
    }

    Column {
        id: group_g
        x: 522
        y: 312
        width: 162
        height: 140

        Rectangle {
            width: parent.width
            height: parent.height/4
            Label {
                text: group_g_data[0].country
                anchors.left: parent.left
                anchors.leftMargin: 0
            }
            Label {
                text: group_g_data[0].points
                anchors.right: parent.right
                anchors.rightMargin: 0
            }
        }
        Rectangle {
            width: parent.width
            height: parent.height/4
            Label {
                text: group_g_data[1].country
                anchors.left: parent.left
                anchors.leftMargin: 0
            }
            Label {
                text: group_g_data[1].points
                anchors.right: parent.right
                anchors.rightMargin: 0
            }
        }
        Rectangle {
            width: parent.width
            height: parent.height/4
            Label {
                text: group_g_data[2].country
                anchors.left: parent.left
                anchors.leftMargin: 0
            }
            Label {
                text: group_g_data[2].points
                anchors.right: parent.right
                anchors.rightMargin: 0
            }
        }
        Rectangle {
            width: parent.width
            height: parent.height/4
            Label {
                text: group_g_data[3].country
                anchors.left: parent.left
                anchors.leftMargin: 0
            }
            Label {
                text: group_g_data[3].points
                anchors.right: parent.right
                anchors.rightMargin: 0
            }
        }
    }

    Column {
        id: group_h
        x: 755
        y: 312
        width: 162
        height: 140

        Rectangle {
            width: parent.width
            height: parent.height/4
            Label {
                text: group_h_data[0].country
                anchors.left: parent.left
                anchors.leftMargin: 0
            }
            Label {
                text: group_h_data[0].points
                anchors.right: parent.right
                anchors.rightMargin: 0
            }
        }
        Rectangle {
            width: parent.width
            height: parent.height/4
            Label {
                text: group_h_data[1].country
                anchors.left: parent.left
                anchors.leftMargin: 0
            }
            Label {
                text: group_h_data[1].points
                anchors.right: parent.right
                anchors.rightMargin: 0
            }
        }
        Rectangle {
            width: parent.width
            height: parent.height/4
            Label {
                text: group_h_data[2].country
                anchors.left: parent.left
                anchors.leftMargin: 0
            }
            Label {
                text: group_h_data[2].points
                anchors.right: parent.right
                anchors.rightMargin: 0
            }
        }
        Rectangle {
            width: parent.width
            height: parent.height/4
            Label {
                text: group_h_data[3].country
                anchors.left: parent.left
                anchors.leftMargin: 0
            }
            Label {
                text: group_h_data[3].points
                anchors.right: parent.right
                anchors.rightMargin: 0
            }
        }
    }



}
