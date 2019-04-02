#include<stdio.h>
#include<malloc.h>
#define OK 1
#define ERROR 0
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define ElemType int

typedef int Status;
typedef struct
{
    int *elem;
    int length;
    int listsize;
}SqList;

Status InitList_Sq(SqList &L)
{  // 算法2.3
  // 构造一个空的线性表L。
  L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
  if (!L.elem) return ERROR;        // 存储分配失败
  L.length = 0;                  // 空表长度为0
  L.listsize = LIST_INIT_SIZE;   // 初始存储容量
  return OK;
} // InitList_Sq

Status ListInvert_Sq(SqList &L)
{
    int i,temp;
    for(i=0;i<L.length/2;i++){
        temp=L.elem[i];
        L.elem[i]=L.elem[L.length-1-i];
        L.elem[L.length-1-i]=temp;
    }
    return OK;
}

Status load(SqList &L)
{
    int i;
   if(L.length==0)return 0;
   else {
        for(i=0;i<L.length;i++)
    printf("%d ",L.elem[i]);
   }
   return OK;
}
main(){
    int n,i;
    SqList L;
    if(!InitList_Sq(L)) return ERROR;
    scanf("%d",&n);
    L.length=n;
    for(i=0;i<n;i++){
        scanf("%d",&L.elem[i]);
    }
    printf("The List is:");
    load(L);
    printf("\n");
    ListInvert_Sq(L);
    printf("The turned List is:");
    load(L);
}
