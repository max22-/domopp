#ifndef LIGHT_H
#define LIGHT_H

#include "mqtt.h"

namespace light {
namespace bedroom {
    void on();
    void off();
}

namespace livingroom {
    void on();
    void off();
}
}


#endif // LIGHT_H
