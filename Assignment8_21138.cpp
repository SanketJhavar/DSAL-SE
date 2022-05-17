/*
Sanket Ganesh Jhavar
Roll no.:21138
SE-1     F-1  Batch
*/

#include <bits/stdc++.h>
#include <iostream>
#define MAX 50
typedef long long ll;
using namespace std;
class Queue
{                         // Queue Class For Topological Sort!
    int Q[MAX];
    int front;
    int rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }
    int top()            // Return the top element of the queue
    {
        return Q[front];
    }

    void Enqueue(int v)
    {

        if (front == -1 && rear == -1)
        {
            front++;
            rear++;
        }
        else
        {
            rear++;
        }
        Q[rear] = v;
    }
    int Dequeue()
    {
        int x;
        x = Q[front];
        front++;
        return x;
    }
    int Empty()
    {
        if (front == rear + 1 || front == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

};
class Graph
{
    ll GraphMatrix[100][100];
    ll TopoSort[100];
    ll B[100];
    ll size;
    ll Q[MAX];

public:
    Graph(int m)
    {
        size = m;  //TOTAL NUMBER OF VERTICES
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                GraphMatrix[i][j] = 0;
            }
        }
    }
    void Insert(int x, int y)
    {
        if (GraphMatrix[y][x] == 0)
        {
            GraphMatrix[x][y] = 1;
        }
        else
        {
            cout << "\nGraph must be Acyclic!" << endl;
        }
    }
    int Indegree(int x)
    {
        int indeg_count = 0;
        for (int i = 0; i < size; i++)
        {
            if (GraphMatrix[i][x] == 1)
            {
                indeg_count++;
            }
        }
        return indeg_count;
    }
    void Display()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << GraphMatrix[i][j] << "  ";
            }
            cout << endl;
        }
    }

    void Topological()
    {
        Queue q;
        int j = 0;
        for (int i = 0; i < size; i++)
        {
            TopoSort[i] = Indegree(i);
            if (TopoSort[i] == 0)
            {
                // q.push(i);
                q.Enqueue(i);
            }
        }
        while (!q.Empty())
        {
            int k = q.top();
            q.Dequeue();
            B[j++] = k;

            for (int i = 0; i < size; i++)
            {
                if (GraphMatrix[k][i] == 1)
                {
                    GraphMatrix[k][i] = 0;
                    TopoSort[i] = TopoSort[i] - 1;
                    if (TopoSort[i] == 0)
                    {
                        q.Enqueue(i);
                    }
                }
            }
        }

        for (int i = 0; i < size; i++)
        {
            cout << B[i] << "  ";
        }
        cout << endl;
    }
    friend class Queue;
};

int main()
{
    int ch, v;
    cout << "\nEnter the total number Of vertices - ";
    cin >> v;
    Graph g(v);
    do
    {
        cout << "\n1.Create Graph - " << endl;
        cout << "2.Display Graph- " << endl;
        cout << "3.Display Topological Sort" << endl;
        cout << "4.Exit - " << endl;
        cout << "\nEnter the Choice  - ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            int e;
            cout << "\nEnter the total number Of edges - ";
            cin >> e;
            for (int i = 0; i < e; i++)
            {
                int x, y;
                cout << "\nEnter the source and destination - ";
                cin >> x >> y;
                g.Insert(x, y);
            }
            break;
        case 2:
            g.Display();
            break;
        case 3:
            g.Topological();
            break;
        case 4:
            ch=0;
          	break;
        default:
            break;
        }
    } while (ch != 0);

    return 0;
}
