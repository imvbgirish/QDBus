#include "Calculator.h"
#include "qdebug.h"

Calculator::Calculator(QObject *parent)
    : QObject{parent}
{}

int Calculator::add(int a, int b)
{
    int sum = a + b;
    qDebug() << "Calculator::add called via D-Bus:" << a << "+" << b << "=" << sum;
    return sum;
}
