/*
Sanket Ganesh Jhavar
Roll no.:21138
SE-1     F-1  Batch
*/
#include <bits/stdc++.h>
#include <iostream>
typedef long long ll;
using namespace std;
class Graph
{
    ll graph[100][100];
    int vertex;

public:
    Graph()
    {
        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 20; j++)
            {
                graph[i][j] = 0;
            }
        }
    }
    Graph(int m)
    {
        vertex = m;
    }

    void Addedge(ll x, ll y, ll wt)
    {
        graph[x][y] = wt;
        graph[y][x] = wt;
    }
    void Display()
    {
        for (int i = 0; i < vertex; i++)
        {
            for (int j = 0; j < vertex; j++)
            {
                cout << graph[i][j] << "   ";
            }
            cout << endl;
        }
    }
    void Prims(int ver)

    {

        int nv = vertex;
        int TempG[nv][nv];
        for (int i = 0; i < nv; i++)
        {
            for (int j = 0; j < nv; j++)
            {
                TempG[i][j] = graph[i][j];
            }
        }

        int count1 = 0, count = 0, visited[20], min = 9999, parent[20], minweight = 0, temp1, temp2, t1, t2;
        int sum = 0;
        for (int i = 0; i < 20; i++)
        {
            visited[i] = 0;
            parent[i] = -1;
        }

        int result[nv][nv];
        for (int i = 0; i < nv; i++)
        {

            for (int j = 0; j < nv; j++)
            {
                result[i][j] = 0;
            }
        }
        int roottemp1, roottemp2;
        visited[count1] = ver;
        count1++;
        while (count < nv - 1)
        {
            min = 9999;
            for (int v1 = 0; v1 < count1; v1++)
            {
                for (int v2 = 0; v2 < nv; v2++)
                {
                    if (TempG[visited[v1]][v2] != 0 && TempG[visited[v1]][v2] < min)
                    {
                        min = TempG[visited[v1]][v2];
                        t1 = visited[v1];
                        t2 = v2;
                    }
                }
            }
            temp1 = t1;temp2 = t2;
            TempG[t1][t2] = TempG[t2][t1] = 0;
            while (t1 >= 0)
            {
                roottemp1 = t1;
                t1 = parent[t1];
            }
            while (t2 >= 0)
            {
                roottemp2 = t2;
                t2 = parent[t2];
            }

            if (roottemp1 != roottemp2)
            {
                result[temp1][temp2] = result[temp2][temp1] = min;
                sum+=result[temp1][temp2];
                parent[roottemp2] = roottemp1;
                count++;
                visited[count1] = roottemp2;
                count1++;
            }
        }



        for (int i = 0; i < nv; i++)
        {

            for (int j = 0; j < nv; j++)
            {
                cout << result[i][j] << "  ";
            }
            cout << endl;
        }
        cout << "\nMinimum Cost is: " << sum << endl;
    }
};

int main()
{
    int t2, ch;
    cout << "\nEnter the Number Of Vertex - ";
    cin >> t2;
    Graph g(t2);
    do
    {
        cout << "\n1.Create Graph - " << endl;
        cout << "2.Display Graph - " << endl;
        cout << "3.Minimum Spanning tree - " << endl;
        cout << "4.Exit - " << endl;
        cout << "Enter the Choice - ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            int t;
            cout << "Total Number Of Edges - ";
            cin >> t;
            int src, des, wt;
            for (int i = 0; i < t; i++)
            {
                cout << "\nEnter the Source and Destination - ";
                cin >> src >> des;
                cout << "\nEnter the weight - ";
                cin >> wt;
                if (src != des)
                {
                    g.Addedge(src, des, wt);
                }
            }
            break;
        case 2:
            g.Display();
            break;
        case 3:
            int ver;
            cout << "Enter the starting Vertex For Spanning tree - ";
            cin >> ver;
            g.Prims(ver);

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
