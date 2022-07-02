#include "algorithms.h"

/// Sorting

template<class T>
void quicksort(vector<T>* arr,int start_idx,int end_idx){
	if (start_idx>=arr->size() || start_idx>=end_idx)
		return;
	int correct_idx=start_idx;
	T pivot=(*arr)[end_idx];

	// find correct idx for pivot
	for(int i=start_idx;i<end_idx;i++)
	{
		if((*arr)[i]->val<pivot->val)
		{	
			T temp=(*arr)[i];
			(*arr)[i]=(*arr)[correct_idx];
			(*arr)[correct_idx]=temp;
			correct_idx++;
		}
	}

	// place pivot in its position
	T temp=(*arr)[correct_idx];
	(*arr)[correct_idx]=(*arr)[end_idx];
	(*arr)[end_idx]=temp;

	// sort partitioned sub lists
	quicksort(arr,start_idx,correct_idx-1);
	quicksort(arr,correct_idx+1,end_idx);
}

template<class T>
void mergesort(vector<T>* arr,int start_idx,int end_idx){

}


/// Graph Algorithms

template <class T>
void dfs(stack<GraphNode<T>*>* stk_ptr,map<string,bool>* visited,void (*process)(GraphNode<T>*))
{
	if (stk_ptr->isEmpty())
		return;
	GraphNode<T>* current=*(stk_ptr->pop());
	(*visited)[current->id]=true;
	process(current);
	for(GraphNode<T>* nbr:current->nbrs){
		if(!(*visited)[nbr->id]){
			stk_ptr->push(nbr);
			dfs(stk_ptr, visited, process);
		}
	}
}

template <class T>
void bfs(queue<GraphNode<T>*>* q_ptr,map<string,bool>* visited,void (*process)(GraphNode<T>*))
{
	if (q_ptr->isEmpty())
		return;
	q_ptr->print();
	GraphNode<T>* current=*(q_ptr->deque());
	(*visited)[current->id]=true;
	// process(current);
	for(GraphNode<T>* nbr:current->nbrs){
		if(!(*visited)[nbr->id])
		{
			q_ptr->enque(nbr);
			(*visited)[nbr->id]=true;
		}
	}
	bfs(q_ptr, visited, process);
}

template<class T>
void minHeapify(vector<T>* arr,int root){
	if (root>=arr->size())
		return;
	
	int ln=2*root+1;
	int rn=2*root+2;
	minHeapify(arr,ln);
	minHeapify(arr,rn);
	if(2*root+1<arr->size() && (*arr)[root]->val>(*arr)[2*root+1]->val){
		T temp=(*arr)[root];
		(*arr)[root]=(*arr)[2*root+1];
		(*arr)[2*root+1]=temp;
		minHeapify(arr,2*root+1);
	}
	if(2*root+2<arr->size() && (*arr)[root]->val>(*arr)[2*root+2]->val){
		T temp=(*arr)[root];
		(*arr)[root]=(*arr)[2*root+2];
		(*arr)[2*root+2]=temp;
		minHeapify(arr,2*root+2);
	}
}

template <class T>
void push_to_heap(vector<T>* arr,T* obj){
	arr->push_back(*obj);
	T temp = (*arr)[0];
	(*arr)[0] = (*arr)[arr->size() - 1];
	(*arr)[arr->size() - 1] = temp;
	minHeapify<T>(arr,0);
}

template<class T>
T pop_from_heap(vector<T> * arr) {
	T temp = (*arr)[0];
	(*arr)[0] = (*arr)[arr->size() - 1];
	(*arr)[arr->size() - 1] = temp;
	(*arr).pop_back();
	minHeapify<T>(arr, 0);
	return temp;
}

template <class T>
void djikstra(graph<T>* g,string start,string goal,map<string,string>* parent){
	map<string,bool> visited;
	(g->nodes[start])->val=0;

	vector<GraphNode<T>*> arr;

	for(auto const& node:g->nodes)
		arr.push_back(node.second);
	
	minHeapify(&arr,0);

	while(visited.size()<g->nodes.size()){
		GraphNode<T>* current=pop_from_heap(&arr);//*(q_ptr.deque());
		
		for(GraphNode<T>* nbr:current->nbrs){
			if(nbr->val<0 || nbr->val>current->val+current->edges[nbr->id])
			{
				nbr->val=current->val+current->edges[nbr->id];
				(*parent)[nbr->id]=current->id;
			}

			if(!visited[nbr->id])
				visited[nbr->id]=true;
		}

		minHeapify(&arr,0);
	}
}

template<class T>
void topological_sort(graph<T>* g,stack<T>* stk_ptr){
	map<string,bool> visited;
	for(auto const& node:g->nodes){
		if (!visited[node->id]){
			stack<T> branch_stk;
			branch_stk.push(node);
			dfs(&branch_stk,&visited,&(stk_ptr->push));
		}
	}
}

template <class T>
void findSCC(graph<T>* g,vector<vector<GraphNode<T>*>>* scc_list){
	stack<GraphNode<T>*> stk;
	topological_sort(&g,&stk);
	g->T(); // transpose of graph
	map<string,bool> visited;
	while(!stk.isEmpty()){
		GraphNode<T>* h=*(stk.pop());
		if(visited[h]){
			stack<GraphNode<T>*> f;
			f.push(*h);
			vector<GraphNode<T>*> scc;
			dfs(&stk,&visited,&((&scc)->push_back));
			scc_list->push_back(scc);
		}
	}
	g->T();
}

