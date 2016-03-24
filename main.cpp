#include "core/application.h"

int main(int argc, char *argv[])
{
    Application a(argc, argv);

    if (argc == 2)
    {
        if (a.interpretFile(argv[1]))

            return a.exec();
    }

    return 0;
}
