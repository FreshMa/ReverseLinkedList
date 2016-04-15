#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char** argv) {
	pNode p;
	p = Create();
	
	cout << "Before reverse:" << endl;
	Display(p);

	p = Reverse(p);
	cout << "After reverse:" << endl;
	Display(p);

	p = Reverse2(p);
	cout << "After reverse2:" << endl;
	Display(p);

	system("pause");
	return 0;
}

pNode Create(){
	//带头节点的单链表
	pNode head = (pNode)malloc(sizeof(pNode));
	//一个用作标记的temp变量
	pNode temp = head;
	head->ele = -1;
	head->next = NULL;
	//循环建立单链表
	for (int i = 1; i <= 10; i++){
		//建立结点并初始化
		pNode node = (pNode)malloc(sizeof(pNode));
		node->ele = i;
		node->next = NULL;
		temp->next = node;
		//temp向后移动，始终指向尾结点
		temp = node;
		//cout << "success" << " " << i << endl;
	}

	return head;
}

//不断地交换头节点下一个结点与标记结点后面的结点的位置，直到链表末尾，交换完成
//空间消耗为O(1)
pNode Reverse(pNode a){
	pNode stable, flag, temp;
	stable = flag = a->next;
	//flag用来标记在原链表中顺序最前的结点，不断向后移动
	while (flag->next){
		//temp保存flag之后的第二个结点，因为flag->next的下一个结点会指向a->next，即stable
		temp = flag->next->next;
		a->next = flag->next;
		a->next->next = stable;
		//变量stable一直指向a->next；
		stable = a->next;

		flag->next = temp;
		
	}
	return a;
}

//第二种是建立一个新的链表，采取尾插法，从原链表上摘一个放到新链表上
//空间消耗为O(n)
pNode Reverse2(pNode a){
	pNode f1, f2;
	pNode h = (pNode)malloc(sizeof(pNode));
	
	h->ele = -1;
	h->next = NULL;
	f1 = a->next;
	f2 = h;
	while (f1){
		//定义temp变量并初始化
		pNode temp = (pNode)malloc(sizeof(pNode));
		temp->ele = f1->ele;
		//开始尾插
		temp->next = f2->next;
		f2->next = temp;

		f1 = f1->next;
	}
	return h;

}

void Display(pNode a){
	pNode q = a->next;
	while (q){
		cout << q->ele <<" ";
		q = q->next;
	}
	cout << endl;
}