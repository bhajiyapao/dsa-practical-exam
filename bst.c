#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
   struct node *left;
   int data;
   struct node *right;
};
struct node *tree;
void createtree (struct node*);
struct node *insertelement(struct node*,int val);
void preordertraversal(struct node*);
void inordertraversal(struct node*);
void postordertraversal(struct node*);
int totalheight(struct node*);
int totalexternalnodes(struct node*);
int totalinternalnodes(struct node*);
struct node* smallestelement(struct node*);
struct node* largestelement(struct node*);
int totalnodes(struct node*);
struct node *deletetree(struct node*);
struct node *mirrorimage(struct node*);
struct node *deleteelement(struct node*,int val);
void createtree(struct node*  tree){
    tree = NULL;
}
struct node *insertelement(struct node* tree,int val){
    struct node *ptr,*parentptr,*nodeptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = val;
    ptr->left = NULL;
    ptr->right = NULL;
    if (tree == NULL)
    {
        tree = ptr;
        tree->left = NULL;
        tree->right = NULL;
    }
    else
    {
        nodeptr = tree;
        parentptr = NULL;
        while (nodeptr!= NULL)
        {
            parentptr = nodeptr;
            if (val<nodeptr->data)
            {
                nodeptr = nodeptr->left;
            }
            else
            {
                nodeptr = nodeptr->right;
            }
        }
        if (val<parentptr->data)
        {
            parentptr->left = ptr;
        }
        else
        {
            parentptr->right = ptr;
        }
    }
}                   
void preordertraversal(struct node *tree){
    if (tree != NULL)
    {
        printf("%d",tree->data);
        preordertraversal(tree->left);
        preordertraversal(tree->right);
    }
}    
void inordertraversal(struct node *tree){
    if (tree!= NULL)
    {
        inordertraversal(tree->left);
        printf("%d",tree->data);
        inordertraversal(tree->right);
    }
    
}    
void postordertraversal(struct node *tree){
    if (tree != NULL)
    {
        postordertraversal(tree->left);
        postordertraversal(tree->right);
        printf("%d",tree->data);
    }
}
int totalnodes(struct node *tree){
    if (tree == NULL)
    {
        return 0;
    }
    else
    {
        return (totalnodes(tree->left) + totalnodes(tree->right) + 1);
    }
}
int totalheight(struct node *tree){
    int height1,height2;
    if (tree!= NULL)
    {
        height1 = totalheight(tree->left);
        height2 = totalheight(tree->right);
        return (height1>height2) ? (height1+1) : (height2+1);
    }
}
int totalexternalnodes(struct node *tree){
    if (tree == NULL)
    {
        return 0;
    }
    else if (tree != NULL && tree->left == NULL && tree->right == NULL)
    {
        return 1;
    }
    else
    {
        return ( totalexternalnodes(tree->left) + totalexternalnodes(tree->right));
    }
}
int totalinternalnodes(struct node *tree){
    if (tree == NULL)
    {
        return 0;
    }
    else
    {
        return ( totalinternalnodes(tree->left) + totalinternalnodes(tree->right) + 1);
    }
}
struct node *smallestelement(struct node *tree){
    if (tree == NULL || tree->left == NULL)
    {
        return tree;
    }
    else
    {
        return smallestelement(tree->left);
    }
}
struct node *largestelement(struct node *tree){
    if (tree== NULL || tree->right == NULL)
    {
        return tree;
    }
    else
    {
        return largestelement(tree->right);
    }
}
struct node *deletetree(struct node *tree){
    if (tree != NULL)
    {
        deletetree(tree->left);
        deletetree(tree->right);
        free(tree);
    }
    
}
struct node *mirrorimage(struct node *tree){
    struct node *temp;
    if (tree != NULL)
    {
        mirrorimage(tree->left);
        mirrorimage(tree->right);
        temp = tree->left;
        tree->left = tree->right;
        tree->right = temp;
    }
    
}
struct node *deleteelement(struct node *tree,int val){
    struct node *temp;
    if (tree == NULL)
    {
        return NULL;
    }
    if (val<tree->data)
    {
        tree->left = deleteelement(tree->left,val);
    }
    else if (val>tree->data)
    {
        tree->right = deleteelement(tree->right,val);
    }
    else
    {
        if (tree->left == NULL && tree->right == NULL)
        {
            free(tree);
            return NULL;
        }
        else if (tree->left == NULL || tree->right == NULL)
        {
            if (tree->left == NULL)
            {
                temp = tree->right;
            }
            else
            {
                temp = tree->left;
            }
            free(tree);
            return temp;
        }
        else
        {
          temp = smallestelement(tree->right);
          tree->data = temp->data;
          tree->right = deleteelement(tree->right,temp->data);
        }   
    }
    return tree;
}