#ifndef Drawable_hpp
#define Drawable_hpp

class Window;

class Drawable
{
public:
    virtual void Draw(const Window* window);
};

#endif