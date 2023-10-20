#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *leftChild;
    struct node *rightChild;
};

struct node *root = NULL;
void insert(int data){
    struct node *tempNode = (struct node*) malloc(sizeof(struct node));
    struct node *current;
    struct node *parent;
    tempNode -> data = data;
    tempNode -> leftChild = NULL;
    tempNode -> rightChild = NULL;
    
    if(root == NULL){
        root = tempNode;
    } else{
        current = root;
        parent = NULL;
        while(1){
            parent = current;
            if(data < parent -> data){
                current = current -> leftChild;

                if(current == NULL){
                    parent -> leftChild = tempNode;
                    return;
                }
            } 
            else{
                current = current -> rightChild;
                if(current == NULL){
                    parent -> rightChild = tempNode;
                }
            }
        }
    }
}

struct node *search(int data)
{
    struct node *current = root;
    printf("Visiting element:");
    while(current -> data != data){
        if(current != NULL){
            printf("%d", current -> data);
        }
        if(current -> data > data){
            current = current -> leftChild;
        } else{
            current = current -> rightChild;
        }
        if(current == NULL){
            return NULL;
        }
    }
    return current;
};


void pre_order_traversal(struct node* root){
    if(root != NULL){
        printf("%d",root -> data);
        pre_order_traversal(root -> leftChild);
        pre_order_traversal(root -> rightChild);
    }
}

void in_order_traversal(struct node* root){
    if(root != NULL){
        in_order_traversal(root -> leftChild);
        printf("%d",root -> data);
        in_order_traversal(root -> rightChild);
    }
}

void post_order_traversal(struct node* root){
    if(root != NULL){
        post_order_traversal(root -> leftChild);
        post_order_traversal(root -> rightChild);
        printf("%d",root -> data);
    }
}

int main(){
    int i;
    int array[7] = {27,14,35,10,19,31,42};
    for(i = 0; i < 7; i++){
        insert(array[i]);
    }
    i = 31;
    struct node * temp = search(i);
    if(temp != NULL){
        printf("[%d] Element found.", temp -> data);
        printf("\n");
    } else{
        printf("[ x ] Element not found (%d).\n", i);
    }
    i = 15;
    temp = search(i);
    if(temp != NULL){
        printf("[%d] Element found.", temp -> data);
        printf("\n");
    } else{
        printf("[ x ] Element not found (%d).\n", i);
    }
    printf("\nPreorder traversal: ");
    pre_order_traversal(root);
    printf("\nInorder traversal: ");
    in_order_traversal(root);
    printf("\nPostorder traversal: ");
    post_order_traversal(root);
    printf("\n");
    return 0;
}
