// #include "ds.h"
// using namespace std;

// /// List

// template<class T>
// void List<T>::pushback(T val){
// 	ListNode<T>* m=new ListNode<T>(val);
// 	ListNode<T>* g=List<T>::head;
// 	if(List<T>::isEmpty()){
// 		List<T>::head=m;
// 		List<T>::size_t++;
// 		return;
// 	}
// 	while(g->next)
// 		g=g->next;
// 	g->next=m;
// 	List<T>::size_t++;
// 	// tail=m;
// }

// template<class T>
// void List<T>::pushfront(T val){
// 	ListNode<T>* m=new ListNode<T>(val);
// 	ListNode<T>* g=List<T>::head;
// 	if(List<T>::isEmpty()){
// 		List<T>::head=m;
// 		List<T>::size_t++;
// 		return;
// 	}
// 	m->next=List<T>::head;
// 	List<T>::head=m;
// 	List<T>::size_t++;
// }

// template<class T>
// void List<T>::pop(T val){
// 	ListNode<T>* g=List<T>::head;
// 	if(List<T>::head->val==val){
// 		List<T>::head=List<T>::head->next;
// 		List<T>::size_t--;
// 		return;
// 	}
	
// 	while(g->next)
// 		if((g->next)->val==val)
// 		{
// 			//delete[] g->next;
// 			g->next=(g->next)->next;
// 			List<T>::size_t--;
// 			return;
// 		}
// 		else
// 			g=g->next;
// }

// template<class T>
// bool List<T>::isEmpty(){
// 	return (List<T>::size_t==0);
// }

// template<class T>
// int List<T>::size(){
// 	return size_t;
// }

// template<class T>
// bool List<T>::contains(T rhs){
// 	if(List<T>::isEmpty())
// 		return false;
// 	ListNode<T>* g=List<T>::head;
// 	while(g->next)
// 		if(g->val==rhs)
// 			return true;
// 	return false;
// }

// template<class T>
// void List<T>::print(){
// 	if(List<T>::isEmpty())
// 		return;
// 	ListNode<T>* g=List<T>::head;
// 	while(g->next){
// 		cout<<g->val<<",";
// 		g=g->next;
// 	}
// 	cout<<g->val<<"\n"<<endl;

// }

// /// Stack

// template<class T>
// void stack<T>::push(T val){
// 	stack<T>::pushfront(val);
// }

// template<class T>
// T* stack<T>::pop(){
// 	if (stack<T>::head==NULL)
// 		return NULL;
// 	T* j=&(stack<T>::head->val);
// 	stack<T>::head=stack<T>::head->next;
// 	stack<T>::size_t--;
// 	return j;
// }


// /// BiList

// template<class T>
// void BiList<T>::pushback(T val){
// 	ListNode<T>* m=new ListNode<T>(val);
// 	ListNode<T>* g=BiList<T>::head;
// 	if(BiList<T>::isEmpty()){
// 		BiList<T>::head=m;
// 		BiList<T>::tail=m;
// 		BiList<T>::size_t++;
// 		return;
// 	}
// 	m->prev=ListNode<T>::tail;
// 	(ListNode<T>::tail)->next=m;
// 	ListNode<T>::tail=m;
// 	BiList<T>::size_t++;
// }

// template<class T>
// void BiList<T>::pushfront(T val){
// 	ListNode<T>* m=new ListNode<T>(val);
// 	ListNode<T>* g=BiList<T>::head;
// 	if(BiList<T>::isEmpty()){
// 		BiList<T>::head=m;
// 		BiList<T>::tail=m;
// 		BiList<T>::size_t++;
// 		return;
// 	}
// 	m->next=BiList<T>::head;
// 	(BiList<T>::head)->prev=m;
// 	BiList<T>::head=m;
// 	BiList<T>::size_t++;
// }

// template<class T>
// void BiList<T>::pop(T val){
// 	ListNode<T>* g=BiList<T>::head;

// 	if(BiList<T>::head->val==val){
// 		BiList<T>::head=BiList<T>::head->next;
// 		(BiList<T>::head)->prev=NULL;
// 		BiList<T>::size_t--;
// 		return;
// 	}
	
// 	while(g->next)
// 		if(g->val==val)
// 		{
			
// 			(g->prev)->next=g->next;
// 			(g->next)->prev=(g->prev);
// 			//delete[] g->next;
// 			BiList<T>::size_t--;
// 			return;
// 		}
// 		else
// 			g=g->next;
// }

// /// Queue

// template<class T>
// void queue<T>::enque(T val){
// 	queue<T>::pushfront(val);
// }

// template<class T>
// T* queue<T>::deque(){
// 	if (queue<T>::isEmpty()){
// 		return NULL;
// 	}
// 	T* j=&(queue<T>::tail->val);
// 	if (queue<T>::tail->prev)
// 		(queue<T>::tail->prev)->next=NULL;
// 	queue<T>::tail=queue<T>::tail->prev;
// 	queue<T>::size_t--;
// 	if(queue<T>::isEmpty())
// 		queue<T>::head=NULL;
// 	return j;
// }

// /// Graph

// template<class T>
// void graph<T>::createNode(string nm,T val){
// 	GraphNode<T>* y=new GraphNode<T>(nm,val);
// 	nodes[nm]=y;
// }

// // template<class T>
// // void graph<T>::removeNode(string nm){
// // 	delete[] nodes[nm];
// // 	nodes.erase(nm);
// // }

// template<class T>
// void graph<T>::removeNode(string nm){
// 	if (nodes.find(nm) == nodes.end())
// 	{
// 		cout<<"Node doesn't exist"<<endl;
// 		return;
// 	}
// 	nodes.erase(nm);
// }

// template<class T>
// void graph<T>::addDirectedEdge(string a,string b,float d){
// 	if (nodes.find(a) == nodes.end() || nodes.find(b) == nodes.end())
// 	{
// 		cout<<"Node doesn't exist"<<endl;
// 		return;
// 	}
// 	nodes[a]->nbrs.push_back(nodes[b]);
// 	nodes[a]->edges[b]=d;
// }

// template<class T>
// void graph<T>::addUndirectedEdge(string a,string b,float d){
// 	if (nodes.find(a) == nodes.end() || nodes.find(b) == nodes.end())
// 	{
// 		cout<<"Node doesn't exist"<<endl;
// 		return;
// 	}
// 	nodes[a]->nbrs.push_back(nodes[b]);
// 	nodes[a]->edges[b]=d;

// 	nodes[b]->nbrs.push_back(nodes[a]);
// 	nodes[b]->edges[a]=d;
// }

// template<class T>
// void graph<T>::removeEdge(string a,string b){
// 	if (nodes.find(a) == nodes.end() || nodes.find(b) == nodes.end())
// 	{
// 		cout<<"Node doesn't exist"<<endl;
// 		return;
// 	}
// 	for(int i=0;i<nodes[a]->nbrs.size();i++)
// 		if(((nodes[a])->nbrs[i])->id==b){
// 			(nodes[a])->nbrs.erase(i);
// 			(nodes[a])->edges.erase(b);
// 		}
// 	for(int i=0;i<nodes[b]->nbrs.size();i++)
// 		if(((nodes[b])->nbrs[i])->id==a){
// 			(nodes[b])->nbrs.erase(i);
// 			(nodes[b])->edges.erase(a);
// 		}
// }

// template <class T>
// void graph<T>::print(){
// 	for (auto const& p : graph<T>::nodes)
// 	{
// 	    cout << *(p.second) << '\n';
// 	}
// }

// template<class T>
// void printNode(GraphNode<T>* gn){
// 	cout <<gn->id<<":"<< gn->val<<'\n';
// }

// template<class T>
// graph<T>::graph(const graph& g)
// {
// 	for(auto const& node:g.nodes)
// 		nodes[node->id]=new GraphNode<T>(node->id,node->val);
// }

// template<class Y>
// void T(){
// 	map<string,GraphNode<Y>*> nodes_;
// 	for(auto const& node:graph<Y>::nodes) // for all nodes in this or g_
// 		for(GraphNode<Y>* nbr:graph<Y>::nbrs) // for each nbr in nbrs of node 
// 		{
// 			nodes_[nbr->id]->nbrs.push_back(node);
// 			nodes_[nbr->id]->edges[node->id]=node->edges[nbr->id];
// 		}
// 	graph<Y>::nodes=nodes_;
// }