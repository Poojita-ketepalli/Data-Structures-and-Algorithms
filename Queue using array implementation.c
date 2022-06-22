#include<stdio.h>
#include<stdlib.h>
#define N 5

int queue[N];
int front = -1;
int rear = -1;

void display(){
	int i;
	if(rear==-1 && front==-1){
		printf("List is empty");
	}
	else{
		for(i=front;i<rear+1;i++){
			printf("%d",queue[i]);
		}
	}
}

void peek(){
	if(rear==-1 && front==-1){
		printf("List is empty");
	}
	else{
		printf("%d",queue[front]);
	}
}

void enqueue(int x){
	if(rear == N-1){
		printf("Overflow\n");
	}
	else if(front==-1 && rear==-1){
		front = rear = 0;
		queue[rear]=x;
		printf("%d is inserted\n",x);
	}
	else{
		rear++;
		queue[rear] = x;
		printf("%d is inserted\n",x);
	}
	
}

void dequeue(){
	if(front==-1 && rear ==-1){
		printf("List is empty\n");
	}
	else if(front==rear){
		front = rear = -1;
	}
	else{
		printf("Deleted node is %d\n",queue[front]);
		front++;
	}
}


int main(){
	int choice,x;
	while(1){
		printf("\n1.Enqueue");
		printf("\n2.Dequeue");
		printf("\n3.Peek");
		printf("\n4.Display");
		printf("\nEnter your choice:");
		scanf("%d",&choice);
			switch(choice){
			case 0: exit(0);
			break;
			case 1: printf("\nEnter data:");
			scanf("%d",&x);
			enqueue(x);
			break;
			case 2: dequeue();
			break;
			case 3: peek();
			break;
			case 4: display();
			break;
		}
	}
	
	return 0;
}
