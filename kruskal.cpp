#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct edge 
{
    int src;
    int des;
    int weight;
};

// struct compare
// {
//     bool operator() (edge const &a, edge const &b) const {
//         return a.weight > b.weight;
//     }
// };

bool compare(edge a,edge b){
    return a.weight > b.weight;
}

class DisjointSet{
    vector<int>parent;
public:
    DisjointSet(int n){
        parent.resize(n);
        makeSet();
    }
    void makeSet(){
        for(int i = 0;i < parent.size();i++){
            parent[i] = i;
        }
    }

    int find(int k){
        if(parent[k] == k){
            return k;
        }
        return find(parent[k]);
    }

    void Union(int x,int y){
        int xset = find(x);
        int yset = find(y);

        parent[y] = x;
    }
};

vector<edge> runKruskal(vector<edge> edges,int v) {
    DisjointSet ds(v);
    vector<edge>MST;
    sort(edges.begin(), edges.end(), compare);

    while(MST.size()!=v-1){ // as we know if the number of vertices is v, then number of edges in mst will be v - 1
        edge next_edge = edges.back();
        edges.pop_back();

        int xset = ds.find(next_edge.src);
        int yset = ds.find(next_edge.des);

        if(xset != yset){
            MST.push_back(next_edge);
            ds.Union(xset, yset);
        }
    }
    return MST;
}

int main()
{
    int v = 7;
    vector<edge> edges =
    {
        {0, 1, 7}, {1, 2, 8}, {0, 3, 5}, {1, 3, 9}, {1, 4, 7}, {2, 4, 5},
        {3, 4, 15}, {3, 5, 6}, {4, 5, 8}, {4, 6, 9}, {5, 6, 11}
    };

    vector<edge>MST = runKruskal(edges,v);

    for(auto &e : MST){
        cout<<e.src<<" "<<e.des<<" "<<e.weight<<endl;
    }
    return 0;
}