//链栈

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
typedef struct LINKNODE{
	struct LINKNODE* next;
}LinkNode;
 
typedef struct LINKSTACK{
	LinkNode head;
	int size;
}LinkStack;
 
typedef struct PERSON{
	LinkNode node;
	char name[64];
	int age;
}Person;
 
/*******************
********************/
//初始化
LinkStack* Init_LinkStack();
//入栈
void Push_LinkStack(LinkStack* stack,LinkNode* data);
//返回栈顶元素
void* Top_LinkStack(LinkStack* stack);
//出栈
void Pop_LinkStack(LinkStack* stack);
//判断是否为空
int IsEmpty_LinkStack(LinkStack* stack);
//返回栈中元素个数
int Size_LinkStack(LinkStack* stack);
//清空栈
void Clear_LinkStack(LinkStack* stack);
//销毁
void Free_LinkStack(LinkStack* stack);
/*******************
********************/
 
//初始化
LinkStack* Init_LinkStack(){
	LinkStack* stack = (LinkStack*)malloc(sizeof(LinkStack));
	stack->head.next = NULL;
	stack->size = 0;
	
	return stack;
}
//入栈
void Push_LinkStack(LinkStack* stack,LinkNode* data){
	if(stack==NULL){
		return;
	}
	if(data==NULL){
		return;
	}
	
	data->next = stack->head.next;
	stack->head.next = data;
	stack->size++;
}
//返回栈顶元素
void* Top_LinkStack(LinkStack* stack){
	if(stack==NULL){
		return NULL;
	}
	if(stack->size==0){
		return NULL;
	}
	return stack->head.next;
}
//出栈
void Pop_LinkStack(LinkStack* stack){
	if(stack==NULL){
		return;
	}
	if(stack->size==0){
		return;
	}
	LinkNode* pNext = stack->head.next;
	stack->head.next = pNext->next;
	stack->size--;
}
//判断是否为空
int IsEmpty_LinkStack(LinkStack* stack){
	if(stack==NULL){
		return -1;
	}
	if(stack->size==0){
		return 1;
	}
	else{
		return -1;
	}
	return -1;
}
//返回栈中元素个数
int Size_LinkStack(LinkStack* stack){
	if(stack==NULL){
		return -1;
	}
	if(stack->size==0){
		return -1;
	}
	return stack->size;
}
//清空栈
void Clear_LinkStack(LinkStack* stack){
	if(stack==NULL){
		return;
	}
	stack->head.next = NULL;
	stack->size = 0;
}
//销毁
void Free_LinkStack(LinkStack* stack){
	if(stack==NULL){
		return;
	}
	free(stack);
}
 
void test01(){
	LinkStack* stack = Init_LinkStack();
	Person p1,p2,p3,p4,p5;
	
	strcpy(p1.name,"a");
	strcpy(p2.name,"b");
	strcpy(p3.name,"c");
	strcpy(p4.name,"d");
	strcpy(p5.name,"e");
	
	p1.age = 10;
	p2.age = 20;
	p3.age = 30;
	p4.age = 40;
	p5.age = 50;
	
	Push_LinkStack(stack,(LinkNode*)&p1);
	Push_LinkStack(stack,(LinkNode*)&p2);
	Push_LinkStack(stack,(LinkNode*)&p3);
	Push_LinkStack(stack,(LinkNode*)&p4);
	Push_LinkStack(stack,(LinkNode*)&p5);
	
	while(Size_LinkStack(stack)>0){
		Person* per = (Person*)Top_LinkStack(stack);
		printf("Name:%s,Age:%d\n",per->name,per->age);
		Pop_LinkStack(stack);
	}
}
 
int main(){
	test01();
	return 0;
}