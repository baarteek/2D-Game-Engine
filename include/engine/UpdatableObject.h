#pragma once

#include "GameObject.h"

class UpdatableObject : virtual public GameObject {
protected:
    bool isActive; 

public:
    UpdatableObject();
    virtual ~UpdatableObject() = default;

    void setActive(bool active);
    bool getActive() const;

    virtual void update() = 0;
};
