#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


//˳��ջ ��δ���ջ�������⣬topָ��-baseָ���޷�ͨ�����룩


Status  initStack(SqStack *S)
{
    S->base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
    if(!S->base) return ERROR;
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
    printf("˳��ջ��ʼ���ɹ���");
    return OK;
}

Status stackEmpty(SqStack* S)
{
    if(S->top == S->base)
    {
        printf("��ջ��һ����ջ����");
        return 0;
    }
    else
    {
        printf("��ջ�ǿգ���");
        return 1;
    }
}

/*Status stackFull(SqStack* S)
{
     return ((S->top - S->base) == S.stacksize);
}*/

Status getTop(SqStack* S, SElemType e)
{	//����ջS��ջ��Ԫ��,��ջ��ָ�뱣�ֲ���
    if(S->top == S->base)   //ջΪ��
    {	printf("Stack is empty!");
	return ERROR;
    }
    e = *(S->top-1);
    return OK;
}

Status push(SqStack* S, SElemType e)
{
    /*if(S.top-S.base >= S.stacksize) //����
    {   //׷�Ӵ洢�ռ�
        S.base = (ElemType*)realloc(S.base(S.stacksize+STACKINCREMENT)*sizeof(ElemType));
        if(!S.base) exit(OVERFLOW);  //����
        S.top = S.base+S.stacksize;
        S.stacksize += STACKINCREMENT;
    }*/
    *S->top++ = e; //ջ��ָ����ƣ���ֵ
    printf("�µ���������ջ����");
    return OK;
}

Status pop(SqStack* S, SElemType *e)
{  //��ջS��ջ��Ԫ�ص���������
    if(S->top == S->base)
    {
        printf("Stack is empty!");
        return ERROR;
   }
   e = S->top;
   S->top--;
   printf("ջ��Ԫ���ѵ����������µ�ջ��Ԫ�أ���");
   return OK;
}

// ��ջ

 void iniStack2(LinkStack top)    //��ʼ����ջ
{
    top = (LinkStack)malloc(sizeof(SNode));
    top -> next = NULL;
}

Status push2(LinkStack top, SElemType e)    //ѹջ
{
    LinkStack q;
    q = (LinkStack*)malloc(sizeof(SNode));
    if (!q) exit(ERROR);  //�洢����ʧ��
    q->data = e;
    q->next = top->next;
    top->next = q;
    return OK;
}

Status pop2(LinkStack top, SElemType e)    //��ջ
{
    LinkStack q;
    if (!top->next) return ERROR;
    e = top->next->data; //ȡ��ջ��Ԫ�ص�ֵ
    q = top->next;  //qָ��ջ��Ԫ��
    top->next = q->next; //ɾ��ջ��Ԫ��
    free (q);  //�ͷ�ջ��Ԫ����ռ�Ŀռ�
    return OK;
}

Status getTop2(LinkStack top, SElemType e)   //��ȡջ��Ԫ��
{
    if (!top->next) return ERROR;
    else
    {
    	e = top->next->data;
     	return OK;
    }
}

