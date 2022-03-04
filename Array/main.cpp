#include <iostream>

using namespace std;

struct Array
{
    int *A;
    int Size;
    int length;
};

void Display(struct Array arr){
    cout<< "Elements are: "<<endl;
    for(int i=0; i<arr.length; i++){
        cout << arr.A[i];
    }
}
int main()
{
    struct Array arr;
    int n;
    cout << "Enter size of array: "<<endl;
    cin >> arr.Size;
    arr.A = new int[arr.Size];
    arr.length=0;
    cout << "Enter how many numbers: "<<endl;
    cin>> n;
    cout << "Enter array elements: "<<endl;
    for(int i=0; i <n; i++){
        cin>>arr.A[i];
    }
    arr.length=n;

    Display(arr);






    return 0;
}
