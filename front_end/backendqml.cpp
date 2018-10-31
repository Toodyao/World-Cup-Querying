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

    qDebug() << be.timeline.get_time_string().c_str();
    qDebug() << has_match();
}

int BackEndQml::get_match_index()
{
    return be.get_curr_match_index(be.timeline);
}

bool BackEndQml::has_match()
{
    return be.has_match();
}
