Node* abc(int in[],int post[],int is,int ie,int &preIndex)
{
    if(is>ie)
    {
        return NULL;
    }
    Node *root=new Node(post[preIndex--]);
    int index;
    for(int i=is;i<=ie;i++)
    {
        if(in[i]==root->data)
        {
         index=i;
        break;
        }
    }
    root->right=abc(in,post,index+1,ie,preIndex);
    root->left=abc(in,post,is,index-1,preIndex);
    
return root;
}
Node* buildTree(int in[],int post[], int n)
{
    int preIndex=n-1;
    int is=0;int ie=n-1;
Node *root1=abc(in,post,is,ie,preIndex);
return root1;
}