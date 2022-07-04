#include "algorithms.h"
#include "ds.h"

int main(){

	// queue
	cout<<" === QUEUE ==="<<endl;
	queue<int> l;
	cout<<"Pushing 1"<<endl;
	l.enque(1);
	cout<<"Pushing 2"<<endl;
	l.enque(2);
	cout<<"Popping "<<(*l.deque())<<endl;
	cout<<"Pushing 3"<<endl;
	l.enque(3);
	cout<<"Pushing -2"<<endl;
	l.enque(-2);
	l.print();
	cout<<"Size: "<<l.size()<<endl;
	cout<<"4 in queue? "<<l.contains(4)<<"\n"<<endl;

	// stack
	cout<<" === STACK ==="<<endl;
	stack<int> st;
	cout<<"Pushing 1"<<endl;
	st.push(1);
	cout<<"Pushing 2"<<endl;
	st.push(2);
	cout<<"Popping "<<(*st.pop())<<endl;
	cout<<"Pushing 3"<<endl;
	st.push(3);
	cout<<"Pushing -2"<<endl;
	st.push(-2);
	st.print();
	cout<<"Size: "<<st.size()<<endl;
	cout<<"4 in stack? "<<st.contains(4)<<"\n"<<endl;

	// graph
	cout<<" === GRAPH ALGORITHMS ==="<<endl;
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

	stack<GraphNode<int>*> stk;
	stk.push(g.nodes["a"]);
	map<string,bool> visited;
	dfs<int>(&stk,&visited,&printNode);

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