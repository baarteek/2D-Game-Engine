#pragma once

class UpdatableObject : virtual public GameObject {
protected:
    bool isActive; 

public:
    UpdatableObject();
    virtual ~UpdatableObject() = default;

    void setActive(bool active);
    bool getActive() const;

    void update() override = 0;
};
