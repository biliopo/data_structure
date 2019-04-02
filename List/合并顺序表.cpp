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
  if (!L.elem) return OK;        // 存储分配失败
  L.length = 0;                  // 空表长度为0
  L.listsize = LIST_INIT_SIZE;   // 初始存储容量
  return OK;
} // InitList_Sq

Status ListInsert_Sq(SqList &L, int i, ElemType e)
{  // 算法2.4
  // 在顺序线性表L的第i个元素之前插入新的元素e，
  // i的合法值为1≤i≤ListLength_Sq(L)+1
  ElemType *p;
  if (i < 1 || i > L.length+1) return ERROR;  // i值不合法
  if (L.length >= L.listsize) {   // 当前存储空间已满，增加容量
    ElemType *newbase = (ElemType *)realloc(L.elem,
                  (L.listsize+LISTINCREMENT)*sizeof (ElemType));
    if (!newbase) return ERROR;   // 存储分配失败
    L.elem = newbase;             // 新基址
    L.listsize += LISTINCREMENT;  // 增加存储容量
  }
  ElemType *q = &(L.elem[i-1]);   // q为插入位置
  for (p = &(L.elem[L.length-1]); p>=q; --p) *(p+1) = *p;
                                  // 插入位置及之后的元素右移
  *q = e;       // 插入e
  ++L.length;   // 表长增1
  return OK;
} // ListInsert_Sq

Status ListDelete_Sq(SqList &L, int i, ElemType &e)
{  // 算法2.5
  // 在顺序线性表L中删除第i个元素，并用e返回其值。
  // i的合法值为1≤i≤ListLength_Sq(L)。
  ElemType *p, *q;
  if (i<1 || i>L.length) return ERROR;  // i值不合法
  p = &(L.elem[i-1]);                   // p为被删除元素的位置
  e = *p;                               // 被删除元素的值赋给e
  q = L.elem+L.length-1;                // 表尾元素的位置
  for (++p; p<=q; ++p) *(p-1) = *p;     // 被删除元素之后的元素左移
  --L.length;                           // 表长减1
  return OK;
} // ListDelete_Sq

Status Mergelist_Sq(SqList La,SqList Lb,SqList &Lc){
    int *pa,*pb,*pc;
    pa=La.elem;pb=Lb.elem;
    Lc.listsize=Lc.length=La.length+Lb.length;
    pc=Lc.elem=(int *)malloc(Lc.listsize*sizeof(int));
    if(!Lc.elem)return ERROR;
    int *pa_last,*pb_last;
    pa_last=La.elem+La.length-1;
    pb_last=Lb.elem+Lb.length-1;
    while(pa<=pa_last&&pb<=pb_last){
        if(*pa<=*pb)*pc++=*pa++;
        else *pc++=*pb++;
    }
    while(pa<=pa_last)*pc++=*pa++;
    while(pb<=pb_last)*pc++=*pb++;

}

Status Lord_Sq(SqList &L){
    int i;
   if(L.length==0)return 0;
   else {
        for(i=0;i<L.length;i++)
    printf("%d ",L.elem[i]);
   }
   return OK;
}

main(){
    SqList La,Lb,Lc;
    InitList_Sq(La);
    InitList_Sq(Lb);
    InitList_Sq(Lc);
    int a,b;
    int i;
    scanf("%d",&a);
    La.length=a;
    for(i=0;i<La.length;i++){
        scanf("%d",&La.elem[i]);
    }
    scanf("%d",&b);
    Lb.length=b;
    for(i=0;i<Lb.length;i++){
        scanf("%d",&Lb.elem[i]);
    }
    Mergelist_Sq(La,Lb,Lc);
    printf("List A:");
    Lord_Sq(La);
    printf("\n");
    printf("List B:");
    Lord_Sq(Lb);
    printf("\n");
    printf("List C:");
    Lord_Sq(Lc);
    printf("\n");
}
