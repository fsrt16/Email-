#include<iostream>
using namespace std;
int a[10];

class A1{
	private :  
	struct node{
	int data ;
	 node *next;
	}*head,*h;
	public :
	
	 A1();
		void append(int n);
		void begun(int n);
	    void  display();
	    void count();
	    void D(int n);
	    void sort();
	    
	    
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
void A1 :: D(int n){
	node *temp,*old;
	temp=head;
	while(temp!=NULL){
		if(temp->data==n){
		           	if(temp==head){
			                 	head=head->next;
			                      }
			        else{
			                    old->next=temp->next;
	                    }
			delete temp;
				return;
		}
		
		else{
			old=temp;
			temp=temp->next;
			
		}
	}
}
void  A1:: sort(){
	node *t, *i,*j;
	int m;
j=head;
i=head->next;
for(i=head;i!=NULL;i=i->next){
	for(j=i->next;j!=NULL;j=j->next){
		if(i->data>j->data){
			m=i->data;
		i->data=j->data;
		j->data=m;
		}
	}
	
}
}



A1::~A1(){
}
A1 a1[10];
A1 *t[10];
void QUADl( int key , int tbsize, int i){
	int c;
	c=key%tbsize;
	c=(c+(i*i))%tbsize;
	a1[c].append(key);
}
void LPROBEl( int key , int tbsize, int i){
	int c;
	c=key%tbsize;
	c=(c+i)%tbsize;
	a1[c].append(key);
}

void HASH1l( int key , int tbsize, int i){
	int c;
	c=key%tbsize;
	a1[c].append(key);
}
void thik(int key, int tbsize , int i){

	
	for(int j=i+1;j<10;j++){
		if(a[j]==0){
			a[j]=key;
		
			return;
		}
	}
	for(int k=0;k<i;k++){
			if(a[k]==0){
			a[k]=key;
		
		return;
		}
	}
}
void thik1(int key, int tbsize , int i){

	
	for(int j=i+1;j<10;j++){
		if(a[(key + j*j)%tbsize]==0){
			a[(key + j*j)%tbsize]=key;
		
			return;
		}
	}
	for(int k=0;k<i;k++){
			if(a[(key + k*k)%tbsize]==0){
			a[(key + k*k)%tbsize]=key;
		
		return;
		}
	}
	
}
	


void display(){
	
	cout<<"THE ARRAY SO CALLED IS :->"<<endl;
	for(int i=0;i<10;i++){
		cout<<"THE ELEMNT NO "<<i<<" : "<<endl;
		cout<<a[i]<<endl;
	}
}
void HASHn( int key , int tbsize, int i){
	int c;
	c=key%tbsize;
	if(a[c]==0 ){
		a[c]=key;
	
	}
	else{
		
		thik(key,tbsize,c);
	
	}
}
void PROBEn( int key , int tbsize, int i){
	int c;
	c=key%tbsize;
	
	if(a[c]==0 ){
		a[c]=key;
	
	}
	else{
		
		thik(key,tbsize,c);
	
	}
}
void QUADn( int key , int tbsize, int i){
	int c;
	c=key%tbsize;

	if(a[c]==0 ){
		a[c]=key;
	
	}
	else{
		
		thik1(key,tbsize,c);
	
	}
}




void dispapos(){
	
	
	cout<<"THE ELEMENTS IN EACH SET OF ARRAY ARE AS FOLLOWS :  "<<endl;
	
		for(int j=0;j<10;j++){
			cout<<"THE INTERFACE ONE ELEMNTS ARE AS FOLLOWS : "<<j<<endl;
		a1[j].display();
		cout<<endl;
	}
	
}
int main(){
	int n,m,b[10],g;
	char ch,ch1;
	for(int i=0;i<10;i++){
	a[i]=0;
}

	cout<<"ENTER THE TABLE SIZE "<<endl;
	cin>>n;
	cout<<"ENTER THE NO OF ELEMENTS "<<endl;
	cin>>m;
	for(int j=0;j<10;j++){
		t[j]=&a1[j];
	}
	cout<<"FOR MULTIPLE STORAGE OF ELEMENT IN ONE INDEX OF ARRAY PRESS 2 OR FOR REVERSAL OF VANCANT ELEMENT PRESS 1"<<endl;
	cin>>g;
	switch(g){
		
	
	case 1 :{
		
			cout<<"FOR NORMAL HASHING (H) , LINEAR PROBING(L) , QUADRATIC FORM(Q)   "<<endl;
	cin>>ch1;
	switch (ch1){
		case 'H' :{
				for(int i=0;i<m;i++){
		cout<<"Enter the elements "<<i+1<<endl;
		cin>>b[i];
		HASHn(b[i],n,i);
	}
			break;
		}
			case 'L' :{
				for(int i=0;i<m;i++){
		cout<<"Enter the elements "<<i+1<<endl;
		cin>>b[i];
		PROBEn(b[i],n,i);
	}
			break;
		}	case 'Q' :{
				for(int i=0;i<m;i++){
		cout<<"Enter the elements "<<i+1<<endl;
		cin>>b[i];
		QUADn(b[i],n,i);
	}
			break;
		}
		default : cout<<"WRONG INPUT "<<endl;
	}
		display();	
	}
		
	 
		
		
		
		
		
		
	case 2 :{
		
	
	cout<<"FOR NORMAL HASHING (H) , LINEAR PROBING(L) , QUADRATIC FORM(Q) in LINKED LIST  "<<endl;
	cin>>ch;
	switch (ch){
		case 'H' :{
				for(int i=0;i<m;i++){
		cout<<"Enter the elements "<<i+1<<endl;
		cin>>b[i];
		HASH1l(b[i],n,i);
	}
			break;
		}
			case 'L' :{
				for(int i=0;i<m;i++){
		cout<<"Enter the elements "<<i+1<<endl;
		cin>>b[i];
		LPROBEl(b[i],n,i);
	}
			break;
		}	case 'Q' :{
				for(int i=0;i<m;i++){
		cout<<"Enter the elements "<<i+1<<endl;
		cin>>b[i];
		QUADl(b[i],n,i);
	}
			break;
		}
		default : cout<<"WRONG INPUT "<<endl;
	}

	dispapos();
	
	break;
}

}
	
	return 0;
	
}

