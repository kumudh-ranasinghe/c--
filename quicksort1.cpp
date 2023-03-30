#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <chrono>
#include <stack>

using namespace std;

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int left, int right) {
    int pivot = arr[right];  
    int i = left - 1;  
    for (int j = left; j <= right - 1; j++) {
        if (arr[j] <= pivot) {
            i++;  
            swap(arr[i], arr[j]);  
        }
    }
    swap(arr[i + 1], arr[right]);  
    return (i + 1);  
}

void quickSort(int arr[], int left, int right) {
    stack<int> stack;  
    stack.push(left);   
    stack.push(right);

    while (!stack.empty()) {
        right = stack.top();
        stack.pop();
        left = stack.top();
        stack.pop();

        int p = partition(arr, left, right);

        if (p - 1 > left) {
            stack.push(left);
            stack.push(p - 1);
        }

        if (p + 1 < right) {
            stack.push(p + 1);
            stack.push(right);
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    srand(time(0));
    for (int i = 0; i < n; i++) {
         arr[i] = rand() % 10001 + 10000;
    }

    double cpu_time_used;

    auto start = chrono::high_resolution_clock::now();
    quickSort(arr, 0, n - 1);
    auto end = chrono::high_resolution_clock::now();

    cpu_time_used = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    /*cout << "Sorted array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }*/
    
    cout << "Time taken: " << cpu_time_used << " nanoseconds" << endl;

    return 0;
}
