

#include "ui/UI.hpp"
#include <iostream>
using namespace std;

#ifdef _WIN32
#ifndef _DEBUG
// #pragma comment( linker, "/subsystem:windows /entry:mainCRTStartup")
#endif
#endif

int main()
{
    NRenderer::UI ui{1600, 900, "MYRender"};
    try
    {
        ui.init();
    }
    catch (const exception &e)
    {
        cerr << e.what() << endl;
    }

    ui.run();

    return 0;
}