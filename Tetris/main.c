#include "interface.h"

int main(void)
{
    Picture pic;

    // ��ʼ��SDL�⣬�������ڡ���Ⱦ��
    if(0 != initSDL())
    {
        return -1;
    }

    // ����ͼƬ��Դ
    if(0 != loadPicResources())
    {
        return -2;
    }

    // ���ƴ���
    paint();

    // �ӳ�5��
    SDL_Delay(5000);

    // �ͷ�ͼƬ
    freePicResources();

    // �˳�SDL�⣬�ͷŴ��ڡ���Ⱦ��
    freeSDL();

    return 0;
}