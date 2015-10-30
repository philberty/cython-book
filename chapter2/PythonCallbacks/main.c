#include <Python.h>
#include "Callback.h"

static
void MyCallback(int val)
{
    printf("[MYCALLBACK] %i\n", val);
}

int main(int argc, char **argv)
{
    // Init Python Runtime
    Py_Initialize();

    // Init callback module
    initCallback();

    // Set Callback
    SetCallback(&MyCallback);

    // notify
    Notify(12345);
    
    // Close Python Runtime
    Py_Finalize();
    return 0;
}
