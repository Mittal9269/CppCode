#include <bits/stdc++.h>
using namespace std;

// #define V 50000

// int graph[V][V];

int minDistance(vector<int>dist, bool sptSet[] , int N){
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

vector<int> dijkstra(vector<int>graph[] , int src , int N)
{
    vector<int>dist; 
    bool sptSet[N]; 
    for (int i = 0; i < N; i++)
        dist.push_back(INT_MAX), sptSet[i] = false;
    dist[src] = 0;
    for (int count = 0; count < N - 1; count++) {
        int u = minDistance(dist, sptSet , N);
        sptSet[u] = true;
        for (int v : graph[u])
            if (!sptSet[v] && dist[u] != INT_MAX
                && dist[u] + 1 < dist[v])
                dist[v] = dist[u] + 1;
    }
    return dist;
}

// driver program to test above function
int main()
{
    int c, cc , ccc , N , M; cin>>c>>cc>>ccc>>N>>M;
    // int graph[V][V];
    vector<int>graph[N];
    for(int i=0; i<M ; i++){
        int a, b; cin>>a>>b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }
    vector<int>male , female , couple;
    male = dijkstra(graph , 0 , N);
    female = dijkstra(graph, 1 , N );
    couple = dijkstra(graph, N-1 , N);
    int result = INT_MAX;
    for(int i=0; i<N; i++){
        result = min(result , c*male[i] + cc*female[i] + ccc*couple[i]);
    }
    cout<<result<<"\n";
    return 0;
}
