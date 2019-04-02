#include <stdio.h>
#include <malloc.h>
#define OK 1
#define ERROR 0
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define ElemType int

typedef struct
{
	int *elem;
	int length;
	int listsize;
}SqList;

int InitList_Sq(SqList &L)
{
    L.elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(!L.elem)return(ERROR);
    L.length=0;
    L.listsize=LIST_INIT_SIZE;
    return OK;

}

int Load_Sq(SqList &L)
{

	int i;
	if(L.length==0) printf("The List is empty!");
	else
	{
		printf("The List is: ");
		for(i=0;i<L.length;i++) printf("%d ",L.elem[i]);
	}
	printf("\n");
	return OK;
}

int ListInsert_Sq(SqList &L,int i,int e)
{
    int *newbase,*q,*p;
    if(i<1||i>L.length+1)return ERROR;
    if(L.length>=L.listsize){
        newbase=(ElemType *)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
        if(!newbase)return(ERROR);
        L.elem=newbase;
        L.listsize+=LISTINCREMENT;
    }
    q=&(L.elem[i-1]);
    for(p=&(L.elem[L.length-1]);p>=q;--p)*(p+1)=*p;
    *q=e;
    ++L.length;
    return OK;

}

int ListDelete_Sq(SqList &L,int i, int &e)
{
    int *p,*q;
    if(i<1||i>L.length)return ERROR;
    p=&(L.elem[i-1]);
    e=*p;
    q=L.elem+L.length-1;
    for(++p;p<=q;++p)*(p-1)=*p;
    --L.length;
    return OK;

}

int main()
{
	SqList T;
	int a, i;
	ElemType e, x;
	if(InitList_Sq(T))
	{
		printf("A Sequence List Has Created.\n");
	}
	while(1)
	{
		printf("1:Insert element\n2:Delete element\n3:Load all elements\n0:Exit\nPlease choose:\n");
		scanf("%d",&a);
		switch(a)
		{
			case 1: scanf("%d%d",&i,&x);
					if(!ListInsert_Sq(T,i,x)) printf("Insert Error!\n");
					else printf("The Element %d is Successfully Inserted!\n",x);
					break;
			case 2: scanf("%d",&i);
					if(!ListDelete_Sq(T,i,e)) printf("Delete Error!\n");
					else printf("The Element %d is Successfully Deleted!\n",e);
					break;
			case 3: Load_Sq(T);
					break;
			case 0: return 1;
		}
	}
}
