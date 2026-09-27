#include <Arduino.h>

#include "BMESPIInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

void setup()
{
    Serial.begin(115200);

    LEDControllerInstance::instance().init();

    bool success = BMESPIInterfaceInstance::instance().init();

    if (!success)
    {
        Serial.println("BME280 initialization failed!");
    }
}

void loop()
{
    float temperature =
        BMESPIInterfaceInstance::instance().get_temperature();

    Serial.print("Temperature: ");
    Serial.println(temperature);

    LEDControllerInstance::instance().update(temperature);
}