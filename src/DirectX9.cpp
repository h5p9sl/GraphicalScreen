#include "DirectX9.hpp"

#include "Window.hpp"

DirectX9::DirectX9(HWND hWnd) {
    // General variables
    this->d3d = nullptr;
    this->d3ddev = nullptr;

    // Call InitD3D
    this->InitD3D(hWnd);
}

DirectX9::~DirectX9() {
    this->CleanupD3D();
}

void DirectX9::InitD3D(HWND hWnd)
{
    this->d3d = Direct3DCreate9(D3D_SDK_VERSION);

    if (!d3d) {
        throw "Direct3DCreate9 failed";
    }

    D3DPRESENT_PARAMETERS d3dpp;
    ZeroMemory(&d3dpp, sizeof(d3dpp));
    d3dpp.Windowed   = TRUE;
    d3dpp.SwapEffect = D3DSWAPEFFECT_COPY;

    if (FAILED(this->d3d->CreateDevice(
        D3DADAPTER_DEFAULT,
        D3DDEVTYPE_HAL,
        hWnd,
        D3DCREATE_SOFTWARE_VERTEXPROCESSING,
        &d3dpp,
        &this->d3ddev))
        )
    {
        throw "LPDIRECT3D9->CreateDevice failed";
    }

}

void DirectX9::CleanupD3D()
{
    this->d3ddev->Release();
    this->d3d->Release();
}