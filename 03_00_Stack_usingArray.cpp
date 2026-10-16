#include <iostream>
using namespace std;


class Stack {
   
    int* arr;
  
    int top;
 
    int capacity;

public:

    Stack(int size)
    {
    
        arr = new int[size];
      
        capacity = size;
 
        top = -1;
    }

  
    ~Stack() { delete[] arr; }


    void push(int x)
    {
      
        if (isFull()) {
            cout << "Overflow\n";
            return;
        }
        cout << "Pushing " << x << "\n";
      
        arr[++top] = x;
    }

 
    int pop()
    {
    
        if (isEmpty()) {
            cout << "Underflow\n";
            return -1;
        }
 
        return arr[top--];
    }

    int peek()
    {
        if (!isEmpty())
            return arr[top];
        else
            return -1;
    }

    bool isEmpty() { return top == -1; }

   
    bool isFull() { return top == capacity - 1; }
};


int main()
{
   
    Stack stack(3);


    stack.push(10);
    stack.push(20);
    stack.push(30);

 
    cout << "The top element is " << stack.peek() << endl;

    cout << "Popping " << stack.pop() << endl;
    
    cout << "The top element is " << stack.peek() << endl;

    
    stack.pop();
    stack.pop();

    if (stack.isEmpty()) {
        cout << "The stack is empty" << endl;
    }
    else {
        cout << "The stack is not empty" << endl;
    }

    return 0;
}