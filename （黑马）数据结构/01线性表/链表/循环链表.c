//循环链表


#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#define CIRCLELINKLIST_TRUE 1
#define CIRCLELINKLIST_FALSE 0
 
 
//链表的小结点
typedef struct CIRCLELINKNODE{
	struct CIRCLELINKNODE* next;
}CircleLinkNode;
 
//链表的结构体
typedef struct CIRCLELINKLIST{
	CircleLinkNode head;
	int size;
}CircleLinkList;
 
typedef struct PERSON{
	CircleLinkNode node;
	char name[64];
	int age;
	int score;
}Person;
 
 
//比较回调
typedef int(*COMPARENODE)(CircleLinkNode*,CircleLinkNode*); 
//打印回调
typedef void(*PRINTNODE)(CircleLinkNode*); 
 
//编写针对链表结构体操作的API函数
 
//初始化
CircleLinkList* Init_CircleLinkList();
//插入
void Insert_CircleLinkList(CircleLinkList* clist,int pos,CircleLinkNode* data);
//获得第一个元素
CircleLinkNode* Front_CircleLinkList(CircleLinkList* clist);
//根据位置删除
void RemoveByPos_CircleLinkList(CircleLinkList* clist,int pos);
//根据值删除
void RemoveByValue_CircleLinkList(CircleLinkList* clist, CircleLinkNode* data, COMPARENODE compare);
//获得链表长度
int Size_CircleLinkList(CircleLinkList* clist);
//判断是否为空
int IsEmpty_CircleLinkList(CircleLinkList* clist);
//查找
int Find_CircleLinkList(CircleLinkList* clist,CircleLinkNode* data,COMPARENODE compare);
//打印节点
void Print_CircleLinkList(CircleLinkList* clist,PRINTNODE print);
//释放内存
void FreeSpace_CircleLinkList(CircleLinkList* clist); 
 
//初始化
CircleLinkList* Init_CircleLinkList(){
	CircleLinkList* clist = (CircleLinkList*)malloc(sizeof(CircleLinkList));
	clist->head.next = &(clist->head);   //这句话的存在就决定了这是个循环链表,表示最新的一个结点都会指向头结点！ 
	clist->size = 0;
	
	return clist;
}
//插入
void Insert_CircleLinkList(CircleLinkList* clist,int pos,CircleLinkNode* data){
	if(clist==NULL){
		return ;
	}
	
	if(data==NULL){
		return ;
	}
	
	if(pos<0||pos>clist->size){
		pos = clist->size;
	}
	
	//根据位置查找节点
	//辅助指针变量
	CircleLinkNode* pCurrent = &(clist->head);
	for(int i = 0;i<pos;i++){
		pCurrent = pCurrent->next;
	}
	
	//新数据入链表
	data->next = pCurrent->next;
	pCurrent->next = data;
	
	clist->size++;
	
}
//获得第一个元素
CircleLinkNode* Front_CircleLinkList(CircleLinkList* clist){
	return clist->head.next;
}
//根据位置删除
void RemoveByPos_CircleLinkList(CircleLinkList* clist,int pos){
	if(clist==NULL){
		return ;
	}
	
	if(pos<0||pos>=clist->size){
		return;
	}
	
	//根据pos找节点
	//辅助指针变量
	CircleLinkNode* pCurrent  = &(clist->head);
	for(int i = 0;i<pos;i++){
		pCurrent = pCurrent->next;
	}
	
	//缓存当前节点的下一个节点
	CircleLinkNode* pNext = pCurrent->next;
	pCurrent->next = pNext->next;
	
	clist->size--;
}
//根据值删除
void RemoveByValue_CircleLinkList(CircleLinkList* clist, CircleLinkNode* data, COMPARENODE compare){
	if(clist==NULL){
		return ;
	}
	
	if(data==NULL){
		return;
	}
	
	//这是循环链表
	CircleLinkNode* pPrev = &(clist->head);
	CircleLinkNode* pCurrent = pPrev->next;
	int i;
	for(i = 0;i<clist->size;i++){
		if(compare(pCurrent,data) == CIRCLELINKLIST_TRUE){
			pPrev->next = pCurrent->next;
			break;
		}
		pPrev = pCurrent;
		pCurrent = pPrev->next;
	}
	
	clist->size--;
}
//获得链表长度
int Size_CircleLinkList(CircleLinkList* clist){
	
	return clist->size;
}
//判断是否为空
int IsEmpty_CircleLinkList(CircleLinkList* clist){
	if(clist==NULL){
		return CIRCLELINKLIST_TRUE;
	}
	return CIRCLELINKLIST_FALSE;
}
//查找
int Find_CircleLinkList(CircleLinkList* clist,CircleLinkNode* data,COMPARENODE compare){
	if(clist==NULL){
		return -1;
	}
	
	if(data==NULL){
		return -1;
	}
	
	CircleLinkNode* pCurrent = clist->head.next;
	int i;
	int flag = -1;
	for(i = 0;i<clist->size;i++){
		if(compare(pCurrent,data)==CIRCLELINKLIST_TRUE){
			flag = i;
			break;
		}
		pCurrent = pCurrent->next;
	}
	return flag;
}
//打印节点
void Print_CircleLinkList(CircleLinkList* clist,PRINTNODE print){
	if(clist==NULL){
		return ;
	}
	
	CircleLinkNode* pCurrent = clist->head.next;
	//打印
	for(int i = 0;i<clist->size;i++){
		
		//这个判断是为了跳过头结点（即空数据的节点） 
		if(pCurrent==&(clist->head)){
			pCurrent = pCurrent->next;
		}
		print(pCurrent);
		pCurrent = pCurrent->next;
	}
	printf("\n");
}
//释放内存
void FreeSpace_CircleLinkList(CircleLinkList* clist){
	if(clist==NULL){
		return ;
	}
	free(clist);
}
 
void MyPrint(CircleLinkNode* data){
	Person* p = (Person*) data;
	printf("Name:%s  Age:%d  Score:%d\n",p->name,p->age,p->score);
	
}
 
int MyCompare(CircleLinkNode* data1,CircleLinkNode* data2){
	Person* p1 = (Person*)data1;
	Person* p2 = (Person*)data2;
	
	if(strcmp(p1->name,p2->name)==0)
		if(p1->age==p2->age)
			if(p1->score==p2->score)
				return CIRCLELINKLIST_TRUE;
				
	return CIRCLELINKLIST_FALSE;
}
 
 
void test01(){
	CircleLinkList* clist = Init_CircleLinkList();
	
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
	
	p1.score = 60;
	p2.score = 70;
	p3.score = 80;
	p4.score = 90;
	p5.score = 100;
	
	Insert_CircleLinkList(clist,100,(CircleLinkNode*)&p1);
	Insert_CircleLinkList(clist,100,(CircleLinkNode*)&p2);
	Insert_CircleLinkList(clist,100,(CircleLinkNode*)&p3);
	Insert_CircleLinkList(clist,100,(CircleLinkNode*)&p4);
	Insert_CircleLinkList(clist,100,(CircleLinkNode*)&p5);
	
	//打印
	Print_CircleLinkList(clist,MyPrint);
	
	Person pDe1;
	strcpy(pDe1.name,"d");
	pDe1.age= 40;
	pDe1.score = 90;
	
	//
	RemoveByValue_CircleLinkList(clist,(CircleLinkNode*)&pDe1,MyCompare);
	
	
	Print_CircleLinkList(clist,MyPrint);
	
	//释放内存
	FreeSpace_CircleLinkList(clist);
}
 
int main(){
	test01();
	
	return 0;
}
 