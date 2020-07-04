#include "mqtt.h"
#include "console.h"
#include "macros.h"
#include "light.h"

Mqtt::Mqtt(const std::string host) : host(host)
{

}

void Mqtt::begin()
{
    Console& console = Console::getInstance();
    mosqpp::lib_init();
    console.println("MQTT",  "Connecting to MQTT broker " + host);
    int ret = connect(host.c_str());
    console.println("MQTT", "connect() returned " + std::to_string(ret));
    console.println("MQTT", "Starting MQTT loop");
    threaded_set();
}

void Mqtt::on_connect(int rc) {
    Console& console = Console::getInstance();
    console.println("MQTT", "Connected to MQTT broker with code " + std::to_string(rc));
    if(rc == 0) {
        console.println("MQTT", "Subscribing to topics");
        subscribe(nullptr, "light/bedroom");
        subscribe(nullptr, "/macro/goToBed");
        subscribe(nullptr, "/macro/hifiPower");
        subscribe(nullptr, "/macro/Marguerite");
    }
}

void Mqtt::on_subscribe(int mid, int qos_count, const int *granted_qos) {
    Console::getInstance().println("MQTT", "Subscription succeeded.");
}

void Mqtt::on_message(const struct mosquitto_message *message)
{
    std::string topic = message->topic;
    Console& console = Console::getInstance();
    console.println("MQTT", "payloadlen=" + std::to_string(message->payloadlen));
    std::string payload = reinterpret_cast<char *>(message->payload);
    console.println("MQTT", topic + " : " + payload);
    if(message->topic == std::string("light/bedroom")) {
        if(payload == "1")
            light::bedroom::on();
        else
            light::bedroom::off();
    }
    else if(message->topic == std::string("/macro/goToBed")) {
        macro::goToBed();
    }
    else if(message->topic == std::string("/macro/hifiPower")) {
        macro::hifiPower();
    }
    else if(message->topic == std::string("/macro/Marguerite")) {
        macro::Marguerite();
    }
    else if(message->topic == std::string("telnet")) {
        system(reinterpret_cast<char *>(message->payload));
    }
}
