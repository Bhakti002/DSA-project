#include <iostream>
using namespace std;



void selectionSort(int arr[], int size) {
    for(int i = 0; i < size - 1; i++) {
        int minIdx = i;
        for(int j = i + 1; j < size; j++) {
            if(arr[j] < arr[minIdx])
                minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }
}



void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for(int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for(int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2) {
        if(L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while(i < n1) arr[k++] = L[i++];
    while(j < n2) arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right) {
    if(left < right) {
        int mid = left + (right - left)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int linearSearch(int arr[], int size, int key) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == key)
            return i;
    }
    return -1;
}

int binarySearch(int arr[], int size, int key) {
    int low = 0, high = size - 1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

void displayArray(int arr[], int size) {
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    const int SIZE = 100;
    int arr[SIZE], n, choice, key;
    bool isSorted = false;

    cout << "Enter the values of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    do {
        cout << "\n\nchoose your choice:\n";
        cout << "1. Sorting\n";
        cout << "2. Searching\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                int sortChoice;
                cout << "select type of sorting:\n";
                cout << "1. Selection Sort\n";
                cout << "2. Merge Sort\n";
                cout << "Enter choice: ";
                cin >> sortChoice;

                if(sortChoice == 1) {
                    selectionSort(arr, n);
                    isSorted = true;
                    cout << "Array sorted using Selection Sort\n\n";
                } else if(sortChoice == 2) {
                    mergeSort(arr, 0, n - 1);
                    isSorted = true;
                    cout << "Array sorted using Merge Sort\n\n";
                } else {
                    cout << "Invalid choice\n\n";
                }
                break;
            }

            case 2: {
                int searchChoice;
                cout << "select the type of seach:\n";
                cout << "1. Linear Search\n";
                cout << "2. Binary Search\n";
                cout << "Enter choice: ";
                cin >> searchChoice;

                cout << "Enter search choice: ";
                cin >> key;

                int result = -1;
                if(searchChoice == 1) {
                    result = linearSearch(arr, n, key);
                } else if(searchChoice == 2) {
                    if (!isSorted) {
                        cout << "Please sort first for binary\n";
                        break;
                    }
                    result = binarySearch(arr, n, key);
                } else {
                    cout << "Invalid choice\n";
                    break;
                }

                if(result != -1)
                    cout << "value found at " << result <<"index."<< endl<<endl;
                else
                    cout << "value not found\n";
                break;
            }

            case 3:
                cout << "your array is: ";
                displayArray(arr, n);
                break;

            case 4:
                cout << "thank you!!\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while(choice != 4);

    return 0;
}

