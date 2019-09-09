#include "fsm.h"
#include <stdio.h>
#include <windows.h> 
int main()
{
	FSM_t fsm;
	InitFSM(&fsm);
	EventID event = EVENT_1;
	while (1)
	{
		printf("current state is state%d\n", fsm.curState);
		printf("event %d is coming ......\n",event);
		FSMEventHandle(&fsm,event);
		ChangeEvent(&event);
		Sleep(2000);
	}
}