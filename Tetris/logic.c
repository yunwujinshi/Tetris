#include "interface.h"

//===========================
// ������void gameFree(void)
// ���ã���Ϸ��Դ�ͷ�
//===========================
void gameFree(void)
{
    // �ͷ�ͼƬ
    freePicResources();

    // �˳�SDL�⣬�ͷŴ��ڡ���Ⱦ��
    freeSDL();
}

//===========================
// ������Uint32 timerFun(Uint32 interval, void * param)
// ���ã���ʱ����Ӧ����
//===========================
Uint32 timerFun(Uint32 interval, void * param)
{
    // ���ƴ���
    paint();

    return interval;
}

//===========================
// ������void init(void)
// ���ã���Ϸ��ʼ��
//===========================
int init(void)
{
    // ��ʼ��SDL��
    if (initSDL() != 0)
    {
        return -1;
    }

    // ����ͼƬ��Դ
    if (loadPicResources() != 0)
    {
        return -2;
    }

    return 0;
}

//===========================
// ������void logicStart(void)
// ���ã���Ϸ��ʼ����Ӷ�ʱ�����Լ��¼�ѭ����
//===========================
void start(void)
{
    SDL_Event event;    // �¼����ͱ���
    int nQuit = 0;      // �˳���ʶ��0ѭ������0�˳�ѭ��

    // ��Ӷ�ʱ������
    SDL_AddTimer(85, timerFun, NULL);

    // ����Ϣ������ѭ����ȡ�¼�
    while (nQuit == 0)  // �ж��Ƿ��˳��¼�ѭ��
    {
        while (SDL_PollEvent(&event))  // ��ȡ�¼�
        {
            switch (event.type)        // �¼������
            {
                case SDL_QUIT:         // �˳��¼�
                    nQuit = 1;         // �û������˳��¼�������ѭ��
                    break;
                default:
                    break;
            }
        }
    }
} 