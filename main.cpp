#include "lib.h"
#include <spdlog/spdlog.h>
#include <iostream>

using namespace std;

int main()
{
//  оставил использование spdlog "на память"),
//  реализовал вывод, требуемый в ДЗ из pdf-ки
//    auto logger = spdlog::stdout_logger_mt("console");
//    logger->info("Hello World version {}", version());
    cout << "build " << version() << endl;
    cout << "Hello, World!" << endl;
    return 0;
}
