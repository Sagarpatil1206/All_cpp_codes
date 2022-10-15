#include<bits/stdc++.h>
using namespace std;

class prims{
    public:
    void primMST(int,vector<pair<int,int> > []);
    void print_graph(int,int [],int []);
    int minKey(bool [],int [],int N);
};

void prims::primMST(int N,vector<pair<int,int> > adj[]){
    int parent[N]; //making parent array to store whose parent is who
      
    int key[N]; //its use to find minimum weighted edge in a selected region (cut)
      
    bool mstSet[N]; //checking if particular vertex is addded in a spanning tree or not
  
    for (int i = 0; i < N; i++) {
        key[i] = INT_MAX, mstSet[i] = false; 
    }//initializing all ,nodes as false and key as nearly infinity for our referance

    key[0] = 0; //as we are starting with vertex 0
    parent[0] = -1;//we will start from root vertex 0
    for (int count = 0; count < N - 1; count++)
    {
        int u=minKey(mstSet,key,N) ;         
        mstSet[u] = true; 
        
        for (auto it : adj[u]) {//iterating over all vertices to find out 
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v]) //updating the kry if we found another weight less than the existing one
                parent[v] = u, key[v] = weight; //updating parent and key of respective vertex
        }
            
    }
    print_graph(N,key,parent);

}

void prims::print_graph(int N,int key[],int parent[]){//printing the minimum spanning tree
    int cost=0;
    
    for(int i = 1; i < N; i++){
        cost+=key[i];//storing weight of minimum spanning tree
        cout << parent[i] << " - " << i <<" \n"; 
    }
    cout<<"Weight of minimum spaning tree is :"<<cost;
}

int prims::minKey(bool mstSet[],int key[],int N){
        int mini = INT_MAX; 
        int u;

        // Pick the minimum key vertex from the set of vertices not yet included in MST
        for (int v = 0; v < N; v++) {
            if (mstSet[v] == false && key[v] < mini) {
                mini = key[v], u = v; }
        }
        return u;
}

int main(){
	int N,m;
    cout<<"Enter number of verices and edges in a graph :"<<endl;
	cin >> N >> m;
	vector<pair<int,int> > adj[N]; //making a adjancy list for storing graph

	int a,b,wt;
	for(int i = 0; i<m ; i++){
        cout<<"Enter end vertices of edge and its weught one by one :"<<endl;
		cin >> a >> b >> wt;
		adj[a].push_back(make_pair(b,wt));//making an adjancy list and including respective weight for
		adj[b].push_back(make_pair(a,wt));//particular edge as well
	}	

    prims obj2;

    obj2.primMST(N,adj);
	
}
// Enter number of verices and edges in a graph :
// 4 5
// Enter end vertices of edge and its weught one by one :
// 1 2 15
// Enter end vertices of edge and its weught one by one :
// 0 2 5
// Enter end vertices of edge and its weught one by one :
// 3 1 2
// Enter end vertices of edge and its weught one by one :
// 3 2 40
// Enter end vertices of edge and its weught one by one :
// 0 1 10
// 0 - 1 
// 0 - 2
// 1 - 3
// Weight of minimum spaning tree is :17