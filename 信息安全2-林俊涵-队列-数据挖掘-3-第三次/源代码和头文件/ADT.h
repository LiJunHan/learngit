#ifndef ADT_H_INCLUDED
#define ADT_H_INCLUDED
#define MAXQUEUE 10
//循环队列结构
typedef struct Aqueue
{
    double data[MAXQUEUE];  	//数据域
    int front;
    int rear;
	size_t data_size;		//数据域内存大小
} AQueue;

//链式队列结构
typedef struct node
{
    double data;       			//数据域指针
    struct node *next;			//指向当前结点的下一结点
} Node;

typedef struct Lqueue
{
    Node *front;       			//队头
    Node *rear;        			//队尾
	size_t data_size;			//数据域内存大小
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
