#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int minKey(bool mstSet[],int key[],int n){
    int min=INT_MAX,ind;
    for(int v=0;v<n;v++){
            if(mstSet[v]==false && key[v]<min){
                min=key[v] ;ind=v;
            }
        }
        return ind;
}

int main(){

    int n,m;
    cin>>n>>m;
    cout<<"Enter number of vertices and edges in graph :";
    vector<pair<int,int>> adj[n];
    for(int i=0;i<m;i++){
        cout<<"enter end points of edge "<<i+1<<" and its weight :";
        int a,b,wt;
        cin>>a>>b>>wt;
        adj[a].push_back(make_pair(b,wt));
        adj[b].push_back(make_pair(a,wt));
    }
    int parent[n];
    int key[n];
    bool mstSet[n];

    for(int i=0;i<n;i++){
        key[i]=INT_MAX;
        mstSet[i]=false;
        parent[i]=-1;
    }

    key[0]=0;

    for(int i=0;i<n-1;i++){
        
        int ind=minKey(mstSet,key,n);
        mstSet[ind]=true;

        for(auto it:adj[ind]){
            int v=it.first;
            int weight=it.second;
            if(mstSet[v]==false && weight<key[v]){//key[v]=its weight with
            parent[v]=ind;key[v]=weight;
            }
        }
    }

    int cost=0;
    for(int i=1;i<n;i++){
            cost+=key[i];
            cout<<parent[i]<<"->"<<i<<"\n";
        }
    cout<<"The cost of minimum spanning tree is :"<<cost;
}