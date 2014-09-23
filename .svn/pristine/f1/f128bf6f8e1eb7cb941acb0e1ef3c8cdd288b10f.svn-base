/*
    Name: Michelle Cabahug
    NetID: cabahug2
    Lab Section: AD9
﻿*/
#include "splay.h"

NODE* getNewNode() //creates a node, allocates memory, returns pointer to node
{
    NODE* newNode = malloc(sizeof(NODE*));
    return newNode;
}

NODE* insert_splay(NODE *root, int data)
{ /* Inserts data into appropriate node location, gets pointer to new node using search,
     Calls splay to arrange the tree with the newly inserted node, returns pointer and root of the tree  
  */
    NODE* node = NULL;
    root = insert(root,data);
    node = search(root,data);
    splay(node, &root);
    return root;
}

NODE* insert(NODE *root, int data)
{ /* recursively searches through structure until it finds the correct
  null pointer, creates a node using getNewNode(),
  reassigns pointers for continuity */
    
    if(root == NULL)
    { //if no node, make one
        NODE* newNode = getNewNode(); //allocate memory
        newNode->left = NULL; //set pointers to null
        newNode->right = NULL;
        newNode->parent = NULL;
        newNode->data = data; //set data field
        root = newNode; //make sure to return pointer to this node
    }
    else
    {
        if(data < root->data)
        {
            //if smaller, node will be in left branch
            root->left = insert(root->left, data);
            root->left->parent = root;
        }
        else if(data > root->data)
        {
            //if larger, node will be in right branch
            root->right = insert(root->right, data);
            root->right->parent = root;
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


NODE* search(NODE *root, int data)
{/* Two edge cases: if the root is null and if the data we're looking for is already inside of the root.
    Otherwise, compare root's data with the data we want. If the data we want is less than the root's 
    data, call search with the root's left. 
    If the data we want is greater than the root's data, call search with the root's right.
  */
    if(root == NULL)
    {
        return root;
    }
    if(root->data == data)
    {
        return root;
    }
    else if(data < root->data)
    {
        search(root->left, data);
    }
    else
    {
        search(root->right, data);
    }
    return root;
}

void left_rotate( NODE *node, NODE **root ) 
{ /*Single rotation. Makes the right leaf the parent. Right leaf's left child becomes 
    the parent's child.*/
    NODE* temp = node->right;
    node->right = temp->left;
    if(temp->left != NULL)
    {
        temp->left->parent = node;
    }
    temp->parent = node->parent;
    if(node->parent == NULL)
    {
        *root = temp;
    }
    else if(node->parent->left == node)
    {
        node->parent->left = temp;
    }
    else
    {
        node->parent->right = temp;
    }
    temp->left = node;
    node->parent = temp;
}
 
void right_rotate( NODE *node, NODE **root ) 
{/*Single rotation. Makes the left leaf the parent. Left leaf's right child becomes 
    the parent's child.*/
    NODE* temp = node->left;
    node->left = temp->right;

    if(temp->right != NULL)
    {
        temp->right->parent = node;
    }

    temp->parent = node->parent;
    
    if(node->parent == NULL)
    {
        *root =  temp;
    }

    else if(node == node->parent->left)
    {
        node->parent->left = temp;
    }    

    else
    {
        node->parent->right = temp;
    }

    temp->right = node;
    node->parent = temp;
}

void splay(NODE *node , NODE **root) 
{ /* Performs zig zig, or zig zag, depending on the node's parent and grandparent.*/
    while(node->parent != NULL)
    {
        if(node->parent->parent == NULL) //if no grandparent
        {
            if(node->parent->left == node) //if node is the left most leaf
            {
                right_rotate(node->parent, root); //rotates left leaf to parent
            }
            else
            {
                left_rotate(node->parent, root); //otherwise node is right leaf, so do left_rotate 
            }
        }
        else if(node->parent->left == node && node->parent->parent->left == node->parent)
        { /*if node is left leaf and the parent of the node is the left of the grandparent,
            right rotate both the grandparent/parent and then the parent/node. This is zig zig. */
            right_rotate( node->parent->parent, root);
            right_rotate( node->parent, root);
        }
        else if(node->parent->right == node && node->parent->parent->right == node->parent)
        { /*if node is right leaf and the parent of the node is the right of the grandparent,
            left rotate both the grandparent/parent and then the parent/node. This is also zig zig.*/
            left_rotate( node->parent->parent, root);
            left_rotate( node->parent, root);
        }
        else if(node->parent->left == node && node->parent->parent->right == node->parent)
        {/*if node is left leaf, but the parent of the node is the right of the grandparent,
            left rotate the grandparent/parent and right rotate the parent/node. This is zig zag. */
            right_rotate(node->parent, root);
            left_rotate(node->parent, root);
        }
        else
        { /*if node is right leaf, but the parent of the node is the left of the grandparent,
            right rotate the grandparent/parent and left rotate the parent/node. This is zig zag. */
            left_rotate(node->parent , root);
            right_rotate(node->parent , root);
        }
    }
}

void freeAll(NODE* root){
    if(root == NULL){ return; }
    if(root->left == NULL && root->right == NULL)
    {
        free(root);
        return;
    }
    else
    {
        if(root->left != NULL)
        {
            freeAll(root->left);
        }
        if(root->right != NULL)
        {
            freeAll(root->right);
        }
    }
    
}

int main()
{
    int choice, data;
    NODE *root = NULL;
    NODE *temp = NULL;
    while(1)
    {
        printf("----------------------------------\n");
        printf("Menu:\n");
        printf("----------------------------------\n");
        printf("1 - Insert\n");
        printf("2 - Pre-Order\n");
        printf("3 - In-Order\n");
        printf("4 - Post-Order\n");
        printf("5 - Exit\n");
        printf("----------------------------------\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: printf("Enter the data to insert:");
                    scanf("%d",&data);
                    root = insert_splay(root, data);
                    printf("Data inserted successfully\n");
                    break;
            case 2: printf("Pre-Order traversal: ");
                    preorder(root);
                    printf("\n");
                    break;
            case 3: printf("In-Order traversal: ");
                    inorder(root);
                    printf("\n");
                    break;
            case 4: printf("Post-Order traversal: ");
                    postorder(root);
                    printf("\n");
                    break;
            case 5: freeAll(root);
                    exit(0);
            default: printf("Invalid choice!\n");
                     continue;
        }
    }
    return 0;
}
