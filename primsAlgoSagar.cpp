#include<iostream>
#include<climits>
#define v 10
using namespace std;


class prims{
    public:
    int n;
    int m;
    int graph[v][v]={0};
    bool sptSet[v];
    int dist[v];
    int parent[v];
    void primsAlgo();
    void createGraph();
    void printPrims();
};

void prims::primsAlgo(){
    for(int i=0;i<n;i++){
        parent[i]=-1;
        dist[i]=INT_MAX;
        sptSet[i]=false;
    }
    parent[0]=-1;
    dist[0]=0;

    for(int i=0;i<n;i++){//dont forget to apply this for loop
        int mindist=INT_MAX;int u;
        for(int i=0;i<n;i++){
            if(sptSet[i]==0 && dist[i]<mindist){
                mindist=dist[i];
                u=i;
            }
        }
        sptSet[u]=true;
        
        for(int i=0;i<n;i++){
            if(graph[u][i] && sptSet[i]==0 && graph[u][i]<dist[i]){
                dist[i]=graph[u][i];
                parent[i]=u;
            }
        }
    }
}

void prims::createGraph(){
    cout<<"Enter number of vertices and edges (1-10) :"<<endl;
    cin>>n>>m;
    cout<<"Enter vertices of edges one by one :"<<endl;
    for(int i=0;i<m;i++){
        int a,b,wt;
        cin>>a>>b>>wt;
        graph[a][b]=wt;
        graph[b][a]=wt;
    }
}

void prims::printPrims(){
    cout<<"Minimum spanning tree includes edges :\n";
    int mincost=0;
    for(int i=1;i<n;i++){
        cout<<parent[i]<<"-"<<i<<"-"<<graph[parent[i]][i]<<endl;
        mincost+=graph[parent[i]][i];
    }
    cout<<"Cost of minimum spanning tree is :"<<mincost<<endl;
}


int main(){
    prims prm;
    prm.createGraph();
    prm.primsAlgo();
    prm.printPrims();
}

/*
0 3 6
1 2 3
1 3 8
1 4 5
2 4 7
3 4 9
0 1 2
*/