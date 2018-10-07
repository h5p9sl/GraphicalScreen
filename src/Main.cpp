#include "Engine/Window.hpp"
#include "Drawables/Noise.hpp"
#include "Drawables/PrimitiveRectangle.hpp"
#include "Drawables/Bouncy2D.hpp"

#include <stdio.h>
#include <chrono>
#include <ctime>

int main(void)
{
    srand(std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count());
    using clock = std::chrono::high_resolution_clock;

    Window window(_T("Direct3D Window"));
    window.Show(true);
    
    PrimitiveRectangle rect;
    PrimitiveTriangle tri;
    Bouncy2D b_rect(&rect, { 0, 0 }, { 200, 200 });
    Bouncy2D b_tri(&tri, { 200, 300 }, { 200, 200 });
    b_rect.Velocity = { 120, 80 };
    b_tri.Velocity = { -50, -150 };

    DWORD c_rect[5] = { 0xFFFF0000, 0xFF00FF00, 0xFF0000FF, 0xFFFF00FF, 0xFFFF0000 };
    DWORD c_tri[3] = { 0xFFFF0000, 0xFF00FF00, 0xFF0000FF };
    rect.SetColor(c_rect);
    tri.SetColor(c_tri);

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

        b_rect.Update(fdelta);
        b_tri.Update(fdelta);

        
        window.Draw(&b_rect);
        window.Draw(&b_tri);

        window.Render();
        Sleep(5);
    }

    puts("Main thread exiting. Return code 0");
    return 0;
}