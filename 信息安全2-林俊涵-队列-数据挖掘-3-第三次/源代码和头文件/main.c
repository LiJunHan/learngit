#include <stdio.h>
#include <stdlib.h>
#include "ADT.h"



AQueue p;
AQueue *q = &p;
int main()
{
    printf("������������Ҫ�Ĺ��ܣ�\n");
    printf("1.��ʼ��ѭ������\n");
    printf("2.�鿴���г���\n");
    printf("3.�ж϶����Ƿ�Ϊ��\n");
    printf("4.��ӡ���е�����\n");
    printf("5.����\n");
    printf("6.���ٶ���\n");
    printf("7.���\n");
    int k;
    int o;
    //AQueue *q;
    scanf("%d",&k);
    switch(k)
    {
        case 1:InitAQueue(q);
                printf("���г�ʼ���ɹ���\n");break;
        case 2:  o= LengthAQueue(q);
                   printf("����Ϊ%d\n",o);
                   break;
        case 3: IsFullAQueue(q);break;
        case 4: APrint(q);
        case 5: DeAQueue(q);
                    printf("���гɹ���\n");break;
        case 6: DestoryAQueue(q);
                printf("�б����ٳɹ�\n");break;
        case 7: printf("��������Ҫ�����Ԫ�أ�");
                    double e;
                    scanf("%f",&e);
                    EnAQueue(q,e);
                    printf("���ݲ���ɹ�����\n");break;
        default: printf("���������������\n");

    }
    main();
    return 0;
}
