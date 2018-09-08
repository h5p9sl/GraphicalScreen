#include "Window.hpp"

unsigned int WindowCount = 0;

Window::Window(const TCHAR* WndName, 
        UDim2 Size,
        UDim2 Position)
    : Window::DirectX9(this->hWnd)
{
    // General variables
    this->WndName = WndName;
    this->Objects.clear();
    WindowCount++;

    // Size and position variables
    UDim2 MonitorSize = {(unsigned int)GetSystemMetrics(SM_CXSCREEN), (unsigned int)GetSystemMetrics(SM_CYSCREEN)}; // Primary monitor dimensions
    (Size.x != -1u && Size.y != -1u) ? this->Size = Size : this->Size = {640, 480};
    (Position.x != -1u && Position.y != -1u) ? this->Position = Position : 
        this->Position = {MonitorSize.x - this->Size.x / 2, MonitorSize.y - this->Size.y / 2};

    // Call InitWindow
    this->InitWindow();
}

Window::~Window()
{
    WindowCount--;
}

void Window::Draw(Drawable* Obj)
{
    if (Obj != nullptr) {
        this->Objects.push_back(Obj);
    } else { 
        throw "Drawable* object was NULL";
    }
}

void Window::Render()
{
    for (std::vector<Drawable*>::iterator Obj = this->Objects.begin(); Obj != this->Objects.end(); Obj++)
    {
        (*Obj)->Draw(this);
    }
}

bool Window::InitWindow()
{
    TCHAR* ClassName = new TCHAR[_tcslen(WndClassName) + 3];
    wsprintf(ClassName, _T("%s%03u"), WndClassName, WindowCount);

    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = (WNDPROC)&this->WindowProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = ClassName;

    if (RegisterClass(&wc) == 0) {
        throw "RegisterClassA failed";
    }

    this->hWnd = CreateWindowEx(
        0,
        ClassName,
        this->WndName,
        WS_OVERLAPPEDWINDOW,
        this->Position.x,
        this->Position.y,
        this->Size.x,
        this->Size.y,
        NULL,
        NULL,
        GetModuleHandle(NULL),
        NULL
    );

    if (this->hWnd == NULL || this->hWnd == INVALID_HANDLE_VALUE) {
        throw "CreateWindowExW failed";
    }

    ShowWindow(this->hWnd, SW_SHOW);

    delete[] ClassName;

    return true;
}

LRESULT CALLBACK Window::WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    return DefWindowProcW(hWnd, uMsg, wParam, lParam);
}