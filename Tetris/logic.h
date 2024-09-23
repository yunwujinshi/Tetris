#ifndef _LOGIC_H_
#define _LOGIC_H_

#include "interface.h"

int init(void);

void gameFree(void);

Uint32 timerFun(Uint32 interval, void * param);

void start(void);

#endif  // _LOGIC_H_