#include "FrameRateLimiter.h"
#include "DxLib.h"
#include <thread>

FrameRateLimiter::FrameRateLimiter(int targetFPS)
    : targetFrameDuration(1000 / targetFPS), lastFrameTime(GetNowCount()),
    frameCount(0), elapsedTime(0.0f), fps(0),
    lastTime(std::chrono::high_resolution_clock::now()) {
}

void FrameRateLimiter::Wait() {
    int currentTime = GetNowCount();
    int frameDuration = currentTime - lastFrameTime;
    if (frameDuration < targetFrameDuration) {
        std::this_thread::sleep_for(std::chrono::milliseconds(targetFrameDuration - frameDuration));
    }
    lastFrameTime = GetNowCount();
}

float FrameRateLimiter::CalculateDeltaTime() {
    auto currentTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> elapsedTime = currentTime - lastTime;
    lastTime = currentTime;
    return elapsedTime.count();

}

void FrameRateLimiter::DrawFPS() {
    frameCount++;
    elapsedTime += CalculateDeltaTime();
    if (elapsedTime >= 1.0f) {
        fps = frameCount;
        frameCount = 0;
        elapsedTime = 0.0f;
    }

    std::string fpsText = "FPS: " + std::to_string(fps);
    DrawString(10, 10, fpsText.c_str(), GetColor(255, 255, 255));
}