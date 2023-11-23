#include <iostream>

using namespace std;

class NODE
{
public:
    int data;
    NODE *next;

    NODE(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Linked_List
{
private:
    NODE *head = NULL;
    NODE *tail = NULL;

public:
    void add_Ist(int data)
    {
        NODE *temp = new NODE(data);
        if (head == NULL)
        {
            head = tail = temp;
            return;
        }
        temp->next = head;
        head = temp;
    }

    void add_Last(int data)
    {
        NODE *temp = new NODE(data);
        if (head == NULL)
        {
            head = tail = temp;
            return;
        }
        tail->next = temp;
        tail = temp;
    }
    void add_Node(int data, int index)
    {
        NODE *temp = new NODE(data);
        if (head == NULL)
        {
            add_Ist(data);
            return;
        }
        NODE *NewNode = head;
        int idx = 0;
        while (idx != (index - 1))
        {
            NewNode = NewNode->next;
            idx++;
        }
        temp->next = NewNode->next;
        NewNode->next = temp;
    }

    void delete_Node(int key)
    {
        NODE *temp = head;
        NODE *prev = NULL;

        if (temp != NULL && temp->data == key)
        {
            head = temp->next;
            delete temp;
            return;
        }

        while (temp != NULL && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL)
            return;

        prev->next = temp->next;

        delete temp;
    }

    void print_List()
    {
        NODE *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL";
        cout << endl;
    }

    void reverse_List()
    {
        NODE *curr = head;
        NODE *prev = NULL;
        NODE *next;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
};

int main()
{
    Linked_List l;

    cout << "Adding Nodes in the List" << endl;
    l.add_Last(5);
    l.add_Last(6);
    l.add_Last(7);
    l.add_Ist(4);
    l.add_Ist(2);
    l.add_Ist(1);
    l.add_Node(3, 2);
    l.print_List();

    cout << "Reversing above List" << endl;
    l.reverse_List();
    l.print_List();

    cout << "Deleting Nodes in the List" << endl;
    l.delete_Node(3);
    l.delete_Node(5);
    l.delete_Node(1);
    l.delete_Node(7);
    l.print_List();

    cout << "Reversing above List" << endl;
    l.reverse_List();
    l.print_List();

    return 0;
}