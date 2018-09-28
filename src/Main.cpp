#include "Window.hpp"

#include "Triangle.hpp"

#include <stdio.h>

int main(void)
{
    Window window(_T("Direct3D Window"));
    window.Show(true);
    
    UDim3f v[3] = { {320.f, 50.f, 0.5f}, {590.f, 420.f, 0.5f}, {50.f, 420.f, 0.5f} };
    DWORD c[3] = {0xffff0000, 0xff00ff00, 0xff0000ff};
    PrimitiveTriangle triangle(v, c);

    // While main window is open
    while (window.IsOpen())
    {
        WndEvent msg;
        while (window.PollEvent(msg)) {
            if (msg == WndEvent::MSG_CLOSE) {
                window.Show(false);
            }
        }

        window.Draw(&triangle);
        
        window.Render();
        Sleep(5);
    }

    puts("Main thread exiting. Return code 0");
    return 0;
}