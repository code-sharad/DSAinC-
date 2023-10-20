#include <stdio.h>
#include <stdlib.h>
#define maxsize 5

void insert();
void del();
void display();

int front = -1 , rear = -1;
int queue[maxsize];
int main(){

    int choice;
    while (choice != 4)
    {
        printf("\n ********  Main Menu  *********\n");
        printf("\n1.Insert and element\n2.Delete an element\n3.Display the queue\n4.Exit\n");
        printf("\nEnter the choice?");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                insert();
                break;
            case 2:
                del();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\n Enter valid choice?\n");
            
        }

    }
    
}


void insert(){
    int item;
    printf("\n Enter the element\n");
    scanf("\n%d",&item);
    if(rear == maxsize){
        printf("\n OVERFLOW\n");
        return;
    }
    if(front == -1 && rear == -1){
        front = 0;
        rear = 0;
    }
    else{
        rear = rear + 1;
    }

    queue[rear] = item;
    printf("\n Value inserted");
}

void del(){
    int item;
    if(front == -1 || front > rear){
        printf("\nUNDERFLOW\n");
        return;
    }
    else{
        item = queue[front];
        if(front == rear){
            front = -1;
            rear = -1;
        }
        else{
            front = front + 1;
        }
        printf("\n value deleted");
    }
}


void display(){
    int i;
    if(rear ==-1){
        printf("\n Empty queue\n");
    }
    else{
        printf("\n printing values.... \n");
        for(i=front;i<=rear;i++){
            printf("\n%d\n",queue[i]);
        }
    }
}