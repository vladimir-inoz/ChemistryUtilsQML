#ifndef DATASOURCE_H
#define DATASOURCE_H

#include <QtCore/QObject>
#include <QtCharts/QAbstractSeries>
#include <QMap>

QT_CHARTS_USE_NAMESPACE

/*!
 * \brief Источник данных для диаграммы массового распределения элементов
 */
class DataSource : public QObject
{
    Q_OBJECT
public:
    explicit DataSource(QObject *parent = 0);
Q_SIGNALS:

public slots:
    /*!
     * \brief update Обновить данные на графике
     * \param series Серии данных графика
     */
    void update(QAbstractSeries *series);
    void setData(QMap<QString, double> newData)
    {
        m_data = newData;
    }

private:
    int m_index;
    QMap<QString, double> m_data;
};

#endif // DATASOURCE_H
