#include <iostream>

using namespace std;

class STACK
{
private:
  int arr[30] = {0};
  int top;

public:
  STACK() : top(0) {}

  void push(int a)
  {
    arr[top] = a;
    top++;
    if (top == 30)
      cout << "OVERFLOW!" << endl;
    print_stack();
  }

  int pop()
  {
    if (top != 0)
    {
      int item;
      top--;
      item = arr[top];
      print_stack();
      return item;
    }
    else
      cout << "UNDERFLOW!" << endl;
  }

  void print_stack()
  {
    cout << "The Stack is: ";
    for (int i = 0; i < top; i++)
    {
      if (top == 0)
        cout << "Empty Stack" << endl;
      else if (arr[i] != 0)
        cout << arr[i] << " ";
    }
    cout << " <- TOP";
    cout << endl;
  }
};

class QUEUE
{

private:
  int arr[30] = {0};
  int head;
  int tail;

public:
  QUEUE() : head(0), tail(0) {}

  void enqueue(int a)
  {
    arr[tail] = a;
    tail++;
    if (tail == 30)
      cout << "OVERFLOW!" << endl;
    print_queue();
  }

  int dequeue()
  {
    if (head == tail)
      cout << "UNDERFLOW!" << endl;
    else
    {
      int item;
      item = arr[head];
      head++;
      print_queue();
      return item;
    }
  }

  void print_queue()
  {
    cout << "The Queue is: ";
    cout << "FRONT -> ";
    for (int i = head; i < tail; i++)
    {
      if (head == tail)
        cout << "Empty Queue" << endl;
      else if (arr[i] != 0)
        cout << arr[i] << " ";
    }
    cout << "<- REAR";
    cout << endl;
  }
};

int main()
{
  cout << "------Stack-------" << endl;
  STACK s;
  s.push(1);
  s.push(2);
  s.push(3);
  s.pop();
  s.push(4);
  s.push(5);
  s.pop();
  s.pop();
  cout << "------Queue-------" << endl;
  QUEUE q;
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.dequeue();
  q.enqueue(4);
  q.enqueue(5);
  q.dequeue();
  q.dequeue();
  return 0;
}
