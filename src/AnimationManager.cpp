#include "AnimationManager.hpp"
#include <cmath>
#include <algorithm>

static float lerp(float a, float b, float t) {
    return a + t * (b - a);
}

AnimationManager::AnimationManager() { }

void AnimationManager::startSwapAnimation(int index1, int index2, float startX1, float startX2, float targetX1, float targetX2, int value1, int value2, float duration) {
    mSwapAnimation.index1 = index1;
    mSwapAnimation.index2 = index2;
    mSwapAnimation.startX1 = startX1;
    mSwapAnimation.startX2 = startX2;
    mSwapAnimation.targetX1 = targetX1;
    mSwapAnimation.targetX2 = targetX2;
    mSwapAnimation.value1 = value1;
    mSwapAnimation.value2 = value2;
    mSwapAnimation.duration = duration;
    mSwapAnimation.elapsed = 0.f;
    mSwapAnimation.active = true;
}

bool AnimationManager::isActive() const {
    return mSwapAnimation.active;
}

void AnimationManager::update(float deltaTime) {
    if (mSwapAnimation.active) {
        mSwapAnimation.elapsed += deltaTime;
        if (mSwapAnimation.elapsed >= mSwapAnimation.duration) {
            mSwapAnimation.active = false;
            mSwapAnimation.elapsed = mSwapAnimation.duration;
        }
    }
}

float AnimationManager::getCurrentPosition(int index, float defaultX) const {
    if (!mSwapAnimation.active)
        return defaultX;
    float t = mSwapAnimation.elapsed / mSwapAnimation.duration;
    if (index == mSwapAnimation.index1) {
        return lerp(mSwapAnimation.startX1, mSwapAnimation.targetX1, t);
    } else if (index == mSwapAnimation.index2) {
        return lerp(mSwapAnimation.startX2, mSwapAnimation.targetX2, t);
    }
    return defaultX;
}

void AnimationManager::reset() {
    mSwapAnimation.active = false;
    mSwapAnimation.elapsed = 0.f;
} 