#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QObject>
#include <QtDBus/QtDBus>

class Calculator : public QObject
{
    Q_OBJECT
public:
    explicit Calculator(QObject *parent = nullptr);

public slots:
    int add(int a, int b);
};

#endif // CALCULATOR_H
