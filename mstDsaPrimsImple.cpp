#include "mstDsaHeader.h"
#include<limits>

void prims::primMST(int N,vector<pair<int,int> > adj[]){
    int parent[N]; //making parent array to store whose parent is who
      
    int key[N]; //its use to find minimum weighted edge in a selected region (cut)
      
    bool mstSet[N]; //checking if particular vertex is addded in a spanning tree or not
  
    for (int i = 0; i < N; i++) {
        key[i] = INT8_MAX, mstSet[i] = false; 
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
        int mini = INT8_MAX; 
        int u;

        // Pick the minimum key vertex from the set of vertices not yet included in MST
        for (int v = 0; v < N; v++) {
            if (mstSet[v] == false && key[v] < mini) {
                mini = key[v], u = v; }
        }
        return u;
}