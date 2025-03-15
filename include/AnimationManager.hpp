#ifndef ANIMATION_MANAGER_HPP
#define ANIMATION_MANAGER_HPP

#include <SFML/Graphics.hpp>

class AnimationManager {
public:
    AnimationManager();
    void startSwapAnimation(int index1, int index2, float startX1, float startX2, float targetX1, float targetX2, int value1, int value2, float duration);
    bool isActive() const;
    void update(float deltaTime);
    float getCurrentPosition(int index, float defaultX) const;
    void reset();
private:
    struct SwapAnimation {
        bool active = false;
        int index1 = -1;
        int index2 = -1;
        float elapsed = 0.f;
        float duration = 0.5f;
        float startX1 = 0.f;
        float startX2 = 0.f;
        float targetX1 = 0.f;
        float targetX2 = 0.f;
        int value1 = 0;
        int value2 = 0;
    } mSwapAnimation;
};

#endif // ANIMATION_MANAGER_HPP 