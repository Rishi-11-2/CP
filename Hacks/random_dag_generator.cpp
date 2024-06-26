// A C++ Program to generate test cases for
// a weighted directed graph
#include <bits/stdc++.h>
using namespace std;

using namespace chrono;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long getRandomNumber(long long l,long long r){
    return uniform_int_distribution<long long>(l,r)(rng);
}

// Define the maximum number of vertices of the graph
#define MAX_VERTICES 1e5

// Define the maximum number of edges
#define MAX_EDGES 1e5

// Define the maximum weight of edges
#define MAXWEIGHT 1e9

int main()
{
    set<pair<int, int> > container;
    set<pair<int, int> >::iterator it;

    // Uncomment the below line to store
    // the test data in a file
    // freopen("Test_Cases_Directed_Weighted_Graph.in",
    //         "w", stdout);

    // For random values every time

    int NUM; // Number of Vertices
    int NUMEDGE; // Number of Edges

    NUM = getRandomNumber(1,MAX_VERTICES);

    // Define the maximum number of edges of the graph
    // Since the most dense graph can have N*(N-1)/2
    // edges where N = n number of vertices in the graph
    NUMEDGE = getRandomNumber(1,MAX_EDGES);

    int d=getRandomNumber(1,NUMEDGE);
    cout<<NUM<<" "<<NUMEDGE<<" "<<d<<endl;
    for (int j = 1; j <= NUMEDGE; j++) {
        int a = 1 + rand() % NUM;
        int b = 1 + rand() % NUM;
        pair<int, int> p = make_pair(a, b);

        // Search for a random "new" edge every time
        // Note - In a tree the edge (a, b) is same
        // as the edge (b, a)
        while (container.find(p) != container.end()) {
            a = getRandomNumber(1,NUM);
            b = getRandomNumber(1,NUM);
            p = make_pair(a, b);
        }
        container.insert(p);
    }

    for (auto it:container) {
        int wt = getRandomNumber(1,MAXWEIGHT);
        cout<<it.first<<" "<<it.second<<" "<<wt<<endl;
    }
    // Uncomment the below line to store
    // the test data in a file
    // fclose(stdout);
    return (0);
}
