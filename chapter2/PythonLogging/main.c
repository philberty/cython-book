#include "NativeLogging.h"

int main(int argc, char **argv)
{
    // we want to ensure we use a command line argument for the output log file
    if (argc < 2) {
        return -1;
    }

    // use the first argument as log file
    SetupNativeLogging(argv[1]);

    // log out some stuff at different levels
    info("info message");
    debug("debug message");
    error("error message");

    // close up everything including Python
    CloseNativeLogging();

    return 0;
}
