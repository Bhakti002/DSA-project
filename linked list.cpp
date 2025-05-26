#include<iostream>

using namespace std;
class Node 
{
public:
    int data;
    Node* next;
};

class LinkedList 
{
    Node* head;
public:
    LinkedList() 
	{
	 head = NULL;
	}

    void insert_at_first(int val) 
	{
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = head;
        head = newNode;
    }
    
    void search(int key) 
	{
        Node* temp = head;
        while (temp != NULL) 
		{
            if (temp->data == key)
			{
                cout << key << "it found\n";
                return;
            }
            temp = temp->next;
        }
        cout << key << "it not found\n";
    }

    void delete_Node(int key) 
	{
        Node *temp = head, *prev = NULL;
        while (temp != NULL && temp->data != key) 
		{
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) 
		{
            cout << key << " not found\n";
            return;
        }
        if (prev == NULL) head = head->next;
        else prev->next = temp->next;
        delete temp;
        cout << key << " deleted\n";
    }

    void reverse() 
	{
        Node *prev = NULL, *curr = head, *next = NULL;
        while (curr != NULL) 
		{
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        cout << "reversed successfully\n";
    }

    void display() 
	{
        Node* temp = head;
        cout << "list: ";
        while (temp != NULL) 
		{
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() 
{
    LinkedList list;
    int choice, value;

    do {
        cout << "\n1. Insert at first\n2.serach element\n3. delete elemnt\n4.reverse\n5. display\n6. Exit\n";
        cout << "enter your choice: ";
        cin >> choice;

        switch (choice) 
		{
        case 1:
            cout << "insert at first: ";
            cin >> value;
            list.insert_at_first(value);
            break;
        case 2:
            cout << "element for serach search: ";
            cin >> value;
            list.search(value);
            break;
        case 3:
            cout << "write a elemnt to delete: ";
            cin >> value;
            list.delete_Node(value);
            break;
        case 4:
            list.reverse();
            break;
        case 5:
            list.display();
            break;
        case 6:
            cout << "exiting...\n";
            break;
        default:
            cout << "invalid\n";
        }
    } while (choice != 0);
    return 0;
}
