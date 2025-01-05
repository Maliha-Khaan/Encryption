#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

class list {
private:
    node *head, *tail;

public:
    list() {
        head = NULL;
        tail = NULL;
    }

    void createnode(int value) {
    node *temp = new node;
    temp->data = value;
    temp->next = temp;  // Points to itself

    if (head == NULL) {
        head = temp;     // List is empty, new node becomes head
        tail = temp;     // New node is also the tail
    } else {
        tail->next = temp; // Current tail points to new node
        tail = temp;       // Update tail to the new node
        tail->next = head; // New tail points back to head to maintain circular nature
    }
}


    void display() {
    if (head == NULL) {  // Check if the list is empty
        cout << "List is empty." << endl;
        return;  // Exit if the list is empty
    }
    
    node *temp = head;  // Start traversal from the head
    do {
        cout << temp->data << "\t";  // Print current node's data
        temp = temp->next;            // Move to the next node
    } while (temp != head);           // Stop when we loop back to head
    
    cout << endl;  // Print a newline after displaying all nodes
}


    void insert_start(int value) {
    node *temp = new node;     // Create a new node
    temp->data = value;        // Set the data for the new node
    
    if (head == NULL) {        // Check if the list is empty
        head = temp;           // If empty, set head to new node
        tail = temp;           // Also set tail to new node
        temp->next = head;     // Single node points to itself
    } else {
        temp->next = head;     // Link new node to the current head
        head = temp;           // Update head to the new node
        tail->next = head;     // Update tail to point to new head
    }
}

    void insert_position(int pos, int value) {
	
    
    node *temp = new node;  // Create a new node
    temp->data = value;     // Set the data for the new node
    node *pre = head;       // Pointer to track the previous node
    node *cur = head;       // Pointer to track the current node
    
    // Traverse the list to find the insertion point
    for (int i = 1; i < pos; i++) {
        pre = cur;          // Move pre to current
        cur = cur->next;    // Move current to next
    }
    
    // Insert the new node between pre and cur
    pre->next = temp;      // Link the previous node to the new node
    temp->next = cur;      // Link the new node to the current node
    
   
}


    void insert_end(int value)
	 {
        node *temp = new node;
        temp->data = value;
            tail->next = temp;
            tail = temp;
            tail->next = head;  // Maintain circular link
        
    }

    void delete_first() 
    {
            node *temp;
			temp = head;
            head = head->next;
            tail->next = head;  // Update tail to point to new head
            delete temp;
        
    }

    void delete_last()
	 {
    
            node *current = head;
            while (current->next != tail) {
                current = current->next;
            }
            delete tail;
            tail = current;
            tail->next = head;  // Maintain circular link
    }


    void delete_position(int pos) 
    {
	

        node *current = head;
        node *previous = NULL;
        for (int i = 1; i < pos; i++) {
            previous = current;
            current = current->next;
            if (current == head) return;  // Position out of range
        }
        
        previous->next = current->next;
        delete current;
    }

    // Destructor to delete the entire list
    ~list() {
        if (head == NULL) return;

        tail->next = NULL;  // Break the circular link
        node *nodePtr = head;
        while (nodePtr != NULL) {
            node *nextNode = nodePtr->next;
            delete nodePtr;
            nodePtr = nextNode;
        }
    }
};

int main() {
    list myList;
    int choice, value, pos;

    while (true) {
        cout << "\n--- Circular Linked List Menu ---\n";
        cout << "1. Insert at start\n";
        cout << "2. Insert at position\n";
        cout << "3. Insert at end\n";
        cout << "4. Delete first\n";
        cout << "5. Delete at position\n";
        cout << "6. Delete last\n";
        cout << "7. Display list\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at start: ";
                cin >> value;
                myList.insert_start(value);
                break;
            case 2:
                cout << "Enter position to insert: ";
                cin >> pos;
                cout << "Enter value to insert: ";
                cin >> value;
                myList.insert_position(pos, value);
                break;
            case 3:
                cout << "Enter value to insert at end: ";
                cin >> value;
                myList.insert_end(value);
                break;
            case 4:
                myList.delete_first();
                cout << "First node deleted." << endl;
                break;
            case 5:
                cout << "Enter position to delete: ";
                cin >> pos;
                myList.delete_position(pos);
                break;
            case 6:
                myList.delete_last();
                cout << "Last node deleted." << endl;
                break;
            case 7:
                cout << "Circular Linked List: ";
                myList.display();
                break;
            case 8:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

