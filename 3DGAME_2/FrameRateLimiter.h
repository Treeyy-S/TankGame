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
    int targetFrameDuration; // 1�t���[���̖ڕW���� (�~���b)
    int lastFrameTime;       // �O��̃t���[���̎��� (�~���b)
    std::chrono::time_point<std::chrono::high_resolution_clock> lastTime; // �O��̃t���[���̎��� (���𑜓x�N���b�N)

    int frameCount;          // �t���[�������J�E���g
    float elapsedTime;       // �o�ߎ���
    int fps;                 // FPS�l
};