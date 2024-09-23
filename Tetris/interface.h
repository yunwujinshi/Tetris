#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#include "data.h"

// 初始化SDL库，创建窗口和渲染器
int initSDL(void);

// 释放SDL库、窗口和渲染器
void freeSDL(void);

// 加载一幅图片
Picture loadPic(const char * path);

// 设置图片的目标显示区域
void setPicDstRect(Picture * picture, int x, int y, int w, int h);

// 设置图片的源区域
void setPicSrcRect(Picture * picture, int x, int y, int w, int h);

// 加载程序所需的图片资源
int loadPicResources(void);

// 释放加载的图片资源
void freePicResources(void);

// 在渲染器中绘制一幅图片
void paintPic(Picture * picture);

// 绘制窗口及图片
void paint(void);

#endif  // _INTERFACE_H_
