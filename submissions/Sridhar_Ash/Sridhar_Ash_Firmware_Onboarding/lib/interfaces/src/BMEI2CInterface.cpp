#include "BMEI2CInterface.h"

bool BMEI2CInterface::init()
{
    return bme.begin();
}

float BMEI2CInterface::get_temperature()
{
    return bme.readTemperature();
}