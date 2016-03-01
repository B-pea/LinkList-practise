//链表的主要操作 创建、删除、插入、输出、排序、反序、销毁

#include<stdlib.h>
#include<stdio.h>
#include <iostream>

using namespace std;
typedef struct node
{
	int data;
	struct node* next;
}*LinkList;

LinkList head = NULL;

bool create_new(int data)	//创建新表头
{
	head = (LinkList)malloc(sizeof(node));
	if (head == NULL)
	{
		return false;
	}
	head->data = data;
	head->next = NULL;
	return true;
}

bool add_node(int data,LinkList head)	//增加链表长度,表尾插入
{
	if (head == NULL)
	{
		return false;
	}

	LinkList new_node;
	new_node = (LinkList) malloc(sizeof(node));
	if (new_node == NULL)
	{
		return false;
	}
	new_node->data = data;
	new_node->next = NULL;
	
	while(head->next != NULL)
	{
		head = head->next;
	}
	head->next = new_node;
	return true;
}

bool insert_node(int data,LinkList head,int index)	//以值为索引的中间插入,索引之前
{
	if (head == NULL)
	{
		return false;
	}
	LinkList insert_node;
	insert_node = (LinkList)malloc(sizeof(node));
	if (insert_node == NULL)
	{
		return false;
	}
	insert_node->data = data;
	
	LinkList temp_node;
	temp_node = (LinkList)malloc(sizeof(node));
	if (temp_node == NULL)
	{
		return false;
	}
	temp_node = head;
	while(temp_node->next->data!=index && temp_node->next->next!=NULL)
	{
		temp_node = temp_node->next;
	}
	if (temp_node->next->data !=index && temp_node->next->next == NULL)
	{
		cout<<"index is not include!"<<endl;
		return false;
	}
	insert_node->next = temp_node->next;
	temp_node->next = insert_node;
	
	return true;
}

bool delete_node(int index,LinkList head)
{
	if (head == NULL)
	{
		return false;
	}
	LinkList temp_node = (LinkList)malloc(sizeof(node));
	if (temp_node == NULL)
	{
		return false;
	}
	temp_node = head;
	while(temp_node->next->data!=index && temp_node->next!=NULL)
	{
		int i = temp_node->next->data;
		temp_node = temp_node->next;
	}
	LinkList delete_node = (LinkList)malloc(sizeof(node));
	if (delete_node == NULL)
	{
		return false;
	}
	delete_node = temp_node->next;
	temp_node->next = delete_node->next;
	free(delete_node);
	
	return true;
}

bool out_list(LinkList head)
{
	if (head == NULL)
	{
		return false;
	}
	//LinkList temp_node = (LinkList)malloc(sizeof(node));
	//if (temp_node == NULL)
	//{
	//	return false;
	//}
	//temp_node = head;
	while(head!=NULL)
	{
		cout<<head->data<<endl;
		head = head->next;
	}
	cout<<endl;
	return true;
}

bool sort_list(LinkList head)
{
	LinkList first_temp = (LinkList)malloc(sizeof(node));
	LinkList next_temp = (LinkList)malloc(sizeof(node));
	if (first_temp == NULL && next_temp == NULL)
	{
		return false;
	}
	first_temp = head;
	int length_list = 0;
	while(first_temp!=NULL)
	{
		length_list++;
		first_temp = first_temp->next;
	}
	first_temp = head;
	int j = 0;
	int length_no = length_list;
	for (j;j<length_list;j++)
	{
		next_temp = first_temp->next;
		for (int i=0;i<length_no-1;i++)
		{
			int temp_data;
			if (first_temp->data > next_temp->data)
			{
				temp_data = next_temp->data;
				next_temp->data = first_temp->data;
				first_temp->data =temp_data;
				out_list(head);
				cout<<j<<endl;
				cout<<endl;
			}
			next_temp = next_temp->next;
		}
		first_temp = first_temp->next;
		length_no--;
	}
	return true;
}

void main ()
{
	create_new(1);
	for (int i = 2;i<10;i++)
	{
		add_node(i,head);
	}
	delete_node(4,head);
	insert_node(99,head,3);
	out_list(head);
	cout<<endl;
	sort_list(head);
	out_list(head);
}