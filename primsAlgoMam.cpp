#include <iostream>
using namespace std;

struct Edge
{
public:
    int U, V, wt;
} ​;

class Graph
{
    int weight[20][20]; //{​{​0,1,5}​,{​0,2,4}​,{​0,3,6}​,{​0,4,2}​,{​1,3,2}​,{​1,5,3}​,{​2,4,3}​,{​3,4,1}​,{​3,5,2}​,{​4,5,4}​}​;
    int visited[20], d[20], p[20];
    int v = 0, e;
    Edge edge[20];

public:
    Graph();
    void creategraph();
    void prim();
    void sortg();
    void kruskals();
    void dijktras();
}​;

void Graph::prim()
{
    int current, totalvisited, mincost, i;
    current = 0;
    d[current] = 0;

    totalvisited = 1;
    visited[current] = 1;

    cout << endl
         << "visited distance and path status is :" << endl
         << "i , visited[i] p[i] , d[i]";
    for (i = 0; i < v; i++)
    {
        cout << endl;
        //cout<<i<<"\t"<<visited[i]<<"\t"<<p[i]<<"\t"<<d[i]<<"\t";
        cout << endl
             << "for I=" << i;
        cout << "Visited[i]" << visited[i];
        cout << " p[i]= " << p[i];
        cout << " d[i]= " << d[i];
    }

    while (totalvisited != v)
    {
        cout << endl
             << "total visited=" << totalvisited;

        for (i = 0; i < v; i++)
        {
            if (weight[current][i] != 0)
                if (visited[i] == 0)
                    if (weight[current][i] < d[i])
                    {
                        d[i] = weight[current][i];
                        p[i] = current;
                    }
        }
        cout << endl
             << "visited distance and path status is :" << endl
             << "i , visited[i] p[i] , d[i]";
        for (i = 0; i < v; i++)
        {
            cout << endl;
            //cout<<i<<"\t"<<visited[i]<<"\t"<<p[i]<<"\t"<<d[i]<<"\t";
            cout << endl
                 << "for I=" << i;
            cout << "Visited[i]" << visited[i];
            cout << " p[i]= " << p[i];
            cout << " d[i]= " << d[i];
        }
        mincost = 32767;
        cout << endl
             << "finding minimum cost";
        for (i = 0; i < v; i++)
        {
            if (visited[i] == 0)
                if (d[i] < mincost)
                {
                    mincost = d[i];
                    current = i;
                }
        }
        cout << endl
             << "for I=" << i;
        cout << "mincost= " << mincost;
        cout << "current= " << current;

        visited[current] = 1;
        totalvisited++;

        cout << endl
             << "current= " << current << " Total Visited== " << totalvisited;
        //for(int j=0;j<3;j++)

    } /*end of while loop */

    cout << endl
         << "Minimum span tree is" << endl;
    mincost = 0;
    for (i = 1; i < v; i++)
    {
        mincost += d[i];
        cout << " Edge " << i << "-->" << p[i] << " Weight= " << d[i] << endl;
        ;
    }

    cout << "Minimum cost = ";
    cout << mincost;

    cout << endl
         << "After Manip visited distance and path status is :";
    cout << endl
         << "i , visited[i] p[i] , d[i]";
    for (i = 0; i < v; i++)
    {
        cout << endl;
        cout << i << "\t" << visited[i] << "\t" << p[i] << "\t" << d[i] << "\t";
    }

} /*end of prim */

void Graph::kruskals()
{    int i,j;
    //Edge temp;
    cout << "edge array is:" << endl;
    for (i = 0; i < e; i++)
    {​
            cout<< edge[i].U << ", " << edge[i].V << ", " << edge[i].wt << endl;
    }
    sortg();    // Sort the list of edges
    Edge t[15]; //MST
    int conn[10], k, r, p, Val, cnt = 0;
    for (i = 0; i < e; i++)
    conn[i] = 0;
    Val = 1;
    cnt = 0;
    j = 0;
    while (cnt < e - 1 && j < e)
    {
        ​ //both vertices are not visited
            if(conn[edge[j].U] == 0 && conn[edge[j].V] == 0)
        {
            ​ cout << "edge selected" << edge[j].U << ", " << edge[j].V << ", " << edge[j].wt << endl;
            t[cnt] = edge[j]; //add edge into MST
            conn[edge[j].U] = Val;
            conn[edge[j].V] = Val;
            Val++;
            cnt++;
        }
        ​ else if (conn[edge[j].U] != conn[edge[j].V]) //if conn value of both vertices is not equal
        {
            ​
                    cout
                << "edge selected" << edge[j].U << ", " << edge[j].V << ", " << edge[j].wt << endl;
            if (conn[edge[j].U] != 0 && conn[edge[j].V] != 0) //if both vertices are visited
            {
                ​
                    t[cnt] = edge[j];
                if (conn[edge[j].U] < conn[edge[j].V]) //if connected value of first vertex is less
                {
                    ​
                        r = conn[edge[j].U];
                    p = conn[edge[j].V];
                }
                ​ else //if connected value of second vertex is less
                {
                    ​ r = conn[edge[j].V];
                    p = conn[edge[j].U];
                }
                ​ for (k = 0; k < e; k++) //replace bigger connected value-p with small value-r
                {
                    ​ if (conn[k] == p)
                        conn[k] = r;
                }
                ​
                    cnt++;
            }
            ​ else if (conn[edge[j].U] == 0 && conn[edge[j].V] != 0) //if first vertex is not visited & second is visited
            {
                ​
                    t[cnt] = edge[j];
                conn[edge[j].U] = conn[edge[j].V];
                cnt++;
            }
            ​ else //if first vertex is visited & second is not visited
            {
                ​
                    t[cnt] = edge[j];
                conn[edge[j].V] = conn[edge[j].U];
                cnt++;
            }
            ​
        }
        ​ else //Both verticces has same connected value-reject edge--- forms cycle
            cout
            << "edge Rejected" << edge[j].U << ", " << edge[j].V << ", " << edge[j].wt << endl;
        j++;
    }
    ​
            cout
        << "Krskals MST contains following edges::" << endl;
    int cost = 0;
    for (i = 0; i < cnt; i++)
    {
        ​ cout << t[i].U << ", " << t[i].V << ", " << t[i].wt << endl;
        cost = cost + t[i].wt;
    }
    ​
            cout
        << endl
        << "Total Cost of MST is " << cost;
}
​

    struct Edge
{
    ​ int U, V, wt;
} ​;

class Graph
{
    int weight[20][20]; //{​{​0,1,5}​,{​0,2,4}​,{​0,3,6}​,{​0,4,2}​,{​1,3,2}​,{​1,5,3}​,{​2,4,3}​,{​3,4,1}​,{​3,5,2}​,{​4,5,4}​}​;
    int visited[20], d[20], p[20];
    int v = 0, e;
    Edge edge[20];

public:
    Graph();
    void creategraph();
    void prim();
    void sortg();
    void kruskals();
    void dijktras();
};