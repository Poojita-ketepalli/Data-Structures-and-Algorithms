#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *prev;
	struct node *next;
};

struct node *head;

void display(){
	struct node *temp;
	temp = head;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
}

void creating_List(){
	struct node *newnode,*temp;
	int n,i;
	printf("Enter number of nodes:");
	scanf("%d",&n);
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("Enter node 1:");
	scanf("%d",&newnode->data);
	head = temp = newnode;
	newnode->next = NULL;
	newnode->prev = NULL;
	for(i=2;i<=n;i++){
		newnode = (struct node *)malloc(sizeof(struct node));
		printf("Enter node %d ",i);
		scanf("%d",&newnode->data);
		newnode->prev = temp;
		newnode->next = NULL;
		temp->next = newnode;
		temp = newnode;
	}
	display();
	
}

void Count_ele(){
	struct node *temp;
	int count=0;
	temp = head;
	while(temp!=0){
		temp = temp->next;
		count++;
	}
	printf("\nNumber of elements in the list are: %d",count);
}

void insertion_at_begining(){
	struct node *newnode;
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("Enter new node to insert:");
	scanf("%d",&newnode->data);
	head->prev = newnode;
	newnode->next = head;
	newnode->prev = NULL;
	head = newnode;
}

void insertion_at_end(){
	struct node *temp,*newnode;
	temp = head;
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("Enter new node to insert:");
	scanf("%d",&newnode->data);
	while(temp->next!=0){
		temp = temp->next;
	}
	newnode->next = NULL;
	newnode->prev = temp;
	temp->next = newnode;
	temp = newnode;
	
	
}

void insertion_at_position(){
	struct node *temp,*newnode;
	int i=1,pos;
	printf("\nEnter position to insert:");
	scanf("%d",&pos);
	temp = head;
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("Enter new node to insert:");
	scanf("%d",&newnode->data);
	while(i<pos-1){
		temp = temp->next;
		i++;
	}
	newnode->next = temp->next;
	newnode->prev = temp;
	temp->next = newnode;
	temp = newnode->next;
	temp->prev = newnode;
}

void deletion_at_begining(){
	struct node *temp;
	temp = head;
	head = head->next;
	head->prev = NULL;
	printf("Deleted node is %d",temp->data);
	free(temp);
}

void deletion_at_ending(){
	struct node *temp,*last;
	temp = head;
	while(temp->next!=0){
		temp = temp->next;
	}
	printf("Deleted node is %d",temp->data);
	last = temp;
	last = last->prev;
	last->next = NULL;
	free(temp);
	
}

void deletion_at_position(){
	struct node *temp,*prevnode,*nextnode;
	temp = head;
	int i=1,pos;
	printf("Enter position to delete the node:");
	scanf("%d",&pos);
	while(i<pos){
		temp = temp->next;
		i++;
	}
	printf("Deleted node is %d",temp->data);
	prevnode = temp->prev;
	nextnode = temp->next;
	
	prevnode->next = nextnode;
	nextnode->prev = prevnode;
	free(temp);
}

void reverse(){
	struct node *temp;
	temp = head;
	while(temp->next!=0){
		temp = temp->next;
	}
	while(temp!=0){
		printf("%d ",temp->data);
		temp = temp->prev;
	}
	
}

void main(){
	int choice;
	creating_List();
	while(1){
		printf("\n\n0.Exit");
		printf("\n1.Display");
		printf("\n2.Count elements");
		printf("\n3.Insertion at beginning");
		printf("\n4.Insertion at end");
		printf("\n5.Insertion at given position");
		printf("\n6.Deletion at begining");
		printf("\n7.Deletion at ending");
		printf("\n8.Deletion at given position");
		printf("\n9.Reversing of a list");
		printf("\nEnter Your Choice:");
		scanf("%d",&choice);
		switch(choice){
			case 0: exit(0);
			break;
			case 1: display();
			break;
			case 2: Count_ele();
			break;
			case 3: insertion_at_begining();
			break;
			case 4: insertion_at_end();
			break;
			case 5: insertion_at_position();
			break;
			case 6: deletion_at_begining();
			break;
			case 7: deletion_at_ending();
			break;
			case 8: deletion_at_position();
			break;
			case 9: reverse();
			break;
		}
	}
}
	

