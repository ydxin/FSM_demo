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
}EventID;  //������¼�

typedef enum
{
	STATE_1 = 1,
	STATE_2,
	STATE_3,
	STATE_4,
	STATE_5
}State; //�����״̬

typedef struct
{
	EventID eventId;//�¼�ID
	State curState;//��ǰ״̬
	void (*eventActFun)();  //����ָ��
	State nextState;//�¸�״̬
}FsmTable_t;

typedef struct
{
	FsmTable_t*  FSMTable;//ָ���״̬��
	State curState;//��ǰ״̬
}FSM_t;


void GoState1();	//����
void GoState2();	//����
void GoState3();	//����
void GoState4();	//����
void GoState5();	//����

void InitFSM(FSM_t* pFSM); //��ʼ��״̬��
void FSMRegist(FSM_t* pFSM,FsmTable_t* pTable); //ע��״̬����ʹ��ָ��״̬���׵�ַ
void FSMStateTransfer(FSM_t* pFSM, State next_state); //״̬�ı亯��
void FSMEventHandle(FSM_t* pFSM, EventID event); //״̬������

void ChangeEvent(EventID* event); //demo�����¼���ѭ��������ʵ���У�Ӧ��������ĳ���¼���Ȼ������״̬���ı�






#endif // !_FSM_H_
