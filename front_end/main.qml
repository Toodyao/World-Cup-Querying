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

    StackView {
        id: stack
        initialItem: "HomePage.qml"
        anchors.fill: parent
    }


    BackEndQml {
        id: be
        onTimelineChanged: {
            console.log("timeline changed", timeline)
            hasMatch = be.has_match();
            console.log("hasMatch: ", hasMatch)
            matchIndex = be.get_match_index()
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
