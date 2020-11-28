//栈——括号匹配

#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 1024
#define SEQSTACK_True 1
#define SEQSTACK_FALSE 0
 
/**
	扫描字符串，如果碰到左括号，直接入栈；
	如果碰到右括号，从栈顶弹出括号，
	判断是否是左括号，如果是则匹配成功
**/
 
//数组模拟栈的顺序存储
typedef struct SEQSTACK{
	void* data[MAX_SIZE];
	int size;
}SeqStack;
 
typedef struct MYCHAR{
	char* PAddres;
	int index;
}MyChar;
 
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
 
int IsLeft(char c){
	return c=='(';
}
 
int IsRight(char c){
	return c==')';
}
 
MyChar* CreatMyChar(char* p,int index){
	MyChar* mychar = (MyChar*)malloc(sizeof(MyChar));
	mychar->PAddres = p;
	mychar->index = index;
	return mychar;
}
 
void ShowError(char* str,int pos){
	printf("%s\n",str);
	for(int i =0;i<pos;i++){
		printf(" ");
	}
	printf("A\n");
}
 
void test01(){
	
	SeqStack* stack = Init_SeqStack();
	
	char* str = "1+2+3(asd)a(s(d(asd)";
	int index = 0;
	char* p = str;
	while(*p!='\0'){
		//如果是左括号，直接进栈
		if(IsLeft(*p)){
			Push_SeqStack(stack,(void*)CreatMyChar(p,index));
		}
		//如果是右括号，弹出,判断是否是左括号
		if(IsRight(*p)){
			if(Size_SeqStack(stack)>0){
				MyChar* mychar = (MyChar*)Top_SeqStack(stack);
				if(IsLeft(*(mychar->PAddres))){
					Pop_SeqStack(stack);
					free(mychar);
				}	
			}
			else{
				printf("右括号没有匹配的左括号\n");
				ShowError(str,index);
				break;
			}
		}
		p++;
		index++;
	}
	
	while(Size_SeqStack(stack)>0){
		MyChar* mchar=(MyChar*)Top_SeqStack(stack);
		printf("左括号没有匹配的右括号：\n");
		ShowError(str,mchar->index);
		Pop_SeqStack(stack);
		free(mchar);
	}
	
}
 
int main(){
	test01();
	return 0;
}
 