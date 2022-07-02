#include "algorithms.h"
#include "ds.h"

int main(){
	// queue<int> l;
	// l.enque(1);
	// l.enque(2);
	// cout<<(*l.deque())<<endl;
	// cout<<(*l.deque())<<endl;

	graph<int> g;
	g.createNode("a",INF);
	g.createNode("b",INF);
	g.createNode("c",INF);
	g.createNode("d",INF);
	g.createNode("e",INF);
	g.addUndirectedEdge("a","b",6);
	g.addUndirectedEdge("b","c",5);
	g.addUndirectedEdge("a","d",1);
	g.addUndirectedEdge("b","d",2);
	g.addUndirectedEdge("b","e",2);
	g.addUndirectedEdge("e","d",1);
	g.addUndirectedEdge("e","c",5);

	// stack<GraphNode<int>*> stk;
	// stk.push(g.nodes["a"]);
	// map<string,bool> visited;
	// dfs(&stk,&visited,&printNode);

	// queue<GraphNode<int>*> q;
	// q.enque(g.nodes["a"]);
	// bfs(&q,&visited,&printNode);

	// map<string,string> parent;
	// djikstra(&g,"a","c",&parent);
	// string cur="b";
	// while(cur!="a"){
	// 	cout<<parent[cur]<<"-";
	// 	cur=parent[cur];
	// }
}