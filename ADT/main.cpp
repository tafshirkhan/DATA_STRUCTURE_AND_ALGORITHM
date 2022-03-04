#include <iostream>

using namespace std;
struct Array
{
    int A[10];
    int Size;
    int length;
};


void Display(struct Array arr){
  cout << "Elements are: "<<endl;
  for(int i=0; i<arr.length; i++){
    cout << arr.A[i] <<endl;
  }
}

void Append(struct Array *arr, int x){
  if(arr->length <arr->Size){
    arr->A[arr->length++]=x;
  }
}

void Insert(struct Array *arr, int index, int x){
    if(index >=0 && index<=arr->length){
        for(int i=arr->length; i>index; i--){
            arr->A[i]=arr->A[i-1];
        }
        arr->A[index]=x;
        arr->length++;
    }

}
int Delete(struct Array *arr, int index){
  int x=0;
  if(index>=0 && index<arr->length){
    x=arr->A[index];
    for(int i=index; i<arr->length-1; i++){
        arr->A[i]=arr->A[i+1];
    }
    arr->length--;
    return x;
  }
  return 0;
}

void Swap(int *x, int *y){
  int temp;
  temp=*x;
  *x=*y;
  *y=temp;

}

int LinearSearch(struct Array arr, int key){
  for(int i=0; i<arr.length; i++){
    if(key == arr.A[i]){
        return i;
    }
  }
  return -1;
}

int ImproveLinearSearch(struct Array *arr, int key){
  for(int i=0; i<arr->length; i++){
    if(key == arr->A[i]){
        //transposition
        //Swap(&arr->A[i], &arr->A[i-1]);
        //Move to front
        Swap(&arr->A[i], &arr->A[0]);
        return i;
    }
  }
  return -1;
}
int BinarySearch(struct Array arr, int key){
    int l,h,mid;
    l=0;
    h=arr.length-1;
    while(l<=h){
        mid=(l+h)/2;
        if(key==arr.A[mid]){
            return mid;
        }
        else if(key<arr.A[mid]){
             h=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return -1;
}

int RBinarySearch(int a[],int l, int h, int key){
    while(l<=h){
        int mid=(l+h)/2;
        if(key==a[mid]){
            return mid;
        }
        else if(key<a[mid]){
             return RBinarySearch(a,l,mid-1,key);
        }
        else{
            return RBinarySearch(a,mid+1,h,key);
        }
    }
    return -1;
}

int Get(struct Array arr, int index){
  if(index >=0 && index<arr.length){
    return arr.A[index];
  }
  return -1;
}

int Set(struct Array *arr, int index, int x){
  if(index >=0 && index<arr->length){
    arr->A[index] = x;
  }
}

int Max(struct Array arr){
  int max = arr.A[0];
  for(int i=0; i<arr.length; i++){
    if(arr.A[i]>max){
        max = arr.A[i];
    }
  }
  return max;
}

int Min(struct Array arr){
  int min = arr.A[0];
  for(int i=0; i<arr.length; i++){
    if(arr.A[i] < min){
        min = arr.A[i];
    }
  }
  return min;
}
void Reverse(struct Array *arr)
{
    int *B;
    int i,j;
    B = new int[arr->length];
    for(i=arr->length-1,j=0;i>=0;i--,j++){
        B[j] = arr->A[i];
    }
    for(int i=0; i<arr->length;i++){
        arr->A[i]=B[i];
    }
}

void Reverse2(struct Array *arr){
    int i,j;
    for(i=0,j=arr->length-1;i<j;i++,j--){
        Swap(&arr->A[i],&arr->A[j]);
    }
}

void InsertSort(struct Array *arr, int x){
    int i=arr->length-1;
    if(arr->length==arr->Size){
        return;
    }
    while( i>=0 && arr->A[i]>x){
        arr->A[i+1]=arr->A[i];
        i--;
    }
    arr->A[i+1]=x;
    arr->length++;
}

int checkSorted(struct Array arr){
    for(int i=0; i<arr.length-1; i++){
        if(arr.A[i] > arr.A[i+1]){
            return 0;
        }
    }
    return 1;
}

void ArrangePositiveNegative(struct Array *arr){
    int i=0;
    int j=arr->length-1;

    while(i<j){
        while(arr->A[i] < 0){
            i++;
        }
        while(arr->A[j] >=0){
            j--;
        }
        if(i<j){
            Swap(&arr->A[i], &arr->A[j]);
        }
    }
}

/*struct Array* MergeArray(struct Array *arr1, struct Array *arr2){
    int i,j,k;
    i=j=k=0;
    //so that we can returning and creating obj inside the main function
    //struct Array *arr3 = new struct Array*(sizeof(struct Array));
    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i]<arr2->A[j]){
            arr3->A[k++]=arr1->A[i++];
        }
        else{
            arr3->A[k++]=arr2->A[j++];
        }
    }
    for(;i<arr1->length; i++){
        arr3->A[k++]=arr1->A[i++];
    }
    for(;j<arr2->length; j++){
        arr3->A[k++]=arr2->A[j++];
    }
    arr3->length=arr1->length+arr2->length;
    arr3->Size=10;

    return arr3;


}*/


int main()
{
    //struct Array arr={{-2,3,1,-4,5,-6,9,-11,22},10,9};
    //struct Array arr1={{2,6,10,15,25},10,5};
    //struct Array arr2={{3,4,7,18,20},10,5};
    //struct Array *arr3; //For merging array

     //Display(arr);
    //Append(&arr,10);
    //Insert(&arr,0,10);
    //Delete(&arr,3);
    //cout <<"Deleted value is"<<" "<< Delete(&arr,3) <<endl;
    //cout<< "Index" <<" "<<ImproveLinearSearch(&arr, 5) <<endl;
    //cout<< "Index" <<" "<<RBinarySearch(arr.A,0,arr.length,2) <<endl;
    //cout<< "value" << " " << Set(&arr, 1,0) <<endl;
    //Reverse2(&arr);
    //InsertSort(&arr,5);
    //cout << "is" <<" "<<checkSorted(arr)<<endl;
    //ArrangePositiveNegative(&arr);

    Display(*arr3);
    return 0;
}
