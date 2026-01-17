#ifndef POWERNODE_H
#define POWERNODE_H

#include<QObject>
#include<QLCDNumber>

class PowerNode : public QObject
{
Q_OBJECT
public:
    PowerNode();

    PowerNode(QLCDNumber* voltage, QLCDNumber* totalPower, QObject* parent = nullptr);
    PowerNode(QLCDNumber* voltage, QLCDNumber* totalPower, int powerPercentage, QObject* parent = nullptr);
    ~PowerNode();

    void setNodeVoltage(int value);
    void setNodeTotalPower(int value);

    int getVoltage();
    double getTotalPower();
    double powerLoad();

private:
    QLCDNumber* voltage;
    QLCDNumber* totalPower;
    int powerPercentage;
};

#endif // POWERNODE_H
