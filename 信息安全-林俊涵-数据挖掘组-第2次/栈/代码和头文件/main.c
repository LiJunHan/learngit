#include <stdio.h>
#include <stdlib.h>
#include "stack.c"
#include "stack.h"

SqStack *SS;
int *e;

int main()
{
    int k;
    printf("������������Ҫ�Ĳ�������\n");
    printf("1.��ʼ��˳��ջ��\n");
    printf("2.���˳��ջ�Ƿ�Ϊ�գ���\n");
    printf("3.��ȡջ��Ԫ�أ���\n");
    printf("4.ѹջ����\n");
    printf("5.��ջ����\n");
    int i;
    scanf("%d",&i);
    switch(i)
    {
        case '1': initStack(SS);break;
        case '2': stackEmpty(SS);break;
        case '3':
                    getTop(SS,k);
                    printf("��ջ��ջ��Ԫ��Ϊ%d",k);break;
        case '4':
                    printf("��������Ҫѹ������ݣ�");
                    scanf("%d",&k);
                    push(SS,k);break;
        case '5': pop(SS,e);
                  printd("��ȡ��������Ϊ%d",*e);break;
        default: printf("�������ѡ�������󣡣�");
    }
    return 0;
}


