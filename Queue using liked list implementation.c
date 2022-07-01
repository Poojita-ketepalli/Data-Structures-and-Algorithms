#include<stdio.h>
#include<stdlib.h>


struct node{
	int data;
	struct node *next;
};
struct node *front;
struct node *rear;

void display(){
	struct node *temp;
	if(front==0 && rear==0){
		printf("List is empty");
	}
	else{
		temp = front;
		while(temp!=0){
			printf("%d ",temp->data);
			temp = temp->next;
		}
	}
}

void enqueue(int x){
	struct node *newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = x;
	newnode->next=NULL;
	if(front==0 && rear==0){
		front = rear = newnode;
	}
	else{
		rear->next = newnode;
		rear = newnode;
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
	else{
		printf("%d ",front->data);
		front = front->next;
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
