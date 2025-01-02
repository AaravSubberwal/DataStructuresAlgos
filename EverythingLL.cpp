/************************************************************************************************
Author: Aarav Subberwal
Date: 10/10/24

While coding this I was actually unaware about that there already exists library for linked lists
in standard template library in C++. But anyway here's my own library for dealing with linked lists
in C++. I tried to replicate the methods usually used in std::vector and made them reusable for LL's.
In fact to define one you can just pass a vector as a argument. This was supposed to be a few hours
project which I'm decently proud of. I feel like writing this library is the best way for a student
to learn LL's and be proficient in them.

Stuff to add:
->binary search
->sort
->define the dataype of LL
->convert LL to vector
**************************************************************************************************/
#include <iostream>
#include <vector>
// reverse, search, sort, [] for indexing
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

class SLL
{
public:
    node *p_head = nullptr;
    int n;
    SLL(std::vector<int> sll)
    {
        if (sll.empty())
        {
            n = 0;
        }
        else
        {
            n = sll.size();
            p_head = new node(sll[0]);
            node *current = p_head;
            for (int i = 1; i < sll.size(); i++)
            {
                current->next = new node(sll[i]);
                current = current->next;
            }
        }
    }

    ~SLL()
    {
        node *current = p_head;
        while (current != nullptr)
        {
            node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    int at(int index)
    {
        if ((index < n) && (index >= 0))
        {
            node *current = p_head;
            for (int i = 0; i < index; i++)
            {
                current = current->next;
            }
            return current->val;
        }
        else
        {
            std::cerr << "Index out of bonds";
        }
    }

    node atNode(int index)
    {
        if ((index < n) && (index >= 0))
        {
            node *current = p_head;
            for (int i = 0; i < index; i++)
            {
                current = current->next;
            }
            return *current;
        }
        else
        {
            std::cerr << "Index out of bounds";
        }
    }

    bool isempty()
    {
        if (n == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void insert(int index, int data)
    {
        if (n == 0)
        {
            std::cerr << "SLL is empty";
        }
        else
        {
            if (index == 0) // insert at front
            {
                node *newfirstnode = new node(data);
                newfirstnode->next = p_head;
                p_head = newfirstnode;
            }
            else if (index == n) // insert at end
            {
                node *newtail = new node(data);
                node *current = p_head;
                while (current->next != nullptr)
                {
                    current = current->next;
                }
                current->next = newtail;
            }
            else if (index < n) // insert anywhere
            {
                node *newnode = new node(data);
                node *current = p_head;
                node *temp;
                for (int i = 0; i < index - 1; i++)
                {
                    current = current->next;
                }
                temp = current->next;
                current->next = newnode;
                newnode->next = temp;
            }
            else
            {
                std::cerr << "Index out of bounds";
                exit;
            }
            n++;
        }
    }
    void remove(int index) // remove(index)
    {
        if (index == 0)
        { // remove first element
            if (this->isempty())
            {
                std::cerr << "sll is empty";
            }
            else
            {
                node *temp = p_head;
                p_head = p_head->next;
                delete temp;
            }
        }
        else if (index < n)
        { // remove any element
            node *current = p_head;
            for (int i = 0; i < index - 1; i++)
            {
                current = current->next;
            }
            node *temp = current->next;
            current->next = temp->next;
            delete temp;
        }
        else
        {
            std::cerr << "index out of bonds";
        }
        n--;
    }
    void printlist()
    {
        node *current = p_head;
        while (current != nullptr)
        {
            std::cout << "-->" << current->val;
            current = current->next;
        }
    }

    int size()
    {
        return n;
    }

    void push_back(int data)
    {
        if (n == 0)
        {
            p_head = new node(data);
        }
        else
        {
            node *newtail = new node(data);
            node *current = p_head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newtail;
        }
        n++;
    }

    void pop_back()
    {
        if (n == 0)
        {
            std::cerr << "SLL is empty";
        }
        else
        {
            node *current = p_head;
            while (current->next->next != nullptr)
            {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
        }
        n--;
    }

    void merge(SLL other)
    {
        node *temp = p_head;
        while (temp->next != nullptr)
        {
            temp = temp->next; // Traverse to the end of the first list
        }
        temp->next = other.p_head;
        n += other.size();
    }

    void reverse()
    { // gdbd
        node *current = p_head;
        node *prev = nullptr;
        node *after = nullptr;
        while (current->next != nullptr)
        {
            after = current->next;
            current->next = prev;
            prev = current;
            current = after;
        }
        p_head = prev;
    }

    bool linearsearch(int value)
    {
        node *current = p_head;
        while (current->next != nullptr)
        {
            if (value == current->val)
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }
};

class DLL
{
public:
    node *p_head = nullptr;
    node *p_tail = nullptr;
    int n;
    DLL(std::vector<int> dll)
    {

        if (dll.empty())
        {
            n = 0;
        }
        else
        {
            p_head = new node(dll[0]);
            n = dll.size();
            node *current = p_head;
            node *temp;
            current->back = nullptr;
            for (int i = 1; i < n; i++)
            {
                current->next = new node(dll[i]);
                temp = current;
                current = current->next;
                current->back = temp;
            }
            current->next = nullptr;
            p_tail = current;
        }
    }
    ~DLL()
    {
        node *temp = p_head;
        while (temp != nullptr)
        {
            node *nextnode = temp->next;
            delete temp;
            temp = nextnode;
        }
    }
    void printlist()
    {
        node *current = p_head;
        while (current != nullptr)
        {
            std::cout << "<->" << current->val;
            current = current->next;
        }
    }

    int at(int index)
    {
        if ((index < n) && (index >= 0))
        {
            node *current = p_head;
            for (int i = 0; i < index; i++)
            {
                current = current->next;
            }
            return current->val;
        }
        else
        {
            std::cerr << "Index out of bonds";
        }
    }

    node atNode(int index)
    {
        if ((index < n) && (index >= 0))
        {
            node *current = p_head;
            for (int i = 0; i < index; i++)
            {
                current = current->next;
            }
            return *current;
        }
        else
        {
            std::cerr << "Index out of bonds";
        }
    }

    bool isempty()
    {
        if (n == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void insert(int index, int data)
    {
        if (index == 0)
        {
            node *newnode = new node(data, p_head);
            p_head->back = newnode;
            p_head = newnode;
            p_head->back = nullptr;
        }
        else if (index == n)
        {
            node *newtail = new node(data);
            node *current = p_head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newtail;
        }
        else if (index < n)
        {
            node *newnode = new node(data);
            node *current = p_head;
            for (int i = 0; i < index - 1; i++)
            {
                current = current->next;
            }
            newnode->next = current->next;
            newnode->back = current;
            current->next->back = newnode;
            current->next = newnode;
        }
        else
        {
            std::cerr << "Index out of bounds";
            exit;
        }
        n++;
    }
    void remove(int index)
    {
        if (index == 0)
        {
            node *temp = p_head;
            p_head = p_head->next;
            p_head->back = nullptr;
            delete temp;
        }
        else if (index < n - 1)
        {
            node *current = p_head;
            for (int i = 0; i < index - 1; i++)
            {
                current = current->next;
            }
            node *temp = current->next;
            current->next = current->next->next;
            temp->next->back = current;
            delete temp;
        }
        else if (index == n - 1)
        {
            node *temp = p_tail;
            p_tail = p_tail->back;
            p_tail->next = nullptr;
            delete temp;
        }
        else
        {
            std::cerr << "Index out of bonds";
            exit;
        }
        n--;
    }

    int size()
    {
        return n;
    }

    void reverse()
    {
        node *current = p_head;
        node *temp = nullptr;
        p_tail = p_head;
        while (current != nullptr)
        {
            temp = current->next;
            current->next = current->back;
            current->back = temp;
            current = current->back;
        }
        p_head = temp->back;
    }
};

class CSLL
{
public:
    node *p_tail = nullptr;
    node *p_head = nullptr;
    int n = 0;
    CSLL(std::vector<int> csll)
    {
        p_tail = new node(csll[0]);
        p_head = p_tail;
        node *current;
        n = csll.size();
        for (int i = 1; i < csll.size(); i++)
        {
            current = new node(csll[i]);
            p_tail->next = current;
            p_tail = current;
        }
        p_tail->next = p_head;
    }
    void printlist()
    {
        if (p_head == nullptr)
        {
            std::cerr << "List is empty." << std::endl;
            return;
        }

        node *current = p_head;
        do
        {
            std::cout << "-->" << current->val;
            current = current->next;
        } while (current != p_head);
    }
    void insert(int index, int data)
    {
        if (n == 0)
        {
            p_head = new node(data);
            p_tail = p_head;
        }
        else
        {
            if (index == 0) // insert at front
            {
                node *newnode = new node(data);
                newnode->next = p_head;
                p_head = newnode;
                p_tail->next = newnode;
                n++;
            }
            else if (index == n) // insert at end
            {
                node *newnode = new node(data);
                p_tail->next = newnode;
                p_tail = newnode;
                p_tail->next = p_head;
            }
            else if (index < n) // insert anywhere
            {
                node *newnode = new node(data);
                node *current = p_head;
                node *temp;
                for (int i = 0; i < index - 1; i++)
                {
                    current = current->next;
                }
                temp = current->next;
                current->next = newnode;
                newnode->next = temp;
            }
            else
            {
                std::cerr << "Index out of bounds";
                exit;
            }
            n++;
        }
    }
    void remove(int index)
    {
        if (index == 0)
        {
            node *temp = p_head;
            p_head = temp->next;
            p_tail->next = p_head;
            delete temp;
            n--;
        }
        else if (index == n - 1)
        {
            node *current = p_head;
            for (int i = 0; i < index - 1; i++)
            {
                current = current->next;
            }
            p_tail = current;
            current = current->next;
            delete current;
            p_tail->next = p_head;
            n--;
        }
        else if (index < n - 1)
        {
            node *current = p_head;
            for (int i = 0; i < index - 1; i++)
            {
                current = current->next;
            }
            node *temp = current->next;
            current->next = current->next->next;
            delete temp;
            n--;
        }
        else
        {
            std::cerr << "Index out of bonds";
        }
    }
};

class CDLL
{
public:
    node *p_tail = nullptr;
    node *p_head = nullptr;
    int n = 0;
    CDLL(std::vector<int> cdll)
    {
        p_head = new node(cdll[0]);
        n = cdll.size();
        node *current = p_head;
        node *temp;
        for (int i = 1; i < n; i++)
        {
            current->next = new node(cdll[i]);
            temp = current;
            current = current->next;
            current->back = temp;
        }
        p_tail = current;
        p_tail->next = p_head;
        p_head->back = p_tail;
    }
    void printlist()
    {
        if (p_head == nullptr)
        {
            std::cerr << "List is empty." << std::endl;
            return;
        }

        node *current = p_head;
        do
        {
            std::cout << "-->" << current->val;
            current = current->next;
        } while (current != p_head);
    }
    void insert(int index, int data)
    {
        if (n == 0)
        {
            p_head = new node(data);
            p_tail = p_head;
        }
        else
        {
            if (index == 0) // insert at front
            {
                node *newnode = new node(data);
                newnode->next = p_head;
                p_head->back = newnode;
                p_head = newnode;
                p_tail->next = newnode;
                n++;
            }
            else if (index == n) // insert at end
            {
                node *newnode = new node(data);
                p_tail->next = newnode;
                newnode->back = p_tail;
                p_tail = newnode;
                p_tail->next = p_head;
                p_head->back = newnode;
            }
            else if (index < n) // insert anywhere
            {
                node *newnode = new node(data);
                node *current = p_head;
                node *temp;
                for (int i = 0; i < index - 1; i++)
                {
                    current = current->next;
                }
                temp = current->next;
                current->next = newnode;
                newnode->next = temp;
            }
            else
            {
                std::cerr << "Index out of bounds";
                exit;
            }
            n++;
        }
    }
    void remove(int index)
    {   
        if (index == 0)
        {
            node *temp = p_head;
            p_head = temp->next;
            p_tail->next = p_head;
            p_head->back = p_tail;
            delete temp;
        }
        else if (index == n - 1)
        {
            node *current = p_tail;
            p_tail = p_tail->back;
            delete current;
            p_tail->next = p_head;
            p_head->back = p_tail;
        }
        else if (index < n - 1)
        {
            node *current = p_head;
            for (int i = 0; i < index - 1; i++)
            {
                current = current->next;
            }
            node *temp = current->next;
            current->next = current->next->next;
            current->next->back = current;
            delete temp;
        }
        else
        {
            std::cerr << "Index out of bonds";
        }
    }
};
