#include <stdio.h>
#include <stdlib.h>

struct Array
{
     int *A;
     int size;
     int length;
};
void Display(struct Array arr)
{
     int i;
     printf("\nElements are\n");
     for(i=0;i<arr.length;i++)
     printf("%d ",arr.A[i]);
}

struct Array* Merge(struct Array *arr1,struct Array *arr2){
     int i,j,k;
     i=j=k=0;
     //creating array from heap, obj will created in heap so that
     //we can return it and use it inside main function.
     struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length){
          if(arr1->A[i]<arr2->A[j]){
          arr3->A[k++]=arr1->A[i++];
          }
          else{
          arr3->A[k++]=arr2->A[j++];
          }
    }
    //for remaining A array elements
    for(;i<arr1->length;i++){
       arr3->A[k++]=arr1->A[i];
    }
    //for remaining B array elements
    for(;j<arr2->length;j++){
       arr3->A[k++]=arr2->A[j];
    }

    arr3->length=arr1->length+arr2->length;
    arr3->size=10;

    //As arr3 created into the heap we can return this to the main function.
    return arr3;
}

struct Array* Union(struct Array *arr1,struct Array *arr2){
     int i,j,k;
     i=j=k=0;

     struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

       while(i<arr1->length && j<arr2->length){
          if(arr1->A[i]<arr2->A[j]){
             arr3->A[k++]=arr1->A[i++];
          }
          else if(arr2->A[j]<arr1->A[i]){
             arr3->A[k++]=arr2->A[j++];
          }
          else{
            arr3->A[k++]=arr1->A[i++];
            j++;
          }
       }
       for(;i<arr1->length;i++){
          arr3->A[k++]=arr1->A[i];
       }
       for(;j<arr2->length;j++){
          arr3->A[k++]=arr2->A[j];
       }
       arr3->length=k;
       arr3->size=10;

       return arr3;
}

struct Array* Intersection(struct Array *arr1,struct Array *arr2){

    int i,j,k;
    i=j=k=0;

    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));
    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i]<arr2->A[j]){
            i++;
        }
        else if(arr2->A[j]<arr1->A[i]){
            j++;
        }
        else if(arr1->A[i] == arr2->A[j]){
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
    }
    arr3->length=k;
    arr3->size=10;

    return arr3;


}

struct Array* Difference(struct Array *arr1,struct Array *arr2){

    int i,j,k;
    i=j=k=0;

    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i]<arr2->A[j]){
            arr3->A[k++]=arr1->A[i++];
        }
        else if(arr2->A[j]<arr1->A[i]){
            j++;
        }
        else if(arr1->A[i] == arr2->A[j]){
            i++;
            j++;
        }

    }
    for(; i<arr1->length; i++){
        arr3->A[k++]=arr1->A[i];
    }
    arr3->length=k;
    arr3->size=10;


}


int main()
{
    int i;
    struct Array arr1;
    struct Array arr2;
    struct Array *arr3;
    int ch;
    int x,index;

    printf("Enter size of the Array 1:\n");
    scanf("%d",&arr1.size);
    //creating array inside the heap memory
    arr1.A=(int *)malloc(arr1.size*sizeof(int));
    printf("Enter Array 1 length:\n");
    scanf("%d",&arr1.length);
    printf("Enter Array 1 elements\n");
    for(i=0; i<arr1.length; i++){
        scanf("%d",&arr1.A[i]);
    }

    printf("Enter size of the Array 2\n");
    scanf("%d",&arr2.size);
    arr2.A=(int *)malloc(arr2.size*sizeof(int));
    printf("Enter Array 2 length:\n");
    scanf("%d",&arr2.length);
    printf("Enter Array 2 elements\n");
    for(i=0; i<arr2.length; i++){
        scanf("%d",&arr2.A[i]);
    }


   do{
    //creating menu bar
    printf("Menu\n");
    printf("1. Merge\n");
    printf("2. Union\n");
    printf("3. Intersection\n");
    printf("4. Difference\n");
    printf("5. Display\n");
    printf("6. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &ch);

    switch(ch){
        case 1: printf("Merge array:\n");
        arr3 = Merge(&arr1,&arr2);
        Display(*arr3);
        break;
        case 2: printf("Union:\n");
        arr3 = Union(&arr1,&arr2);
        Display(*arr3);
        break;
        case 3: printf("Intersection:\n");
        arr3 = Intersection(&arr1,&arr2);
        Display(*arr3);
        break;
        case 4: printf("Difference:\n");
        arr3 = Difference(&arr1,&arr2);
        Display(*arr3);
        break;
        case 5:Display(arr1);
    }
   }while(ch<6);

     return 0;
}
