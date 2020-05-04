#include "computer.h"
#include "globals.h"

namespace computer {
void shutdown() {
    mqtt.publish(nullptr, "computer/shutdown", 1, "1", 2, 0);
}
}
