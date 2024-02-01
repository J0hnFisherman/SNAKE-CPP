#include <iostream>
#include <ctime>
int main()
{
    std::string input;
    time_t startTime = std::time(nullptr);

    while (true)
    {
        std::time_t currentTime = std::time(nullptr);
        std::time_t gameDuration = currentTime - startTime;

        std::tm *timeInfo = std::localtime(&gameDuration);
        std::cout << "Czas Gry: "
                  << (timeInfo->tm_hour < 10 ? "0" : "") << timeInfo->tm_hour - 1 << ":"
                  << (timeInfo->tm_min < 10 ? "0" : "") << timeInfo->tm_min << ":"
                  << (timeInfo->tm_sec < 10 ? "0" : "") << timeInfo->tm_sec << std::endl;

        std::getline(std::cin, input);
        if (input == "Q" || input == "q")
        {
            return 0;
        }
    }
}