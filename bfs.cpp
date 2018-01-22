#include <iostream>
#include <list>
#include <queue>
using namespace std;

//make an adjacency list from a list of edges
//number of vertices is given and the graph is simple
int main(){
    int num_verteces;
    cin >> num_verteces;

    list<int> *adjl = new list<int>[num_verteces];

    int edge1,edge2;
    //two because the graph is undirected
    while((cin >> edge1 >> edge2)&&(edge1 != (-1))){
        adjl[edge1-1].push_back(edge2-1);
        adjl[edge2-1].push_back(edge1-1);
    }
    
    int index = 0;
    while(index < num_verteces){
        list<int>::iterator it;
        cout << index+1 << ": ";
        for(it = adjl[index].begin(); it != adjl[index].end(); ++it)
            cout << (*it) + 1 << " ";
        cout << endl;
        index++;
    }

    cout << endl << endl;
    //---------------------------------------------------------
    //BREATH-FIRST-SEARCH
    //the adjacency list is in adjl and the number of verteces
    //is num_verteces
    //0: not visited, 1: passed by, 2: completely checked, -1 no parent
    queue<int> to_visit;
    int start_vertex;
    cin >> start_vertex;

    int *visited = new int[num_verteces];
    int *parent = new int[num_verteces];

    for(int i = 0; i < num_verteces; ++i){
        visited[i] = 0;
        parent[i] = -1;
    }

    to_visit.push(start_vertex-1);
    cout << start_vertex-1 << endl;
    while(!(to_visit.empty())){
        int current = to_visit.front();
        to_visit.pop();
        visited[current]=2;

        list<int>::iterator itr;
        for(itr=adjl[current].begin(); itr != adjl[current].end(); ++itr){
            if(visited[*itr]==0){
                to_visit.push(*itr);
                visited[*itr]=1;
                parent[*itr]=current;
            }
        }

    }

    for(int i = 0; i < num_verteces; ++i){
        cout << visited[i] << "   ";
        cout << parent[i]+1 << endl;
    }

    return 0;
}
