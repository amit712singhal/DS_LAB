#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int curr_data)
    {
        this->data = curr_data;
        this->next = this; // Point to itself initially
    }
};

class circular_LinkedList
{
private:
    Node *head;

public:
    circular_LinkedList()
    {
        head = NULL;
    }

    void insertFront(int data)
    {
        Node *newNode = new Node(data);

        if (head == NULL)
        {
            head = newNode;
            head->next = head; // Point to itself for circularity
        }
        else
        {
            Node *last = head;
            while (last->next != head)
                last = last->next;
            newNode->next = head;
            last->next = newNode;
            head = newNode;
        }
    }

    void deleteEnd()
    {
        if (head == NULL)
        {
            cout << "List is empty. Cannot delete from an empty list.\n";
            return;
        }

        if (head->next == head)
        {
            delete head;
            head = NULL;
            return;
        }

        Node *last = head;
        while (last->next->next != head)
            last = last->next;
        Node *temp = last->next;
        last->next = head;
        delete temp;
    }

    void displayList()
    {
        if (head == NULL)
        {
            cout << "List is empty.\n";
            return;
        }

        Node *temp = head;
        cout << "Circular Linked List: ";
        do
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << temp->data << " (back to head)" << endl;
    }
};

int main()
{
    circular_LinkedList cll;
    cout << endl;

    // Insertion at Front
    cll.insertFront(5);
    cll.insertFront(4);
    cll.insertFront(3);
    cll.displayList();

    // Deletion at End
    cll.deleteEnd();
    cll.displayList();

    // Insertion at Front
    cll.insertFront(2);
    cll.insertFront(1);
    cll.insertFront(0);
    cll.displayList();

    // Deletion at End when only 1 element is present
    cll.deleteEnd();
    cll.displayList();

    // Deletion at End from an empty list
    cll.deleteEnd();
    cll.displayList();

    return 0;
}