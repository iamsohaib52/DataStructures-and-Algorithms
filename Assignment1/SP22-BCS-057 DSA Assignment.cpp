#include <iostream>
using namespace std;

class List {
    struct Node {
        int data;
        Node* next;
        Node* prev;

        Node(int value) : data(value), next(NULL), prev(NULL) {}
    };

    Node* head_singly;
    Node* head_doubly;
    Node* head_circular;

public:
    List() {
        head_singly = NULL;
        head_doubly = NULL;
        head_circular = NULL;
    }

    // Functions for inserting into singly, doubly, and circular linked lists
    void insert_beg_singly(int n) {
        Node* newNode = new Node(n);
        newNode->next = head_singly;
        head_singly = newNode;
    }

    void insert_end_singly(int n) {
        Node* newNode = new Node(n);
        if (head_singly == NULL) {
            head_singly = newNode;
        } else {
            Node* current = head_singly;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void insert_beg_doubly(int n) {
        Node* newNode = new Node(n);
        newNode->next = head_doubly;
        newNode->prev = NULL;

        if (head_doubly != NULL) {
            head_doubly->prev = newNode;
        }

        head_doubly = newNode;
    }

    void insert_end_doubly(int n) {
        Node* newNode = new Node(n);
        newNode->next = NULL;

        if (head_doubly == NULL) {
            newNode->prev = NULL;
            head_doubly = newNode;
        } else {
            Node* current = head_doubly;
            while (current->next != NULL) {
                current = current->next;
            }

            newNode->prev = current;
            current->next = newNode;
        }
    }

    void insert_beg_circular(int n) {
        Node* newNode = new Node(n);
        if (head_circular == NULL) {
            head_circular = newNode;
            head_circular->next = head_circular;
        } else {
            Node* current = head_circular;
            while (current->next != head_circular) {
                current = current->next;
            }
            newNode->next = head_circular;
            head_circular = newNode;
            current->next = head_circular;
        }
    }

    void insert_end_circular(int n) {
        Node* newNode = new Node(n);
        if (head_circular == NULL) {
            head_circular = newNode;
            head_circular->next = head_circular;
        } else {
            Node* current = head_circular;
            while (current->next != head_circular) {
                current = current->next;
            }
            newNode->next = head_circular;
            current->next = newNode;
        }
    }

    // Functions for deleting from singly, doubly, and circular linked lists
    void delete_beg_singly() {
        if (head_singly == NULL) {
            return; // List is empty
        }
        Node* temp = head_singly;
        head_singly = head_singly->next;
        delete temp;
    }

    void delete_end_singly() {
        if (head_singly == NULL) {
            return; // List is empty
        } else if (head_singly->next == NULL) {
            delete head_singly;
            head_singly = NULL;
        } else {
            Node* current = head_singly;
            while (current->next->next != NULL) {
                current = current->next;
            }
            delete current->next;
            current->next = NULL;
        }
    }

    void delete_beg_doubly() {
        if (head_doubly == NULL) {
            return; // List is empty
        }
        Node* temp = head_doubly;
        head_doubly = head_doubly->next;
        if (head_doubly != NULL) {
            head_doubly->prev = NULL;
        }
        delete temp;
    }

    void delete_end_doubly() {
        if (head_doubly == NULL) {
            return; // List is empty
        } else if (head_doubly->next == NULL) {
            delete head_doubly;
            head_doubly = NULL;
        } else {
            Node* current = head_doubly;
            while (current->next->next != NULL) {
                current = current->next;
            }
            delete current->next;
            current->next = NULL;
        }
    }

    void delete_beg_circular() {
        if (head_circular == NULL) {
            return; // List is empty
        }
        Node* current = head_circular;
        while (current->next != head_circular) {
            current = current->next;
        }
        Node* temp = head_circular;
        head_circular = head_circular->next;
        current->next = head_circular;
        delete temp;
    }

    void delete_end_circular() {
        if (head_circular == NULL) {
            return; // List is empty
        } else if (head_circular->next == head_circular) {
            delete head_circular;
            head_circular = NULL;
        } else {
            Node* current = head_circular;
            Node* previous = NULL;
            while (current->next != head_circular) {
                previous = current;
                current = current->next;
            }
            previous->next = head_circular;
            delete current;
        }
    }

    // Functions for seeking in singly, doubly, and circular linked lists
    int seek_singly(int value) {
        Node* current = head_singly;
        int index = 0;

        while (current != NULL) {
            if (current->data == value) {
                return index; // Value found at this index
            }
            current = current->next;
            index++;
        }

        return -1; // Value not found in the list
    }

    int seek_doubly(int value) {
        Node* current = head_doubly;
        int forwardIndex = 0;

        // Forward traversal
        while (current != NULL) {
            if (current->data == value) {
                return forwardIndex; // Value found at this index
            }
            current = current->next;
            forwardIndex++;
        }

        // Value not found in the forward direction, let's try backward
        current = head_doubly;
        int backwardIndex = 0;
        while (current->next != NULL) {
            current = current->next;
        }

        while (current != NULL) {
            if (current->data == value) {
                return backwardIndex; // Value found at this index
            }
            current = current->prev;
            backwardIndex--;
        }

        return -1; // Value not found in the list
    }

    int seek_circular(int value) {
        if (head_circular == NULL) {
            return -1; // List is empty
        }

        Node* current = head_circular;
        int index = 0;

        do {
            if (current->data == value) {
                return index; // Value found at this index
            }
            current = current->next;
            index++;
        } while (current != head_circular);

        return -1; // Value not found in the list
    }

    // Functions for reversing singly, doubly, and circular linked lists
    void reverse_singly() {
        Node* prev = NULL;
        Node* current = head_singly;
        Node* nextNode = NULL;

        while (current != NULL) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }

        head_singly = prev;
    }

    void reverse_doubly() {
        Node* current = head_doubly;
        Node* temp = NULL;
        while (current != NULL) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        if (temp != NULL) {
            head_doubly = temp->prev;
        }
    }

    void reverse_circular() {
        if (head_circular == NULL) {
            return; // List is empty
        }

        Node* current = head_circular;
        Node* prev = NULL;
        Node* nextNode = NULL;

        do {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        } while (current != head_circular);

        head_circular->next = prev;
        head_circular = prev;
    }

    // Display functions for singly, doubly, and circular linked lists
    void display_singly() {
        Node* current = head_singly;
        while (current != NULL) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    void display_doubly() {
        Node* current = head_doubly;
        while (current != NULL) {
            cout << current->data << " <-> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    void display_circular() {
        if (head_circular == NULL) {
            cout << "Empty Circular Linked List" << endl;
            return;
        }

        Node* current = head_circular;
        do {
            cout << current->data << " -> ";
            current = current->next;
        } while (current != head_circular);
        cout << "Head" << endl;
    }
};

int main() {
    List l;
    int ch, val;

    do {
        cout << "\nOperations on link list" << endl;
        cout << "1-Insertion \n2-Deletion \n3-Seek \n4-Reverse \n5-Display \n6-Exit" << endl;
        cout << "\nEnter Your Choice: ";
        cin >> ch;
        int ps, ds;
        switch (ch) {
            case 1:
                cout << "\n1-Insertion in Singly \n2-Insertion in Doubly \n3-Insertion in Circular" << endl;
                cout << "\nEnter your choice: ";
                cin >> ps;

                switch (ps) {
                    case 1:
                        cout << "\n1-Insertion at beginning \n2-Insertion at end\n";
                        cout << "\nEnter Your Choice: ";
                        cin >> ds;
                        cout << "\nEnter Value to insert: ";
                        cin >> val;
                        switch (ds) {
                            case 1:
                                l.insert_beg_singly(val);
                                cout<<"\nData after insertion"<<endl;
                                l.display_singly();
                                break;
                            case 2:
                                l.insert_end_singly(val);
                                cout<<"\nData after insertion"<<endl;
                                l.display_singly();
                                break;
                            default:
                                cout << "\nInvalid choice." << endl;
                        }
                        break;
                    case 2:
                        cout << "\n1-Insertion at beginning \n2-Insertion at end" << endl;
                        cout << "\nEnter Your Choice: ";
                        cin >> ds;
                        cout << "\nEnter Value to insert: ";
                        cin >> val;
                        switch (ds) {
                            case 1:
                                l.insert_beg_doubly(val);
                                cout<<"\nData after insertion"<<endl;
                                l.display_doubly();
                                break;
                            case 2:
                                l.insert_end_doubly(val);
                                cout<<"\nData after insertion"<<endl;
                                l.display_doubly();
                                break;
                            default:
                                cout << "Invalid choice." << endl;
                        }
                        break;
                    case 3:
                        cout << "\n1-Insertion at beginning \n2-Insertion at end" << endl;
                        cout << "\nEnter Your Choice: ";
                        cin >> ds;
                        cout << "\nEnter Value to insert: ";
                        cin >> val;
                        switch (ds) {
                            case 1:
                                l.insert_beg_circular(val);
                                cout<<"\nData after insertion"<<endl;
                                l.display_circular();
                                break;
                            case 2:
                                l.insert_end_circular(val);
                                cout<<"\nData after insertion"<<endl;
                                l.display_circular();
                                break;
                            default:
                                cout << "Invalid choice." << endl;
                        }
                        break;
                    default:
                        cout << "Invalid choice." << endl;
                }
                break;

            case 2:
                cout << "\n1-Deletion in Singly \n2-Deletion in Doubly \n3-Deletion in Circular" << endl;
                cout << "\nEnter your choice: ";
                cin >> ps;
                switch (ps) {
                    case 1:
                        cout << "\n1-Deletion at beginning \n2-Deletion at end ";
                        cout << "\nEnter Your Choice: ";
                        cin >> ds;

                        switch (ds) {
                            case 1:
                                l.delete_beg_singly();
                                cout<<"\nData after deletion"<<endl;
                                l.display_singly();
                                break;
                            case 2:
                                l.delete_end_singly();
                                cout<<"\nData after deletion"<<endl;
                                l.display_singly();
                                break;
                            default:
                                cout << "Invalid choice." << endl;
                        }
                        break;
                    case 2:
                        cout << "\n1-Deletion at beginning \n2-Deletion at end" << endl;
                        cout << "\nEnter Your Choice: ";
                        cin >> ds;
                        switch (ds) {
                            case 1:
                                l.delete_beg_doubly();
                                cout<<"\nData after deletion"<<endl;
                                l.display_doubly();
                                break;
                            case 2:
                                l.delete_end_doubly();
                                cout<<"\nData after deletion"<<endl;
                                l.display_doubly();
                                break;
                            default:
                                cout << "Invalid choice." << endl;
                                break;
                        }
                        break;
                    case 3:
                        cout << "\n1-Deletion at beginning \n2-Deletion at end" << endl;
                        cout << "\nEnter Your Choice: ";
                        cin >> ds;
                        switch (ds) {
                            case 1:
                                l.delete_beg_circular();
                                cout<<"\nData after deletion"<<endl;
                                l.display_circular();
                                break;
                            case 2:
                                l.delete_end_circular();
                                cout<<"\nData after deletion"<<endl;
                                l.display_circular();
                                break;
                            default:
                                cout << "Invalid choice." << endl;
                                break;
                        }
                        break;
                    default:
                        cout << "Invalid choice." << endl;
                        break;
                }
                break;

            case 3:
                cout << "\n1-Seek in Singly \n2-Seek in Doubly \n3-Seek in Circular" << endl;
                cout << "\nEnter your choice: ";
                cin >> ps;
                switch (ps) {
                    case 1:
                        cout << "Enter the value to seek: ";
                        cin >> val;
                        int position_singly;
                        position_singly = l.seek_singly(val);
                        if (position_singly != -1) {
                            cout << "Value found at position " << position_singly << endl;
                        } else {
                            cout << "Value not found in the singly linked list." << endl;
                        }
                        break;
                    case 2:
                        cout << "Enter the value to seek: ";
                        cin >> val;
                        int position_doubly;
                        position_doubly = l.seek_doubly(val);
                        if (position_doubly != -1) {
                            cout << "Value found at position " << position_doubly << endl;
                        } else {
                            cout << "Value not found in the doubly linked list." << endl;
                        }
                        break;
                    case 3:
                        cout << "Enter the value to seek: ";
                        cin >> val;
                        int position_circular;
                        position_circular = l.seek_circular(val);
                        if (position_circular != -1) {
                            cout << "Value found at position " << position_circular << endl;
                        } else {
                            cout << "Value not found in the circular linked list." << endl;
                        }
                        break;
                    default:
                        cout << "Invalid choice." << endl;
                        break;
                }
                break;

            case 4:
                cout<<"\n1-Reverse in singly \n2-Reverse in Doubly \n3-Reverse in Circular\n";
                cout << "\nEnter your choice: ";
                cin >> ps;
                switch(ps){
                    case 1:
                        l.reverse_singly();
                        cout<<"\nData after reversal"<<endl;
                        l.display_singly();
                        break;
                    case 2:
                        l.reverse_doubly();
                        cout<<"\nData after reversal"<<endl;
                        l.display_doubly();
                        break;
                    case 3:
                        l.reverse_circular();
                        cout<<"\nData after reversal"<<endl;
                        l.display_circular();
                        break;
                    default:
                        cout<<"Invalid Command"<<endl;
                }
                break;

            case 5:
                cout << "\n1-Display Singly \n2-Display Doubly \n3-Display Circular" << endl;
                cout << "\nEnter your choice: ";
                cin >> ps;
                switch (ps) {
                    case 1:
                        cout << "Data in Singly Linked List:" << endl;
                        l.display_singly();
                        break;
                    case 2:
                        cout << "Data in Doubly Linked List:" << endl;
                        l.display_doubly();
                        break;
                    case 3:
                        cout << "Data in Circular Linked List:" << endl;
                        l.display_circular();
                        break;
                    default:
                        cout << "Invalid choice." << endl;
                        break;
                }
                break;

            case 6:
                return 0; // Exit the program

            default:
                cout << "Invalid choice." << endl;
                break;
        }
    } while (ch != 6);

    return 0;
}


