#include <iostream>
#include <list>
#include <map> 
using namespace std;

class Graph
{
    int numVertices;
    list<int> *adjLists;
    bool *visited;
   	map<char, int> map_no;
   	int g_index;
public:
    Graph(int V);
    void addEdge(char src, char dest);
    void DFS(char src);
};
 
Graph::Graph(int vertices)
{
    numVertices = vertices;
    adjLists = new list<int>[vertices];
    visited = new bool[vertices];
    g_index = 0;
}
 
void Graph::addEdge(char src, char dest)
{
	int src_i = 0;
	int dest_i = 0;
	map<char, int>::iterator 	map_iter = map_no.find(src);
	if(map_iter!=map_no.end()){
			src_i=map_no[src];
	}else{
			src_i=g_index;	
			map_no[src]=src_i;		
			g_index++;
	}
    map_iter = map_no.find(dest);
	if(map_iter!=map_no.end()){
			dest_i=map_no[dest];
	}else{
			dest_i=g_index;
			map_no[dest]=dest_i;
			g_index++;
	}
    //adjLists[src].push_back(dest);
  	adjLists[src_i].push_front(dest_i);
  	cout << __FUNCTION__ << __LINE__<<"  " <<src<<endl;
}
 
void Graph::DFS(char vertex)
{
    cout << __FUNCTION__ << __LINE__<<endl;
#if 1
    visited[map_no[vertex]]= true;
    list<int> adjList = adjLists[map_no[vertex]];
    
    cout << vertex << " "<<endl;
 
    list<int>::iterator i;
    for(i = adjList.begin(); i != adjList.end(); ++i){
    	
    	map<char, int>::iterator iter;
		iter = map_no.begin();
		while(iter != map_no.end()) {
			if(iter->second==*i)
				break;
		     iter++;
		}
    	
		cout << " visit " << iter->first << " "<<endl;
        if(!visited[iter->first])
            DFS(iter->first);   
	}
#endif	
}
 
int main()
{
    Graph g(7);
    g.addEdge('A','B');
    g.addEdge('A', 'C');
    g.addEdge('B', 'D');
    g.addEdge('B', 'E');
	g.addEdge('C', 'F');
	g.addEdge('C', 'G');
    g.DFS('A');
 
    return 0;
}
