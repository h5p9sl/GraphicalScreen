#include "Engine/Window.hpp"
#include "Drawables/Noise.hpp"
#include "Drawables/PrimitiveRectangle.hpp"

#include <stdio.h>
#include <chrono>
#include <ctime>

int main(void)
{
    srand(std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count());
    using clock = std::chrono::high_resolution_clock;

    Window window(_T("Direct3D Window"));
    window.Show(true);
    
    PrimitiveRectangle rect({ 0.f, 100 }, { 200, 200 });
    PrimitiveTriangle tri({ 200.f, 100 }, { 200, 200 });
    DWORD c_rect[5] = { 0xFF00FF00, 0xFF0000FF, 0xFFFF00FF, 0xFFFF0000, 0xFF00FF00 };
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

        static const float MoveSpeed = 250;
        tri.Position.x += MoveSpeed * fdelta;
        rect.Position.x += MoveSpeed * fdelta;
        if (tri.Position.x > 640) tri.Position.x = 0 - tri.Size.x;
        if (rect.Position.x > 640) rect.Position.x = tri.Position.x - rect.Size.x;
        window.Draw(&tri);
        window.Draw(&rect);

        window.Render();
        Sleep(5);
    }

    puts("Main thread exiting. Return code 0");
    return 0;
}