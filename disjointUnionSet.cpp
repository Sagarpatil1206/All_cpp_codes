#include<iostream>
#include<vector>
using namespace std;
const int N=1e5+6;
vector<int> parent(N);//we declare parent vector of size N
vector<int> size(N);

void make_set(int v){//here at first we will assign value of parennt to each vertex id]s of thesmselves at start
    parent[v]=v;//art first size will be 1 of every vertex
    size[v]=1;
}

int find_set(int v){//here we are finding the set 
    if(parent[v]==v){
        return v;
    }
    parent[v]=find_set(parent[v]);
    return parent[v];
}

void union_set(int a,int b){
    a=find_set(a);
    b=find_set(b);
    if(a!=b){
        if(size[a]<size[b]){
            swap(a,b);
        }
        parent[b]=a;
        size[a]+=size[b];
    }
}

int main(){

    for(int i=0;i<N;i++){
        make_set(i);
    }

    cout<<"Enter number of vertices and edges :";
    int n,m;//n=number of vertices and m=number of edges
    cin>>n>>m;
    vector<vector<int>> edges;
    cout<<"Enter vertices of edge in a graphs one by one :";
    for(int i=0;i<m;i++){
        int u,v;//current vertices of current edge
        cin>>u>>v;
        edges.push_back({u,v});
    }

    bool cycle=false;
    for(auto i:edges){
        int u=i[0];
        int v=i[1];
        int x=find_set(u);
        int y=find_set(v);
        if(x==y){
            cycle=true;
        }else{
            union_set(u,v);
        }
    }
    if(cycle){
        cout<<"Cycle is found"<<endl;
    }else{
        cout<<"Cycle is not found"<<endl;
    }
}

//for future referance 
//https://cp-algorithms.com/data_structures/disjoint_set_union.html