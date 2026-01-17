#include "powernode.h"

PowerNode::PowerNode() {
    voltage = nullptr;
    totalPower = nullptr;
}

PowerNode::~PowerNode(){}

PowerNode::PowerNode(QLCDNumber* voltage, QLCDNumber* totalPower, QObject* parent):voltage{voltage}, totalPower{totalPower}, QObject{parent}{
    powerPercentage = -1;
}

PowerNode::PowerNode(QLCDNumber* voltage, QLCDNumber* totalPower, int powerPercentage, QObject* parent): voltage{voltage}, totalPower{totalPower},
    powerPercentage{powerPercentage}, QObject{parent}
{
    if(voltage->intValue() < 0){
        voltage->display(100);
    }
    if(totalPower->intValue() < 0){
        totalPower->display(100);
    }
    if(powerPercentage <0){
        powerPercentage = 0;
    }
}

void PowerNode::setNodeVoltage(int value){
    voltage->display(value);
}

void PowerNode::setNodeTotalPower(int value){
    totalPower->display(value);
}

int PowerNode::getVoltage(){
    return voltage->intValue();
}

double PowerNode::getTotalPower(){
    return totalPower->value();
}

double PowerNode::powerLoad(){
    return static_cast<double>(powerPercentage);
}
