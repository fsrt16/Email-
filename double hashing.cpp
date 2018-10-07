#include<iostream>
using namespace std;
int h2, a[10];


void hashfn1(int key, int tablesize,int R){
	h2=R-(key%R);
	int r;
	for(int i=0;i<10;i++){
		r=(key+(i*h2))%tablesize;
	
		if(a[r]==-1){
			a[r]=key;
			return;
		}
	}	
}
void display(){
	cout<<"THE ARRAY AS PER DOUBLE HASHING IMPLEMENTATION IS :-->  "<<endl;
	for(int i=0;i<10;i++){
		cout<<"THE ELEMENT IS "<<i<<endl;
		cout<<a[i]<<endl;
	}
}
int main(){
	int n, m , b[10] , p;
	for(int i=0;i<10;i++){
		a[i]=-1;
	}
	cout<<"ENTER THE TABLE SIZE BELOW "<<endl;
	cin>>n;
	cout<<"ENTER THE NO OF ELEMENTS : "<<endl;
	cin>>m;
	cout<<"ENTER THE PRIME NUMBER : "<<endl;
	cin>>p;
	for(int j=0;j<m;j++){
		cout<<"THE ELEMENT NO IS : "<<j+1<<endl;
		cin>>b[j];
		
		hashfn1(b[j],n,p);	
	}
	display();
	return 0;
	}





