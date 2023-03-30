#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int partition(int arr[], int left, int right) {
    int pivot = arr[right];  
    int i = left - 1;  

    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);  
        }
    }

    swap(arr[i+1], arr[right]);
    return i+1;  
}

void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int p = partition(arr, left, right);

        quickSort(arr, left, p-1);
        quickSort(arr, p+1, right);
    }
}

void getmedian(int arr[], int n){
    float median;

    for(int i = 0; i < n; i++){
        int temp[i+1];
        for(int k = 0; k <= i; k++){
            temp[k] = arr[k];
        }

        quickSort(temp, 0, i);

        if(i%2 == 0){            
            median = temp[i/2];
        } 
        else {
            median = temp[(i/2)] + temp[(i/2)+1] ;
            median = median/2;
        }

        cout << "\nSorted Array : [ ";
        for(int j = 0; j <= i; j++){
            cout << temp[j] << " ";
        }
        cout << "]" << setw(25-i*2) << "Median : " << fixed << setprecision(1) << median;
    }
}

int main(){
    int arr[] =  {10, 7, 8, 9, 1, 5};
    /*cout << "enter stream: ";
    cin >> arr[];*/
    int n = sizeof(arr)/sizeof(arr[0]);

    getmedian(arr,n);
    return 0;
}