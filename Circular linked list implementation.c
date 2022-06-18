#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};
struct node *head;

void display(){
	struct node *temp;
	temp = head;
	if(head==0){
		printf("Empty list");
	}
	else{
		while(temp->next!=head){
			printf("%d ",temp->data);
			temp = temp->next;
		}
		printf("%d ",temp->data);
	}
	
}
void creating_List(){
	struct node *newnode,*temp;
	int n,i;
	printf("\nEnter number of nodes:");
	scanf("%d",&n);
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("Enter node 1 data:");
	scanf("%d",&newnode->data);
	head = newnode;
	newnode->next = NULL;
	temp=head;
	for(i=2;i<=n;i++){
		newnode = (struct node *)malloc(sizeof(struct node));
		printf("Enter node %d data:",i);
		scanf("%d",&newnode->data);
		temp->next = newnode;
		newnode->next = head;
		temp = newnode;
	}
	
	
}
void Count_ele(){
	struct node *temp;
	int count=1;
	temp = head;
	if(head==0){
		printf("Empty list");
	}
	else{
		while(temp->next!=head){
			count++;
			temp = temp->next;
		}
		printf("\nNumber of elements in the list:%d",count);
	}
}

void insertion_at_begining(){
	struct node *newnode,*temp;
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("Enter data to insert:");
	scanf("%d",&newnode->data);
	temp = head;
	while(temp->next!=head){
		temp = temp->next;
	}
	newnode->next = head;
	head = newnode;
	temp->next = newnode;
	printf("Node inserted successfully\n");
	display();
}

void insertion_at_end(){
	struct node *newnode,*temp;
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("Enter data to insert:");
	scanf("%d",&newnode->data);
	temp = head;
	while(temp->next!=head){
		temp = temp->next;
	}
	temp->next = newnode;
	newnode->next = head;
	temp = temp->next;
	printf("Node inserted successfully\n");
	display();
}

void insertion_at_position(){
	struct node *newnode,*temp,*prevnode;
	int i=1,pos;
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("Enter position to insert:");
	scanf("%d",&pos);
	printf("Enter data to insert:");
	scanf("%d",&newnode->data);
	temp = head;
	while(i<pos){
		prevnode = temp;
		temp = temp->next;
		i++;
	}
	prevnode->next = newnode;
	newnode->next = temp;
	printf("Node inserted successfully\n");
	display();
}

void deletion_at_begining(){
	struct node *temp,*temp1;
	temp  = temp1= head;
	printf("Deleted node is %d",head->data);
	while(temp->next!=head){
		temp = temp->next;
	}
	head = head->next;
	temp1->next = NULL;
	free(temp1);
	temp->next = head;
	printf("\nNode deleted successfully!!\n");
	display();
}

void deletion_at_ending(){
	struct node *temp,*prevnode;
	temp = head;
	while(temp->next!=head){
		prevnode = temp;
		temp = temp->next;
	}
	prevnode->next = head;
	printf("Deleted node is %d",temp->data);
	free(temp);
	printf("\nNode deleted successfully!!\n");
	display();
	
}

void deletion_at_position(){
	struct node *temp,*prevnode,*nextnode;
	int i=1,pos;
	printf("Enter position to delete the data:");
	scanf("%d",&pos);
	temp = head;
	while(i<pos){
		prevnode = temp;
		temp = temp->next;
		i++;
	}
	nextnode = temp->next;
	prevnode->next = nextnode;
	printf("Deleted node is %d",temp->data);
	free(temp);
	printf("\nNode deleted successfully!!\n");
	display();
}

void reverse(){
	struct node *tail,*prev,*current,*nextnode;
	tail = head;
	if(head==0){
		printf("Empty list");
	}
	else{
		while(tail->next!=head){
		tail = tail->next;
		}
		current = tail->next;
		nextnode = current->next;
		while(current!=tail){
			prev = current;
			current = nextnode;
			nextnode = current->next;
			current->next = prev;
		}
		nextnode->next = tail;
		head= tail;
		display();
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
