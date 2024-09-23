#include "interface.h"

int main(void)
{
    Picture pic;

    // 初始化SDL库，创建窗口、渲染器
    if(0 != initSDL())
    {
        return -1;
    }

    // 加载图片资源
    if(0 != loadPicResources())
    {
        return -2;
    }

    // 绘制窗口
    paint();

    // 延迟5秒
    SDL_Delay(5000);

    // 释放图片
    freePicResources();

    // 退出SDL库，释放窗口、渲染器
    freeSDL();

    return 0;
}