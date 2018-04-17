#include <stdio.h>
#include <stdlib.h>
#include "stack.c"
#include "stack.h"

SqStack *SS;
int *e;

int main()
{
    int k;
    printf("请输入您所需要的操作！！\n");
    printf("1.初始化顺序栈！\n");
    printf("2.检查顺序栈是否为空！！\n");
    printf("3.获取栈顶元素！！\n");
    printf("4.压栈！！\n");
    printf("5.出栈！！\n");
    int i;
    scanf("%d",&i);
    switch(i)
    {
        case '1': initStack(SS);break;
        case '2': stackEmpty(SS);break;
        case '3':
                    getTop(SS,k);
                    printf("该栈的栈顶元素为%d",k);break;
        case '4':
                    printf("请输入您要压入的数据：");
                    scanf("%d",&k);
                    push(SS,k);break;
        case '5': pop(SS,e);
                  printd("您取出的数据为%d",*e);break;
        default: printf("您输入的选择项有误！！");
    }
    return 0;
}


