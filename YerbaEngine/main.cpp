#include "YerbaEngine.h"

int main()
{
    YerbaEngine application;

    try
    {
        application.run();
    }
    catch(const std::exception& exception)
    {
        std::cerr << exception.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;;
}