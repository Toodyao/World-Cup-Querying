#include "backendqml.h"
#include <QDebug>
#include <QJSValue>
#include <QJSEngine>

BackEndQml::BackEndQml(QObject *parent) : QObject(parent)
{
    be.init("../back_end/data/output.json");
}

QString BackEndQml::getTimeline()
{
    return be.get_time_string().c_str();
}

void BackEndQml::setTimeline(const QString &t)
{
    if (be.get_time_string() == t.toLocal8Bit().constData())
        return;
    be.set_time(t.toLocal8Bit().constData());
    be.update();
    emit timelineChanged();
}

int BackEndQml::get_match_index()
{
    return be.get_curr_match_index(be.timeline);
}

bool BackEndQml::has_match()
{
    return be.has_match();
}

QString BackEndQml::get_home_name()
{
    return be.get_home_name().c_str();
}

QString BackEndQml::get_away_name()
{
    return be.get_away_name().c_str();
}

int BackEndQml::get_home_goal()
{
    return be.get_home_goal();
}

int BackEndQml::get_away_goal()
{
    return be.get_away_goal();
}

QVariantList BackEndQml::get_group_a()
{
    return groups_to_QVarList(be.groups[0]);
}

QVariantList BackEndQml::get_group_b()
{
    return groups_to_QVarList(be.groups[1]);
}

QVariantList BackEndQml::get_group_c()
{
    return groups_to_QVarList(be.groups[2]);
}

QVariantList BackEndQml::get_group_d()
{
    return groups_to_QVarList(be.groups[3]);
}

QVariantList BackEndQml::get_group_e()
{
    return groups_to_QVarList(be.groups[4]);
}

QVariantList BackEndQml::get_group_f()
{
    return groups_to_QVarList(be.groups[5]);
}

QVariantList BackEndQml::get_group_g()
{
    return groups_to_QVarList(be.groups[6]);
}

QVariantList BackEndQml::get_group_h()
{
    return groups_to_QVarList(be.groups[7]);
}

QVariantList BackEndQml::get_goal_rank()
{
    QJSEngine jse;
    QVariantList ret;
    std::vector<Player> goal_rank = be.get_goal_rank();
    for (auto& i : goal_rank) {
        QJSValue jsv = jse.newObject();
        jsv.setProperty("name", i.name.c_str());
        jsv.setProperty("country", i.country.c_str());
        jsv.setProperty("goal", i.goal);
        ret.append(jsv.toVariant());
    }
//    for (auto& i : ret) {
//        qDebug() << i.toMap()["name"].toString();
//    }
    return ret;
}

QVariantList BackEndQml::groups_to_QVarList(Rank<Team> v)
{
    QVariantList ret;
    QJSEngine jse;
    for (auto& i : v.v) {
        QJSValue jsv = jse.newObject();
        jsv.setProperty("country", i.country.c_str());
        jsv.setProperty("points", i.points);
        ret.append(jsv.toVariant());
    }
    return ret;
}
