#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};
struct node *front=0;
struct node *rear=0;

void display(){
	struct node *temp;
	if(front==0 && rear==0){
		printf("List is empty");
	}
	else{
		temp = front;
		while(temp->next!=front){
			printf("%d ",temp->data);
			temp = temp->next;
		}
		printf("%d",temp->data);
	}
}

void enqueue(int x){
	struct node *newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = x;
	newnode->next=NULL;
	if(rear==0){
		front = rear = newnode;
		rear->next = newnode;
	}
	else{
		rear->next = newnode;
		rear = newnode;
		rear->next = front;
	}
	printf("\n");
	display();
}

void dequeue(){
	struct node *temp;
	temp=front;
	printf("\n");
	if(front==0 && rear==0){
		printf("List is empty");
	}
	else if(front==rear){
		front=rear=0;
		free(temp);
	}
	else{
		printf("%d ",front->data);
		front = front->next;
		rear->next = front;
		free(temp);
	}
}

void peek(){
	printf("%d",front->data);
}

void main(){
	enqueue(5);
	enqueue(6);
	enqueue(-3);
	dequeue();
	peek();
}
