#include<stdio.h>
#include<stdlib.h>
#define N 5

int stack[N];
int top = -1;

void push(){
	int data;
	printf("Enter data:");
	scanf("%d",&data);
	if(top==N-1){
		printf("Overflow! You cannot insert\n");
	}
	else{
		top++;
		stack[top]=data;
	}
}

void pop(){
	int data;
	if(top==-1){
		printf("Underflow! Stack is empty\n");
	}
	else{
		data = stack[top];
		printf("Deleted item is %d\n",data);
		top--;
	}
}

void peek(){
	if(top==-1){
		printf("Stack is empty");
	}
	else{
		printf("Top element is %d",stack[top]);
	}
}

void display(){
	int i;
	for(i=top;i>=0;i--){
		printf("%d ",stack[i]);
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
