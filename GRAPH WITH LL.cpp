/* * C++ Program to Implement Adjacency List Graph Implementationn UNDIRECTED */
#include <iostream>
#include <cstdlib>
using namespace std;
/* * Adjacency List Node */ 
struct AdjListNode
{
    int data;
    int wt;
    struct AdjListNode* next;
};
/* * Adjacency List */  
struct AdjList
{
    struct AdjListNode *head;
};
/* * Class Graph */ 
class Graph
{
    private:
        int V;
        AdjList* array; 
    public:
        Graph(int V)
        {
            this->V = V;
            array = new AdjList [V];		 //total vertices
            for (int i = 0; i < V; ++i)
                array[i].head = NULL;  
//linking head of all vertices (array) to NULL ,it //doesn't store any number only stores //HEAD
        }
        /* * Adding Edge to Graph  */ 
       void addEdge(int src, int dest ,int edg)
        {	

        										// 0-->2

        										// 1-->NULL

        										// 2-->0
         // Add an edge from src to dest.  A new node is added to the adjacency
// list of src.  The node is added at the begining
        	AdjListNode* newNode = new AdjListNode;  //newNode stores both data(dest) and //*next pointer


            newNode->data = dest;          
            newNode->next = NULL;
			newNode->wt=edg;		
           	//adding nodes at beginning of each list just like in linked list//
            newNode->next = array[src].head;	
	//*next(of dst) storing address of head->next node i.e.. 1--->2 (first node from head)
            array[src].head = newNode;				//	0-->1-->2
	 // Since graph is undirected, add an edge from dest to src also
	newNode = new AdjListNode; 			 //now newNode storing data(src)
            newNode->data = src;				
            newNode->next = NULL;			// 0--->NULL
            newNode->next = array[dest].head;		// 0---->NULL (bcuz.. 1-->NULL)
            array[dest].head = newNode;			// 1---->0
        }
        /** Print the graph */ 
        void printGraph()
        {
            int v;
            for (v = 0; v < V; ++v)
            {
                AdjListNode* tmp = array[v].head;   //tmp has the address of (0,1..)vertex head 
                cout<<"\n Adjacency list of vertex "<<v<<"\n head ";
                while (tmp)
                {
                    cout<<"-> "<<tmp->data<<" wieght "<<tmp->wt;
                    tmp = tmp->next;
                }
                cout<<endl;
            }
        }

};


 /* * Main * */ 
int main()
{
    Graph gh(7);
        gh.addEdge(1, 6,10);
        gh.addEdge(1, 2,12);
        gh.addEdge(2,7,25);
		gh.addEdge(2,3,26);
		gh.addEdge(7,4,13);
		gh.addEdge(7,5,56);
		gh.addEdge(3,4,14);
		gh.addEdge(4,5,10);
		gh.addEdge(5,6,29);    
    // print the adjacency list representation of the above graph
    gh.printGraph();
    char ch;
    cout<<"DO YOU WANT A GREEDY STARTEGY USING PRIMS (y/n) "<<endl;
    cin>>ch;
    
    return 0;
}

