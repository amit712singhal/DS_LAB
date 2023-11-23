#include <iostream>
using namespace std;

// Linked_List
class Node
{
public:
    int data;
    Node *next;

    Node(int n)
    {
        this->data = n;
        this->next = NULL;
    }
};

// Creating Stack using Linked_List
class Stack_LL
{
    Node *top;

public:
    Stack_LL() { top = NULL; }

    // checking if stack is empty or not
    bool isEmpty()
    {
        return top == NULL;
    }

    // getting the top element in the stack
    int peek()
    {
        if (!isEmpty())
            return top->data;
        else
            exit(1);
    }

    // inserting elements in the stack
    void push(int data)
    {
        Node *temp = new Node(data);

        if (!temp)
        {
            cout << "\nStack Overflow";
            exit(1);
        }

        temp->data = data;

        temp->next = top;

        top = temp;
    }

    // deleting elements from stack
    void pop()
    {
        Node *temp;

        if (top == NULL)
        {
            cout << "\nStack Underflow" << endl;
            exit(1);
        }
        else
        {
            temp = top;
            top = top->next;
            free(temp);
        }
    }

    // printing elements of stack by traversing it
    void display()
    {
        Node *temp;

        if (top == NULL)
        {
            cout << "\nStack Underflow";
            exit(1);
        }
        else
        {
            temp = top;
            cout << "TOP ---> ";
            while (temp != NULL)
            {
                cout << temp->data;
                temp = temp->next;
                if (temp != NULL)
                    cout << " -> ";
            }
        }
        cout << endl;
    }
};

int main()
{
    Stack_LL s;

    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);

    s.display();

    s.pop();
    s.pop();
    s.pop();

    s.display();

    cout << "Top element: " << s.peek() << endl;
    cout << "Is the stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}