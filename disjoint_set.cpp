#include<iostream>
#include<vector>
using namespace std;

class DisjointSet{
private:
    int n; // no of items
    vector<int>parent;
    vector<int>rank;
public:

/**
 * rank array element  0 0 0 0 0 0
 *  index              0 1 2 3 4 5 
 * 
 * parent array element  0 1 2 3 4 5
 *  index                0 1 2 3 4 5
 */
    DisjointSet(int n){
        this->n = n;
        parent.resize(n);
        rank.assign(n,0); 
        makeSet();
    }
    // Initialization
    void makeSet(){
        for(int i = 0;i < parent.size();i++){
            parent[i] = i;
        }
    }

    int find(int k){
        if(parent[k] != k){
            parent[k] = find(parent[k]);
        }  // path compression

        return parent[k];

    }

    void Union(int x,int y){
        int xset = find(x);
        int yset = find(y);

        if(xset == yset) {  // it means they belong to same set
            return;
        }

        if(rank[xset] < rank[yset]){
            parent[xset] = yset;
        }
        else if(rank[xset] > rank[yset]){
            parent[yset] = xset;
        }
        else{
            
            parent[yset] = xset;
            rank[xset]++;
        }
    }

    void printParents(){
        for(int i = 0;i < parent.size();i++){
            cout<<i<<" ";
        }
        cout<<endl;
        for(int i = 0;i < parent.size();i++){
            cout<<parent[i]<<" ";
        }
        cout<<endl<<endl;
    }

};
int main()
{

    DisjointSet obj(5);
    obj.printParents();
    obj.Union(2,3);
    obj.printParents();
    obj.Union(0,1);
    obj.printParents();
    obj.Union(2,0);
    obj.printParents();
    cout<<endl;
    cout<<obj.find(1)<<endl;
    obj.printParents();
    
    return 0;
}