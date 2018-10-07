#include "Window.hpp"

#include "Pixel.hpp"

#include <stdio.h>
#include <chrono>

int main(void)
{
    using clock = std::chrono::high_resolution_clock;

    Window window(_T("Direct3D Window"));
    window.Show(true);
    
    Pixel pixel({25.f, 25.f}, D3DCOLOR_XRGB(255,0,0));

    auto time_start = clock::now();

    // While main window is open
    while (window.IsOpen())
    {
        auto delta = clock::now() - time_start;
        time_start = clock::now();

        float fdelta = std::chrono::duration_cast<std::chrono::milliseconds>(delta).count() / 1000.f;

        printf("%f\n", fdelta);

        WndEvent msg;
        while (window.PollEvent(msg)) {
            if (msg == WndEvent::MSG_CLOSE) {
                window.Show(false);
            }
        }
        
        window.Draw(&pixel);

        window.Render();
        Sleep(5);
    }

    puts("Main thread exiting. Return code 0");
    return 0;
}