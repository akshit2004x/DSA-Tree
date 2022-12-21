#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * right;
    struct node * left;
};
struct node  * createnode(int d)
{
    struct node *n;
    n=(struct node *)malloc(sizeof(struct node));
    n->data=d;
    n->right=NULL;
    n->left=NULL;
    return n;
}
void inorder(struct node * root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void preorder(struct node * root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node * root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
struct node * searchiter(struct node * root,int key)
{
    while(root!=NULL)
    {
    if(key==root->data)
        return root;
    else if(key<root->data)
    {
        root=root->left;
    }
    else
    { 
        root=root->right;
    }
    }   
    return NULL;
}
void insert(struct node * root,int key)
{
    struct node * prev;
    while(root!=NULL)
    {
        prev=root;
        if(key==root->data)
        {
            printf("element is already");
            return;
        }
        else if(key<root->data)
        {
            root=root->left;
        }
        else if(key>root->data)
        {
            root=root->right;
        }
        struct node * new= createnode(key);
        if(key<prev->data)
            prev->left=new;
        else
            prev->right=new;
    }
    printf("eleement is inserted");
}
int  max(struct node * root)
{
    struct node * temp=root;
    while(temp->right!=NULL)
    {
        temp=temp->right;
    }
    return temp->data;
}
int min(struct node * root)
{
    struct node * temp=root;
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp->data;
}
struct node *inorderpredessor(struct node *root)
{
    root=root->left;
    while(root->right!=NULL)
    {
        root=root->right;
    }
    return root;
}
struct node *deletion(struct node * root,int value)
{
    struct node *ipre;
    if(root==NULL)
    {
        return NULL;
    }
    else if( root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    else if(value < root->data)
    {
        deletion(root->left,value);
    }
    else if(value > root->data)
    {
        deletion(root->right,value);
    }
    else
    {
        ipre = inorderpredessor(root);
        root->data=ipre->data;
        deletion(root->left,ipre->data);
    }
}
int getLeafCount(struct node* node)
{
  if(node == NULL)       
    return 0;
  if(node->left == NULL && node->right==NULL)      
    return 1;            
  else 
    return getLeafCount(node->left)+ getLeafCount(node->right);      
}
int nonleaf(struct node* root)
{
   if (root == NULL || (root->left == NULL && root->right == NULL)){
      return 0;
   }
   return 1 + nonleaf(root->left) + nonleaf(root->right);
}
int count(struct node * root)
{
    if(root==NULL)
        return 0;
    else
        return 1 +count(root->left) + count(root->right);
}
int sumofnodes(struct node *root)
{
    int rightsubtree=0,leftsubtree=0,sum = 0;
    if(root != NULL)
    {
        leftsubtree = sumofnodes(root->left);
        rightsubtree = sumofnodes(root->right);
        sum = (root->data) + leftsubtree + rightsubtree;
        return sum;
    }
}
int height(struct node * root)
{
    int c=count(root);
    int h;
    h=(c+1)/2;
    return h;
}
int main()
{
    struct node * p1,*p2,*p3,* p4,p5;
    p1=createnode(2);
    p2=createnode(1);
    p3=createnode(3);
    p4=createnode(4);
    p1->left=p2;
    p1->right=p3;
    p3->right=p4;
    printf("------------------------------------------------------------------------------------------------------------\nBinary Search Tree Menu\n------------------------------------------------------------------------------------------------------------\n0. Quit\n1. Create\n2. In-Order Traversal\n3. Pre-Order Traversal\n4. Post-Order Traversal\n5. Searching of a Key\n6. Find Smallest Element\n7. Find Largest Element\n8. Deletion of Node\n9. Total count number of external (leaf) nodes in the BST.\n10. Total count number of internal (non-leaf) nodes in the BST.\n11. Find number of nodes in the BST.\n12. Find sum of all nodes of the BST.\n13. Print height and depth of the BST.\n14. Find nodes which are at maximum depth in the BST\n-----------------------------------------------------------------------------------------------------------\nEnter your choice:");
    int ch,c;
    printf("enter choice");
    scanf("%d ",&ch);
    switch(ch)
    {
    case 0:
        printf("QUIT");
        break;
    case 1:
        insert(p1,7);
        break;
    case 2:
        printf("\nInorder traversal\n");
        inorder(p1);
        break;
    case 3:
        printf("\nPre order traversal\n");
        preorder(p1);
        break;
    case 4:
        printf("\nPost order traversal\n");
        postorder(p1);
        break;
    case 5:
        struct node *n =searchiter(p1,1);
        if(n!=NULL)
            printf("element is present ");
        else
            printf("element is not a present");
        break;
    case 6:
        c=min(p1);
        printf("\nMinimum element %d ",c);
        break;
    case 7:
        c=max(p1);
        printf("Maximum element %d ",c);
        break;
    case 8: 
        deletion(p1,2);
        printf("element deleted succesfully");
        break;
    case 9:
        printf("\nTotal count number of external (leaf) nodes in the BST is %d ",getLeafCount(p1));
        break;
    case 10:
        printf("\nTotal count number of internal (non-leaf) nodes in the BST is %d",nonleaf(p1));
        break;
    case 11:
        printf("\ntotal no of nodes %d",count(p1));
        break;
    case 12:
        printf("\ntotal sum of nodes %d",sumofnodes(p1));
        break;
    case 13:
        printf("\nheight = %d",height(p1));
        break;
    }
}