#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#define ERROR  0
#define OK  1

#define STACK_INIT_SIZE   100
#define STACKINCREMENT  10
typedef int SElemType;
typedef int Status;

typedef struct
{
    SElemType *base;        // ջ��ָ�루ʼ��ָ��ջ�ף�
    SElemType *top;         // ջ��ָ��
    int  stacksize;         // ��ǰջ���������
} SqStack;


typedef struct SNode         //����һ����ջ
 {
    SElemType data;
    struct SNode *next;
 }SNode,*LinkStack;


 //˳��ջ
Status  initStack(SqStack *S);
Status stackEmpty(SqStack* S);
Status getTop(SqStack* S, SElemType e);
Status push(SqStack* S, SElemType e);
Status pop(SqStack* S, SElemType *e);
//��ջ
 void iniStack2(LinkStack top);
 Status push2(LinkStack top, SElemType e);
 Status pop2(LinkStack top, SElemType e);
 Status getTop2(LinkStack top, SElemType e);




#endif // STACK_H_INCLUDED
