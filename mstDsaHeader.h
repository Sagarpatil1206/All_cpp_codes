#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>

using namespace std;

const int N=1e5+6;
vector<int> parent(N);//we declare parent vector of size N
vector<int> size(N);//storing the size of graph associated with the particular parent .

class kruskalClass{
    public:
    void make_set(int);
    int find_set(int);
    void union_set(int,int);
    void kruskal(vector<vector<int>>);
};

class prims{
    public:
    void primMST(int,vector<pair<int,int> > []);
    void print_graph(int,int [],int []);
    int minKey(bool [],int [],int n);
};