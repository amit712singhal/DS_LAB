#include <iostream>

using namespace std;

class NODE
{
public:
    int data;
    NODE *prev;
    NODE *next;
    NODE(int current_data)
    {
        this->data = current_data;

        this->prev = this->next = NULL;
    }
};

class doubly_LINKED_LIST
{
private:
    NODE *Head;
    NODE *Tail;

public:
    doubly_LINKED_LIST() { this->Head = this->Tail = NULL; }

    void print_LL()
    {
        NODE *temp = Head;
        cout
            << "------------------ Doubly LinkedList ------------------" << endl
            << "NULL <-> ";
        while (temp != NULL)
        {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void add_FRONT(int data)
    {
        NODE *NewNode = new NODE(data);
        if (Head == NULL)
        {
            Head = Tail = NewNode;
            return;
        }
        Head->prev = NewNode;
        NewNode->next = Head;
        Head = NewNode;
    }

    void remove_LAST()
    {
        if (Head == NULL)
        {
            return;
        }
        NODE *temp = Tail;
        Tail = Tail->prev;

        Tail->next = temp->prev = NULL;
        cout << "Removed Node is :: " << temp->data << endl;
        free(temp);
        print_LL();
    }
};

int main()

{
    doubly_LINKED_LIST d;
    cout << endl;

    d.add_FRONT(10);
    d.add_FRONT(9);
    d.add_FRONT(8);
    d.add_FRONT(7);
    d.add_FRONT(6);
    d.add_FRONT(5);
    d.print_LL();
    d.remove_LAST();

    d.add_FRONT(4);
    d.add_FRONT(3);
    d.add_FRONT(2);
    d.add_FRONT(1);
    d.add_FRONT(0);
    d.print_LL();
    d.remove_LAST();

    return 0;
}