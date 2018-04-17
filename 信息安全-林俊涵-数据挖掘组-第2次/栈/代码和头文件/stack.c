#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


//顺序栈 （未解决栈溢满问题，top指针-base指针无法通过编译）


Status  initStack(SqStack *S)
{
    S->base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
    if(!S->base) return ERROR;
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
    printf("顺序栈初始化成功！");
    return OK;
}

Status stackEmpty(SqStack* S)
{
    if(S->top == S->base)
    {
        printf("该栈是一个空栈！！");
        return 0;
    }
    else
    {
        printf("该栈非空！！");
        return 1;
    }
}

/*Status stackFull(SqStack* S)
{
     return ((S->top - S->base) == S.stacksize);
}*/

Status getTop(SqStack* S, SElemType e)
{	//返回栈S的栈顶元素,但栈顶指针保持不变
    if(S->top == S->base)   //栈为空
    {	printf("Stack is empty!");
	return ERROR;
    }
    e = *(S->top-1);
    return OK;
}

Status push(SqStack* S, SElemType e)
{
    /*if(S.top-S.base >= S.stacksize) //判满
    {   //追加存储空间
        S.base = (ElemType*)realloc(S.base(S.stacksize+STACKINCREMENT)*sizeof(ElemType));
        if(!S.base) exit(OVERFLOW);  //上溢
        S.top = S.base+S.stacksize;
        S.stacksize += STACKINCREMENT;
    }*/
    *S->top++ = e; //栈顶指针后移，赋值
    printf("新的数据已入栈！！");
    return OK;
}

Status pop(SqStack* S, SElemType *e)
{  //将栈S的栈顶元素弹出并返回
    if(S->top == S->base)
    {
        printf("Stack is empty!");
        return ERROR;
   }
   e = S->top;
   S->top--;
   printf("栈顶元素已弹出，生成新的栈顶元素！！");
   return OK;
}

// 链栈

 void iniStack2(LinkStack top)    //初始化链栈
{
    top = (LinkStack)malloc(sizeof(SNode));
    top -> next = NULL;
}

Status push2(LinkStack top, SElemType e)    //压栈
{
    LinkStack q;
    q = (LinkStack*)malloc(sizeof(SNode));
    if (!q) exit(ERROR);  //存储分配失败
    q->data = e;
    q->next = top->next;
    top->next = q;
    return OK;
}

Status pop2(LinkStack top, SElemType e)    //出栈
{
    LinkStack q;
    if (!top->next) return ERROR;
    e = top->next->data; //取出栈顶元素的值
    q = top->next;  //q指向栈顶元素
    top->next = q->next; //删除栈顶元素
    free (q);  //释放栈顶元素所占的空间
    return OK;
}

Status getTop2(LinkStack top, SElemType e)   //获取栈顶元素
{
    if (!top->next) return ERROR;
    else
    {
    	e = top->next->data;
     	return OK;
    }
}

