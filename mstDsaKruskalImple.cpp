#include<iostream>
#include "mstDsaHeader.h"
using namespace std;

void kruskalClass::make_set(int v){//here at first we will assign value of parennt to each vertex id]s of thesmselves at start
    parent[v]=v;//art first size will be 1 of every vertex
    size[v]=1;
}

int kruskalClass::find_set(int v){//here we are finding the set for particular vertex
    if(parent[v]==v){//only if its staring vertex or not yet included
        return v;
    }
    parent[v]=find_set(parent[v]);
    return parent[v];//returning parent
}

void kruskalClass::union_set(int a,int b){//making union of that two vertices which are making
    a=find_set(a);//finding their parents and store in it
    b=find_set(b);
    if(a!=b){//that is their parents are not same
        if(size[a]<size[b]){//we will be joining smaller set to bigger one as it will reduce t.c.
            swap(a,b);
        }
        parent[b]=a;//making parent of b as a
        size[a]+=size[b];
    }
}

void kruskalClass::kruskal(vector<vector<int>> edges){

    sort(edges.begin(),edges.end());//sprting all the edges according to there weights

    bool cycle=false;//initializing xycle to false
    int cost=0;//initial cost will be 0
    cout<<"Edges in kruskal's algorithm are :\n";
    for(auto i:edges){//iterating over the edges
        int wt=i[0];
        int u=i[1];
        int v=i[2];
        int x=find_set(u);
        int y=find_set(v);//finding their sets or parents
        if(x==y){//if they have same parent there will be a cycle so we will not include it
            continue;
        }else{//no cycle condition
            cout<<u<<"->"<<v<<endl;
            cost+=wt;
            union_set(u,v);
        }
    }
    
    cout<<"The cost of minimum spanning tree is :"<<cost;
}