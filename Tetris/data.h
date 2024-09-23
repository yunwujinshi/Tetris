#ifndef _DATA_H_
#define _DATA_H_

/* 程序中用到的外部头文件 */
#include <stdio.h>
#include "SDL.h"
#include "SDL_image.h"

/* 图片本地路径 */
#define PATH_BACKGROUND    "../image/background.png"    // 背景图片
#define PATH_BLOCK_1       "../image/type-1.png"        // 方块1的像素图
#define PATH_BLOCK_2       "../image/type-2.png"        // 方块2的像素图
#define PATH_BLOCK_3       "../image/type-3.png"        // 方块3的像素图
#define PATH_BLOCK_4       "../image/type-4.png"        // 方块4的像素图

#define WINDOW_WIDTH         400   // 窗口宽度
#define WINDOW_HEIGHT        600   // 窗口高度

/* 背景图片位置 */
#define BACKGROUND_PIC_W    WINDOW_WIDTH
#define BACKGROUND_PIC_H    WINDOW_HEIGHT
#define BACKGROUND_PIC_X    0
#define BACKGROUND_PIC_Y    0

/* 图片类型结构体 */
typedef struct picture
{
    SDL_Texture *pPic;     // 图片纹理指针
    SDL_Rect srcRect;      // 源区域
    SDL_Rect dstRect;      // 目标区域
} Picture;

#endif  // _DATA_H_
