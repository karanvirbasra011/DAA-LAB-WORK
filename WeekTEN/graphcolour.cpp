#include<iostream>
#include<chrono>
#include<cstdlib>
using namespace std;
using namespace std::chrono;

bool canColor(int node, int c, int adj[][20], int V, int colors[]){
    for(int i = 0; i < V; i++)
        if(adj[node][i] && c == colors[i]) return false;
    return true;
}

bool colorGraph(int node, int V, int adj[][20], int colors[], int numColors){
    if(node == V) return true;

    for(int c = 1; c <= numColors; c++){
        if(canColor(node, c, adj, V, colors)){
            colors[node] = c;
            if(colorGraph(node + 1, V, adj, colors, numColors)) return true;
            colors[node] = 0;
        }
    }
    return false;
}

int main(){
    int lo = 4, hi = 18, gap = 1, runs = 3;
    int numColors = 3;
    for(int i = lo; i <= hi; i+=gap){
        int adj[20][20] = {0};
        // Generate random sparse graph
        for(int r = 0; r < i; r++){
            for(int c = r+1; c < i; c++){
                if(rand() % 3 == 0){
                    adj[r][c] = 1;
                    adj[c][r] = 1;
                }
            }
        }
        int colors[20] = {0};
        long long elapsed = 0;
        for(int j = 1; j <= runs; j++){
            for(int k = 0; k < 20; k++) colors[k] = 0;
            auto t1 = system_clock::now();
            volatile bool res = colorGraph(0, i, adj, colors, numColors);
            auto t2 = system_clock::now();
            elapsed += duration_cast<nanoseconds>(t2-t1).count();
        }
        cout<<"Time for "<<i<<" vertices : "<<elapsed/runs<<"   nanoseconds "<<endl;
    }
    return 0;
}
