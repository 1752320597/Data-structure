//队列——顺序循环队列

#include<stdio.h>
#include<malloc.h>
#define State int
#define Ture 1
#define False 1
#define MAXSIZE 10   //队列容量为10，故实际能装填数组的大小为9（循环队列的满状态是指容量还剩1） 
 
typedef struct QUEUE
{
	int a[MAXSIZE];
	int rear;
	int front;
}Queue;
 
Queue* Init(){
	Queue* q = (Queue*)malloc(sizeof(Queue));
	q->rear = 0;
	q->front = 0;
	
	return q;
}
 
//入队 
State Push(Queue* Q,int e){
	if(Q==NULL){
		return False;	
	} 
		
	if( (Q->rear+1%MAXSIZE) == Q->front){  // (Q->rear+1%MAXSIZE) == Q->front  判断队列是否满了 
		return False; 
	}
	
	Q->a[Q->rear] = e ;      //入队 
	Q->rear = (Q->rear+1)%MAXSIZE;  //rear 向后移动 
	
	return Ture; 
}
 
//出队 
State Pop(Queue* Q,int *e){
	if(Q==NULL){
		return False;
	} 
	if( Q->rear == Q->front){  // Q->rear == Q->front  判断队列是否空 
		return False; 
	}
	
	*e = Q->a[Q->front]; 
	Q->front = (Q->front+1)%MAXSIZE;  //front 向后移动 （出队） 
	
	return Ture; 
}
 
//打印队列 
State Prinf(Queue* Q){
 	if(Q==NULL){
	 	return False;
	 } 
		
	if( Q->rear == Q->front){  // Q->rear == Q->front  判断队列是否空 
		return False; 
	}
	int i = Q->front; 
	printf("队列序列为：");
	do{
		printf("%d ",Q->a[i]); 
		i = (i+1)%MAXSIZE;
	}while(Q->rear != i); 
	
	printf("\n");
	return Ture; 
}
 
int main(){
	Queue* q = Init();
	for(int i = 0;i<MAXSIZE-1;i++){
		Push(q,i); 
	} 
	Prinf(q);
			
	int e = 0; 
	Pop(q,&e);
	printf("\n本次出队的元素为：%d\n",e); 
	
	Pop(q,&e);
	printf("\n本次出队的元素为：%d\n",e);
	Prinf(q);
	
	Push(q,9); 
	Push(q,10); 
	Prinf(q);
	
	return 0;
}


//说明

/*
顺序队列的数据成员有3个：数组、头下标、尾下标。其中，头尾两下标初始都是从0下标开始

typedef struct QUEUE
{
	int a[MAXSIZE];
	int front;
	int rear;
}Queue;



队列的数据操作是尾进、头出，即

queue[rear] = e ;    //尾进
rear ++;
 
front ++ ;   //头出

头尾位置：
front - - - - - rear
入队（rear + 1）

front - - - - - - rear
出队（front + 1）

  front - - - - - rear
 
循环队列
由于单纯的队列可能会出现空间未满，但是头尾下标却一直逼近数组的容量值，所以当头尾下标溢出数组容量时要及时转回初始的0下标

queue[rear] = e ;       //尾进 
rear = (rear+1)%MAXSIZE;  
 
front = (front+1)%MAXSIZE   //头出
*/