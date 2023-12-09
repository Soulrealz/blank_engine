#include <iostream>
#include "Utility.h"

int main()
{
    Blank::Logger::init();

    LOG_TRACE("1");
    LOG_DEBUG("2");
    LOG_INFO("3");
    LOG_WARN("4");
    LOG_ERROR("5");
    LOG_CRITICAL("6");
}
