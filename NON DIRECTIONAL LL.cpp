#include<iostream>
using namespace std;
const int m=10;
		struct node{
	int data ;
	 node *next;
	}*head;
class A1{
	public :

	 A1();
		void append(int n);
		void add(int p, int n);
		void begun(int n);
	    void  display();
	    void count();
	    	 ~A1();   
};
A1 :: A1(){
	head=NULL;
	
}


	  void A1::append(int n){
	node *temp=head ,*r ,*o ;
if(head==NULL){
	head=new node;
	if(head==NULL)
{
	cout<<"NO MEMORY "<<endl;
	return;}
	head->data=n;
	head->next=NULL;
}
else{
	temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	r=new node;
	r->data=n;
	r->next=NULL;
	temp->next=r;
	
}	
}
	
		
void A1::display(){
	node *temp;
 temp=head;
 while(temp!=NULL){
 	cout<<temp->data<<"  ";
 	temp=temp->next;
 }
}

void A1 :: add(int p, int n){
	node *temp,*r;
	r=head;
	temp=new node;
	
	temp->data=n;
	temp->next=NULL;
	for(int i=2;i<p;i++){
		r=r->next;
	}
	
	temp->next=r->next;
	r->next=temp;
}
void A1:: count(){
    node *temp;
    int c=0;
    temp=head;
    while(temp!=NULL){
        c++;
        temp=temp->next;
    }
    cout<<" THE NO OF NODES ARE  :  "<<c;
}
void A1 :: begun(int n){
	node *temp,*q;
	q=head;
	temp=new node;
	
	temp->data=n;
	temp->next=NULL;
	if(head==NULL){
		head=temp;
	}
	else{
		
		temp->next=head;
		head=temp;
	}
}

A1::~A1(){
}
	A1 a[m];
class A1m{
	private :  
	struct node{
	int data ;
	 node *next;
	}*head;
	public :
	
	 A1m();
	 void push(int n);
	 void pop();
	 void disp();
	 ~A1m();   
	    
};
A1m :: A1m(){
	head=NULL;
	
}
void A1m::push(int n){
	node *t;
	t=new node;
	t->data=n;
	
	if(head==NULL){
		t->next=NULL;
		head=t;
	}
	else{
		t->next=head;
		head=t;
	}
}
void A1m::pop(){
	if(head==NULL){
		cout<<"EMPTY STACK SORRY!!!!!"<<endl;
		return ;
	}
	node *t;
	t=head;
	head=head->next;
	delete t;
}
void A1m::disp(){
	node *t;
	t=head;
	while(t->next!=NULL){
		cout<<t->data<<endl;
		t=t->next;
	}
}
A1m :: ~A1m(){	
}

void DFS(int n){
	
	int counter=0,c=0;
	A1m a2;
	A1 a,b;
	a2.push(n);
	cout<<" "<<n<<" "<<endl;
	a.append(n);
node *temp=a[n].head;
node *t=a.head;
	 while(temp->next!=NULL){
	 		counter++;
	 		while(t->data==temp->data){
	 			c=-1;
			 }
			 if(c!=-1){
	 		DFS(temp->data);
	 		}
			 temp=temp->next;
	 }

		if(counter!=0){
		node d;
		d = a2.pop();
		return;		
			
		}
	
	}

int main(){
	
	int m,k,n;
	char ch;
	cout<<"ENTER THE NO OF VERTICES : "<<endl;
	cin>>m;

	cout<<"ENTER THE RELATIONS FOR VERTICES STARTING FROM ZERO : "<<endl;

	for(int i=0;i<m;i++){
		cout<<"IS thie connection for   "<<i<< "   y/n   "<<endl;
		cin>>ch;
		while(ch=='y'){
			cout<<"ENTER THE VERTICE CONNECTED "<<endl;
			cin>>k;
			a[i].append(k);
			cout<<"IS thier connection for "<<i<<" y/n "<<endl;
		cin>>ch;
		}
	}


cout<<" THE CONNECTIONS AS GIVEN ARE AS FOLLOWS  "<<endl;

for(int j=0;j<m;j++){
	cout<<"  CONNECTIONS FOR VERTICES "<<j<<" ARE AS :-> ";
	a[j].display();
	cout<<endl;
}
cout<<"THE STARTING NODE ( 0 to "<<m-1<<" ) "<<endl;
	cin>>n;	
	DFS(n);

	return 0;

}
