#include <stdio.h>
#include <stdlib.h>
#include "ADT.h"


Status InitAQueue(AQueue *Q)   //��ʼ��ѭ������
{
    //Q = (double*)malloc(MAXQUEUE*sizeof(double));
    Q->front=0;
    Q->rear=0;
    return TRUE;
}

int LengthAQueue(AQueue *Q)   //�鿴���г���
{
    return ((Q->rear) - (Q->front) + MAXQUEUE)%MAXQUEUE;
}

int EnAQueue(AQueue *Q, float e)   //���
{
    if((Q->rear+1)%MAXQUEUE == Q->front)
        return FLASE;
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1)%MAXQUEUE;
    return TRUE;
}

Status DeAQueue(AQueue *Q)      //����
{
    if(Q->front == Q->rear)
        return FLASE;
    Q->front = (Q->front + 1)%MAXQUEUE;
    return TRUE;
}

void DestoryAQueue(AQueue *Q)   //���ٶ���
{
    if(Q!=NULL)
    {
        free(Q);
        Q = NULL;
        printf("�������ٳɹ���\n");
    }
}

Status IsFullAQueue(const AQueue *Q)   //�ж��Ƿ�Ϊ��
{
    if((Q->rear + 1)%MAXQUEUE == Q->front)
        printf("����Ϊ��\n");
    else
        printf("���в���\n");
        return TRUE;
}

void APrint(AQueue *Q)              //��ӡ��������
{
    if(Q->rear == Q->front)
        printf("�ö���Ϊ��!\n");
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
        printf("���ٿռ�ʧ�ܣ�");
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
