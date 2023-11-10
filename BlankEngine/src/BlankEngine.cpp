#include <iostream>
#include "Utility.h"

int main()
{
    Blank::Logger::init();

    BLANK_ENGINE_TRACE("1");
    BLANK_ENGINE_DEBUG("2");
    BLANK_ENGINE_INFO("3");
    BLANK_ENGINE_WARN("4");
    BLANK_ENGINE_ERROR("5");
    BLANK_ENGINE_CRITICAL("6");
}
