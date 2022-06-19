#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};
struct node *top;

void push(){
	int x;
	struct node *newnode;
	printf("Enter data");
	scanf("%d",&x);
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = x;
	newnode->next = top;
	top = newnode;	
}

void pop(){
	struct node *temp;
	temp = top;
	if(top==0){
		printf("List is empty");
	}
	else{
		printf("Deleted node is %d",temp->data);
		top = top->next;
		free(temp);
	}
}

void peek(){
	if(top==0){
		printf("\nList is empty");
	}
	else{
		printf("\nTop element is %d",top->data);
	}
}

void display(){
	struct node *temp;
	temp = top;
	if(top==NULL){
		printf("\nList is empty");
	}
	else{
		while(temp!=0){
			printf("%d ",temp->data);
			temp = temp->next;
		}
	}
}

void main(){
	int choice;
	while(1){
		printf("\n0.Exit\n");
		printf("1.Push\n");
		printf("2.Pop\n");
		printf("3.Peek\n");
		printf("4.Display\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice){
			case 0: exit(0);
			break;
			case 1: push();
			break;
			case 2: pop();
			break;
			case 3: peek();
			break;
			case 4: display();
			break;
		}
	}
}
