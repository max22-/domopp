#include "light.h"
#include "globals.h"

namespace light {
namespace bedroom {
    void on()
    {
        mqtt.publish(nullptr, "/light/bedroom", 1, "1", 2, true);
    }

    void off()
    {
        mqtt.publish(nullptr, "/light/bedroom", 1, "0", 2, true);
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
