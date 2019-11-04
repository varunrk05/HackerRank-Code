#include <stdio.h>
#include <stdlib.h>

typedef struct Node *listPointer;
typedef struct Node{
	char data;
	listPointer next;
}listNode;

listPointer createNode()
{
	listPointer temp = (listPointer)malloc(sizeof(listNode));
	temp->next = temp;
	temp->data = '\0';
	return temp;
}

void insert(listPointer list, char x)
{
    //printf("insert\n");
	listPointer temp = createNode();
	listPointer p;
	temp->data = x;
	temp->next = list;
	if(list->next == list)
		list->next = temp;
	else{
		p = list->next;
		while(p->next != list)
			p = p->next;
		p->next = temp;
	}
}

void display(listPointer list)
{
	listPointer temp = list->next;

	if(temp != list)
	{
		while(temp->next != list)
		{
			printf("%c ", temp->data);
			temp = temp->next;
		}
		printf("%c ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
int main()
{
	listPointer list1 = createNode();
	listPointer list2 = createNode();
	listPointer list3 = createNode();
	int n,i;
	char x;

	printf("Enter size of List 1:\n");
	scanf("%d", &n);
	printf("Enter list in ascending order:\n");
	for (i = 0; i < n; ++i)
	{
		scanf(" %c",&x);
		insert(list1, x);
	}

	printf("Enter size of List 2:\n");
	scanf("%d", &n);
	printf("Enter list in ascending order:\n");
	for (i = 0; i < n; i++)
	{
		scanf(" %c",&x);
		insert(list2, x);
	}

    display(list1);
    printf("\n");
	display(list2);

	listPointer t1 = list1->next;
	listPointer t2 = list2->next;

	while(t1 != list1 && t2 != list2){
            //printf("\n\n 1st while");
		char c1 = t1->data;
		char c2 = t2->data;

		if(c1 > c2)
		{
			insert(list3, c2);
			t2 = t2->next;
		}
		else
		{
			insert(list3, c1);
			t1 = t1->next;
		}
	}

	while(t1 != list1)
	{
	    printf("\n\n 2nd while");
		insert(list3, t1->data);
		t1 = t1->next;
	}

	while(t2 != list2)
	{
	    printf("\n\n 3rd while");
		insert(list3, t2->data);
		t2 = t2->next;
	}

	printf("List 1 is:\n");
	display(list1);
	printf("List 2 is:\n");
	display(list2);
	printf("Merged list is:\n");
	display(list3);
	return 0;
}
