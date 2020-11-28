//企业链表

#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
 
//链点
typedef struct LINKNODE{
	struct  LINKNODE* next; 
}LinkNode;
 
//链表头节点 
typedef struct LINKLIST{
	LinkNode* head;
	int size; 
}LinkList; 
 
//遍历函数指针 
typedef void(*PRINTLINKNODE)(void*);
//比较函数指针 
typedef int(*COMPARENODE)(LinkNode*,LinkNode*);
 
//链表节点 
typedef struct PERSON{
	LinkNode node;
	char name[64];
	int age; 
}Person; 
 
//初始化链表 
LinkList* Init_LinkList();
//插入
void Insert_LinkList(LinkList* list,LinkNode* data);
//删除
void Remove_LinkList(LinkList* list,int pos);
//查找
int Find_LinkList(LinkList* list,LinkNode* data,COMPARENODE compare); 
//返回链表大小
int Size_LinkList(LinkList* list);
//打印
void Print_LinkList(LinkList* list,PRINTLINKNODE print); 
//释放链表内存
void  FreeSpace_LinkList(LinkList* list); 
 
/*************************************************************/
//初始化链表 
LinkList* Init_LinkList(){
	LinkList* list =  (LinkList*)malloc(sizeof(LinkList));
	list->head->next = NULL;
	list->size = 0;
	return list; 
} 
//插入
void Insert_LinkList(LinkList* list,int pos,LinkNode* data){
	
	if(list==NULL){
		return ; 
	} 
	if(pos < 0 || pos > list->size){
		pos = list->size; 
	}
	if(data==NULL){
		return ; 
	}
	
	//查找插入位置 
	LinkNode* pCurrent = list->head;
	for(int i=0;i<pos;i++){
		pCurrent =  pCurrent->next; 
	} 
	
	//插入新节点
	data->next =  pCurrent->next;
	pCurrent->next = data;
	
	list->size++; 
 
}
//删除
void Remove_LinkList(LinkList* list,int pos){
	if(list==NULL){
		return ; 
	}
	if(pos < 0 || pos > list->size){
		return ; 
	}
	
	LinkNode* pCurrent = list->head;
	for(int i=0;i<pos;i++){
		pCurrent =  pCurrent->next; 
	} 
		
	//删除节点 
	pCurrent->next =  pCurrent->next->next;
	
	list->size--; 
}
//查找
int Find_LinkList(LinkList* list,LinkNode* data,COMPARENODE compare){
	if(list==NULL){
		return -1; 
	}
	if(data==NULL){
		return -1; 
	}
	
	//辅助指针变量 
	LinkNode* pCurrent = list->head->next;
	int index = 0; 
	int flag = -1; 
	while(pCurrent!=NULL){
		if(compare(pCurrent,data) == 0){
			flag = index; 
			break; 
		} 
		pCurrent = pCurrent->next; 
		index++; 
	} 
	
	return flag; 
	 
}
//返回链表大小
int Size_LinkList(LinkList* list){
	
	return 0;	 
}
//打印
void Print_LinkList(LinkList* list,PRINTLINKNODE print){
	
	if(list==NULL){
		return ; 
	} 
	
	//辅助指针
	LinkNode* pCurrent = list->head->next; 
	while(pCurrent!=NULL){
		print(pCurrent); 
		pCurrent = pCurrent->next; 
	} 
} 
//释放链表内存
void  FreeSpace_LinkList(LinkList* list){
	
	if(list==NULL){
		return ; 
	} 
	free(list); 
}  
 
void MyPrint(void* data){
	Person* p =(Person*)data; 
	printf("Name:%s Age:%d \n",p->name,p->age); 
} 
 
int MyCompare(LinkNode* node1,LinkNode* node2){
	Person* p1 = (Person*) node1;
	Person* p2 = (Person*) node2;
	
	if(strcmp(p1->name,p2->name)==0 && p1->age == p2->age){
		return 0; 
	} 
	
	return -1; 
} 
 
int main(){
	
	//创建链表 
	LinkList* list = Init_LinkList();
	 
	//创建数据 
	Person p1,p2,p3,p4,p5;
	strcpy(p1.name,"a"); 
	strcpy(p2.name,"b");
	strcpy(p3.name,"c");
	strcpy(p4.name,"d");
	strcpy(p5.name,"e");
	
	p1.age = 10;
	p2.age = 11;
	p3.age = 12;
	p4.age = 13;
	p5.age = 14;
	
	//将节点插入链表
	Insert_LinkList(list,0,(LinkNode*)&p1); 
	Insert_LinkList(list,0,(LinkNode*)&p2); 
	Insert_LinkList(list,0,(LinkNode*)&p3); 
	Insert_LinkList(list,0,(LinkNode*)&p4); 
	Insert_LinkList(list,0,(LinkNode*)&p5); 
	
	Print_LinkList(list,MyPrint); 
	printf("--------------------------------\n"); 
	Remove_LinkList(list,2); 
	
	Print_LinkList(list,MyPrint); 
	printf("--------------------------------\n");
	
	Person findP;
	strcpy(findP.name,"d");
	findP.age = 13; 
	int pos  = Find_LinkList(list,(LinkNode*)&findP,MyCompare); 
	printf("pos = %d",pos); 
	
	FreeSpace_LinkList(list); 
 
	
	return 0;
} 


//说明

/*
企业链表与普通的链表的区别是，后者的结点包含数据域和指针域，而前者只有指针域。

因为指针的灵活性，只要将指针强转为任意一种数据结构的指针，便能拥有想要的数据元素。

假如我们只有某个LinkNode指针，那么可以强转为Person的指针，从而获得相应的数据成员。
*/