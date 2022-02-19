#include<iostream>
#include<vector>
using namespace std;

struct edge{
    int src;
    int des;
};

class DisjointSet{
private:
    int n;
    vector<int> parent;
public:
    DisjointSet(int n){
        this->n = n;
        parent.resize(n);
    }

    void makeSet(){
        for(int i = 0;i < n;i++){
            parent[i] = i;
        }
    }

    int find(int k){
        if(parent[k] != k){
            return find(parent[k]);
        }
        return parent[k];
    }

    void Union(int x,int y){
        int xset = find(x);
        int yset = find(y);

        parent[x] = y;
    }
};

class Graph{

public:
    int v;
    vector<vector<int>>adj;

    Graph(int v){
        this->v = v;
        adj.resize(v);
    }
    void add_edge(vector<edge> &edges){
        for(int i = 0;i < edges.size();i++){
            adj[edges[i].src].push_back(edges[i].des);
        }
    }
};

bool detect_cycle(Graph const &graph,int n){
    DisjointSet ds(n);
    ds.makeSet();
    // u v
    for(int u = 0;u < n;u++){
        for(auto& v : graph.adj[u]){
            int uset = ds.find(u);
            int vset = ds.find(v);

            if(uset == vset){
                return true;
            }
            else{
                ds.Union(uset,vset);
            }
            
        }
    }
    return false;
}


int main()
{
    int v = 5;
    Graph g1(v);
    vector<edge>Edges = 
    {
        {0, 1}, {1, 3}, {0, 3}
    };

    g1.add_edge(Edges);

    bool hasCycle = detect_cycle(g1,v);
    cout<<hasCycle<<endl;
    


    return 0;
}

