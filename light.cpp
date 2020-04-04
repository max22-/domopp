#include "light.h"

Light::Light(Mqtt& mqttClient) : mqttClient(mqttClient)
{

}

void Light::on()
{
    mqttClient.publish(nullptr, "/light/bedroom", 1, "1", 2, true);
}

void Light::off()
{
    mqttClient.publish(nullptr, "/light/bedroom", 1, "0", 2, true);
}
