#include "fsm.h"
#include <string.h>
#include <stdio.h>
unsigned short tableNums = 0;
FsmTable_t table[] =
{
	//到来的事件，当前的状态，将要执行的函数，下一个状态
	{EVENT_1,STATE_1,GoState2,STATE_2},
	{EVENT_2,STATE_2,GoState3,STATE_3},
	{EVENT_3,STATE_3,GoState4,STATE_4},
	{EVENT_4,STATE_4,GoState5,STATE_5},
	{EVENT_5,STATE_5,GoState1,STATE_1},
};

void GoState1()
{
	printf("Go to state 1   \n");
}

void GoState2()
{
	printf("Go to state 2  \n");
}

void GoState3()
{
	printf("Go to state 3   \n");
}

void GoState4()
{
	printf("Go to state 4   \n");
}

void GoState5()
{
	printf("Go to state 5   \n");
}

void InitFSM(FSM_t* pFSM)
{
	tableNums = sizeof(table) / sizeof(FsmTable_t);
	pFSM->curState = STATE_1;
	FSMRegist(pFSM, table); //指向第一个状态表，状态表首地址


}

void FSMRegist(FSM_t* pFSM, FsmTable_t* pTable)
{
	pFSM->FSMTable = pTable;
}

void FSMStateTransfer(FSM_t* pFSM, State next_state)
{
	pFSM->curState = next_state;
}

void FSMEventHandle(FSM_t* pFSM, EventID event)
{
	FsmTable_t* pActTable = pFSM->FSMTable;
	void (*eventActFun)() = NULL;
	int nextState ;
	int curState = pFSM->curState;
	int flag = 0;
	for (int i = 0; i < tableNums; i++)
	{
		if (event==pActTable[i].eventId && curState ==pActTable[i].curState)
		{
			flag = 1;
			nextState = pActTable[i].nextState;
			eventActFun = pActTable[i].eventActFun;
			break;
		}
	}
	if (flag)
	{
		if (eventActFun)
		{
			eventActFun();
		}
		FSMStateTransfer(pFSM,nextState);
	}


}

void ChangeEvent(EventID* event)
{
	if ((*event) > EVENT_5)  
		(*event) = EVENT_1;
	else 
		(*event)++;
	
}

