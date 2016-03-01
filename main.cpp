#include <iostream>
#include <string>
struct node;
typedef struct node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Postiton;

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Postiton P,List L);
Postiton Find(int x,List L);
void Delete(int x,List L);
Postiton FindPrevious(int x,List L);
void Insert(int x,List L,Postiton P);
void DeleteList(List L);
Postiton Header(List L);
Postiton First(List L);
Postiton Advance(Postiton P);
int Retrieve(Postiton P);

typedef struct node{
	int Data;
	Postiton Next;
}*Linklist;

int IsEmpty(List L)
{
	return L->Next == NULL;
}

int IsLast(Postiton P,List L)
{
	return P->Next == NULL;
}

Postiton Find(int x,List L)
{
	Postiton p;

	p = L->Next;
	while(p->Data != x && p->Next != NULL)
	{
		p = p->Next;
	}
	return p;
}

Postiton FindPrevious(int x,List L)
{
	Postiton p;
	p = L;
	while(p->Next->Data != x && p->Next != NULL)
	{
		p = p->Next;
	}
	return p;
}

void Delete(int x,List L)
{
	Postiton p,temp;
	p = FindPrevious(x,L);
	if (!IsLast(p,L))
	{
		temp = p->Next;
		p->Next = temp->Next;
		free(temp);
	}
}

void Insert(int x,List L,Postiton P)
{
	Postiton temp;
	temp = malloc(sizeof(struct node));
	if (temp == NULL)
	{
		FatalError("out of space!!");
	}
	temp->Data = x;
	temp->Next = P->Next;
	P->Next = temp;
}

void DeleteList(List L)
{
	Postiton P,temp;
	P = L->Next;
	L->Next = NULL;
	while(P != NULL)
	{
		temp = P->Next;
		free(P);
		P = temp;
	}
}