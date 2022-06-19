#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};
struct node *head;
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
		newnode->next = NULL;
		temp = newnode;
	}
	
	
}

void display(){
	struct node *temp;
	if(head==0){
		printf("List is empty");
	}
	else{
		temp=head;
		while(temp!=0){
			printf("%d ",temp->data);
			temp = temp->next;
		}
	}
	
}

void Count_ele(){
	struct node *temp;
	int count=0;
	temp = head;
	while(temp!=NULL){
		temp = temp->next;
		count++;
	}
	printf("\nNumber of elements in the list is: %d",count);
}

void insertion_at_begining(){
	struct node *newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data to insert:");
	scanf("%d",&newnode->data);
	newnode->next = head;
	head = newnode;
}

void insertion_at_end(){
	struct node *newnode,*temp;
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data to insert:");
	scanf("%d",&newnode->data);
	temp=head;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = newnode;
	newnode->next = NULL;
}

void insertion_at_position(){
	struct node *newnode,*temp;
	int pos,i=1;
	printf("\nEnter Position to insert:");
	scanf("%d",&pos);
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data to insert:");
	scanf("%d",&newnode->data);
	temp = head;
	while(i<pos-1){
		temp = temp->next;
		i++;
	}
	newnode->next = temp->next;
	temp->next = newnode;
	
}

void deletion_at_begining(){
	struct node *temp;
	temp = head;
	head = head->next;
	printf("deleted node is %d",temp->data);
	free(temp);
	
}

void deletion_at_ending(){
	struct node *temp,*temp1;
	temp = head;
	while(temp->next!=0){
		temp1 = temp;
		temp=temp->next;
	}
	if(temp==head){
		head==0;
	}
	else{
		temp1->next=0;
		printf("Deleted node is %d",temp->data);
	}
	free(temp);
}

void deletion_at_position(){
	int pos,i=1;
	struct node *temp,*prevnode;
	printf("\nEnter Position");
	scanf("%d",&pos);
	temp = head;
	while(i<pos){
		prevnode = temp;
		temp = temp->next;
		i++;
	}
	if(temp==head){
		head=NULL;
	}
	else{
		prevnode->next = temp->next;
		printf("Deleted node is %d ",temp->data);
	}
	free(temp);
	
}

void reverse(){
	struct node *currentnode,*prevnode,*nextnode;
	prevnode = NULL;
	currentnode = nextnode = head;
	while(nextnode!=NULL){
		nextnode = nextnode->next;
		currentnode->next = prevnode;
		prevnode = currentnode;
		currentnode = nextnode;
	}
	head = prevnode;
	free(nextnode);
	free(currentnode);
	display();
	
}

int main(){
	
	int choice,yes=1;
	while(yes){
	printf("\n1.Creating List");
	printf("\n2.Display");
	printf("\n3.Count elements");
	printf("\n4.Insertion at beginning");
	printf("\n5.Insertion at end");
	printf("\n6.Insertion at given position");
	printf("\n7.Deletion at begining");
	printf("\n8.Deletion at ending");
	printf("\n9.Deletion at given position");
	printf("\n10.Reversing of a list");
	printf("\nEnter Your Choice:");
	scanf("%d",&choice);
	switch(choice){
		case 1: creating_List();
		break;
		case 2: display();
		break;
		case 3: Count_ele();
		break;
		case 4: insertion_at_begining();
		break;
		case 5: insertion_at_end();
		break;
		case 6: insertion_at_position();
		break;
		case 7: deletion_at_begining();
		break;
		case 8: deletion_at_ending();
		break;
		case 9: deletion_at_position();
		break;
		case 10: reverse();
		break;
	}
	printf("\nContinue?(0,1)");
	scanf("%d",&yes);
}
	
}
