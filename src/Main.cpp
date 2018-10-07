#include "Window.hpp"

#include "Pixel.hpp"
#include "Noise.hpp"

#include <stdio.h>
#include <chrono>

int main(void)
{
    using clock = std::chrono::high_resolution_clock;

    Window window(_T("Direct3D Window"));
    window.Show(true);
    
    Noise noise({ 0.f, 0.f }, { 640, 480 }, 20000);

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
        
        window.Draw(&noise);

        window.Render();
        Sleep(5);
    }

    puts("Main thread exiting. Return code 0");
    return 0;
}