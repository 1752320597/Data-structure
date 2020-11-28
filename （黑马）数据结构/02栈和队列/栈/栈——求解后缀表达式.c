//栈——求解后缀表达式

/***
	求解后缀表达式：
		遍历后缀表达式中的数字和符号：
				对于数字：进栈
				对于符号：从栈中弹出数字作为右操作数
						  从栈中弹出数字作为左操作数
						  根据运算符进行运算
						  将运算结果压入栈中
		遍历结束：栈中唯一数字作为计算结果
***/
 
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
 
typedef struct MYCHAR{
	LinkNode node;
	char* p;
}MyChar;
 
typedef struct POSTFIX{
	char* poschar;
	int size;
}Postfix;
 
typedef struct MYNUM{
	LinkNode node;
	int val;
}MyNum;
 
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
 
 
 
 
//判断是否是数字
int IsNumber(char c){
	return c>='0'&&c<='9';
}
//判断是否是左括号
int IsLeft(char c){
	return c=='(';
}
//判断是否是右括号
int IsRight(char c){
	return c==')';
}
//判断是否是运算符
int IsOperate(char c){
	return c=='+'||c=='-'||c=='*'||c=='/';
}
//保存到后缀表达式中
void PreservePos(Postfix* str,char* p){
	str->poschar[str->size] = *p;
	str->poschar[str->size+1] = '\0';   //结束标志 
	str->size++;
	//printf("Now is %c\n",*p);
}
//输出数字
void NumberOperate(char* p,Postfix* str){
	PreservePos(str,p);
	printf("%c",*p);
}
//返回运算符号的优先级
int GetPriority(char c){
	if(c=='*'||c=='/'){
		return 2;
	}
	if(c=='+'||c=='-'){
		return 1;
	}
	return 0;
}
 
//创建MyChar
MyChar* CreatMyChar(char* p){
	MyChar* mychar = (MyChar*)malloc(sizeof(MyChar));
	mychar->p = p;
	return mychar;
}
//创建Postfix
Postfix* CreatPostfix(){
	Postfix* mypos = (Postfix*)malloc(sizeof(Postfix));
	char* mychar = (char*)malloc(100*sizeof(char));   //表达式的长度上限为100 
	mypos->poschar = mychar;
	mypos->size = 0;
	return mypos;
}
 
 
//左括号的操作
void LeftOperate(LinkStack* stack,char* p){
	Push_LinkStack(stack,(LinkNode*)CreatMyChar(p));
}
//右括号的操作
void RightOperate(LinkStack* stack,Postfix* str){
	while(Size_LinkStack(stack)>0){
				MyChar* mc = (MyChar*)Top_LinkStack(stack);
				//如果匹配到左括号
				if(IsLeft(*(mc->p))){
					Pop_LinkStack(stack);
					break;
				}
				PreservePos(str,mc->p);
				//输出
				printf("%c",*(mc->p));
				//弹出
				Pop_LinkStack(stack);
				//释放内存
				free(mc);
			}
}
//运算符号的操作
void OperateOperate(LinkStack* stack,char* p,Postfix* str){
	//取出栈顶符号
	MyChar* mc1 = (MyChar*)Top_LinkStack(stack);
	if(mc1==NULL){
		Push_LinkStack(stack,(LinkNode*)CreatMyChar(p));
		return ;
	}
	//如果栈顶优先级低，当前字符直接入栈
	if(GetPriority(*(mc1->p))<GetPriority(*p)){
		Push_LinkStack(stack,(LinkNode*)CreatMyChar(p));
		return ;
	}
	else
	{	//如果优先级高
		PreservePos(str,mc1->p);
		printf("%c",*(mc1->p));
		//弹出运算符 
		Pop_LinkStack(stack);
		//如果栈空了 
		if(Size_LinkStack(stack)==0){		
			Push_LinkStack(stack,(LinkNode*)CreatMyChar(p));
			return ;
		}
		while(Size_LinkStack(stack)>0){
			//printf("\nNow is %c\n",*p);
			MyChar* mc2 = (MyChar*)Top_LinkStack(stack);
			//如果优先级低  当前符号入栈
			if(GetPriority(*(mc2->p))<GetPriority(*p)){
				Push_LinkStack(stack,(LinkNode*)CreatMyChar(p));
				break;
			}
			PreservePos(str,mc2->p);
			printf("%c",*(mc2->p));
			//弹出运算符 
			Pop_LinkStack(stack);	
			free(mc2);
			//如果栈空了 
			if(Size_LinkStack(stack)==0){		
				Push_LinkStack(stack,(LinkNode*)CreatMyChar(p));
				return ;
			}
		}		
	}
	free(mc1);
}
 
//将中缀表达式转换成后缀表达式(字符串形式)
char* InToPos(char* p){
	
	LinkStack* stack = Init_LinkStack();
	Postfix* str = CreatPostfix();
	
	while(*p!='\0'){
		
		//如果是数字 
		if(IsNumber(*p)){
			NumberOperate(p,str);
		}
		//如果是左括号 
		if(IsLeft(*p)){
			LeftOperate(stack,p);
		}
		//如果是运算符 
		if(IsOperate(*p)){
			
			OperateOperate(stack,p,str);
		}
		//如果是右括号 
		if(IsRight(*p)){
			RightOperate(stack,str);
		}
		
		p++;
	}
	//将剩余在栈中的运算符都弹出
	while(Size_LinkStack(stack)>0){
		MyChar* mc = (MyChar*)Top_LinkStack(stack);
		PreservePos(str,mc->p);
		printf("%c",*(mc->p));
		Pop_LinkStack(stack);
		free(mc);
	}
	return str->poschar;
}
/******************************************/
/******************************************/
/******************************************/
int IfIsNumber(char c){
	return c>='0'&&c<='9';
}
int Caculate(char c,int left,int right){
	int ret;
	switch(c)
	{
		case '+':
			ret = left + right;
			break;
		case '-':
			ret = left - right;
			break;
		case '*':
			ret = left * right;
			break;
		case '/':
			ret = left / right;
			break;
	}
	return ret;
}
 
void DealPos(char* p){
 
	LinkStack* stack = Init_LinkStack();
	
	while(*p!='\0'){
		if(IfIsNumber(*p)){
			MyNum* mynum = (MyNum*)malloc(sizeof(MyNum));
			mynum->val = *p - '0';
			Push_LinkStack(stack,(LinkNode*)mynum);			
		}
		else{
			//弹出右操作数
			MyNum* right = (MyNum*)Top_LinkStack(stack);
			int rightNum = right->val;
			Pop_LinkStack(stack);
			free(right);
			//弹出左操作数
			MyNum* left = (MyNum*)Top_LinkStack(stack);
			int leftNum = left->val;
			Pop_LinkStack(stack);
			free(left);
			//运算
			int ret = Caculate(*p,leftNum,rightNum);
			//运算结果入栈
			MyNum* mynum = (MyNum*)malloc(sizeof(MyNum));
			mynum->val = ret;
			Push_LinkStack(stack,(LinkNode*)mynum);
		}
		p++;
	}
	if(Size_LinkStack(stack)==1){
		MyNum* mynum = (MyNum*)Top_LinkStack(stack);
		printf("the result is %d\n",mynum->val);
		free(mynum);
	}
	Free_LinkStack(stack);
}
 
void test01(){
	
	char* instr = "1+9*8*(1+2)-5/5";  
	char* p = instr;
	char* posstr = InToPos(p);
	printf("\nthe postfix is = %s\n",posstr);
	DealPos(posstr);
	
}
 
int main(){
	test01();
	return 0;
}