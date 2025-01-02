#include <iostream>
using namespace std;

class stack_arr
{
private:
    int stackk[100];
    int top = -1;

public:
    void push(int x)
    {
        if (top == 99)
        {
            cerr << "stack overflow";
        }
        else
        {
            top++;
            stackk[top] = x;
        }
    }
    void printit()
    {
        for (int i = 0; i < top + 1; i++)
        {
            std::cout << stackk[i] << ", ";
        }
    }
    void pop()
    {
        if (top != -1)
        {
            top--;
        }
        else
        {
            std::cerr << "stack is empty";
        }
    }
    int Top()
    {
        if (top != -1)
        {
            return stackk[top];
        }
        else
        {
            std::cerr << "stack is empty";
        }
    }
    int size()
    {
        return top + 1;
    }
};

class node
{
public:
    node *next = nullptr;
    node *back = nullptr;
    int val;
    node(int data)
    {
        val = data;
    }
    node(int data, node *n)
    {
        val = data;
        next = n;
    }
    node(int data, node *n, node *m)
    {
        val = data;
        next = n;
        back = m;
    }
};

class stack_LL
{
private:
    node *top;
    int n = 0;

public:
    stack_LL()
    {
        top = nullptr;
    }
    void push(int x)
    {
        if (top == nullptr)
        {
            top = new node(x);
            n++;
        }
        else
        {
            node *newnode = new node(x);
            newnode->next = top;
            top = newnode;
            n++;
        }
    }
    void printit()
    {
        node *current = top;
        while (current != nullptr)
        {
            cout << current->val << ", ";
            current = current->next;
        }
    }
    int pop()
    {
        if (top == nullptr)
        {
            return -1;
        }
        else if (n == 1)
        {
            node *temp = top;
            top = nullptr;
            int topdata = temp->val;
            delete temp;
            n = 0;
            return topdata;
        }
        else
        {
            node *temp = top;
            int topdata = temp->val;
            top = top->next;
            delete temp;
            n--;
            return topdata;
        }
    }
    int peek()
    {
        return top->val;
    }
    int size()
    {
        return n;
    }
    bool isempty()
    {
        return top == nullptr;
    }
};

class queue_arr
{
    int front = -1;
    int back = -1;
    const static int n = 100;
    int que[n];
    void push(int x)
    {
        if (back == n - 1)
        {
            cerr << "queue overflow";
            return;
        }
        back++;
        que[back] = x;
        if (front == -1)
        {
            front = 0;
        }
    }
    int pop()
    {
        if (front = -1 || front > back)
        {
            return -1;
        }
        front++;
        return que[front - 1];
    }
    int peek()
    {
        if (front = -1 || front > back)
        {
            return -1;
        }
        return que[front];
    }
    bool isempty()
    {
        return (front = -1 || front > back);
    }
};

class queue_LL
{
    node *front;
    node *back;
    int n = 0;
    queue_LL()
    {
        front = nullptr;
        back = nullptr;
    }
    void push(int x)
    {
        if (front == nullptr)
        {
            node *newnode = new node(x);
            front = newnode;
            back = newnode;
        }
        else
        {
            back->next = new node(x);
            back = back->next;
        }
        n++;
    }
    int pop()
    {
        if (front == nullptr)
        {
            cerr << "Queue is empty" << endl;
            return -1;
        }
        node *temp = front;
        int toreturn = front->val;
        front = front->next;
        if (front == nullptr)
        {
            back = nullptr;
        }
        delete temp;
        n--;
        return toreturn;
    }
    int peek()
    {
        if (front == nullptr)
        {
            cerr << "Queue is empty" << endl;
            return -1;
        }
        return front->val;
    }
    int size()
    {
        return n;
    }
    bool isempty()
    {
        return (front == nullptr);
    }
};
