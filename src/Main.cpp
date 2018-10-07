#include "Engine/Window.hpp"
#include "Drawables/Noise.hpp"

#include <stdio.h>
#include <chrono>
#include <ctime>

int main(void)
{
    srand(std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count());
    using clock = std::chrono::high_resolution_clock;

    Window window(_T("Direct3D Window"));
    window.Show(true);
    
    Noise noise({ 0,0 }, { 640, 480 }, 10000);
    //Pixel mousepixel(UDim2f(), 0xFFFFFFFF);

    auto time_start = clock::now();

    // While main window is open
    while (window.IsOpen())
    {
        auto delta = clock::now() - time_start;
        float fdelta = std::chrono::duration_cast<std::chrono::milliseconds>(delta).count() / 1000.f;
        time_start = clock::now();

        printf("%f\n", fdelta);

        WndEvent msg;
        while (window.PollEvent(msg)) {
            if (msg == WndEvent::MSG_CLOSE) {
                window.Close();
                break;
            }
        }
        
        // Aw thats fucked m8
        //mousepixel.SetPosition(window.GetCursorPos());

        //window.Draw(&mousepixel);
        window.Draw(&noise);

        window.Render();
        Sleep(15);
    }

    puts("Main thread exiting. Return code 0");
    return 0;
}