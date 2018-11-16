#ifndef BACKENDQML_H
#define BACKENDQML_H

#include "../back_end/src/backend.h"
#include <QObject>
#include <QVariantList>

class BackEndQml : public QObject
{
    Q_OBJECT
    BackEnd be;

//    Q_DECLARE_METATYPE(Player)

    Q_PROPERTY(QString timeline READ getTimeline WRITE setTimeline NOTIFY timelineChanged)
    Q_PROPERTY(int     matchIndex READ getMatchIndex WRITE setMatchIndex NOTIFY indexChanged)

public:
    explicit BackEndQml(QObject *parent = nullptr);

    QString getTimeline();
    void    setTimeline(const QString& t);
    int     getMatchIndex();
    void    setMatchIndex(const int i);

    Q_INVOKABLE int  get_match_index();
    Q_INVOKABLE bool has_match();
    Q_INVOKABLE QString get_home_name();
    Q_INVOKABLE QString get_away_name();
    Q_INVOKABLE int get_home_goal();
    Q_INVOKABLE int get_away_goal();
    Q_INVOKABLE QVariantList get_curr_event();
    Q_INVOKABLE QVariantList get_finished_match();
    Q_INVOKABLE QVariantList get_next_match();


    Q_INVOKABLE QVariantList get_goal_rank();

    Q_INVOKABLE QVariantList get_group_a();
    Q_INVOKABLE QVariantList get_group_b();
    Q_INVOKABLE QVariantList get_group_c();
    Q_INVOKABLE QVariantList get_group_d();
    Q_INVOKABLE QVariantList get_group_e();
    Q_INVOKABLE QVariantList get_group_f();
    Q_INVOKABLE QVariantList get_group_g();
    Q_INVOKABLE QVariantList get_group_h();

    Q_INVOKABLE QVariantList get_knockout();

    QVariantList groups_to_QVarList(Rank<Team> v);

signals:
    void timelineChanged();
    void indexChanged();

public slots:
};

#endif // BACKENDQML_H
