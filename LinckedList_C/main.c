#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first=NULL; //global pointer


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

int main()
{
    int A[]={3,5,7,8,10};
    create(A,5);

    /*struct Node *temp;
    temp=LenearSearch(first,15);
    temp=LenearSearch(first,10);
    if(temp){
        printf("Key is: %d\n",temp->data);
    }
    else{
        printf("Key is not found");
    }*/
    printf("Deleted element is: %d\n",Delete(first,4));
    Display(first);
    return 0;
}
