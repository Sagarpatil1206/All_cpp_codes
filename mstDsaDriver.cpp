#include<iostream>
#include "mstDsaPrimsImple.cpp"
#include "mstDsaKruskalImple.cpp"
#include "mstDsaHeader.h"

using namespace std;

int main(){

    kruskalClass obj1;

    for(int i=0;i<N;i++){
        obj1.make_set(i);//making all vertices as their own parents
    }

    cout<<"Enter number of vertices and edges :";
    int n,m;//n=number of vertices and m=number of edges
    cin>>n>>m;
    vector<vector<int>> edges;//to store values of edges
    string arrS[4];
    // arrS[4]={"Canteen","FE","Computer","IT"};
    cout<<"Enter vertices of edge and it's weight in a graphs one by one :";
    for(int i=0;i<m;i++){
        int wt,u,v;//current vertices of current edge
        cin>>u>>v>>wt;
        edges.push_back({wt,u,v});// weight and its vertices
    }

    obj1.kruskal(edges);

    int N,M;
    cout<<"Enter number of verices and edges in a graph :"<<endl;
	cin >> N >> M;
	vector<pair<int,int> > adj[N]; //making a adjancy list for storing graph

	
	for(int i = 0; i<M ; i++){
        int a,b,wt;
        cout<<"Enter end vertices of edge and its weught one by one :"<<endl;
		cin >> a >> b >> wt;
		adj[a].push_back(make_pair(b,wt));//making an adjancy list and including respective weight for
		adj[b].push_back(make_pair(a,wt));//particular edge as well
	}	

    prims obj2;

    obj2.primMST(N,adj);
}

/*
Enter number of vertices and edges :4 5
Enter vertices of edge and it's weight in a graphs one by one :1 2 15
0 2 5
3 1 2
3 2 40
0 1 10
Edges in kruskal's algorithm are :
3->1
0->2
0->1
The cost of minimum spanning tree is :17


Enter number of verices and edges in a graph :
4 5
Enter end vertices of edge and its weught one by one :
1 2 15
Enter end vertices of edge and its weught one by one :
0 2 5
Enter end vertices of edge and its weught one by one :
3 1 2
Enter end vertices of edge and its weught one by one :
3 2 40
Enter end vertices of edge and its weught one by one :
0 1 10
0 - 1 
0 - 2
1 - 3
Weight of minimum spaning tree is :17
*/