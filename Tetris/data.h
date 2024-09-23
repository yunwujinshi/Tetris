#ifndef _DATA_H_
#define _DATA_H_

/* �������õ����ⲿͷ�ļ� */
#include <stdio.h>
#include "SDL.h"
#include "SDL_image.h"

/* ͼƬ����·�� */
#define PATH_BACKGROUND    "../image/background.png"    // ����ͼƬ
#define PATH_BLOCK_1       "../image/type-1.png"        // ����1������ͼ
#define PATH_BLOCK_2       "../image/type-2.png"        // ����2������ͼ
#define PATH_BLOCK_3       "../image/type-3.png"        // ����3������ͼ
#define PATH_BLOCK_4       "../image/type-4.png"        // ����4������ͼ

#define WINDOW_WIDTH         400   // ���ڿ��
#define WINDOW_HEIGHT        600   // ���ڸ߶�

/* ����ͼƬλ�� */
#define BACKGROUND_PIC_W    WINDOW_WIDTH
#define BACKGROUND_PIC_H    WINDOW_HEIGHT
#define BACKGROUND_PIC_X    0
#define BACKGROUND_PIC_Y    0

/* ͼƬ���ͽṹ�� */
typedef struct picture
{
    SDL_Texture *pPic;     // ͼƬ����ָ��
    SDL_Rect srcRect;      // Դ����
    SDL_Rect dstRect;      // Ŀ������
} Picture;

#endif  // _DATA_H_
