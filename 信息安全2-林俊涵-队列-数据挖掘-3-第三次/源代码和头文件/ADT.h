#ifndef ADT_H_INCLUDED
#define ADT_H_INCLUDED
#define MAXQUEUE 10
//ѭ�����нṹ
typedef struct Aqueue
{
    double data[MAXQUEUE];  	//������
    int front;
    int rear;
	size_t data_size;		//�������ڴ��С
} AQueue;

//��ʽ���нṹ
typedef struct node
{
    double data;       			//������ָ��
    struct node *next;			//ָ��ǰ������һ���
} Node;

typedef struct Lqueue
{
    Node *front;       			//��ͷ
    Node *rear;        			//��β
	size_t data_size;			//�������ڴ��С
} LQueue;

typedef enum
{
    FLASE=0, TRUE=1
} Status;

Status InitAQueue(AQueue *Q);

int LengthAQueue(AQueue *Q);
int EnAQueue(AQueue *Q, float e);
Status DeAQueue(AQueue *Q);
void DestoryAQueue(AQueue *Q);
Status IsFullAQueue(const AQueue *Q);
void APrint(AQueue *Q);
//void InitAQueue(LQueue *Q);
int EnLQueue(LQueue *L, double e);
//double DeAQueue(LQueue *Q);
#endif // ADT_H_INCLUDED
