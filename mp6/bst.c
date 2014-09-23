/*
    Name: Michelle Cabahug
    NetID: cabahug2
    Lab Section: AD9
﻿*/

#include "bst.h"

NODE* getNewNode() //creates a node, allocates memory, returns pointer to node
{
    NODE* newNode = malloc(sizeof(NODE*));
    return newNode;
}

NODE* findMax(NODE *root) 
/*searches through tree with root *root and returns pointer to node with
  highest data value*/ 
{
    if(root == NULL)
    { 
        return NULL;
    }
    else{
        if(root->right == NULL)
        {
            return root;
        }   
        else
        {
            return findMax(root->right);
        }
    }
}

NODE* insert(NODE *root, int data)
/*recursively searches through structure until it finds the correct
  null pointer, creates a node using getNewNode(),
  reassigns pointers for continuity */
{
    if(root == NULL)
    { //if no node, make one
        NODE* newNode = getNewNode(); //allocate memory
        newNode->left = NULL; //set pointers to null
        newNode->right = NULL;
        newNode->data = data; //set data field
        root = newNode; //make sure to return pointer to this node
    }
    else
    {
        if(data < root->data)
        {
            //if smaller, node will be in left branch
            root->left = insert(root->left, data);
        }
        else if(data > root->data)
        {
            //if larger, node will be in right branch
            root->right = insert(root->right, data);
        }
    }
    return root;
}

NODE* delete(NODE *root, int data)
//recursively searches for a node with a data value equal to the parameter data
{
    NODE* maxNode;
    if(root == NULL)
    { 
        //if there's no node with the value data, print error
        printf("Element not found in tree.");
    }
    else
    {
        if(data < root->data)
        {
            //if smaller, node will be in left branch
            root->left = delete(root->left, data);
        }
        else if(data > root->data)
        {
            //if larger, node will be in right branch
            root->right = delete(root->right, data);
        }
        else if(root->data == data)
        {
            /*if both pointers exist,
              set the node's data to the data of the largest element in its left
              subtree and recursively delete that node*/
            if(root->right != NULL && root->left != NULL)
            { 
                maxNode = findMax(root->left);
                root->data = maxNode->data;
                root->left = delete(root->left,maxNode->data);
            }
            //if only left pointer, parent points to left child
            else if(root->left != NULL){
                root = root->left;
            }
            //if only right pointer, parent points to right child
            else if(root->right != NULL)
            {
                root = root->right;
            }
            else
            {
                return NULL;
            }
        }
    }
    return root;
}

void preorder(NODE *root)
//print each node, then branch left, then right
{
    if(root == NULL)
    { 
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
    return;
}

void inorder(NODE *root)
//branch left, then print each node, then branch right
{
    if(root == NULL)
    { 
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
    return;
}

void postorder(NODE *root)
//branch left, then right, then print each node
{
    if(root == NULL)
    { 
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
    return;
}

int main()
{
    int choice, data;
    NODE *root = NULL;
    while(1)
    {
        printf("----------------------------------\n");
        printf("Menu:\n");
        printf("----------------------------------\n");
        printf("1 - Insert\n");
        printf("2 - Delete\n");
        printf("3 - Pre-Order\n");
        printf("4 - In-Order\n");
        printf("5 - Post-Order\n");
        printf("6 - Exit\n");
        printf("----------------------------------\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the data to insert:");
                    scanf("%d",&data);
                    root = insert(root, data);
                    printf("Data inserted successfully\n");
                    break;
            case 2: printf("Enter the data to be deleted:");
                    scanf("%d",&data);
                    root = delete(root, data);
                    printf("Data deleted successfully\n");
                    break;
            case 3: printf("Pre-Order traversal: ");
                    preorder(root);
                    printf("\n");
                    break;
            case 4: printf("In-Order traversal: ");
                    inorder(root);
                    printf("\n");
                    break;
            case 5: printf("Post-Order traversal: ");
                    postorder(root);
                    printf("\n");
                    break;
            case 6: exit(0);
            default: printf("Invalid choice!\n");
                     continue;
        }
    }
    return 0;
}
