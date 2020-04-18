#include "YerbaEngine.h"

int main()
{
    YerbaEngine application;

    try
    {
        application.run();
    }
    catch(const std::exception& exeption)
    {
        std::cerr << exeption.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;;
}