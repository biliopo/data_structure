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
{  // �㷨2.3
  // ����һ���յ����Ա�L��
  L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
  if (!L.elem) return OK;        // �洢����ʧ��
  L.length = 0;                  // �ձ���Ϊ0
  L.listsize = LIST_INIT_SIZE;   // ��ʼ�洢����
  return OK;
} // InitList_Sq

Status ListInsert_Sq(SqList &L, int i, ElemType e)
{  // �㷨2.4
  // ��˳�����Ա�L�ĵ�i��Ԫ��֮ǰ�����µ�Ԫ��e��
  // i�ĺϷ�ֵΪ1��i��ListLength_Sq(L)+1
  ElemType *p;
  if (i < 1 || i > L.length+1) return ERROR;  // iֵ���Ϸ�
  if (L.length >= L.listsize) {   // ��ǰ�洢�ռ���������������
    ElemType *newbase = (ElemType *)realloc(L.elem,
                  (L.listsize+LISTINCREMENT)*sizeof (ElemType));
    if (!newbase) return ERROR;   // �洢����ʧ��
    L.elem = newbase;             // �»�ַ
    L.listsize += LISTINCREMENT;  // ���Ӵ洢����
  }
  ElemType *q = &(L.elem[i-1]);   // qΪ����λ��
  for (p = &(L.elem[L.length-1]); p>=q; --p) *(p+1) = *p;
                                  // ����λ�ü�֮���Ԫ������
  *q = e;       // ����e
  ++L.length;   // ����1
  return OK;
} // ListInsert_Sq

Status ListDelete_Sq(SqList &L, int i, ElemType &e)
{  // �㷨2.5
  // ��˳�����Ա�L��ɾ����i��Ԫ�أ�����e������ֵ��
  // i�ĺϷ�ֵΪ1��i��ListLength_Sq(L)��
  ElemType *p, *q;
  if (i<1 || i>L.length) return ERROR;  // iֵ���Ϸ�
  p = &(L.elem[i-1]);                   // pΪ��ɾ��Ԫ�ص�λ��
  e = *p;                               // ��ɾ��Ԫ�ص�ֵ����e
  q = L.elem+L.length-1;                // ��βԪ�ص�λ��
  for (++p; p<=q; ++p) *(p-1) = *p;     // ��ɾ��Ԫ��֮���Ԫ������
  --L.length;                           // ����1
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
