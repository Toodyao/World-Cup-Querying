#ifndef BACKENDQML_H
#define BACKENDQML_H

#include "../back_end/src/backend.h"
#include <QObject>

class BackEndQml : public QObject
{
    Q_OBJECT
    BackEnd be;
    Q_PROPERTY(QString timeline READ getTimeline WRITE setTimeline NOTIFY timelineChanged)

public:
    explicit BackEndQml(QObject *parent = nullptr);

    QString getTimeline();
    void    setTimeline(const QString& t);

    Q_INVOKABLE int  get_match_index();
    Q_INVOKABLE bool has_match();

signals:
    void timelineChanged();

public slots:
};

#endif // BACKENDQML_H
