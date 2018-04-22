#include <stdio.h>
#include <stdlib.h>
#include "ADT.h"



AQueue p;
AQueue *q = &p;
int main()
{
    printf("请输入您所需要的功能：\n");
    printf("1.初始化循环链表\n");
    printf("2.查看队列长度\n");
    printf("3.判断队列是否为满\n");
    printf("4.打印队列的内容\n");
    printf("5.出队\n");
    printf("6.销毁队列\n");
    printf("7.入队\n");
    int k;
    int o;
    //AQueue *q;
    scanf("%d",&k);
    switch(k)
    {
        case 1:InitAQueue(q);
                printf("队列初始化成功！\n");break;
        case 2:  o= LengthAQueue(q);
                   printf("长度为%d\n",o);
                   break;
        case 3: IsFullAQueue(q);break;
        case 4: APrint(q);
        case 5: DeAQueue(q);
                    printf("出列成功！\n");break;
        case 6: DestoryAQueue(q);
                printf("列表销毁成功\n");break;
        case 7: printf("请输入您要插入的元素：");
                    double e;
                    scanf("%f",&e);
                    EnAQueue(q,e);
                    printf("数据插入成功！！\n");break;
        default: printf("您输入的请求有误！\n");

    }
    main();
    return 0;
}
