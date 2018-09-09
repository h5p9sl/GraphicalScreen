#include "Window.hpp"

#include "Triangle.hpp"

#include <stdio.h>

int main(void)
{
    Window window(_T("ChickenBoi"));
    window.Show(true);

    Triangle triangle;
    triangle.p[0] = {5, 10, 0};
    triangle.p[1] = {10, 15, 0};
    triangle.p[2] = {15, 10, 0};

    while (window.IsOpen())
    {
        MSG msg;
        while (window.PollEvent(msg))
        {
            // For some reason this stuff doesn't work.
            // msg.message is never equal to either WM_DESTROY
            // or WM_QUIT
            if (msg.message == WM_DESTROY) {
                puts("WM_CLOSE recieved.");
                window.Show(false);
                PostQuitMessage(0);
            }
            if (msg.message == WM_QUIT) {
                puts("WM_QUIT recieved.");
                return 1;
            }
        }

        window.Draw(&triangle);

        window.Render();

        Sleep(5);
    }

    return 0;
}