#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <class t>
class MemoryCalculate 
{
private:
    vector<t> id;
    vector<string> name;

public:
    MemoryCalculate() 
	{
        cout << "HELLO!!! CONSTRUCTOR";
    }

    void add() 
	{
        t newid;
        string newname;
        cout << "\nenter new id:";
        cin >> newid;
        cout << "\nenter new name:";
        cin >> newname;
        id.push_back(newid);
        name.push_back(newname);
    }

    void display() const 
	{
        cout << "student list is:" << endl;
        if (id.empty()) 
		{
            cout << "student is not available!" << endl;
            return;
        }
        for (int i = 0; i < id.size(); ++i) 
		{
            cout << "\nID: " << id[i] << ", Name: " << name[i] << endl;
        }
    }

    void remove(t searchId) 
	{
        for (int i = 0; i < id.size(); i++) 
		{
            if (id[i] == searchId) 
			{
                id.erase(id.begin() + i);
                name.erase(name.begin() + i);
                cout << "Student with ID " << searchId << " removed." << endl;
                return;
            }
        }
        cout << "name and ID " << searchId << " not found." << endl;
    }

    void search(t searchId) const 
	{
        for (int i = 0; i < id.size(); i++) 
		{
            if (id[i] == searchId) 
			{
                cout << "student found \n\n ID: " << id[i] << ", Name: " << name[i] << endl;
                return;
            }
        }
        cout << "Student with ID " << searchId << " not found." << endl;
    }
};

int main() 
{
    MemoryCalculate<int> studentList;
    int choice;

    while (1) 
	{
        cout << "\n-----Your List-----" << endl;
        cout << "1. Enter students list." << endl;
        cout << "2. Display the list of students." << endl;
        cout << "3. Remove any student from the list with the help of ID." << endl;
        cout << "4. Search student by ID.." << endl;
        cout << "5. Exit" << endl;
        cout << "Please enter your choice:- ";
        cin >> choice;

        switch (choice) 
		{
            case 1:
                studentList.add();
                break;
            case 2:
                studentList.display();
                break;
            case 3: {
                int removeId;
                cout << "Enter ID of the student you waht to remove: ";
                cin >> removeId;
                studentList.remove(removeId);
                break;
            }
            case 4: {
                int searchId;
                cout << "Enter ID of the student you want to search: ";
                cin >> searchId;
                studentList.search(searchId);
                break;
            }
            case 5:
                exit(0);
            default:
                cout << "sorry you entered wrong choice...." << endl;
        }
    }

    return 0;
}
