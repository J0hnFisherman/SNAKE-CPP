#include <iostream>
#include <ctime>

void getGameDuration(std::time_t startTime);
bool isExitDecision(std::string input);

int main()
{
    std::string input;
    std::time_t startTime = std::time(nullptr);

    while (true)
    {
        getGameDuration(startTime);

        std::getline(std::cin, input);
        if (isExitDecision(input))
        {
            return 0;
        }
    }
}

void getGameDuration(std::time_t startTime)
{
    std::time_t currentTime = std::time(nullptr);
    std::time_t gameDuration = currentTime - startTime;

    std::tm *timeInfo = std::localtime(&gameDuration);
    std::cout << "Czas Gry: "
              << (timeInfo->tm_hour < 10 ? "0" : "") << timeInfo->tm_hour - 1 << ":"
              << (timeInfo->tm_min < 10 ? "0" : "") << timeInfo->tm_min << ":"
              << (timeInfo->tm_sec < 10 ? "0" : "") << timeInfo->tm_sec << std::endl;
}

bool isExitDecision(std::string input)
{

    return input == "Q" || input == "q";
}