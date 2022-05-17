/*
Sanket Ganesh Jhavar
Roll no.:21138
SE-1     F-1  Batch
*/
#include <iostream>
using namespace std;

class Node{
	int data;
	Node * next;
	public:
		Node()
		{
			this->data=0;
			this->next=NULL;
		}
		Node(int data)
		{
			this->data=data;
			this->next=nullptr;
		}
		friend class Graph;
		friend class Queue;
		friend class Stack;
};


class Queue{
	Node* front,*rear;
	public:
	Queue()
	{
		front = rear = nullptr;
	}
	void push(int data)
	{
		Node *new1 = new Node(data);
		if(!isEmpty())
		{
			rear->next = new1;
			rear = new1;
		}
		else
		{
			front = rear = new1;
		}
	}

	bool isEmpty()
	{
		return (front == nullptr);
	}

	int giveFront()
	{
		if(!isEmpty())
			return front->data;
		else cout<<"Queue underflow";
		return 0;
	}

	auto giveRear()
	{
		if(!isEmpty())
			return rear->data;
		else cout<<"Queue underflow";
		return 0;
	}

	void pop()
	{
		if(!isEmpty())
		{
			Node *current = front;
			front = front->next;
			delete current;
		}
	}

};

class Stack
{
	Node *top;
	public:
		Stack(){top = nullptr;}

		bool isEmpty(){return (top == NULL);}

		void push(int data)
		{
			Node *new1 = new Node(data);
			if(!isEmpty())
			{
				new1->next = top;
				top = new1;
			}
			else top = new1;
		}
		void pop()
		{
			if(!isEmpty())
			{
				Node *temp = top;
				top = top->next;
				delete temp;
			}
			else cout<<"Stack underflow"<<"\n";
		}
		int giveTop()
		{
			if(!isEmpty())
				return top->data;
			else cout<<"Stack underflow";
			return 0;
		}
};

class Graph{
	int vertices;
	int edges;
	Node **header;
	public:
		Graph(int v,int e)
		{
			vertices=v;
			edges=e;
			header = new Node*[vertices];
			for(int i=0;i<vertices;i++)
			{
				header[i]=NULL;
			}
		}

		void add(int source,int destination)
		{
			Node *n=new Node(destination);
			if(header[source]==nullptr)
			{
				header[source]= n;
			}
			else
			{
				Node *t=header[source];
				while(t->next!=nullptr)
				{
					t=t->next;
				}
				t->next=n;
			}
		}
		void acceptGraph()
		{
			for(int i=0;i<edges;i++)
			{
				int source,destination;
				cout<<"Enter the Source Vertex of Edge: ";
				cin>>source;
				cout<<"Enter the Destination Vertex of Edge ";
				cin>>destination;
				add(source,destination);
			}
		}
		void display()
		{
			for(int i=0;i<vertices;i++)
			{
				Node *t=header[i];
				cout<<"vertex "<<i<<":";
				while(t!=nullptr)
				{
					cout<<t->data<<" ";
					t=t->next;
				}
				cout<<endl;
			}
		}
		void bfs()
		{
			Queue q;
			int startingVertex=0;
			bool arr[vertices];
			for(int i=0;i<vertices;i++)
			{
				arr[i]=false;
			}
			cout<<"BFS: ";
			q.push(startingVertex);
			while(!q.isEmpty())
			{
				int top = q.giveFront();
				q.pop();
				cout<<top<<" - ";
				Node *temp = header[top];
				arr[top]=true;
				// cout<<top<<" ";
				while(temp!=nullptr)
				{
					if(arr[temp->data]!= true)
					{
						arr[temp->data]=true;
						q.push(temp->data);
					}
					temp=temp->next;
				}
			}
			cout<<"\n";
		}
		void dfs()
		{
			Stack s;
			int startingVertex=0;
			bool arr[vertices];
			for(int i=0;i<vertices;i++)
			{
				arr[i]=false;
			}
			cout<<"DFS: ";
			s.push(startingVertex);
			while(!s.isEmpty())
			{
				int top = s.giveTop();
				s.pop();
				cout<<top<<" - ";

				Node *temp = header[top];
				arr[top]=true;

				while(temp!=nullptr)
				{
					if(arr[temp->data]!= true)
					{
						arr[temp->data]=true;
						s.push(temp->data);
					}
					temp=temp->next;
				}
			}
			cout<<"\n";
		}
};
int main()
{
	Graph g(4,6);
	g.acceptGraph();
	g.display();
	g.bfs();
	g.dfs();


	return 0;
}