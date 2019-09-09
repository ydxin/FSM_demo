#pragma once
#ifndef _FSM_H_
#define _FSM_H_

typedef enum
{
	EVENT_1 = 1,
	EVENT_2,
	EVENT_3,
	EVENT_4,
	EVENT_5
}EventID;  //定义的事件

typedef enum
{
	STATE_1 = 1,
	STATE_2,
	STATE_3,
	STATE_4,
	STATE_5
}State; //定义的状态

typedef struct
{
	EventID eventId;//事件ID
	State curState;//当前状态
	void (*eventActFun)();  //函数指针
	State nextState;//下个状态
}FsmTable_t;

typedef struct
{
	FsmTable_t*  FSMTable;//指向的状态表
	State curState;//当前状态
}FSM_t;


void GoState1();	//动作
void GoState2();	//动作
void GoState3();	//动作
void GoState4();	//动作
void GoState5();	//动作

void InitFSM(FSM_t* pFSM); //初始化状态机
void FSMRegist(FSM_t* pFSM,FsmTable_t* pTable); //注册状态机，使其指向状态表首地址
void FSMStateTransfer(FSM_t* pFSM, State next_state); //状态改变函数
void FSMEventHandle(FSM_t* pFSM, EventID event); //状态处理函数

void ChangeEvent(EventID* event); //demo利用事件的循环来处理，实际中，应该是由于某种事件，然后引发状态机改变






#endif // !_FSM_H_
