/*
 Documentation Section
 
 $Submitted by :-  MARUTHI R (1SI20AD009)

$Problem Statement  :-  Write a C program to delete a node in Binary tree

$Ref  Example:-
       5          
      / \
    6   4      
         / \
      8   5-> Right Deepest Node 
       
       $ Logic:
      We just Need to replace  the Deleting element with right deepest node and free the pointer pointing to right deepest node.
  
  */


#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
struct node *left,*right;
} node;

node *r=NULL; // Deep Node

node *insert()
{
    node *newnode;
    int a;
    printf("Enter data(-1 to insert NULL):");
    scanf("%d",&a);

    if(a==-1)
        return NULL;

    newnode=(node*)malloc(sizeof(node));
    newnode->data=a;

    printf("Enter left child of %d:\n",a);
    newnode->left=insert();

    printf("Enter right child of %d:\n",a);
    newnode->right=insert();

    return newnode;
}

void  preorder(node *temp) //Address of root node is passed in temp 
{

    if(temp!=NULL)
    {

        r=temp;
        printf(" %d",temp->data);
        preorder(temp->left);

        preorder(temp->right);
    }
}
// Function to In-order Traversal of tree
void inorder(node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }

}

node Delete(node *root,int key)
{
    if(root!=NULL)
    {
        Delete(root->left,key);
        if((root->data)==key)
        {
            root->data=r->data; //Swapping of Deepest element with Key data
            return;
        }
        Delete(root->right,key);
    }

}
int main()
{
    node *root,*temp;
    int key;
    root=insert();

    printf("\nThe preorder traversal of tree is:\n");
    preorder(root);
    printf("\n");

    printf("\nThe inorder traversal of tree is:\n");
    inorder(root);
    printf("\n");

    printf("\n\nRight Deepest Node  %d\n",r->data);
    printf("Enter data to Delete\n");
    scanf("%d",&key);
    Delete(root,key);
    free(r); //freeing the deepest  node in binary tree .

    printf("\nThe inorder traversal of tree after deletion is:\n");
    inorder(root);


    return 0;


}
