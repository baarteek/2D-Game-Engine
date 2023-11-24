#pragma once

class GameObject {
public:
    GameObject();
    virtual ~GameObject() = default;

    virtual void update() = 0;
    virtual void init() = 0;
    virtual void destroy() = 0; 
};
