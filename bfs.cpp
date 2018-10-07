#include <stdio.h>
#include<iostream>
#include <stdlib.h>
#include <limits.h>
using namespace std;
int a1[6][6],b[6][6];

// A structure to represent a queue
struct Queue
{
    int front, rear, size;
    unsigned capacity;
    int* array;
};

// function to create a queue of given capacity. 
// It initializes size of queue as 0
struct Queue* createQueue(unsigned capacity)
{
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0; 
    queue->rear = capacity - 1;  // This is important, see the enqueue
    queue->array = (int*) malloc(queue->capacity * sizeof(int));
    return queue;
}

// Queue is full when size becomes equal to the capacity 
int isFull(struct Queue* queue)
{  return (queue->size == queue->capacity);  }

// Queue is empty when size is 0
int isEmpty(struct Queue* queue)
{  return (queue->size == 0); }

// Function to add an item to the queue.  
// It changes rear and size
void enqueue(struct Queue* queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1)%queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;

}

// Function to remove an item from queue. 
// It changes front and size
int dequeue(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1)%queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// Function to get front of queue
int front(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}

// Function to get rear of queue
int rear(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->rear];
}


void chkcompgrph(int n){
	


	
	for(int j=0;j<6;j++){
		if(j!=n){
		
if(b[n][j]==0 && b[j][n]==0){

cout<<"THE VERTEX "<<n<<" is not complete "<<endl;
return;	
}		}
	}
	cout<<"THE VERTEX IS COMPLETE "<<endl;



}
void chkvompgrph(){
	
int c;

for(int n=0;n<6;n++){

	for(int j=0;j<6;j++){
		if(j!=n){
		
if(b[n][j]==0 && b[j][n]==0){
cout<<"THE GRAPH "<<n<<" is not complete "<<endl;
return;	
}		}
	}
	c++;

}
if(c==6){
	cout<<endl<<"!!!  THE GIVEN GRAPH IS COMPLETE !!!"<<endl;
}

}





int main()
{
 

    
    int y,c=0,c1=0;
    
cout<<"ENTER THE ADJACENCY MATRIX FOR THE SAME "<<endl;
	for(int i=0;i<6;i++){
		cout<<" row "<<i+1;
			cout<<endl;
				for(int j=0;j<6;j++){
					cout<<"ENTER THE COLUMN NO : "<<j+1<<"   ";
			cin>>a1[i][j];
		
		}
		cout<<endl;
	}
	for(int i=0;i<6;i++){
				for(int j=0;j<6;j++){
					
			b[i][j]=a1[i][j];
		
		}
	}
	for(int i=0;i<6;i++){
		cout<<" [ ";
		for(int j=0;j<6;j++){
			cout<<" "<<b[i][j]<<"  ";
			
		}
		cout<<" ] "<<endl;
	}
	cout<<endl;
	cout<<"WHICH VERTEX DO YOU WANT TO KNOW THE CONNECTIONS OF : "<<endl;
cin>>y;
for(int i=0;i<6;i++){
	if(a1[y][i]==1){
		cout<<"CONNECTED OUTWARD TO -->   "<<i<<endl;
		c++; 
	}
}
for(int i=0;i<6;i++){
	if(a1[i][y]==1){
		cout<<"CONNECTED INWARD TO -->   "<<i<<endl;
		c1++; 
	}
}
cout<<"total inward connection  is :  "<<c1<<endl;

cout<<"total outward connection  is :  "<<c<<endl;

cout<<"TOTAL CONNECTIONS ARE -->  "<<c+c1<<endl;

	int n;
	cout<<"THE STARTING NODE ( 0 to 5) "<<endl;
	cin>>n;

struct Queue* queue = createQueue(1000);


	   enqueue(queue, n);
    for(int j=0;j<6;j++){
				a1[j][n]=0;
			}
	for(int i=0;i<6;i++){
		if(a1[n][i]==1){
		
			for(int j=0;j<6;j++){
				a1[j][i]=0;
			}
			 enqueue(queue, i);		
	}
}
	while(front(queue)!=rear(queue)){
		cout<<" "<<dequeue(queue)<<" ";
    for(int j=0;j<6;j++){
				a1[j][front(queue)]=0;
			}
	for(int i=0;i<6;i++){
		if(a1[front(queue)][i]==1){
		
			for(int j=0;j<6;j++){
				a1[j][i]=0;
			}
			 enqueue(queue, i);		
	}
	}
}
cout<<" "<<dequeue(queue)<<" ";
int r;
cout<<endl<<"CHECK WHETHER THE FOLLOWING VERTEX IS CONNECTED OR NOT ????"<<endl;
cin>>r;
chkcompgrph(r);

cout<<"CHECK WHETHER THE GRAPH IS COMPLETE OR NOT "<<endl;


chkvompgrph();



    return 0;
}
