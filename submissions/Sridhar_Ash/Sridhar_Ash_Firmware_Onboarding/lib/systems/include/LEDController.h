#pragma once

#include <Arduino.h>
#include <etl/singleton.h>

#include "BMEConstants.h"

class LEDController
{
public:
    LEDController() = default;

    void init();
    void update(float temperature);

private:
    unsigned long last_blink_time = 0;
    bool led_state = false;
};

using LEDControllerInstance = etl::singleton<LEDController>;