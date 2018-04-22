#include <stdio.h>
#include <stdlib.h>
#include "ADT.h"


Status InitAQueue(AQueue *Q)   //初始化循环队列
{
    //Q = (double*)malloc(MAXQUEUE*sizeof(double));
    Q->front=0;
    Q->rear=0;
    return TRUE;
}

int LengthAQueue(AQueue *Q)   //查看队列长度
{
    return ((Q->rear) - (Q->front) + MAXQUEUE)%MAXQUEUE;
}

int EnAQueue(AQueue *Q, float e)   //入队
{
    if((Q->rear+1)%MAXQUEUE == Q->front)
        return FLASE;
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1)%MAXQUEUE;
    return TRUE;
}

Status DeAQueue(AQueue *Q)      //出列
{
    if(Q->front == Q->rear)
        return FLASE;
    Q->front = (Q->front + 1)%MAXQUEUE;
    return TRUE;
}

void DestoryAQueue(AQueue *Q)   //销毁队列
{
    if(Q!=NULL)
    {
        free(Q);
        Q = NULL;
        printf("队列销毁成功！\n");
    }
}

Status IsFullAQueue(const AQueue *Q)   //判断是否为满
{
    if((Q->rear + 1)%MAXQUEUE == Q->front)
        printf("队列为满\n");
    else
        printf("队列不满\n");
        return TRUE;
}

void APrint(AQueue *Q)              //打印队列内容
{
    if(Q->rear == Q->front)
        printf("该队列为空!\n");
    if(Q->rear > Q->front)
    {
        int i = Q->front;
        int j = Q->rear;
        for(;i==j;i++)
            printf("%f",Q->data[i]);
    }
    if(Q->rear < Q->front)
    {
        int i = Q->rear;
        int j = Q->front;
        for(int a=0;a<i;i++)
            printf("%f",Q->data[a]);
        for(;j<MAXQUEUE;j++)
            printf("%f",Q->data[j]);
    }
}

/*void InitAQueue(LQueue *Q)
{
    Q = (LQueue*)malloc(sizeof(LQueue));
    Q->front=NULL;
    Q->rear=NULL;
}
*/
int EnLQueue(LQueue *L, double e)
{
    Node *s = (Node*)malloc(sizeof(Node));
    if(!s)
    {
        printf("开辟空间失败！");
        return -1;
    }
    s->data = e;
    s->next = NULL;
    L->rear->next = s;
    L->rear = s;
    return 1;

}

/*double DeAQueue(LQueue *Q)
{
    if(Q->front==Q->rear)
        return -1;
    double x;
    x=Q->front->data;
    LQueue *k;
    k=Q->front;
    Q->front = Q->front->next;
    free(k);
    return x;
}*/
