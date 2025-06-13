#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Node 
{
public:
    int data;
    Node* next;
    Node(int val) 
	{
        data = val;
        next = NULL;
    }
};

void insert(Node*& head, int val) 
{
    Node* newNode = new Node(val);
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

void display(Node* head) 
{
    cout << "Linked List: ";
    while (head != NULL) 
	{
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}


int binarySearch(const vector<int>& arr, int key) 
{
    int start = 0, end = arr.size() - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}


void mergeSort(vector<int>& arr) 
{
    sort(arr.begin(), arr.end());
}

void queueSorting() 
{
    queue<int> q;
    int n, x;
    cout << "Enter number of elements in queue: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) 
	{
        cin >> x;
        q.push(x);
    }

    vector<int> temp;
    while (!q.empty()) 
	{
        temp.push_back(q.front());
        q.pop();
    }

    sort(temp.begin(), temp.end());

    cout << "Sorted Queue: ";
    for (int i = 0; i < temp.size(); i++) 
	{
        cout << temp[i] << " ";
    }
    cout << endl;
}

int main() 
{
    int choice;
    cout << "1) Linked List\n2) Binary Search\n3) Merge and Queue Sorting\n4) Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) 
	{
        case 1: 
		{
            Node* head = NULL;
            int n, val;
            cout << "How many elements? ";
            cin >> n;
            cout << "Enter elements: ";
            for (int i = 0; i < n; i++) 
			{
                cin >> val;
                insert(head, val);
            }
            display(head);
            break;
        }
        case 2: 
		{
            int n, key;
            cout << "Array size: ";
            cin >> n;
            vector<int> arr(n);
            cout << "Enter sorted array: ";
            for (int i = 0; i < n; i++)
                cin >> arr[i];
            cout << "Enter element to search: ";
            cin >> key;
            int res = binarySearch(arr, key);
            if (res != -1)
                cout << "Found at index: " << res << endl;
            else
                cout << "Not found" << endl;
            break;
        }
        case 3: 
		{
            int n;
            cout << "Merge Sort - Enter number of elements: ";
            cin >> n;
            vector<int> arr(n);
            cout << "Enter elements: ";
            for (int i = 0; i < n; i++)
                cin >> arr[i];
            mergeSort(arr);
            cout << "Sorted array: ";
            for (int i = 0; i < arr.size(); i++)
                cout << arr[i] << " ";
            cout << endl;

            queueSorting();
            break;
        }
        case 4:
		{
        	cout<<"Exiting program!!";
			break;
		}
        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}

