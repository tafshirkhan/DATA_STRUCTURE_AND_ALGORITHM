#include <stdio.h>
#include <stdlib.h>

struct Stack
{
   int size;
   int top;
   int *S; //for storing elements.
};

void create(struct Stack *st)
{
    printf("Size of the stack: ");
    scanf("%d",&st->size);
    st->top = -1;
    st->S=(int)malloc(st->size*sizeof(int));
}

void Display(struct Stack st)
{
    int i;
    for(i=st.top; i>=0; i--)
    {
        printf("%d ",st.S[i]);
    }
    printf("\n");
}

void Push(struct Stack *st, int x)
{
    if(st->top == st->size-1)
    {
        printf("Overflow\n");
    }
    else{
        st->top++;
        st->S[st->top]=x;
    }
}

int Pop(struct Stack *st)
{
    int x = -1;
    if(st->top == -1){
        printf("Underflow\n");
    }
    else{
        x = st->S[st->top--];
    }
    return x;
}

int Peak(struct Stack st, int index)
{
    int x =-1;
    if(st.top-index+1<0){
        printf("Invalid \n");
    }else{
        x = st.S[st.top-index+1];
    }
    return x;
}

int isEmpty(struct Stack st)
{
    if(st.top==-1){
        return 1;
    }
    return 0;
}

int isFull(struct Stack st)
{
    if(st.top==st.size-1){
        return 1;
    }
    return 0;
}

int stackTop(struct Stack st)
{
    if(!isEmpty(st)){
        return st.S[st.top];
    }
    return -1;
}


int main()
{
    struct Stack st;


    return 0;
}
