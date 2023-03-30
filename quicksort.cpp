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

// Recursive Quick Sort function
void quickSort(int arr[], int left, int right) {
    if (left < right) {
        // partition the array into two sub-arrays around pivot
        int p = partition(arr, left, right);

        // recursively sort the two sub-arrays
        quickSort(arr, left, p-1);
        quickSort(arr, p+1, right);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    // Generate random array
    srand(time(0));
    for (int i = 0; i < n; i++) {
         arr[i] = rand() % 10001 + 10000;
    }

    double cpu_time_used;

    auto start = chrono::high_resolution_clock::now();
    quickSort(arr, 0, n-1);
    auto end = chrono::high_resolution_clock::now();

    cpu_time_used = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    /*cout << "Sorted array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }*/

    cout << "Time taken: " << cpu_time_used << " nanoseconds" << endl;

    return 0;
}