//带头节点单向链表

#include<stdio.h>
#include<stdlib.h> 
#include<string.h>

//链表节点
typedef struct LINKNODE{
	void* data; //无类型指针，可以指向任何类型数据 
	struct  LINKNODE* next; 
}LinkNode; 
 
//链表结构体
typedef struct LINKLIST{
	LinkNode* head;
	int size; 
}LinkList; 
 
typedef struct PERSON{
	char name[64];
	int age; 
	int score; 
}Person; 
 
//打印函数指针 
typedef void(*PRINTLINKNODE)(void*); 
 
//初始化链表
LinkList* Init_LinkList();
//指定位置插入
void Insert_LinkList(LinkList* list,int pos,void* data);
//删除指定位置的值
void RemoveByPos_LinkList(LinkList* list,int pos); 
//获得链表长度
int Size_LinkList(LinkList* list); 
//查找
int Find_LinkList(LinkList* list,void* data); 
//返回第一个节点
void* Front_LinkList(LinkList* list); 
//打印链表节点 
void Print_LinkList(LinkList* list,PRINTLINKNODE print); 
//释放链表内存
void FreeSpace_LinkList(LinkList* list); 
 
/********************************************************************/ 
 
//初始化链表
LinkList* Init_LinkList(){
	//创建表头 LinkList
	LinkList* list = (LinkList*)malloc(sizeof(LinkList));
	list->size = 0;
	
	//创建头结点 LinkNode(Head) 不保存数据信息
	list->head = (LinkNode*)malloc(sizeof(LinkNode)); 
	list->head->data = NULL;
	list->head->next = NULL; 
	
	return list; 
	 
} 
//指定位置插入
void Insert_LinkList(LinkList* list,int pos,void* data){
	if(list==NULL){
		return ; 
	} 
	if(data==NULL){
		return ; 
	}  
	if(pos<0 || pos>list->size){
		pos = list->size; 
	} 
	
	//创建新的节点 LinkNode
	LinkNode* NewNode = (LinkNode*)malloc(sizeof(LinkNode));
	NewNode->data = data;
	NewNode->next = NULL;
	
	//找节点  辅助指针变量
	LinkNode* pCurrent = list->head;
	for(int i= 0;i<pos;i++){
		pCurrent = pCurrent->next; 
	} 
	//新节点入链表
	NewNode->next = pCurrent->next;
	pCurrent->next = NewNode; 
	 
	list->size++; 
}
//删除指定位置的值
void RemoveByPos_LinkList(LinkList* list,int pos){
	if(list==NULL){
		return ; 
	}  
	if(pos<0 || pos>=list->size){
		pos = list->size; 
	}
	
	//查找删除节点的前一个节点
	LinkNode* pCurrent = list->head;
	for(int i= 0;i<pos;i++){
		pCurrent = pCurrent->next; 
	} 
	LinkNode* pDel =  pCurrent->next;
	pCurrent->next =  pDel->next; 
	//释放删除节点的内存
	free(pDel);
	list->size--; 
} 
//获得链表长度
int Size_LinkList(LinkList* list){
	
	return list->size; 
} 
//查找
int Find_LinkList(LinkList* list,void* data){
	if(list==NULL){
		return -1; 
	} 
	if(data==NULL){
		return -1; 
	}  
	LinkNode* pCurrent = list->head->next;
	int i; 
	for(i= 0;i<=list->size;i++){
		if(pCurrent->data==data){
			break; 
		} 
		pCurrent = pCurrent->next; 
	}  
	
	return i; 
} 
//返回第一个节点
void* Front_LinkList(LinkList* list){
	return list->head->next->data; 
} 
//打印链表节点 
void Print_LinkList(LinkList* list,PRINTLINKNODE print){
	if(list==NULL){
		return ; 
	} 
	LinkNode* pCurrent = list->head->next;
	for(int i= 0;i<list->size;i++){
		print(pCurrent->data); 
		pCurrent = pCurrent->next; 
	}  
} 
//释放链表内存
void FreeSpace_LinkList(LinkList* list){
	if(list==NULL){
		return ; 
	} 
	LinkNode* pCurrent = list->head;
	while(pCurrent!=NULL){
		LinkNode* pNext =  pCurrent->next;
		free(pCurrent); 
		pCurrent = pNext; 
	} 
 
	//释放表头内存
	list->size = 0;
	free(list); 
	list = NULL;
} 
void MyPrint(void* data){
	Person* p =(Person*)data; 
	printf("Name:%s Age:%d Score%d \n",p->name,p->age,p->score); 
} 
 
/********************************************************************/ 
/********************************************************************/ 
 
void test01(){
	//创建链表
	LinkList* list =  Init_LinkList();
	
	//创建数据 
	Person p1 = {"a",16,100};
	Person p2 = {"b",17,101};
	Person p3 = {"c",18,102};
	Person p4 = {"d",19,103};
	Person p5 = {"e",20,104};
	
	//数据插入链表
	 Insert_LinkList(list,0,&p1); 
	 Insert_LinkList(list,1,&p2); 
	 Insert_LinkList(list,2,&p3); 
	 Insert_LinkList(list,3,&p4); 
	 Insert_LinkList(list,4,&p5); 
	 
	 //打印
	 Print_LinkList(list,MyPrint); 
	 printf("------------------------\n"); 
	 //删除
	RemoveByPos_LinkList(list,3); 
	//打印
	 Print_LinkList(list,MyPrint);
	 printf("------------------------\n"); 
	 //返回第一个节点
	 Person* ret = (Person*) Front_LinkList(list); 
	 printf("Name:%s Age:%d Score%d \n",ret->name,ret->age,ret->score); 
	 //销毁链表 
	 FreeSpace_LinkList(list);  
 
} 
 
 
/********************************************************************/ 
/********************************************************************/ 
 
int main(){
	test01(); 
	return 0; 
} 
 
 
//说明

/*
一、写链表，主要需要两个结构体：
       一个是表头LinkList（只要知道了表头的地址，就能往下找到每一个结点；表头还记录结点长度）

       一个是结点LinkNode（包括数据域和指针域，每个结点都是通过指针域串联起来）

二、初始化链表
       初始化链表主要有两部分操作，一是为表头LinkList申请内存，二是为头结点LinkNode(Head) 申请内存。
	   将头结点的地址赋    给表头的head，也就是说head相当于头结点LinkNode(Head) 。一切的操作都从head开始遍历。

三、添加第1个结点
       申请内存创建新结点NewNode，填充数据data，next指向空地址NULL，然后将头结点LinkNode(Head)的next指新结点 
	   NewNode的地址
	   
四、插入新节点
       和第三步的添加第一个结点差不多，只不过原来头结点是指向空的，现在的情况是头结点指向了第1个结点，我们可以在头
	   结点和第1个结点之间插入一个新结点，也就是第0个位置上插入新结点（pos = 0）
   
五、删除结点
       假如要删除第n个结点，则只需将第n-1个结点的Next指向第n+1个结点的地址即可

六、销毁链表
            既然在插入结点的时候，每一个结点都是申请了内存，那么最后销毁链表的时候也应该一一释放掉每个结点的内存。

            结点释放顺序规则：

               ·从当前头结点head开始

               ·用指针pNext保存下一个结点的地址

               ·释放当前结点，保存pNext的下一个结点的地址

               ·释放当前结点，保存pNext的下一个结点的地址

            ..........

 

            当结点的内存都释放之后，就要处理表头list了：

               ·将list的size置零

               ·释放list的内存

               ·将list置NULL
			   
*/
 