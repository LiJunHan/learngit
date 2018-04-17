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
    SElemType *base;        // 栈底指针（始终指向栈底）
    SElemType *top;         // 栈顶指针
    int  stacksize;         // 当前栈的最大容量
} SqStack;


typedef struct SNode         //定义一个链栈
 {
    SElemType data;
    struct SNode *next;
 }SNode,*LinkStack;


 //顺序栈
Status  initStack(SqStack *S);
Status stackEmpty(SqStack* S);
Status getTop(SqStack* S, SElemType e);
Status push(SqStack* S, SElemType e);
Status pop(SqStack* S, SElemType *e);
//链栈
 void iniStack2(LinkStack top);
 Status push2(LinkStack top, SElemType e);
 Status pop2(LinkStack top, SElemType e);
 Status getTop2(LinkStack top, SElemType e);




#endif // STACK_H_INCLUDED
