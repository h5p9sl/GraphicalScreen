#ifndef DirectX9_hpp
#define DirectX9_hpp
#include <d3d9.h>
#include <d3dx9.h>
#include "Types/UDim.hpp"

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

class Window;

class DirectX9
{
protected:
    LPDIRECT3D9 d3d;
    LPDIRECT3DDEVICE9 d3ddev;
    UDim2 Position; // Defaults to center of screen
    UDim2 Size; // Defaults to 640x480
public:
    DirectX9(HWND hWnd);
    ~DirectX9();
private:
    void InitD3D(HWND hWnd);
    void CleanupD3D();
};

#endif