//顺序栈

#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 1024
#define SEQSTACK_True 1
#define SEQSTACK_FALSE 0
 
//数组模拟栈的顺序存储
typedef struct SEQSTACK{
	void* data[MAX_SIZE];
	int size;
}SeqStack;
 
typedef struct PERSON{
	char name[64];
	int age;
}Person;
 
/*******************
********************/
//初始化
SeqStack* Init_SeqStack();
//入栈
void Push_SeqStack(SeqStack* stack,void* data);
//返回栈顶元素
void* Top_SeqStack(SeqStack* stack);
//出栈
void Pop_SeqStack(SeqStack* stack);
//判断是否为空
int IsEmpty_SeqStack(SeqStack* stack);
//返回栈中元素个数
int Size_SeqStack(SeqStack* stack);
//清空栈
void Clear_SeqStack(SeqStack* stack);
//销毁
void Free_SeqStack(SeqStack* stack);
/*******************
********************/
 
 
//初始化
SeqStack* Init_SeqStack(){
	SeqStack* stack = (SeqStack*)malloc(sizeof(SeqStack));
	for(int i=0;i<MAX_SIZE;i++){
		stack->data[i] = NULL;
	}
	stack->size = 0;
	
	return stack;
}
//入栈
void Push_SeqStack(SeqStack* stack,void* data){
	if(stack==NULL){
		return;
	}
	if(stack->size==MAX_SIZE){
		return;
	}
	if(data==NULL){
		return;
	}
	
	stack->data[stack->size] = data;
	stack->size++;
}
//返回栈顶元素
void* Top_SeqStack(SeqStack* stack){
	if(stack==NULL){
		return NULL;
	}
	if(stack->size==0){
		return NULL;
	}
	return stack->data[stack->size-1];
}
//出栈
void Pop_SeqStack(SeqStack* stack){
	if(stack==NULL){
		return ;
	}
	if(stack->size==0){
		return ;
	}
	
	stack->size--;
}
//判断是否为空
int IsEmpty_SeqStack(SeqStack* stack){
	if(stack==NULL){
		return -1;
	}
	if(stack->size==0){
		return SEQSTACK_True;
	}else{
		return SEQSTACK_FALSE;
	}
	return -1;
}
//返回栈中元素个数
int Size_SeqStack(SeqStack* stack){
	return stack->size;
}
//清空栈
void Clear_SeqStack(SeqStack* stack){
	if(stack==NULL){
		return ;
	}
	stack->size = 0;
}
//销毁
void Free_SeqStack(SeqStack* stack){
	if(stack==NULL){
		return ;
	}
	free(stack);
}
 
 
void test01(){
	SeqStack* stack = Init_SeqStack();
	Person p1 ={"a",1};
	Person p2 ={"b",2};
	Person p3 ={"c",3};
	Person p4 ={"d",4};
	Person p5 ={"e",5};
	
	Push_SeqStack(stack,&p1);
	Push_SeqStack(stack,&p2);
	Push_SeqStack(stack,&p3);
	Push_SeqStack(stack,&p4);
	Push_SeqStack(stack,&p5);
	
	//输出
	while(Size_SeqStack(stack)>0){
		//访问栈顶元素
		Person* per = (Person*)Top_SeqStack(stack);
		printf("Name:%s,Age:%d\n",per->name,per->age);
		//出栈
		Pop_SeqStack(stack);
	}
	
}
 
int main(){
	test01();
	return 0;
}
 