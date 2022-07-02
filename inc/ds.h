#ifndef __DS_H__
#define __DS_H__

#include <iostream>
#include <vector>
#include <map>
#include <limits>
using namespace std;

#define INF numeric_limits<int>::max()
////////////////////////////////////////////////////////////////////

// Node class Templates
template<class T>
struct ListNode{
  T val;
  ListNode<T>* next;
  ListNode<T>* prev;
  ListNode(T f):val(f){}
};

template<class T>
ostream& operator<< (std::ostream &out, const ListNode<T>& data) {
    out << data.val;
    return out;
}

template <class T>
struct GraphNode{
  T val;
  string id;
  vector<GraphNode<T>*> nbrs;
  map<string,float> edges;
  GraphNode(string nm,T f):val(f),id(nm){}
};

template<class T>
ostream& operator<< (std::ostream &out, const GraphNode<T>& data) {
    out <<data.id<<":"<< data.val<<'\n';
    for (auto const& p : data.edges)
    {
        out << data.id<<"--"<<p.first <<":"<< p.second << '\n';
    }
    return out;
}


/////////////////////////////////////////////////////////////////////////

// Linked List
template <class T>
class List{
  public:
    ListNode<T>* head;
    void pushback(T val){
      ListNode<T>* m=new ListNode<T>(val);
      ListNode<T>* g=head;
      if(isEmpty()){
        head=m;
        size_t++;
        return;
      }
      while(g->next)
        g=g->next;
      g->next=m;
      size_t++;
      // tail=m;
    }

    void pushfront(T val){
      ListNode<T>* m=new ListNode<T>(val);
      ListNode<T>* g=head;
      if(isEmpty()){
        head=m;
        size_t++;
        return;
      }
      m->next=head;
      head=m;
      size_t++;
    }

    void pop(T val){
      ListNode<T>* g=head;
      if(head->val==val){
        head=head->next;
        size_t--;
        return;
      }
      
      while(g->next)
        if((g->next)->val==val)
        {
          //delete[] g->next;
          g->next=(g->next)->next;
          size_t--;
          return;
        }
        else
          g=g->next;
    }

    bool isEmpty(){
      return (this->size_t==0);
    }

    int size(){
      return size_t;
    }

    bool contains(T rhs){
      if(isEmpty())
        return false;
      ListNode<T>* g=head;
      while(g->next)
        if(g->val==rhs)
          return true;
      return false;
    }

    void print(){
      if(isEmpty())
        return;
      ListNode<T>* g=head;
      while(g->next){
        cout<<g->val<<",";
        g=g->next;
      }
      cout<<g->val<<"\n"<<endl;

    }
  protected:
    int size_t=0;
};


// Bidirectional List
template <class T>
class BiList:public List<T>{
  public:
    ListNode<T>* tail;

    void pushback(T val){
      ListNode<T>* m=new ListNode<T>(val);
      ListNode<T>* g=this->head;
      if(this->isEmpty()){
        this->head=m;
        tail=m;
        this->size_t++;
        return;
      }
      m->prev=tail;
      (tail)->next=m;
      tail=m;
      this->size_t++;
    }

    void pushfront(T val){
      ListNode<T>* m=new ListNode<T>(val);
      ListNode<T>* g=this->head;
      if(this->isEmpty()){
        this->head=m;
        tail=m;
        this->size_t++;
        return;
      }
      m->next=this->head;
      (this->head)->prev=m;
      this->head=m;
      this->size_t++;
    }

    void pop(T val){
      ListNode<T>* g=this->head;

      if(this->head->val==val){
        this->head=this->head->next;
        (this->head)->prev=NULL;
        this->size_t--;
        return;
      }
      
      while(g->next)
        if(g->val==val)
        {
          
          (g->prev)->next=g->next;
          (g->next)->prev=(g->prev);
          //delete[] g->next;
          this->size_t--;
          return;
        }
        else
          g=g->next;
    }
};

// Stack
template<class T>
class stack:public List<T>{
  public:
    void push(T val){
      pushfront(val);
    }

    T* pop(){
      if (this->head==NULL)
        return NULL;
      T* j=&(this->head->val);
      this->head=this->head->next;
      this->size_t--;
      return j;
    }
};

// Queue
template<class T>
class queue:public BiList<T>{
  public:
    void enque(T val){
      pushfront(val);
    }

    T* deque(){
      if (this->isEmpty()){
        return NULL;
      }
      T* j=&(this->tail->val);
      if (this->tail->prev)
        (this->tail->prev)->next=NULL;
      this->tail=this->tail->prev;
      this->size_t--;
      if(this->isEmpty())
        this->head=NULL;
      return j;
    }
};

//////////////////////////////////////////////////////////////////////////

template<class T>
class graph{
  public:
    map<string,GraphNode<T>*> nodes;
    graph(const graph& g){
      for(auto const& node:g.nodes)
        nodes[node->id]=new GraphNode<T>(node->id,node->val);
    }
    graph(){};
    void createNode(string nm,T val){
      GraphNode<T>* y=new GraphNode<T>(nm,val);
      nodes[nm]=y;
    }

    void removeNode(string nm){
      if (nodes.find(nm) == nodes.end())
      {
        cout<<"Node doesn't exist"<<endl;
        return;
      }
      nodes.erase(nm);
    }

    void addDirectedEdge(string a,string b,float d){
      if (nodes.find(a) == nodes.end() || nodes.find(b) == nodes.end())
      {
        cout<<"Node doesn't exist"<<endl;
        return;
      }
      nodes[a]->nbrs.push_back(nodes[b]);
      nodes[a]->edges[b]=d;
    }

    void addUndirectedEdge(string a,string b,float d){
      if (nodes.find(a) == nodes.end() || nodes.find(b) == nodes.end())
      {
        cout<<"Node doesn't exist"<<endl;
        return;
      }
      nodes[a]->nbrs.push_back(nodes[b]);
      nodes[a]->edges[b]=d;

      nodes[b]->nbrs.push_back(nodes[a]);
      nodes[b]->edges[a]=d;
    }

    void removeEdge(string a,string b){
      if (nodes.find(a) == nodes.end() || nodes.find(b) == nodes.end())
      {
        cout<<"Node doesn't exist"<<endl;
        return;
      }
      for(int i=0;i<nodes[a]->nbrs.size();i++)
        if(((nodes[a])->nbrs[i])->id==b){
          (nodes[a])->nbrs.erase(i);
          (nodes[a])->edges.erase(b);
        }
      for(int i=0;i<nodes[b]->nbrs.size();i++)
        if(((nodes[b])->nbrs[i])->id==a){
          (nodes[b])->nbrs.erase(i);
          (nodes[b])->edges.erase(a);
        }
    }

    void Transpose(){
      map<string,GraphNode<T>*> nodes_;
      for(auto const& node:graph<T>::nodes) // for all nodes in this or g_
        for(GraphNode<T>* nbr:graph<T>::nbrs) // for each nbr in nbrs of node 
        {
          nodes_[nbr->id]->nbrs.push_back(node);
          nodes_[nbr->id]->edges[node->id]=node->edges[nbr->id];
        }
      graph<T>::nodes=nodes_;
    }

    void print(){
      for (auto const& p : graph<T>::nodes)
      {
          cout << *(p.second) << '\n';
      }
    }
};


/// Utils

template<class T>
void printNode(GraphNode<T>* gn){
  std::cout <<gn->id<<":"<< gn->val<<'\n';
}

#endif




