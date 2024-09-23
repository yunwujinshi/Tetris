#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#include "data.h"

// ��ʼ��SDL�⣬�������ں���Ⱦ��
int initSDL(void);

// �ͷ�SDL�⡢���ں���Ⱦ��
void freeSDL(void);

// ����һ��ͼƬ
Picture loadPic(const char * path);

// ����ͼƬ��Ŀ����ʾ����
void setPicDstRect(Picture * picture, int x, int y, int w, int h);

// ����ͼƬ��Դ����
void setPicSrcRect(Picture * picture, int x, int y, int w, int h);

// ���س��������ͼƬ��Դ
int loadPicResources(void);

// �ͷż��ص�ͼƬ��Դ
void freePicResources(void);

// ����Ⱦ���л���һ��ͼƬ
void paintPic(Picture * picture);

// ���ƴ��ڼ�ͼƬ
void paint(void);

#endif  // _INTERFACE_H_
