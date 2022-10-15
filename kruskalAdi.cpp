#include <iostream>
using namespace std;
struct Edge
{
    int u, v, wt;
};
class Graph
{
    Edge edge[20];
    int weight[20][20];
    int dist[20];
    int path[20];
    int vn, en;
    string str[20];

public:
    Graph();
    void create();
    void display();
    void prims();
    void kruskals();
    void sort();
};
Graph::Graph()
{
    do
    {
        cout << "Max no of edges and vertices=20" << endl;
        cout << "Enter number of vertices:";
        cin >> vn;
        cout << "Enter number of edges:";
        cin >> en;
    } while (vn < 1 || vn > 20 || en < 1 || en > 20); //MAX number of vertices and
    for (int i = 0; i < vn; i++)
    { //initialising the adjacency matrix
        for (int j = 0; j < en; j++)
        {
            weight[i][j] = 0;
        }
    }
}
void Graph::create()
{ //Creating a new graph with vn vertices and en edges
    int a, b, w;
    for (int i = 0; i < vn; i++)
    {
        cout << "Vertex" << i << ":";
        cin >> str[i]; //Entering name of department as vertex of graph
    }
    cout << "you entered: " << endl;
    for (int i = 0; i < vn; i++)
    { //Displaying vertices of graph
        cout << i << ":" << str[i] << endl;
    }
    cout << "enter edges in graph: " << endl;
    for (int i = 0; i < en; i++)
    { //to update edges in adjacency matrix
        cout << "Enter vertices and weight:";
        cin >> a >> b >> w;
        edge[i].u = a;
        edge[i].v = b;
        edge[i].wt = w;
        weight[a][b] = w;
        weight[b][a] = w;
    }
}
void Graph::prims()
{
    int total_vis = 0; //total visited nodes
    int vis[vn];       //array about visited and unvsited nodes
    for (int i = 0; i < vn; i++)
    { //Initialising all distances with value 5000
        dist[i] = 5000;
        vis[i] = 0;
        path[i] = 0;
    }
    cout << "Vertex \t Dist \t Visited";
    for (int i = 0; i < vn; i++)
    {
        cout << endl;
        cout << i << "\t";
        cout << dist[i] << "\t";
        cout << vis[i] << " ";
    }
    int curent = 0;
    vis[0] = 1;    //visiting first vertex
    total_vis = 1; //incrementing total visited nodes for visiting first vertex
    dist[curent] = 0;
    while (total_vis != vn)
    {
        cout << "Current Vertex: " << curent << endl;
        cout << "Total Visited: " << total_vis << endl;
        for (int i = 0; i < vn; i++)
        {
            if (weight[curent][i] != 0)
            {
                if (vis[i] == 0)
                {
                    if (weight[curent][i] < dist[i])
                    {
                        dist[i] = weight[curent][i];
                        path[i] = curent;
                    }
                }
            }
        }
        cout << "From" << curent << endl;
        cout << "Vertex \t Dist \t Visited";
        for (int i = 0; i < vn; i++)
        {
            cout << endl;
            cout << i << "\t";
            cout << dist[i] << "\t";
            cout << vis[i] << " ";
        }
        int min_cost = 45433;
        for (int i = 0; i < vn; i++)
        {
            if (vis[i] == 0)
            {
                if (dist[i] < min_cost)
                {
                    min_cost = dist[i];
                    curent = i;
                }
            }
        }
        vis[curent] = 1;
        total_vis++;
        cout << endl
             << "Selected vertex: " << curent << endl;
        cout << "mincost: " << min_cost << endl;
        cout << "Vertex \t Dist \t Visited";
        for (int i = 0; i < vn; i++)
        {
            cout << endl;
            cout << i << "\t";
            cout << dist[i] << "\t";
            cout << vis[i] << " ";
        }
    }
    int cost = 0;
    cout << endl
         << "Minimum Spanning tree is: " << endl;
    cout << "Department \t Path \t Distance" << endl;
    for (int i = 0; i < vn; i++)
    { //printing MST obtained using Prims Algorithm
        cout << endl;
        cout << str[i] << "\t\t";
        cout << str[path[i]] << "\t";
        cout << dist[i] << "\t";
        cost = cost + dist[i];
    }
    cout << endl
         << "Total Cost= " << cost << endl;
}
void Graph::sort()
{
    bool swapped = false;
    for (int i = 0; i < en; i++)
    {
        for (int j = 0; j < en - i - 1; j++)
        {
            if (edge[j].wt > edge[j + 1].wt)
            {
                swap(edge[j], edge[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}
void Graph::kruskals()
{
    cout << "Edges are:" << endl;
    cout << "U V Weight" << endl;
    for (int i = 0; i < en; i++)
        cout << edge[i].u << " " << edge[i].v << " " << edge[i].wt << endl;
    //cout<<"After sorting:"<<endl;
    sort();
    int connt[en];
    int val = 1, s, l;
    int cnt = 0;
    int j = 0;
    Edge temp[20];
    cout << endl
         << "================================================================="
         << endl;
    while (cnt < en - 1 && j < en)
    {
        //if both vertices are not visited
        if (connt[edge[j].u] == 0 && connt[edge[j].v] == 0)
        {
            cout << "Edge selected:" << edge[j].u << " " << edge[j].v << " " << edge[j].wt << endl;
            temp[cnt] = edge[j];
            connt[edge[j].u] = connt[edge[j].v] = val;
            val++;
            cnt++;
        }
        //if both vertices have different connection value
        else if (connt[edge[j].u] != connt[edge[j].v])
        {
            cout << "Edge selected:" << edge[j].u << " " << edge[j].v << " " << edge[j].wt << endl;
            temp[cnt] = edge[j];
            //if both vertices are visited
            if (connt[edge[j].u] != 0 && connt[edge[j].v] != 0)
            {
                //replace smaller connt value among both with grater one
                //if first vertex is having less connt value
                if (connt[edge[j].u] < connt[edge[j].v])
                {
                    s = connt[edge[j].u];
                    l = connt[edge[j].v];
                }
                //if connt value of second is less
                else
                {
                    s = connt[edge[j].v];
                    l = connt[edge[j].u];
                }
                //replace large value with smaller
                for (int i = 0; i < en; i++)
                {
                    if (connt[i] == l)
                        connt[i] = s;
                }
                cnt++;
            }
            //if only first vertex is visited
            else if (connt[edge[j].u] != 0 && connt[edge[j].v] == 0)
            {
                connt[edge[j].v] = connt[edge[j].u];
                cnt++;
            }
            //if only second vertex is visited
            else
            {
                connt[edge[j].u] = connt[edge[j].v];
                cnt++;
            }
        }
        //if both vertices have same connt values, reject it
        else
            cout << "Edge Rejected:" << edge[j].u << " " << edge[j].v << " " << edge[j].wt << endl;
        j++;
    }
    cout << endl
         << "================================================================="
         << endl;
    cout << "Minimum spanning tree with kruskal's algorithm:" << endl;
    int cost = 0;
    cout << "Dept1\tDept2\tWeight" << endl;
    for (int i = 0; i < cnt; i++)
    {
        cout << str[temp[i].u] << "\t" << str[temp[i].v] << "\t" << temp[i].wt
             << endl;
        cost += temp[i].wt;
    }
    cout << endl
         << "Total cost:" << cost;
}
void Graph::display()
{
    cout << endl
         << "Matrix is:" << endl;
    for (int i = 0; i < vn; i++)
    {
        cout << " ";
        for (int j = 0; j < vn; j++)
        {
            cout << weight[i][j] << " ";
        }
        cout << endl;
    }
}
using namespace std;
int main()
{
    cout << "Minimum spanning tree" << endl;
    Graph g;
    g.create();
    g.display();
    while (true)
    {
        int ch;
        cout << endl
             << " 1 : MST with Prim's Algoritm" << endl
             << " 2 : MST with Kruskal's Algorithm " << endl
             << " 3 : Display Original Graph " << endl
             << " 4 : Exit " << endl;
        cout << "enter choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            g.prims();
            break;
        case 2:
            g.kruskals();
            break;
        case 3:
            g.display();
            break;
        case 4:
            return 0;
        }
    }
    return 0;
}