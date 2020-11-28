//二叉排序树 查找与插入

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Status int 
 
//二叉树结点
typedef struct BINARYNODE{
	int data;
	struct BINARYNODE* lchild;
	struct BINARYNODE* rchild;
}BinaryNode;
 
void Recursion1(BinaryNode* root);     //前序遍历
Status SearchBST(BinaryNode *&bt,int key);    //查找 
Status InsertBST(BinaryNode *&bt, int key);   //插入 
BinaryNode* CreateBST(int A[],int n);     //创建二叉排序树 
 
void CreateBinaryTree(){
	
	int a[5] = {5,4,7,8,3};
	BinaryNode* bitree = CreateBST(a,5);
 
	BinaryNode* &p = bitree; 
	
	printf("bitree树前序遍历1：\n");
	Recursion1(bitree);
	printf("\n");
	
	int key = 6; 
	printf("是否查找到%d:%s\n",key,SearchBST(p,key)==1?"是":"否"); 
	
	if(SearchBST(p,6)==0)
	   InsertBST(p,6);    
	   
	if(SearchBST(p,9)==0)
	   InsertBST(p,9);        
	
	printf("bitree树前序遍历2：\n");
	Recursion1(bitree);
	printf("\n");
}
 
Status SearchBST(BinaryNode *&bt,int key){
	
	if(!bt)
		return 0;
	else if(bt->data==key)
		return 1;
	else if(key<bt->data)
		return SearchBST(bt->lchild,key); 
	else
		return SearchBST(bt->rchild,key);	
}
 
Status InsertBST(BinaryNode *&bt, int key)
{
    if (!bt)
    {
        bt = (BinaryNode*)malloc(sizeof(BinaryNode));
        bt->data = key;
        bt->lchild = bt->rchild = NULL;
        return 1;
    }
    else if (key == bt->data)
        return 0;
    else if (key < bt->data)
        return InsertBST(bt->lchild, key);
    else
        return InsertBST(bt->rchild, key);
}
BinaryNode* CreateBST(int A[],int n)
{
    BinaryNode *bt = NULL;
    int i = 0;
    while(i < n)
    if (InsertBST(bt, A[i]) == 1)
    {
        printf(" 第%d步，插入%d:\n",i+1, A[i]);
        ++i;
    }
    return bt;
}
 
//前序遍历
void Recursion1(BinaryNode* root){
	
	if(root == NULL){
		return ;
	}
	printf("%d ",root->data);
	Recursion1(root->lchild);
	Recursion1(root->rchild);
}
 
int main(){
	CreateBinaryTree();
	return 0;
}
 