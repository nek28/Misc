#include <iostream>
#include <list>
using namespace std;

//make an adjacency list from a list of edges
//number of vertices is given and the graph is simple
int main(){
    int num_vertices;
    cin >> num_vertices;

    list<int> *adjl = new list<int>[num_vertices];

    int edge1,edge2;
    //two because the graph is undirected
    while(cin >> edge1 >> edge2){
        adjl[edge1-1].push_back(edge2-1);
        adjl[edge2-1].push_back(edge1-1);
    }
    
    int index = 0;
    while(index < num_vertices){
        list<int>::iterator it;
        cout << index+1 << ": ";
        for(it = adjl[index].begin(); it != adjl[index].end(); ++it)
            cout << (*it) + 1 << " ";
        cout << endl;
        index++;
    }

    return 0;
}
