#include <iostream>
#include<vector>
using namespace std;
void adjacencyMatrix()
{
    int V, E;
    cout<<"Enter the vertices and edges"<<endl;
    cin>>V>>E;
    int matrix[V][V];
    for(int i = 0 ; i<V ; i++)
    {
        for(int j = 0 ; j<V ; j++) {
            matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < E; ++i) {
        cout<<"enter the first virtex and the second vertix"<<endl;
        int f, t;
        cin>>f>>t;
        matrix[f][t] = 1;
        matrix[t][f] = 1;
    }
    for(int i = 0 ; i<V ; i++)
    {
        for(int j = 0 ; j<V ; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

}
void addEdge(vector<int> adj[], int s, int d)
{
    adj[s].push_back(d);
    adj[d].push_back(s);
}

void printGraph(vector<int> adj[], int V)
{
    for (int v = 0; v < V; ++v) {
        cout << "\n Adjacency list of vertex " << v
             << "\n head ";
        for (auto x : adj[v])
            cout << "-> " << x;
        cout << endl;
    }
}



int main()
{
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    printGraph(adj, V);
}
