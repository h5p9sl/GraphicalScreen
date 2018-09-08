#ifndef Window_hpp
#define Window_hpp

#include <tchar.h>
#include <Windows.h>
#include <vector>
#include "Graphics/Drawable.hpp"
#include "DirectX9.hpp"

#define WndClassName _T("h5p9sl_")
extern unsigned int WindowCount;

class Window : public DirectX9
{
private:
    /* std::vector<Drawable*> Window::Objects
    Array of drawable object pointers to be drawn when Window::Render() is called
    */
    std::vector<Drawable*> Objects;
    const TCHAR* WndName;
    HWND hWnd;
public:
    Window(const TCHAR* WndName,
        UDim2 Size={-1u, -1u},
        UDim2 Position = {-1u, -1u});
    ~Window();
    void Draw(Drawable* Obj);
    void Render();
private:
    bool InitWindow();
    LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
};

#endif