#include<iostream>
#include<climits>
#define v 10
using namespace std;

class dijkstras{
    
    int n;int m;
    int graph[v][v]={0};
    int dist[v];
    int sptSet[v];
    string cityArr[v];

    public:
    void createGraph();
    void dijkstra();
    void printDijkstra();
    void assignNames();
};

void dijkstras::dijkstra(){
    for(int i=0;i<n;i++){//initialization
        dist[i]=INT_MAX;
        sptSet[i]=false;
    }
    dist[0]=0;
    for(int i=0;i<n;i++){//for each vertex
        int minDist=INT_MAX;int u;
        for(int i=0;i<n;i++){//find minimum distance for those who are not in sptset and with minimum distance among them
            if(sptSet[i]==false && dist[i]<minDist){
                minDist=dist[i];
                u=i;
            }
        }
        sptSet[u]=true;
        for(int i=0;i<n;i++){//most imp loop
            if(sptSet[i]==false && graph[u][i] && dist[u]!=INT_MAX && dist[u]+graph[i][u]<dist[i]){//here we are checking if graph[u][i] exists
                dist[i]=dist[u]+graph[u][i];//grsph[u][i] adjacent nodes of u
            }
        }
    }
}

void dijkstras::createGraph(){
    cout<<"Enter the vertices of edge and cost of that edge one by one : \n";
    for(int i=0;i<m;i++){
        int a;int b;int wt;
        cin>>a>>b>>wt;
        graph[a][b]=wt;
        graph[b][a]=wt;
    }
}

void dijkstras::printDijkstra(){
    for(int i=0;i<n;i++){
        cout<<cityArr[i]<<":"<<dist[i]<<endl;
    }
}

void dijkstras::assignNames(){
    cout<<"Enter total number of vertices (1 to 10) and edges:";
    cin>>n;cin>>m;
    cout<<"Assign city name to the given vertex"<<endl;
    for(int i=0;i<n;i++){
        cout<<"Vertex "<<i<<" :";
        cin>>cityArr[i];
    }
}

int main(){
    dijkstras djk;
    djk.assignNames();
    djk.createGraph();
    djk.dijkstra();
    djk.printDijkstra();
}

/*Enter the source vertex:- 1
Enter the destination vertex:- 2
Enter the weight of the graph:- 10
Inserted edge between 1 and 2*/