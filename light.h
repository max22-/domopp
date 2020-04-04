#ifndef LIGHT_H
#define LIGHT_H

#include "mqtt.h"

class Light
{
public:
    Light(Mqtt& mqttClient);
    void on();
    void off();

private:
    Mqtt& mqttClient;
};

#endif // LIGHT_H
