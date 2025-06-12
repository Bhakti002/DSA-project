#include <iostream>
#include <stack>
using namespace std;

int main() 
{
    stack<int> s;
    int choice, value;

    while (true) 
	{
        cout << "\nMenu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top\n";
        cout << "4. Size\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
		{
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                cout << value << " pushed into the stack.\n";
                break;

            case 2:
                if (!s.empty()) 
				{
                    cout << s.top() << " popped from the stack.\n";
                    s.pop();
                } 
				else 
				{
                    cout << "Stack is empty! Nothing to pop.\n";
                }
                break;

            case 3:
                if (!s.empty()) 
				{
                    cout << "Top element: " << s.top() << endl;
                } 
				else 
				{
                    cout << "Stack is empty.\n";
                }
                break;

            case 4:
                cout << "Stack size: " << s.size() << endl;
                break;

            case 5:
                cout << "Exiting program.\n";
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
