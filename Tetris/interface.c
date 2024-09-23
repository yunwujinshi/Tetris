#include "interface.h"

//===========================
SDL_Window * g_pWindow = NULL;      // 窗口指针
SDL_Renderer * g_pRenderer = NULL;  // 渲染器
Picture g_picBackGround;            // 背景图片
Picture g_picBlock_1;               // 方块1的像素图
Picture g_picBlock_2;               // 方块2的像素图
Picture g_picBlock_3;               // 方块3的像素图
Picture g_picBlock_4;               // 方块4的像素图

//===========================
// 初始化SDL库及窗口、渲染器
int initSDL(void)
{
    if (0 != SDL_Init(SDL_INIT_EVERYTHING))
    {
        printf("SDL2.0初始化失败: %s\n", SDL_GetError());
        return -1;
    }

    g_pWindow = SDL_CreateWindow("Tetris Game",
                                SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                WINDOW_WIDTH, WINDOW_HEIGHT,
                                SDL_WINDOW_SHOWN);
    if (NULL == g_pWindow)
    {
        printf("窗口创建失败: %s\n", SDL_GetError());
        return -2;
    }

    g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, SDL_RENDERER_ACCELERATED);
    if (NULL == g_pRenderer)
    {
        printf("渲染器创建失败: %s\n", SDL_GetError());
        return -3;
    }

    return 0;
}

//===========================
// 释放SDL库、窗口、渲染器
void freeSDL(void)
{
    SDL_DestroyRenderer(g_pRenderer);
    SDL_DestroyWindow(g_pWindow);
    SDL_Quit();
}

//===========================
// 加载一幅图片
Picture loadPic(const char * path)
{
    Picture pic;
    pic.pPic = IMG_LoadTexture(g_pRenderer, path);
    if (NULL == pic.pPic)
    {
        printf("图片加载失败: %s\n", SDL_GetError());
    }
    return pic;
}

//===========================
// 设置图片的目标显示区域
void setPicDstRect(Picture * picture, int x, int y, int w, int h)
{
    picture->dstRect.x = x;
    picture->dstRect.y = y;
    picture->dstRect.w = w;
    picture->dstRect.h = h;
}

//===========================
// 设置图片的源区域
void setPicSrcRect(Picture * picture, int x, int y, int w, int h)
{
    picture->srcRect.x = x;
    picture->srcRect.y = y;
    if (0 == w || 0 == h)
    {
        SDL_QueryTexture(picture->pPic, NULL, NULL, &(picture->srcRect.w), &(picture->srcRect.h));
    }
    else
    {
        picture->srcRect.w = w;
        picture->srcRect.h = h;
    }
}

//===========================
// 加载程序所需的图片资源
int loadPicResources(void)
{
    g_picBackGround = loadPic(PATH_BACKGROUND);
    if (g_picBackGround.pPic == NULL)
    {
        return -1;
    }
    setPicSrcRect(&g_picBackGround, 0, 0, 0, 0);
    setPicDstRect(&g_picBackGround, BACKGROUND_PIC_X, BACKGROUND_PIC_Y, BACKGROUND_PIC_W, BACKGROUND_PIC_H);
	


    return 0;
}

//===========================
// 释放程序加载的图片资源
void freePicResources(void)
{
    SDL_DestroyTexture(g_picBackGround.pPic);
    SDL_DestroyTexture(g_picBlock_1.pPic);
    SDL_DestroyTexture(g_picBlock_2.pPic);
    SDL_DestroyTexture(g_picBlock_3.pPic);
    SDL_DestroyTexture(g_picBlock_4.pPic);
}

//===========================
// 在渲染器中绘制一幅图片
void paintPic(Picture * picture)
{
    SDL_RenderCopy(g_pRenderer, picture->pPic, &(picture->srcRect), &(picture->dstRect));
}

//===========================
// 绘制窗口
void paint(void)
{
    paintPic(&g_picBackGround);
    // 你可以在此添加其他图片渲染，例如方块渲染
    SDL_RenderPresent(g_pRenderer);
}
