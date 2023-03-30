#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <chrono>
#include <stack>

using namespace std;

// Function to swap two elements in an array
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Partition function to return the pivot index
int partition(int arr[], int left, int right) {
    int pivot = arr[right];  // choose the rightmost element as pivot
    int i = left - 1;  // Initialize i to be one index before the first element
    for (int j = left; j <= right - 1; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++;  // increment index of smaller element
            swap(arr[i], arr[j]);  // swap the elements at i and j
        }
    }
    swap(arr[i + 1], arr[right]);  // swap the pivot element with the element at i+1
    return (i + 1);  // return the index of pivot
}

// Function to perform Quick Sort iteratively
void quickSort(int arr[], int left, int right) {
    stack<int> stack;  // create a stack to store indices of subarrays
    stack.push(left);  // push the indices of the first subarray onto the stack
    stack.push(right);

    while (!stack.empty()) {
        // pop the top two indices from the stack to get the next subarray
        right = stack.top();
        stack.pop();
        left = stack.top();
        stack.pop();

        // find the pivot index and partition the subarray
        int p = partition(arr, left, right);

        // If there are elements on the left side of pivot,
        // push the left subarray onto the stack
        if (p - 1 > left) {
            stack.push(left);
            stack.push(p - 1);
        }

        // If there are elements on the right side of pivot,
        // push the right subarray onto the stack
        if (p + 1 < right) {
            stack.push(p + 1);
            stack.push(right);
        }
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
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
    quickSort(arr, 0, n - 1);
    auto end = chrono::high_resolution_clock::now();

    cpu_time_used = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    cout << "Sorted array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "Time taken: " << cpu_time_used << " nanoseconds" << endl;

    return 0;
}
