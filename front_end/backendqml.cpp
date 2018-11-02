#include "backendqml.h"
#include <QDebug>

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
