
#include "datasource.h"
#include <QtCharts/QPieSeries>
#include <QtCharts/QAreaSeries>
#include <QtQuick/QQuickView>
#include <QtQuick/QQuickItem>
#include <QtCore/QDebug>
#include <QtCore/QtMath>

QT_CHARTS_USE_NAMESPACE

Q_DECLARE_METATYPE(QAbstractSeries *)
Q_DECLARE_METATYPE(QAbstractAxis *)

DataSource::DataSource(QObject *parent) :
    QObject(parent),
    m_index(-1)
{
    qRegisterMetaType<QAbstractSeries*>();
    qRegisterMetaType<QAbstractAxis*>();
}

void DataSource::update(QAbstractSeries *series)
{
    if (series) {
        QPieSeries *pieSeries = static_cast<QPieSeries *>(series);
        pieSeries->clear();
        auto it = m_data.constBegin();
        while (it != m_data.constEnd())
        {
            pieSeries->append(it.key(), it.value());
            it++;
        }
    }
}
