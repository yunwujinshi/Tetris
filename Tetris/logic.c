#include "interface.h"

//===========================
// 函数：void gameFree(void)
// 作用：游戏资源释放
//===========================
void gameFree(void)
{
    // 释放图片
    freePicResources();

    // 退出SDL库，释放窗口、渲染器
    freeSDL();
}

//===========================
// 函数：Uint32 timerFun(Uint32 interval, void * param)
// 作用：定时器响应函数
//===========================
Uint32 timerFun(Uint32 interval, void * param)
{
    // 绘制窗口
    paint();

    return interval;
}

//===========================
// 函数：void init(void)
// 作用：游戏初始化
//===========================
int init(void)
{
    // 初始化SDL库
    if (initSDL() != 0)
    {
        return -1;
    }

    // 加载图片资源
    if (loadPicResources() != 0)
    {
        return -2;
    }

    return 0;
}

//===========================
// 函数：void logicStart(void)
// 作用：游戏开始（添加定时器，以及事件循环）
//===========================
void start(void)
{
    SDL_Event event;    // 事件类型变量
    int nQuit = 0;      // 退出标识，0循环，非0退出循环

    // 添加定时器函数
    SDL_AddTimer(85, timerFun, NULL);

    // 从消息队列中循环获取事件
    while (nQuit == 0)  // 判断是否退出事件循环
    {
        while (SDL_PollEvent(&event))  // 获取事件
        {
            switch (event.type)        // 事件的类别
            {
                case SDL_QUIT:         // 退出事件
                    nQuit = 1;         // 用户激活退出事件，跳出循环
                    break;
                default:
                    break;
            }
        }
    }
} 