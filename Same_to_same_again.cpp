#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int value;
        Node* next;
        Node(int value)
        {
            this->value=value;
            this->next=NULL;
        }
};
class Stack
{
    public:
    Node* top;
    Stack()
    {
        top = NULL;
    }
    void push(int val)
    {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        int val = top->value;
        Node* temp = top;
        top = top->next;
        delete temp;
        return val;
    }
    bool isEmpty()
    {
        return top == NULL;
    }
};
class Queue
{
public:
    Node* front;
    Node* rear;
    Queue()
    {
        front = NULL;
        rear = NULL;
    }
    void enqueue(int val)
    {
        Node* newNode = new Node(val);
        if (isEmpty())
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int val = front->value;
        Node* temp = front;
        front = front->next;
        if (front == NULL)
        {
            rear = NULL;
        }
        delete temp;
        return val;
    }
    bool isEmpty()
    {
        return front == NULL;
    }
};
string CLS(int n, int m, int A[], int B[])
{
    Stack stackA;
    Queue queueB;
    for (int i = 0; i < n; i++)
    {
        stackA.push(A[i]);
    }
    for (int i = 0; i < m; i++)
    {
        queueB.enqueue(B[i]);
    }
    while (!stackA.isEmpty() && !queueB.isEmpty())
    {
        int topA = stackA.pop();
        int frontB = queueB.dequeue();
        if (topA != frontB)
        {
            return "NO";
        }
    }
    if (!stackA.isEmpty() || !queueB.isEmpty())
    {
        return "NO";
    }
    return "YES";
}
int main()
{
    int n, m;
    cin >> n >> m;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    int B[m];
    for (int i = 0; i < m; i++)
    {
        cin >> B[i];
    }
    string result = checkListsAreSame(n, m, A, B);
    cout << result << endl;
    return 0;
}
