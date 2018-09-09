#include "Window.hpp"

unsigned int WindowCount = 0;

Window::Window(const TCHAR* WndName, 
        UDim2 Size,
        UDim2 Position)
    : Window::DirectX9()
{
    // General variables
    this->WndName = WndName;
    this->Objects.clear();
    WindowCount++;

    // Size and position variables
    UDim2 MonitorSize = {(unsigned int)GetSystemMetrics(SM_CXSCREEN), (unsigned int)GetSystemMetrics(SM_CYSCREEN)}; // Primary monitor dimensions
    (Size.x != (unsigned int)-1 && Size.y != (unsigned int)-1) ? this->Size = Size : this->Size = {640, 480};
    (Position.x != (unsigned int)-1 && Position.y != (unsigned int)-1) ? this->Position = Position : 
        this->Position = {MonitorSize.x / 2 - this->Size.x / 2, MonitorSize.y / 2 - this->Size.y / 2};

    if (this->InitWindow() != true || this->InitD3D(this->hWnd) != true) {
        delete this;
    }
}

Window::~Window()
{
    WindowCount--;
}

bool Window::IsOpen()
{
    // Up until the following line was implimented,
    // the window would close, but the program wouldn't
    // exit. This is because of the Window::PollEvent
    // MSG issue, see Main().
    return IsWindowVisible(this->hWnd) == TRUE;
    //return this->Shown;
}

bool Window::PollEvent(MSG& event)
{
    MSG msg;
    if (PeekMessage(&msg, this->hWnd, 0u, 0u, PM_REMOVE))
    {
        event = msg;
        TranslateMessage(&msg);
        DispatchMessage(&msg);
        return true;
    }
    return false;
}

void Window::Show(bool Show)
{
    int nCmdShow = (Show == true) ? SW_SHOW : SW_HIDE;
    ShowWindow(this->hWnd, nCmdShow);
    UpdateWindow(this->hWnd);
    this->Shown = Show;
}

void Window::Draw(Drawable* Obj)
{
    if (Obj != nullptr) {
        this->Objects.push_back(Obj);
    }
}

void Window::Render()
{
    this->d3ddev->Clear(1, nullptr, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0,0,0), 1.f, 0);
    this->d3ddev->BeginScene();

    for (std::vector<Drawable*>::iterator Obj = this->Objects.begin(); Obj != this->Objects.end(); Obj++)
    {
        (*Obj)->Draw(this->d3ddev);
    }

    this->d3ddev->EndScene();
    this->d3ddev->Present(NULL, NULL, NULL, NULL);

    // Clear objects to draw for new frame
    this->Objects.clear();
}

bool Window::InitWindow()
{
    TCHAR* ClassName = new TCHAR[_tcslen(WndClassName) + 3];
    wsprintf(ClassName, _T("%s%03u"), WndClassName, WindowCount);

    this->ClassName = ClassName;

    WNDCLASSEX wc;
    memset(&wc, 0, sizeof(WNDCLASSEX));
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.lpfnWndProc = DefWindowProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = ClassName;

    if (RegisterClassEx(&wc) == 0) {
        return false;
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
    
    if (this->hWnd == NULL) {
        return false;
    }

    delete[] ClassName;

    return true;
}