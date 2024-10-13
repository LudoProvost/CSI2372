/*Ex2 - a3 CSI2372A*/

#include "myLinkedList.h"

int main()
{
	int size_of_linked_list = 0; // added to remove undefined error
	Evaluation* first = nullptr; // added to remove undefined error

	do
	{
		cout << endl << endl << "1) Display  of the complete linked list.\n";
		cout << "2) Insert an element\n";
		cout << "3) Remove an element.\n";
		cout << "4) Calculation of the class average.\n";
		cout << "5) Exit the program.\n" << endl << endl;
		cout << "Your choice ??: ";
		
		int choice; // added to remove undefined error
		int number; // added to remove undefined error

		cin >> choice;

		switch (choice)
		{
		case 1: display(first);
			break;
		case 2: 
			do {
				cout << "\nAfter which element you want to insert? (0 for start): "; // added to fit example of output
				cin >> number;
			} while (number > size_of_linked_list); // verify if number is valid

			first = add(first, number);
			size_of_linked_list++;
			break;
		case 3: 
			do {
				cout << "\nWhat is the number of the element to delete? : "; // added to fit example of output
				cin >> number;
			} while (number > size_of_linked_list); // verify if number is valid

			first = remove(first, number);
			size_of_linked_list--;
			break;
		case 4: 
			number = size_of_linked_list; // added to make sense, base code expects number to be size of linked list but expects number to be something else for case 2 and 3
			average(first, number);
			break;
		case 5: exit(0);
		default:
			break;
		}
	} while (1);
	return 0;
}



/*
*add() Function*
**/
Evaluation* add(Evaluation* p, int& number)
{
    cout << "\tEntering the item from the chained list.\n\n"; // added to fit example output

	Evaluation* new_node = new Evaluation; // create new node that will be added
    Evaluation* current_p = p;

    // use user input for new student name and grade
	char student[capacity];
	int grade;

    cout << "Enter the student name: ";
    // cin >> student;
	std::getline(std::cin, student);

    cout << "Enter the grade: ";
    cin >> grade;

    strcpy(new_node->student, student);
	new_node->grade = grade;
	new_node->next = nullptr;

    // edge case, add head node
    if (number == 0 || p == nullptr) {
        new_node->next = p;
        return new_node;
    }

    // navigate to the correct member to add
    int current_member = 0;
    while (current_member < number - 1) {
        current_p = current_p->next;
        current_member++;
    }

    // insert the new node
    new_node->next = current_p->next;
    current_p->next = new_node;

    return p; // return head of linked list
}


/**
*remove() Function*
**/

Evaluation* remove(Evaluation* p, int& number)
{
	// edge case if first member is removed
	if (number <= 1) {
        return p->next;
    }

    // navigate to the member located before the member to remove
    Evaluation* current_p = p;
    int current_member = 1;
    while (current_member < number - 1) {
        current_p = current_p->next;
        current_member++;
    }

    // remove the member
    Evaluation* member_to_remove = current_p->next;
    current_p->next = member_to_remove->next;

    return p; // return head of linked list
}



/**
*display() Function *
**/
void display(Evaluation* p)
{
	// edge case, list empty
	if (p == nullptr) {
        cout << "The list is empty." << endl;
        return;
    }

	while (p != nullptr) {
		cout << "\nStudent : " << p->student << "\nThe grade is : " << p->grade << endl; // for every node visited, print its student and grade
		
		p = p->next; // move through linked list
	}
}



/**
*average() Function *
***/
int average(Evaluation* p, int const& nbre)
{
	// edge case, list empty
	if (nbre == 0) {
        cout << "No students to calculate the average" << endl;
        return 0;
    }

	int total_grade = 0;

    while (p != nullptr) {
        total_grade += p->grade;
        p = p->next; // move through linked list
    }

    cout << "The average grade is: " << (total_grade / nbre) << endl;
    return 1;
}






