#include "ds.h"

/// Sorting

template<class T>
void quicksort(vector<T>* arr);

template<class T>
void mergesort(vector<T>* arr);


/// Trees

template<class T>
void minHeapify(vector<T>* arr,int root);

template<class T>
void push_to_heap(vector<T>* arr,T* obj);

template<class T>
T pop_from_heap(vector<T> * arr);


/// Graph Algorithms

template<class T>
void dfs(stack<GraphNode<T>*>* stk_ptr,map<string,bool>* visited,void (*process)(GraphNode<T>*));

template<class T>
void bfs(queue<GraphNode<T>*>* q_ptr,map<string,bool>* visited,void (*process)(GraphNode<T>*));

template <class T>
void djikstra(graph<T>* g,string start,string goal,map<string,string>* parent);

template <class T>
void topological_sort(graph<T>* g,stack<T>* stk_ptr);

template <class T>
void findSCC(graph<T>* g,vector<vector<GraphNode<T>*>>* scc_list);