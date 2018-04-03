#include "backend.h"
#include "Borrowed/FormulaParser.h"
#include <QDebug>

BackEnd::BackEnd(QObject *parent) :
    QObject(parent)
{
}

QString BackEnd::input()
{
    return m_input;
}

QString BackEnd::output()
{
    return m_output;
}

void BackEnd::setInput(const QString &input)
{
    if (input == m_input)
        return;

    m_input = input;
    //убираем пробелы
    m_input.replace(" ","");

    std::string text = m_input.toStdString();
    FormulaParserUWPComponent::FormulaParser parser;
    string sum;
    double molemass;
    parser.SetFormula(text, &sum, &molemass);

    //формируем ассоциативный массив с процентным составом
    //элементов
    //для этого преобразуем std::map в QMap
    int errorCode;
    auto elements = parser.ParseElements(&errorCode);
    QMap<QString, double> resElements;
    for (auto x : elements)
        resElements.insert(QString(x.first.c_str()), x.second);
    emit chartReady(resElements);
    m_output = QString::number(molemass) + QString::fromUtf8(" г/моль");

    emit outputChanged();
    emit inputChanged();
}
