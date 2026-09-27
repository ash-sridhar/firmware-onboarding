#include "BMESPIInterface.h"

BMESPIInterface::BMESPIInterface()
    : bme(BMEConstants::BME_CS_PIN)
{
}

bool BMESPIInterface::init()
{
    return bme.begin();
}

float BMESPIInterface::get_temperature()
{
    return bme.readTemperature();
}