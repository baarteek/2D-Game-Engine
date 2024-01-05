#pragma once

class AnimatedObject {
public:
    virtual ~AnimatedObject() = default;

    virtual void animate() = 0;
};
