#include "Calculator.h"
#include "qdebug.h"

Calculator::Calculator(QObject *parent)
    : QObject{parent}
{}

int Calculator::add()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    return 45;

}
