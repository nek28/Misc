#include <iostream>
#include <vector>
using namespace std;

//make a square matrix of size sz and initialize it to 0
int **sq_matrix(size_t sz){
    int **m = new int*[sz];
    for(int i = 0; i < sz; ++i){
        m[i] = new int[sz];
    }

    for(int i = 0; i < sz; ++i)
        for(int j = 0; j < sz; ++j)
            m[i][j] = 0;

    return m;
}

//fill in an edge in an undirected graph (two places in the adj. matrix)
//graph verteces begin from 1 and the graph is simple
void edge(int **matrix, size_t sz, int edge1, int edge2){
    if(edge1 <= sz && edge2 <= sz){
        matrix[edge1-1][edge2-1] = 1;
        matrix[edge2-1][edge1-1] = 1;
    }
}

//print a square matrix
void print_matrix(int **matrix, size_t sz){
    for(size_t i = 0; i < sz; ++i){
        for(size_t j = 0; j < sz; ++j){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

//get a list of edges and display the adjecency matrix
int main(){
    //the number of edges is given
    int num_edges;
    cin >> num_edges;

    //initialize the matrix
    int **M = sq_matrix(num_edges);

    vector<int> edges;
    int current;
    while(cin >> current)
        edges.push_back(current);
    
    for(int i = 0; i < edges.size(); i += 2)
        edge(M, num_edges, edges[i], edges[i+1]);
    
    print_matrix(M, num_edges);

    return 0;
}
