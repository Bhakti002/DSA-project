#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* next;
};

class LinkedList 
{
public:
    Node* head;
    LinkedList() { head = NULL; }

    void insert(int val) 
	{
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = NULL;

        if (head == NULL) 
		{
            head = newNode;
        } else 
		{
            Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    void display() 
	{
        Node* temp = head;
        cout << "Linked List: ";
        while (temp != NULL) 
		{
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
// for merge sort
void merge(int a[], int l, int m, int r) 
{
    int i = l, j = m+1, k = 0;
    int temp[r-l+1];
    
    while(i <= m && j <= r)
        temp[k++] = (a[i] < a[j]) ? a[i++] : a[j++];
    
    while(i <= m) temp[k++] = a[i++];
    while(j <= r) temp[k++] = a[j++];
    
    for(int i = l, k = 0; i <= r; i++, k++)
        a[i] = temp[k];
}

void mergeSort(int a[], int l, int r) 
{
    if(l < r) 
	{
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
        merge(a, l, m, r);
    }
}


// for quick sort
int partition(int arr[], int low, int high) 
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) 
	{
        if (arr[j] < pivot) 
		{
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) 
{
    if (low < high) 
	{
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// for binary search
int binarySearch(int arr[], int n, int key) 
{
    int low = 0, high = n - 1;
    while (low <= high) 
	{
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() 
{
    LinkedList ll;
    int choice, val, arr[100], n, key;

    while (true) 
	{
        cout << "\n--- MENU ---\n";
        cout << "1. Insert in Linked List\n";
        cout << "2. Display Linked List\n";
        cout << "3. Merge Sort\n";
        cout << "4. Quick Sort\n";
        cout << "5. Binary Search\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
		{
        case 1:
            cout << "Enter value to insert: ";
            cin >> val;
            ll.insert(val);
            break;

        case 2:
            ll.display();
            break;

        case 3:
            cout << "Enter number of elements: ";
            cin >> n;
            cout << "Enter " << n << " elements: ";
            for (int i = 0; i < n; i++) cin >> arr[i];
            mergeSort(arr, 0, n - 1);
            cout << "Sorted Array (Merge Sort): ";
            for (int i = 0; i < n; i++) cout << arr[i] << " ";
            cout << endl;
            break;

        case 4:
            cout << "Enter number of elements: ";
            cin >> n;
            cout << "Enter " << n << " elements: ";
            for (int i = 0; i < n; i++) cin >> arr[i];
            quickSort(arr, 0, n - 1);
            cout << "Sorted Array (Quick Sort): ";
            for (int i = 0; i < n; i++) cout << arr[i] << " ";
            cout << endl;
            break;

        case 5:
            cout << "Enter number of elements: ";
            cin >> n;
            cout << "Enter sorted array: ";
            for (int i = 0; i < n; i++) cin >> arr[i];
            cout << "Enter value to search: ";
            cin >> key;
            val = binarySearch(arr, n, key);
            if (val != -1)
                cout << "Value found at index: " << val << endl;
            else
                cout << "Value not found!" << endl;
            break;

        case 6:
            cout << "Exiting program..." << endl;
            return 0;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}
