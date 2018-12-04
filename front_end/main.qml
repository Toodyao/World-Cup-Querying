import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.0
import BackEndQml 1.0

ApplicationWindow {
    id: window
    visible: true
    width: 960
    height: 540
    title: qsTr("World Cup Querying System")

    property bool   isTimelineChanged: false
    property bool   hasMatch
    property int    matchIndex

    property int    homeGoal
    property int    awayGoal
    property string homeName
    property string awayName

    property var    goal_rank
    property var    group_a_data
    property var    group_b_data
    property var    group_c_data
    property var    group_d_data
    property var    group_e_data
    property var    group_f_data
    property var    group_g_data
    property var    group_h_data

    property var    knockout_tree
    property var    curr_event
    property var    finished_match

    property var    selected_match
    property var    selected_event
    property int    event_list_width
    property var    selected_comments

    function convert_event_type1(type_name) {
        switch(String(type_name)) {
        case "goal":             return qsTr("进球");
        case "substitution-in":  return qsTr("上场");
        case "substitution-out": return qsTr("下场");
        case "yellow-card":      return qsTr("黄牌");
        case "red-card":         return qsTr("红牌");
        case "goal-penalty":     return qsTr("罚球");
        case "goal-own":         return qsTr("乌龙球");
        default:                 return type_name;
        }
    }

    StackView {
        id: stack
        initialItem: "HomePage.qml"
        anchors.fill: parent
    }


    BackEndQml {
        id: be
        onTimelineChanged: {
            console.log("timeline changed main", timeline)
            hasMatch = be.has_match();
            matchIndex = be.get_match_index()
            console.log("get_match_index main", be.get_match_index());
            console.log("index changed main", matchIndex);
            homeName = be.get_home_name()
            awayName = be.get_away_name()
            homeGoal = be.get_home_goal()
            awayGoal = be.get_away_goal()

            goal_rank = be.get_goal_rank()

            group_a_data = be.get_group_a()
            group_b_data = be.get_group_b()
            group_c_data = be.get_group_c()
            group_d_data = be.get_group_d()
            group_e_data = be.get_group_e()
            group_f_data = be.get_group_f()
            group_g_data = be.get_group_g()
            group_h_data = be.get_group_h()

            knockout_tree = be.get_knockout()

            curr_event = be.get_curr_event()
            finished_match = be.get_finished_match()


        }
    }


}
