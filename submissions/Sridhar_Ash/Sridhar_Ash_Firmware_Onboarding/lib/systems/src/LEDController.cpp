#include "LEDController.h"

void LEDController::init()
{
    pinMode(BMEConstants::LED_PIN, OUTPUT);
    digitalWrite(BMEConstants::LED_PIN, LOW);
}

void LEDController::update(float temperature)
{
    unsigned long blink_interval;

    if (temperature <= BMEConstants::MIN_TEMP)
    {
        blink_interval = BMEConstants::SLOW_BLINK_MS;
    }
    else if (temperature >= BMEConstants::MAX_TEMP)
    {
        blink_interval = BMEConstants::FAST_BLINK_MS;
    }
    else
    {
        float ratio =
            (temperature - BMEConstants::MIN_TEMP) /
            (BMEConstants::MAX_TEMP - BMEConstants::MIN_TEMP);

        blink_interval =
            BMEConstants::SLOW_BLINK_MS -
            ratio * (BMEConstants::SLOW_BLINK_MS -
                     BMEConstants::FAST_BLINK_MS);
    }

    if (millis() - last_blink_time >= blink_interval)
    {
        last_blink_time = millis();

        led_state = !led_state;

        digitalWrite(BMEConstants::LED_PIN, led_state);
    }
}