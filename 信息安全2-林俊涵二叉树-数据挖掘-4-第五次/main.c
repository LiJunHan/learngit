#include <stdio.h>
#include <stdlib.h>
typedef char TElemType;     // �������������Ԫ������Ϊ�ַ�

typedef struct  BiTNode {
    TElemType     data;     // ������
    struct BiTNode  *lchild,*rchild;  // ���Һ���ָ��
} BiTNode,*BiTree;   // ��������

enum Status{
	SUCEESS,
	ERROR
};

typedef struct
{
    int  date[10];
    int top;
}SqStack;

typedef struct Node{
    TElemType Data;
    struct Node *Next;
}Node;

struct QNode{
    struct Node *rear;
    struct Node *front;
};

typedef struct QNode *Queue;

int Push(SqStack *s,int ch)
{
    if(s->top == 9)
        return -1;
    s->top++;
    s->date[s->top] = ch;
    return 0;
}

int Pop(SqStack *s,int *ch)
{
    if(s->top==-1)
        return -1;
    *ch = s->date[s->top];
    s->top--;
    return 0;
}

Queue CreateQueue()
{
    Queue PtrQ;
    PtrQ=(Queue)malloc(sizeof(struct QNode));
    struct Node *rear;
    struct Node *front;
    rear =(Node*)malloc(sizeof(Node));
    rear=NULL;
    front =(Node*)malloc(sizeof(struct Node));
    front=NULL;
    PtrQ->front=front;
    PtrQ->rear=rear;
    return PtrQ;
}

TElemType DeleteQ(Queue PtrQ)
{
    struct Node *FrontCell;
    TElemType FrontElem;

    if(IsEmpty(PtrQ)){
        printf("���п�");
        return ERROR;
    }
    FrontCell=PtrQ->front;
    if(PtrQ->front==PtrQ->rear)
       PtrQ->front=PtrQ->rear=NULL;
    else{
        PtrQ->front=PtrQ->front->Next;
    }
      FrontElem=FrontCell->Data;
      free(FrontCell);
      return FrontElem;
}

void InsertQ(TElemType item,Queue PtrQ)
{
    struct Node *FrontCell;
    FrontCell=(Node*)malloc(sizeof(struct Node));
    FrontCell->Data=item;
    FrontCell->Next=NULL;

    if(IsEmpty(PtrQ)){
        PtrQ->front=FrontCell;
        PtrQ->rear=FrontCell;
    }
    else{
        PtrQ->rear->Next=FrontCell;
        PtrQ->rear=FrontCell;
    }
}

int IsEmpty(Queue Q){
     return(Q->front==NULL);
}


//���ö��в�α���
void LevelOrderTraversal(BiTree BT)
{
    Queue Q;
    BiTree T;
    if(!BT) return 0;
    Q=CreateQueue();
    T=BT;
    InsertQ(T,Q);
    while(!IsEmpty(Q))
    {
        T=DeleteQ(Q);
        printf("%c\t",T->data);
        if(T->lchild) InsertQ(T->lchild,Q);
        if(T->rchild) InsertQ(T->rchild,Q);
    }
    return 0;
}

int InitBiTree(BiTree T)
{
    T = (BiTree)malloc(sizeof(BiTNode));
    (*T).lchild = NULL;
    (*T).rchild = NULL;
    if(T==NULL)
        return -1;
    return 0;
}

int CreateBiTree()
{
    BiTree p;
    TElemType ch;
    scanf("%c",&ch);
    if(ch==' ')
        p = NULL;
    else
    {
        p = (BiTree)malloc(sizeof(BiTNode));
        p->data = ch;
        p->lchild = CreateBiTree();
        p->rchild = CreateBiTree();
    }
    return p;
}

void preOrderTraverse(BiTree T)   //ǰ�����
{
    if( T )
    {
        printf("%c\t",T->data);
        preOrderTraverse(T->lchild);
        preOrderTraverse(T->rchild);
    }
}

void inOrderTraverse(BiTree T)  //�������
{
    if( T )
    {
        inOrderTraverse(T->lchild);
        printf("%c\t",T->data);
        inOrderTraverse(T->rchild);
    }
}
char k[10];
int i = 0;
void PostOrderTraverse(BiTree T)   //�������
{

    if( T )
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        printf("%c\t",T->data);
        k[i] = T->data;
        i++;
    }
}

/*void PostOrderTraversek(BiTree T)   //�������
{

    char *m,*n;
    int sum;
    int *o;
    SqStack *p = &l;
    if(T)
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        if((T->data)>='0'&&(T->data)<='9')
        {
            Push(p,T->data);
        }
        else
        {
            Pop(p,*m);
            Pop(p,*n);
            if((T->data)=='+') sum = ((int)((*m)-'0'))+((int)((*n)-'0'));
            if((T->data)=='*') sum = ((int)((*m)-'0'))*((int)((*n)-'0'));
            if((T->data)=='/') sum = ((int)((*m)-'0'))/((int)((*n)-'0'));
            if((T->data)=='-') sum = ((int)((*m)-'0'))-((int)((*n)-'0'));
            Push(p,sum);
        }
    }
    Pop(p,*o);
    printf("%d",*o);
}*/

int main()
{

    BiTree p;
    InitBiTree(p);
    printf("�봴��һ��������(�ո�Ϊ�ÿշ�)��");
    p = CreateBiTree();
    printf("ǰ��������Ϊ��");
    preOrderTraverse(p);
    printf("\n����������Ϊ��");
    inOrderTraverse(p);
    printf("\n��������Ľ����");
    PostOrderTraverse(p);
    for(int i = 0;i<10;i++)
        printf("%c",k[i]);
    SqStack l;
    char *m,*n;
    int sum;
    SqStack *d = &l;
    for(int g = 0;k[g]!='a';g++)
    {
        if(k[g]>='0'&&k[g]<='9')
        {
            Push(d,k[g]);
        }
        else
        {
            Pop(d,*m);
            Pop(d,*n);
            if(k[g]=='+') sum = ((int)((*m)-'0'))+((int)((*n)-'0'));
            if(k[g]=='*') sum = ((int)((*m)-'0'))*((int)((*n)-'0'));
            if(k[g]=='/') sum = ((int)((*m)-'0'))/((int)((*n)-'0'));
            if(k[g]=='-') sum = ((int)((*m)-'0'))-((int)((*n)-'0'));
            Push(d,sum);
        }
    }
    //PostOrderTraversek(p);
    printf("\n����Ľ����%d",sum);
    //LevelOrderTraversal(p);


    return 0;
}
