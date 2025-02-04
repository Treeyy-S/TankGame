#include"Camera.h"
const float DEFAULT_CAMERA_POS_X = 6.5f;
const float DEFAULT_CAMERA_POS_Y = 10.0f;
const float DEFAULT_CAMERA_POS_Z = -24.5f;
const float DEFAULT_LOOK_AT_POS_X = 6.5f;
const float DEFAULT_LOOK_AT_POS_Y = 0.0f;
const float DEFAULT_LOOK_AT_POS_Z = -4.5f;
float cameraPosX = 0.0f;
float cameraPosY = 0.0f;
float cameraPosZ = 0.0f;

void SetCamera()
{
    //カメラの位置を設定
    //HD 1920x1080
    VECTOR cameraPos = VGet(DEFAULT_CAMERA_POS_X, DEFAULT_CAMERA_POS_Y, DEFAULT_CAMERA_POS_Z);
    //カメラの注視点を設定
    VECTOR lookAtPos = VGet(DEFAULT_LOOK_AT_POS_X, DEFAULT_LOOK_AT_POS_Y, DEFAULT_LOOK_AT_POS_Z);
    SetCameraNearFar(1.0f, 1000.0f);
    //カメラの位置を設定
    SetCameraPositionAndTarget_UpVecY(cameraPos, lookAtPos);
    //真上からの撮影のために必要
    // カメラ設定
    VECTOR upVec = VGet(0.0f, 0.0f, 1.0f);       //上方向ベクトルをZ軸方向に設定
    SetCameraPositionAndTargetAndUpVec(cameraPos, lookAtPos, upVec);

}

void UpdateCamera(VECTOR PlayerPos)
{
    //カメラの位置を設定
    SetCameraPositionAndTarget_UpVecY(VGet(PlayerPos.x, PlayerPos.y + 1.5f, PlayerPos.z - 2.5f), VGet(PlayerPos.x,1.0f,PlayerPos.z));
}
//デバッグ用
void changeCameraPos()
{
    //if (CheckHitKey(KEY_INPUT_UP))
    //{
    //    cameraPosZ += 0.1f;
    //}
    //if (CheckHitKey(KEY_INPUT_DOWN))
    //{
    //    cameraPosZ -= 0.1f;
    //}
    //if (CheckHitKey(KEY_INPUT_LEFT))
    //{
    //    cameraPosX -= 0.1f;
    //}
    //if (CheckHitKey(KEY_INPUT_RIGHT))
    //{
    //    cameraPosX += 0.1f;
    //}
    //if (CheckHitKey(KEY_INPUT_SPACE))
    //{
    //    cameraPosY += 0.1f;
    //}
    //if (CheckHitKey(KEY_INPUT_LSHIFT))
    //{
    //    cameraPosY -= 0.1f;
    //}
    //VECTOR cameraPos = VGet(DEFAULT_CAMERA_POS_X + cameraPosX, DEFAULT_CAMERA_POS_Y + cameraPosY, DEFAULT_CAMERA_POS_Z + cameraPosZ);
    ////カメラの注視点を設定
    //VECTOR lookAtPos = VGet(DEFAULT_LOOK_AT_POS_X, DEFAULT_LOOK_AT_POS_Y, DEFAULT_LOOK_AT_POS_Z);
    ////カメラの位置を設定
    //SetCameraPositionAndTarget_UpVecY(cameraPos, lookAtPos);
}
