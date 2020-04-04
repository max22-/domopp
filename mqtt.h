#ifndef MQTT_H
#define MQTT_H

#include <mosquittopp.h>
#include <string>

class Mqtt : public mosqpp::mosquittopp
{
public:
    Mqtt(const std::string host);
    void on_connect(int) override;
    void on_message(const struct mosquitto_message *message) override;
    void on_subscribe(int mid, int qos_count, const int *granted_qos) override;

private:
    const std::string host;

};

#endif // MQTT_H
