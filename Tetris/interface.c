#include "interface.h"

//===========================
SDL_Window * g_pWindow = NULL;      // ����ָ��
SDL_Renderer * g_pRenderer = NULL;  // ��Ⱦ��
Picture g_picBackGround;            // ����ͼƬ
Picture g_picBlock_1;               // ����1������ͼ
Picture g_picBlock_2;               // ����2������ͼ
Picture g_picBlock_3;               // ����3������ͼ
Picture g_picBlock_4;               // ����4������ͼ

//===========================
// ��ʼ��SDL�⼰���ڡ���Ⱦ��
int initSDL(void)
{
    if (0 != SDL_Init(SDL_INIT_EVERYTHING))
    {
        printf("SDL2.0��ʼ��ʧ��: %s\n", SDL_GetError());
        return -1;
    }

    g_pWindow = SDL_CreateWindow("Tetris Game",
                                SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                WINDOW_WIDTH, WINDOW_HEIGHT,
                                SDL_WINDOW_SHOWN);
    if (NULL == g_pWindow)
    {
        printf("���ڴ���ʧ��: %s\n", SDL_GetError());
        return -2;
    }

    g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, SDL_RENDERER_ACCELERATED);
    if (NULL == g_pRenderer)
    {
        printf("��Ⱦ������ʧ��: %s\n", SDL_GetError());
        return -3;
    }

    return 0;
}

//===========================
// �ͷ�SDL�⡢���ڡ���Ⱦ��
void freeSDL(void)
{
    SDL_DestroyRenderer(g_pRenderer);
    SDL_DestroyWindow(g_pWindow);
    SDL_Quit();
}

//===========================
// ����һ��ͼƬ
Picture loadPic(const char * path)
{
    Picture pic;
    pic.pPic = IMG_LoadTexture(g_pRenderer, path);
    if (NULL == pic.pPic)
    {
        printf("ͼƬ����ʧ��: %s\n", SDL_GetError());
    }
    return pic;
}

//===========================
// ����ͼƬ��Ŀ����ʾ����
void setPicDstRect(Picture * picture, int x, int y, int w, int h)
{
    picture->dstRect.x = x;
    picture->dstRect.y = y;
    picture->dstRect.w = w;
    picture->dstRect.h = h;
}

//===========================
// ����ͼƬ��Դ����
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
// ���س��������ͼƬ��Դ
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
// �ͷų�����ص�ͼƬ��Դ
void freePicResources(void)
{
    SDL_DestroyTexture(g_picBackGround.pPic);
    SDL_DestroyTexture(g_picBlock_1.pPic);
    SDL_DestroyTexture(g_picBlock_2.pPic);
    SDL_DestroyTexture(g_picBlock_3.pPic);
    SDL_DestroyTexture(g_picBlock_4.pPic);
}

//===========================
// ����Ⱦ���л���һ��ͼƬ
void paintPic(Picture * picture)
{
    SDL_RenderCopy(g_pRenderer, picture->pPic, &(picture->srcRect), &(picture->dstRect));
}

//===========================
// ���ƴ���
void paint(void)
{
    paintPic(&g_picBackGround);
    // ������ڴ��������ͼƬ��Ⱦ�����緽����Ⱦ
    SDL_RenderPresent(g_pRenderer);
}
