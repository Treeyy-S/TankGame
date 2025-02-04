#pragma once
#include <chrono>
#include <string>

class FrameRateLimiter {
public:
    FrameRateLimiter(int targetFPS);
    void Wait();
    float CalculateDeltaTime();
    void DrawFPS();

private:
    int targetFrameDuration; // 1フレームの目標時間 (ミリ秒)
    int lastFrameTime;       // 前回のフレームの時間 (ミリ秒)
    std::chrono::time_point<std::chrono::high_resolution_clock> lastTime; // 前回のフレームの時間 (高解像度クロック)

    int frameCount;          // フレーム数をカウント
    float elapsedTime;       // 経過時間
    int fps;                 // FPS値
};