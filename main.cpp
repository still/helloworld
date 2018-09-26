#include "lib.h"
#include <spdlog/spdlog.h>
#include <iostream>

using namespace std;

int main()
{
    auto logger = spdlog::stdout_logger_mt("console");
    logger->info("Hello World version {}", version());
    return 0;
}
