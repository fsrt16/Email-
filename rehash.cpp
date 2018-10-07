#include<iostream>
using namespace std;
int che_prime(int n){
int c,d;
for(int i=2;i<n;i++){
	if(n%i==0){
		c++;
	}	
}
if(c==0){
	return n;
}
else{
	che_prime( n+1);
}
	
}
int main(){
	int c;
	cout<<"ENTER A NO "<<endl;
	cin>>c;
	int d;
	d=che_prime(c);
	cout<<endl<<d<<endl;
	return 0;
}
