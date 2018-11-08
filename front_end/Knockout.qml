import QtQuick 2.9
import QtQuick.Controls 2.2

Item {
    id: knockout
    width: 960
    height: 540

    Label {
        id: knockout_banner
        x: 449
        y: 31
        text: qsTr("淘汰赛")
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

    KnockoutBox {
        id: box7
        x: 30
        y: 117
        home_name_v: knockout_tree[7].home_name
        home_goal_v: knockout_tree[7].home_goal
        away_name_v: knockout_tree[7].away_name
        away_goal_v: knockout_tree[7].away_goal
    }

    KnockoutBox {
        id: box8
        x: 30
        y: 207
        home_name_v: knockout_tree[8].home_name
        home_goal_v: knockout_tree[8].home_goal
        away_name_v: knockout_tree[8].away_name
        away_goal_v: knockout_tree[8].away_goal
    }

    KnockoutBox {
        id: box9
        x: 30
        y: 305
        home_name_v: knockout_tree[9].home_name
        home_goal_v: knockout_tree[9].home_goal
        away_name_v: knockout_tree[9].away_name
        away_goal_v: knockout_tree[9].away_goal
    }

    KnockoutBox {
        id: box10
        x: 30
        y: 407
        home_name_v: knockout_tree[10].home_name
        home_goal_v: knockout_tree[10].home_goal
        away_name_v: knockout_tree[10].away_name
        away_goal_v: knockout_tree[10].away_goal
    }

    KnockoutBox {
        id: box11
        x: 806
        y: 117
        home_name_v: knockout_tree[11].home_name
        home_goal_v: knockout_tree[11].home_goal
        away_name_v: knockout_tree[11].away_name
        away_goal_v: knockout_tree[11].away_goal
    }

    KnockoutBox {
        id: box12
        x: 806
        y: 207
        home_name_v: knockout_tree[12].home_name
        home_goal_v: knockout_tree[12].home_goal
        away_name_v: knockout_tree[12].away_name
        away_goal_v: knockout_tree[12].away_goal
    }

    KnockoutBox {
        id: box13
        x: 806
        y: 305
        home_name_v: knockout_tree[13].home_name
        home_goal_v: knockout_tree[13].home_goal
        away_name_v: knockout_tree[13].away_name
        away_goal_v: knockout_tree[13].away_goal
    }

    KnockoutBox {
        id: box14
        x: 806
        y: 407
        home_name_v: knockout_tree[14].home_name
        home_goal_v: knockout_tree[14].home_goal
        away_name_v: knockout_tree[14].away_name
        away_goal_v: knockout_tree[14].away_goal
    }

    KnockoutBox {
        id: box3
        x: 205
        y: 161
        home_name_v: knockout_tree[3].home_name
        home_goal_v: knockout_tree[3].home_goal
        away_name_v: knockout_tree[3].away_name
        away_goal_v: knockout_tree[3].away_goal
    }

    KnockoutBox {
        id: box4
        x: 205
        y: 352
        home_name_v: knockout_tree[4].home_name
        home_goal_v: knockout_tree[4].home_goal
        away_name_v: knockout_tree[4].away_name
        away_goal_v: knockout_tree[4].away_goal
    }

    KnockoutBox {
        id: box5
        x: 661
        y: 161
        home_name_v: knockout_tree[5].home_name
        home_goal_v: knockout_tree[5].home_goal
        away_name_v: knockout_tree[5].away_name
        away_goal_v: knockout_tree[5].away_goal
    }

    KnockoutBox {
        id: box6
        x: 661
        y: 352
        home_name_v: knockout_tree[6].home_name
        home_goal_v: knockout_tree[6].home_goal
        away_name_v: knockout_tree[6].away_name
        away_goal_v: knockout_tree[6].away_goal
    }

    KnockoutBox {
        id: box1
        x: 288
        y: 263
        home_name_v: knockout_tree[1].home_name
        home_goal_v: knockout_tree[1].home_goal
        away_name_v: knockout_tree[1].away_name
        away_goal_v: knockout_tree[1].away_goal
    }

    KnockoutBox {
        id: box2
        x: 568
        y: 263
        home_name_v: knockout_tree[2].home_name
        home_goal_v: knockout_tree[2].home_goal
        away_name_v: knockout_tree[2].away_name
        away_goal_v: knockout_tree[2].away_goal
    }

    KnockoutBox {
        id: box0
        x: 429
        y: 263
        home_name_v: knockout_tree[0].home_name
        home_goal_v: knockout_tree[0].home_goal
        away_name_v: knockout_tree[0].away_name
        away_goal_v: knockout_tree[0].away_goal
    }

    KnockoutBox {
        id: box15
        x: 429
        y: 386
        home_name_v: knockout_tree[15].home_name
        home_goal_v: knockout_tree[15].home_goal
        away_name_v: knockout_tree[15].away_name
        away_goal_v: knockout_tree[15].away_goal
    }





}
