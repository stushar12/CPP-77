#include<bits/stdc++.h>
using namespace std;

struct Node 
{
	int data; 
	Node* left;
	Node* right;
};

Node* GetNewNode(int data) 
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

Node* Insert(Node* root,int data) 
{
	if(root == NULL)                                      // empty tree
    {                                           
		root = GetNewNode(data);
	}
	
	else if(data <= root->data)                         // if data to be inserted start lesser, insert inorder left subtree. 
    {
		root->left = Insert(root->left,data);
	}
	
	else                                                // else, insert inorder right subtree. 
    {
		root->right = Insert(root->right,data);
	}
	return root;
}

Node* inorder_and_preorder(int inorder[],int postorder[],int start,int end,int &postorder_index)
{
    if(start>end)
    {
        return NULL;
    }
    Node* root = GetNewNode(postorder[postorder_index--]);
    int index;
    for(int i=start;i<=end;i++)
    {
        if(inorder[i]==root->data)
        {
         index=i;
        break;
        }
    }
    root->right=inorder_and_preorder(inorder,postorder,index+1,end,postorder_index);
	root->left=inorder_and_preorder(inorder,postorder,start,index-1,postorder_index);
return root;
}

Node* buildTree(int inorder[],int postorder[], int n)
{
    int postorder_index=n-1;
    int start=0;
	int end=n-1;
	Node *root1=inorder_and_preorder(inorder,postorder,start,end,postorder_index);
	return root1;
}
