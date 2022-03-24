#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first=NULL, *second=NULL, *third=NULL; //global pointer


void create(int A[],int n){
    int i;
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(i=1; i<n; i++){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void createSecond(int A[],int n){
    int i;
    struct Node *t,*last;
    second=(struct Node *)malloc(sizeof(struct Node));
    second->data=A[0];
    second->next=NULL;
    last=second;

    for(i=1; i<n; i++){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void Display(struct Node *p){
    while(p!=NULL){
        printf("%d\n",p->data);
        p=p->next;
    }
}

void RecursiveDisplay(struct Node *p){
    if(p != NULL){
        RecursiveDisplay(p->next);
        printf("%d\n",p->data);

    }
}

int Count(struct Node *p){
    int c=0;
    while(p!=NULL){
        c++;
        p=p->next;
    }
    return(c);
}

int RecursiveCount(struct Node *p){
    int c=0;
    if(p==NULL){
        return 0;
    }
    else{
        return RecursiveCount(p->next)+1;
    }
}

int Sum(struct Node *p){
    int sum=0;
    while(p){
        sum = sum + p->data;
        p=p->next;
    }
    return(sum);
}

int RecursiveSum(struct Node *p){
    int sum=0;
    if(p==NULL){
        return 0;
    }
    else{
        return RecursiveSum(p->next)+p->data;
    }

}

int Max(struct Node *p){
    int max=-32768;
    while(p){
        if(p->data>max){
            max=p->data;
        }
        p=p->next;
    }
    return max;
}

int RecursiveMax(struct Node *p){
    int max=-32768;
    int x=0;
    if(p==0){
        return max;
    }
    x=RecursiveMax(p->next);
    if(x > p->data){
        return x;
    }
    else{
        return p->data;
    }
}

struct Node * LenearSearch(struct Node *p, int key){
    struct Node *q=NULL;

    while(p!=NULL){
        if(key==p->data){
            q->next=p->next;
            p->next=first;
            first=p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}

struct Node * RecursiveSearch(struct Node *p, int key){
    if(p==NULL){
        return NULL;
    }
    if(key==p->data){
        return p;
    }
    return RecursiveSearch(p->next,key);
}

void InsertNode(struct Node *p, int index, int x){
    struct Node *t;
    int i;
    if(index < 0 || index > Count(p)){
        return;
    }
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    if(index==0){
        t->next=first;
        first=t;
    }
    else{
        for(i=0; i<index-1; i++){
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }
}

void SortedInsert(struct Node *p, int x){
    struct Node *t, *q=NULL;
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;

    if(first==NULL){
        first=t;
    }
    else{
        while(p && p->data < x){
            q=p;
            p=p->next;
        }
        if(p==first){
            t->next=first;
            first=t;
        }
        else{
            t->next = q->next;
            q->next=t;
        }
    }
}

int Delete(struct Node *p, int index){
    struct Node *q=NULL;
    int x=-1,i;
    if(index < 1 || index > Count(p)){
        return -1;
    }
    if(x==1){
        q=first;
        x=first->data;
        first=first->next;
        //delete q;
        free(q);
        return x;
    }
    else{
        for(i=0; i<index-1; i++){
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        //delete p;
        free(p);
        return x;
    }
}

int isSorted(struct Node *p)
{
 int x=-65536;

 while(p!=NULL)
 {
     if(p->data < x){
        return 0;
     }

     x=p->data;
     p=p->next;
 }
 return 1;

}

void removeDuplicate(struct Node *p){
    struct Node *q = p->next;

    while(q!=NULL){
        if(p->data != q->data){
            p=q;
            q=q->next;
        }
        else{
            p->next = q->next;
            free(q);
            q=p->next;
        }
    }
}

void ReverseListByArray(struct Node *p)
{
     int *A,i=0;
     struct Node *q=p;

     A=(int *)malloc(sizeof(int)*Count(p));

     while(q!=NULL)
     {
         A[i]=q->data;
         q=q->next;
         i++;
     }
     q=p;
     i--;
     while(q!=NULL)
     {
         q->data=A[i];
         q=q->next;
         i--;
     }
}

void ReverseListByPointer(struct Node *p){
    struct Node *q = NULL, *r = NULL;

    while(p!=NULL){
        r = q;
        q = p;
        p=p->next;
        q->next = r;
    }
    first = q;
}

void ReverseRecursively(struct Node *q, struct Node *p){
    if(p){
        ReverseRecursively(p, p->next);
        p->next = q;
    }
    else{
        first = q;
    }
}

void Concat(struct Node *p, struct Node *q){
    third=p;

    while(p->next != NULL){
        p = p->next;
    }
    p->next = q;
}

void Merging(struct Node *p, struct Node *q){
    struct Node *last;
    if(p->data < q->data){
        third=last=p;
        p=p->next;
        third->next=NULL;
    }
    else{
        third=last=q;
        q=q->next;
        third->next=NULL;
    }

    while(p && q){
        if(p->data < q->data){
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else{
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
    if(p){
        last->next=p;
    }
    if(q){
        last->next=q;
    }
}

int isLoop(struct Node *f){
    struct Node *p,*q;
    do{
        p=p->next;
        q=q->next;
        q=q?q->next:q;
    }
    while(p && q && p!=q);
    {
          if(p==q){
            return 1;
          }
          else{
            return 0;
          }
    }
}

int main()
{
    struct Node *t1,*t2;
    int A[]={10,20,30,40,50};

    //int B[]={5,152,252,352,452};
    create(A,5);

    //createSecond(B,5);

    //generating a loop
    t1=first->next->next;
    t2=first->next->next->next->next;
    t2->next=t1;

    /*struct Node *temp;
    temp=LenearSearch(first,15);
    temp=LenearSearch(first,10);
    if(temp){
        printf("Key is: %d\n",temp->data);
    }
    else{
        printf("Key is not found");
    }*/

    //removeDuplicate(first);

    //ReverseListByArray(first);
    //ReverseListByPointer(first);
    //ReverseRecursively(NULL, first);

    //Concat(second,first);
    //printf("Concatenation\n");
    //Display(third);

    //Merging(first,second);
    //Display(third);
    printf("%d\n",isLoop(first));



    return 0;
}
