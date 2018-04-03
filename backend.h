#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QMap>
#include <QString>

class BackEnd : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString input READ input WRITE setInput NOTIFY inputChanged)
    Q_PROPERTY(QString output READ output NOTIFY outputChanged)

public:
    explicit BackEnd(QObject *parent = nullptr);

    QString input();
    void setInput(const QString &input);

    QString output();

signals:
    void inputChanged();
    void outputChanged();
    void chartReady(QMap<QString, double> chart_data);

private:
    QString m_input;
    QString m_output;
};

#endif // BACKEND_H
