#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <chrono>

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

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    int arr1[5];
    int count = 0;
    while(count < 5){
        srand(time(0));
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 10001 + 10000;
        }

        double cpu_time_used;
    
        auto start = chrono::high_resolution_clock::now();
        quickSort(arr, 0, n-1);
        auto end = chrono::high_resolution_clock::now();

        cpu_time_used = chrono::duration_cast<chrono::microseconds>(end - start).count();

        /*cout << "Sorted array is: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }*/
        arr1[count] = cpu_time_used;
        cout << "Time taken: " << cpu_time_used << " microseconds" << endl;
        count++;
    }   
    float avg = 0;
    for(int j = 0; j < 5;j++){
        avg += arr1[j];
    }
    cout << "Average time: " << avg/5 << " microseconds" << endl;
    return 0;
}
