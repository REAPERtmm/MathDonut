#include "CustomOutput.h"

CustomOutput* CustomOutput::output = nullptr;
const char* CustomOutput::COLORS = "@#%*+=-:. ";

CustomOutput::CustomOutput(int width, int height)
    : WIDTH(width), HEIGHT(height) 
{ 
    count = 0;
}

void CustomOutput::Init(int width, int height)
{
    static CustomOutput out{ width, height };
    output = &out;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hConsole, &mode);
    SetConsoleMode(hConsole, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
}

CustomOutput& CustomOutput::Get()
{
    return *output;
}

CustomOutput& CustomOutput::operator<<(const char* value)
{
    std::cout << value;
    if(value[0] != '\x1B')
        output->count += strlen(value);
    if (output->count >= WIDTH) {
        std::cout << '\n';
        output->count = 0;
    }
    return *output;
}

CustomOutput& CustomOutput::operator<<(char value)
{
    std::cout << value;
    output->count++;
    if (output->count >= WIDTH) {
        std::cout << '\n';
        output->count = 0;
    }
    return *output;
}

CustomOutput& CustomOutput::operator<<(float value) {
    return *this << (int)(value * 10);
}

CustomOutput& CustomOutput::operator<<(int value) {
    return *this << COLORS[value];
}