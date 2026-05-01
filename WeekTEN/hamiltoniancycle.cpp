#include<iostream>
#include<chrono>
#include<cstdlib>
#include<sstream>
using namespace std;
using namespace std::chrono;

bool isValid(int v, int pos, int adj[][20], int path[], int V){
    if(!adj[path[pos - 1]][v]) return false;

    for(int i = 0; i < pos; i++)
        if(path[i] == v) return false;
    return true;
}

bool findHamiltonian(int pos, int adj[][20], int path[], int V){
    if(pos == V){
        return adj[path[pos - 1]][path[0]] == 1;
    }

    for(int v = 1; v < V; v++){
        if(isValid(v, pos, adj, path, V)){
            path[pos] = v;
            if(findHamiltonian(pos + 1, adj, path, V)) return true;
            path[pos] = -1;
        }
    }
    return false;
}

int main(){
    int lo = 4, hi = 12, gap = 1, runs = 3;
    for(int i = lo; i <= hi; i+=gap){
        int adj[20][20];
        // Generate complete graph (guarantees hamiltonian cycle)
        for(int r = 0; r < i; r++)
            for(int c = 0; c < i; c++)
                adj[r][c] = (r != c) ? 1 : 0;
        // Remove some edges randomly to make it harder
        for(int r = 0; r < i; r++){
            for(int c = r+1; c < i; c++){
                if(rand() % 4 == 0 && i > 5){
                    adj[r][c] = 0;
                    adj[c][r] = 0;
                }
            }
        }
        int path[20];
        long long elapsed = 0;
        for(int j = 1; j <= runs; j++){
            for(int k = 0; k < 20; k++) path[k] = -1;
            path[0] = 0;
            streambuf* oldBuf = cout.rdbuf();
            ostringstream nullStream;
            cout.rdbuf(nullStream.rdbuf());
            auto t1 = system_clock::now();
            findHamiltonian(1, adj, path, i);
            auto t2 = system_clock::now();
            cout.rdbuf(oldBuf);
            elapsed += duration_cast<nanoseconds>(t2-t1).count();
        }
        cout<<"Time for "<<i<<" vertices : "<<elapsed/runs<<"   nanoseconds "<<endl;
    }
    return 0;
}
