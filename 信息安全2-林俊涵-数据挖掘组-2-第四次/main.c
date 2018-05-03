#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAXSIZE 10
#define RANDMAX 1000000
#define RANDMIN 900000
#define Max_ 10      //数组个数
#define RADIX_10 10    //整形排序
#define KEYNUM_31 10

typedef struct
{
    int r[10001];
    int length ;
}SqList;

void insertSort(int Array[],int size)   //插入算法
{
    int i,j;
    for(i=2;i<=size;i++)
    {
        Array[0] = Array[i];
        for(j=i-1;Array[j]>Array[0];j--)
        {
            Array[j+1] = Array[j];
        }
        Array[j+1]=Array[0];
    }
}

/*
void mergeArray(int a[], int first, int mid, int last) {

    int i, j, m, n;
    i = first, m = mid;
    j = mid+1, n = last;
    int k = 0;
    int temp[SIZE];

    while(i<=m && j<=n) {
        if(a[i] < a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }

    while(i<=m) temp[k++] = a[i++];
    while(j<=n) temp[k++] = a[j++];

    for(i=0; i<k; i++) {
        a[first+i] = temp[i];
    }

}

//归并排序
void merge_sort(int a[], int start, int end) {
    int mid = (start+end)/2;
    if(start<end) {
        merge_sort(a, start, mid);
        merge_sort(a, mid+1, end);
        mergeArray(a, start, mid, end);
    }
}
*/


void getRandArray(int Array[] ,int size)   //获取随机数
{
    srand((unsigned) time(NULL));
    for(int i=0;i<=size;i++)
    {
        Array[i] = rand() % (RANDMAX - RANDMIN) + RANDMIN ;
    }
}


void countSort(int array[],int size)
{
    int *countArray = (int *)calloc(RANDMAX,sizeof(int));
    //用于统计Array数组中各个值出现的次数
    int *sortedArray = (int *)calloc(size,sizeof(int));
    //用来存放已经有序的数列
    int index = 0;
    for(index=0; index < size; ++index)
    {
        countArray[array[index]]++;
    }
    //统计数组array中各个不同数出现的次数，循环结束后countArray[i]表示数值i在array中出现的次数
    for(index=1;index<RANDMAX;++index)
    {
        countArray[index]+=countArray[index-1];
    }
    for(index = size - 1; index >= 0; --index)
    {
        sortedArray[countArray[array[index]] - 1] = array[index];
        --countArray[array[index]];
    }
    memcpy(array, sortedArray, size * sizeof(int));
    free(sortedArray);
    free(countArray);
}

int GetNumInPos(int num,int pos)   //取第N位数据
{
    int temp = 1;
    for (int i = 0; i < pos - 1; i++)
        temp *= 10;

    return (num / temp) % 10;
}

void RadixSort(int* pDataArray, int size)
{
    int *radixArrays[size];    //分别为0~9的序列空间
    for (int i = 0; i < 10; i++)
    {
        radixArrays[i] = (int *)malloc(sizeof(int) * (size + 1));
        radixArrays[i][0] = 0;    //index为0处记录这组数据的个数
    }

    for (int pos = 1; pos <= KEYNUM_31; pos++)    //从个位开始到31位
    {
        for (int i = 0; i < size; i++)    //分配过程
        {
            int num = GetNumInPos(pDataArray[i], pos);
            int index = ++radixArrays[num][0];
            radixArrays[num][index] = pDataArray[i];
        }

        for (int i = 0, j =0; i < RADIX_10; i++)    //收集
        {
            for (int k = 1; k <= radixArrays[i][0]; k++)
                pDataArray[j++] = radixArrays[i][k];
            radixArrays[i][0] = 0;    //复位
        }
    }
}

/**
*
*   快速排序
*/
int Partitoion(int Array[],int low,int high)
{
    int pivotkey;
    pivotkey = Array[low];
    Array[0] = pivotkey;
    while(low<high)
    {
        while(low<high&&Array[high]>=pivotkey)
            high--;
            Array[low] = Array[high];
        while(low<high&&Array[low]<=pivotkey)
            low++;
            Array[high] = Array[low];
    }
    Array[low] = Array[0];
    return low;
}

void QuickSort(int Array[],int low,int high)
{
    int pivot;
    if(low<high)
    {
        pivot=Partitoion(Array,low,high);
        QuickSort(Array,low,pivot-1);
        QuickSort(Array,pivot+1,high);
    }

}

void colorSort(int Array[],int size)
{
    int k;
    int low = 0;
    int high = size - 1;
    int index = 0;
    for(;high!=index;)
    {
        if(Array[index]==0)
        {
            k=Array[low];
            Array[low]=Array[index];
            Array[index]=k;
            low++;
             if(Array[index]==2)
                    {
                        k=Array[high];
                        Array[high]=Array[index];
                        Array[index]=k;
                        high--;
                        index++;
                        continue;
                    }
            index++;
        }
        else
        {
            if(Array[index]==1)
            {
                index++;
                continue;
            }
            else
                {
                    if(Array[index]==2)
                    {
                        k=Array[high];
                        Array[high]=Array[index];
                        Array[index]=k;
                        low++;
                        if(Array[index]==0)
                        {
                            k=Array[low];
                            Array[low]=Array[index];
                            Array[index]=k;
                            low++;
                            index++;
                            continue;
                        }
                        index++;
                    }

                }

        }
    }
}

int main()
{
    int a[10]={1,2,1,0,1,2,1,0,2,1};
    colorSort(a,10);
    //for(int i =0;i<10;i++)
    //printf("%d",a[i]);

    double TheTimes;
    clock_t start11,end11,start12,end12,start13,end13;
    clock_t start21,end21,start22,end22,start23,end23;
    clock_t start31,end31,start32,end32,start33,end33;
    clock_t start41,end41,start42,end42,start43,end43;
    int p1[10001];
    int p2[50001];
    int p3[200001];
    getRandArray(p1,10001);
    getRandArray(p2,50001);
    getRandArray(p3,200001);
    //insertSort(p3,200001);
   // countSort(p3,200001);
    start11 = clock();
    insertSort(p1,10001);
    end11 = clock();

    start12 = clock();
    insertSort(p2,50001);
    end12 = clock();

    start13 = clock();
    QuickSort(p1,0,10001);
    end13 = clock();

    getRandArray(p1,10001);
    getRandArray(p2,50001);
    getRandArray(p3,200001);

    start21 = clock();
    QuickSort(p1,0,10001);
    end21 = clock();

    start22 = clock();
    QuickSort(p2,0,50001);
    end22 = clock();

    start23 = clock();
    insertSort(p3,200001);
    end23 = clock();

    getRandArray(p1,10001);
    getRandArray(p2,50001);
    getRandArray(p3,200001);
    start31 = clock();
    countSort(p1,10001);
    end31 = clock();

    start32 = clock();
    countSort(p2,50001);
    end32 = clock();

    start33 = clock();
    countSort(p3,200001);
    end33 = clock();

    getRandArray(p1,10001);
    getRandArray(p2,50001);
    getRandArray(p3,200001);

    start41 = clock();
    RadixSort(p1,10001);
    end41 = clock();

    start42 = clock();
    RadixSort(p2,50001);
    end42 = clock();

    start43 = clock();
    RadixSort(p3,200001);
    end43 = clock();
    //
    //RadixSort(p1,10001);



    //printf("time=%f\n",(double)(end-start)/CLK_TCK);

    printf("---------------------------------------------------------------------\n");
    printf("|            |        10K|                  50K|                200K|\n");
    printf("---------------------------------------------------------------------\n");
    printf("|    插入排序|   %f|             %f|            %f|\n",(double)(end11-start11)/CLK_TCK,(double)(end12-start12)/CLK_TCK,(double)(end13-start13)/CLK_TCK);
    printf("---------------------------------------------------------------------\n");
    printf("|    快速排序|   %f|             %f|           %f|\n",(double)(end21-start21)/CLK_TCK,(double)(end22-start22)/CLK_TCK,(double)(end23-start23)/CLK_TCK);
    printf("---------------------------------------------------------------------\n");
    printf("|    递归排序|   %f|             %f|            %f|\n",(double)(end41-start41)/CLK_TCK,(double)(end42-start42)/CLK_TCK,(double)(end43-start43)/CLK_TCK);
    printf("---------------------------------------------------------------------\n");
    printf("|    计数排序|   %f|             %f|            %f|\n",(double)(end31-start31)/CLK_TCK,(double)(end32-start32)/CLK_TCK,(double)(end33-start33)/CLK_TCK);
    printf("---------------------------------------------------------------------\n");
    printf("|基数计数排序|   %f|             %f|            %f|\n",(double)(end41-start41)/CLK_TCK,(double)(end42-start42)/CLK_TCK,(double)(end43-start43)/CLK_TCK);
    printf("---------------------------------------------------------------------\n");

    /*getRandArray(p2,50001);
    for(int i=1;i<=50001;++i)
    {

        printf("%d\n",p2[i]);
    }
    getRandArray(p1,200001);
    for(int i=1;i<=200001;++i)
    {

        printf("%d\n",p3[i]);
    }*/

    /*for(int i=1;i<=50000;++i)
        p2.r[i]=getRand();
    for(int i=1li<=200000;++i)
        p3.r[i]=getRand();*/

    // p.r[11]=87;


    //insertSort(d);
    //MergeSort(d);
    //QuickSort(d);
   /* countSort(array,size);
        for(int k=0;k<10;k++)
    {
        printf("%d\n",array[k]);
    }
    int arr_test[Max_] = { 8, 4, 2, 3, 5, 1, 6, 9, 0, 7 };
    */

    return 0;
}

