#include "Drawable.hpp"

class Bouncy2D : public Drawable
{
private:
    UDim2f Velocity;
    UDim2f Position;
    UDim2f Size;
    Drawable* pDrawableChild;
public:
    Bouncy2D(Drawable* obj, UDim2f Size, UDim2f Position);
    ~Bouncy2D();
public:
    void Update(float fdelta);
protected:
    virtual void Initialize(LPDIRECT3DDEVICE9 D3DDevice) = 0; // Not needed
public:
    virtual void Draw(LPDIRECT3DDEVICE9 D3DDevice);
};