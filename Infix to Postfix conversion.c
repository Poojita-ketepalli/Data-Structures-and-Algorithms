#include<stdio.h>
#include<stdlib.h>
#define N 100

char stack[N];
int top=-1;

void push(char data){
	if(top==N-1){
		printf("Overflow! You cannot insert\n");
	}
	else{
		top++;
		stack[top]=data;
	}
}

char pop(){
	if(top==-1){
		return -1;
	}
	else{
		return stack[top--];
	}
}

int precedence(char data){
	if(data == '('){
		return 0;
	}
	else if(data == '+' || data == '-'){
		return 1;
	}
	else if(data == '/' || data == '*'){
		return 2;
	}
	else if(data == '^'){
		return 3;
	}
	return 0;
}

int main(){
	char exp[100];
	char *temp,x;
	printf("\nEnter infix expression:");
	scanf("%s",exp);
	temp = exp;
	
	while(*temp!='\0'){
		if(isalnum(*temp)){
			printf("%c",*temp);
		}
		else if(*temp == '('){
			push(*temp);
		}
		else if(*temp==')'){
			while((x=pop())!='('){
				printf("%c",x);
			}
		}
		else{
			while(precedence(stack[top])>=precedence(*temp)){
				printf("%c",pop());
			}
			push(*temp);
		}
		temp++;
	}
	while(top!=-1){
		printf("%c",pop());
	}
	
	return 0;
	
}
