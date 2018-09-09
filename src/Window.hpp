#ifndef Window_hpp
#define Window_hpp
#include <tchar.h>
#include <Windows.h>
#include <vector>
#include "Drawable.hpp"
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
    const TCHAR* ClassName;
    HWND hWnd;
    bool Shown;
public:
    Window(const TCHAR* WndName,
        UDim2 Size={-1u, -1u},
        UDim2 Position = {-1u, -1u});
    ~Window();
    bool IsOpen();
    bool PollEvent(MSG& event);
    void Show(bool Show);
    void Draw(Drawable* Obj);
    void Render();
    void Close();
private:
    bool InitWindow();
};

#endif