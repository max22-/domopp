#include "light.h"
#include "globals.h"
#include "console.h"
#ifdef __arm__
#include <wiringPi.h>
#endif

namespace light {
namespace bedroom {

    const int pinNumber = 7;

    void on()
    {
        Console::getInstance().println("LIGHT", "Turning bedroom light on");
        #ifdef __arm__
        pinMode(pinNumber, OUTPUT);
        digitalWrite(pinNumber, LOW);
        #endif
        mqtt.publish(nullptr, "/light/bedroom/status", 1, "1", 0, true);
    }

    void off()
    {
        Console::getInstance().println("LIGHT", "Turning bedroom light off");
        #ifdef __arm__
        pinMode(pinNumber, INPUT);
        #endif
        mqtt.publish(nullptr, "/light/bedroom/status", 1, "0", 0, true);
    }
}

namespace livingroom {
    void on()
    {
        mqtt.publish(nullptr, "cmnd/livingroom-light/POWER", 2, "ON", 2, false);
    }

    void off()
    {
        mqtt.publish(nullptr, "cmnd/livingroom-light/POWER", 3, "OFF", 2, false);
    }

}
}
