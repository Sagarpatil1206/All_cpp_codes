#include<iostream>
#include<climits>
#define v 10
using namespace std;

class kruskal{
    public:
    int n;int m;
    int graph[v][v]={INT_MAX};
    int parent[v];
    int findParent(int);
    void unionSet(int,int);
    void kruskalAlgo();
    void printKruskal();
    void createGraphAM();
};

int kruskal::findParent(int a){
    while(parent[a]!=a){
        a=parent[a];
    }
    return a;
}

void kruskal::unionSet(int i,int j){
    int a=findParent(i);
    int b=findParent(j);
    parent[a]=b;
}

void kruskal::kruskalAlgo(){
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    int edges=0;
    int mincost=0;
    while(edges<n-1){
        int minDist=INT_MAX;int a=-1;int b=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(findParent(i)!=findParent(j) && graph[i][j]<minDist){
                    minDist=graph[i][j];
                    a=i;b=j;
                }
            }
        }
        unionSet(a,b);
        mincost+=minDist;
        cout<<"Edges "<<edges<<":"<<a<<"-"<<b<<" "<<minDist<<endl;
        edges++;
    }
    cout<<"Mincost is "<<mincost<<endl;
}

void kruskal::createGraphAM(){
    cout<<"Enter the number of vertices and edges :";
    cin>>n>>m;
    cout<<"Enter verices of edges and it weight :"<<endl;
    for(int i=0;i<m;i++){
        int a,b,wt;
        cin>>a>>b>>wt;
        graph[a][b]=wt;
        graph[b][a]=wt;
    }
}

void kruskal::printKruskal(){
    for(int i=0;i<n;i++){
    cout<<parent[i]<<"-"<<i<<"-"<<graph[parent[i]][i]<<endl;
    }
}

int main(){
    kruskal krs;
    krs.createGraphAM();
    krs.kruskalAlgo();
    // krs.printKruskal();
}
/*
0 1 2
0 3 6
1 2 3
1 3 8
1 4 5
2 4 7
3 4 9
*/