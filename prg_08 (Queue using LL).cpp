// Implement  a  Linear Queue using Linked List  and  Perform following operations :  Insert, Delete, and Display  the queue elements

#include <iostream>
using namespace std;

// Node structure to represent each element in the queue
struct Node
{
    int data;
    Node *next;

    // Constructor to initialize the node
    Node(int value) : data(value), next(nullptr) {}
};

// Queue class with basic operations
class Queue
{
private:
    Node *front; // Front of the queue
    Node *rear;  // Rear of the queue

public:
    // Constructor to initialize an empty queue
    Queue() : front(nullptr), rear(nullptr) {}

    // Function to insert an element into the queue
    void enqueue(int value)
    {
        // Create a new node with the given value
        Node *newNode = new Node(value);

        // If the queue is empty, set both front and rear to the new node
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            // Otherwise, add the new node to the rear and update the rear
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Inserted " << value << " into the queue." << endl;
    }

    // Function to delete an element from the queue
    void dequeue()
    {
        // Check if the queue is empty
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        // Store the front node to be deleted
        Node *temp = front;

        // Move the front to the next node
        front = front->next;

        // If the front becomes null, update the rear to null as well
        if (front == nullptr)
        {
            rear = nullptr;
        }

        // Delete the node and free the memory
        delete temp;

        cout << "Deleted element from the queue." << endl;
    }

    // Function to display the elements in the queue
    void display()
    {
        // Check if the queue is empty
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }

        // Traverse the queue and print each element
        Node *current = front;
        cout << "Queue elements: ";
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Function to check if the queue is empty
    bool isEmpty()
    {
        return front == nullptr;
    }
};

// Main function to test the queue operations
int main()
{
    Queue queue;

    // Insert elements into the queue
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    // Display the initial queue
    queue.display();

    // Delete an element from the queue
    queue.dequeue();

    // Display the updated queue
    queue.display();

    return 0;
}
