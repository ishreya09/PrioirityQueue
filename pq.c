// create an unordered linked list and apply the priority queue operations on it

#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int data;
    int priority;
	struct node *link;
};
typedef struct node node_t;
struct mylist
{
    node_t* head;
};
typedef struct mylist mylist_t;


void insert(mylist_t* value) 
{
    value->head=NULL;
}

int len(mylist_t* value)
{
    if(!(value->head))
        return 0;
    int i=0;
    node_t* n=value->head;
    while(n)
    {
        i++;
        n=n->link;
    }
    return i;
}
void enqueue(mylist_t* value)
{
    node_t* temp=value->head;
    value->head=(node_t*)malloc(sizeof(node_t));
    value->head->link=temp;
    scanf("%d %d",&(value->head->data),&(value->head->priority));
}
void dequeue(mylist_t* value)
{
    int length=len(value);
    node_t* temp=value->head;
    node_t* ele=(node_t*)malloc(length*sizeof(node_t));
    node_t* n=value->head;
    for(int i=0;i<length;i++)
    {
        ele[i]=*n;
        n=n->link;
    }
    int m=0;
    for(int i=1;i<length;i++)
    {
        if(ele[i].priority>=ele[m].priority)
            m=i;
    }
    if(!m)
    {
        node_t* temp=ele[0].link;
        printf("deleted %d\n",value->head->data);
        free(value->head);
        value->head=temp;
    }
    else
    {
        node_t* temp=ele[m].link;
        printf("deleted %d\n",ele[m].data);
        node_t* max=value->head;
        for(int i=0;i<m-1;i++)
        {
            max=max->link;
        }
        free(max->link);
        max->link=temp;
        
    }   
}



void display(mylist_t* value)
{
	if(!(value->head))
        printf("No Elements");
    else
    {
        int length=len(value);
        node_t* ele=(node_t*)malloc(length*sizeof(node_t));
        node_t* n=value->head;

        for(int i=0;i<length;i++)
        {
            printf("%d %d\n",n->data,n->priority);
            n=n->link;
        }
    }
}

int main() 
{
        printf("+++++++++++++++++++++++++++++++++++++++++++\n");
        printf("+               FUNCTIONS                 +\n");
        printf("+       1. Add the Element                +\n");
        printf("+       2. Remove the Element             +\n");
        printf("+       3. print the Elements             +\n");
        printf("+       4. Exit                           +\n");
        printf("+++++++++++++++++++++++++++++++++++++++++++\n");
	mylist_t value;
    insert(&value);
    char n;
	
	while ((n=getchar())!=EOF)
    {   
    	
		
		switch (n-'0')
        {
		    case 1:enqueue(&value);
		    break;
		    case 2:dequeue(&value);
		    break;
		    case 3:display(&value);
		    break;
		
		}
        if (n >= '4'){
            break;
        }
	}
	return 0;
}
