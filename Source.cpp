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
	//��ͷ�ڵ�ĵ�����
	pNode head = (pNode)malloc(sizeof(pNode));
	//һ��������ǵ�temp����
	pNode temp = head;
	head->ele = -1;
	head->next = NULL;
	//ѭ������������
	for (int i = 1; i <= 10; i++){
		//������㲢��ʼ��
		pNode node = (pNode)malloc(sizeof(pNode));
		node->ele = i;
		node->next = NULL;
		temp->next = node;
		//temp����ƶ���ʼ��ָ��β���
		temp = node;
		//cout << "success" << " " << i << endl;
	}

	return head;
}

//���ϵؽ���ͷ�ڵ���һ��������ǽ�����Ľ���λ�ã�ֱ������ĩβ���������
//�ռ�����ΪO(1)
pNode Reverse(pNode a){
	pNode stable, flag, temp;
	stable = flag = a->next;
	//flag���������ԭ������˳����ǰ�Ľ�㣬��������ƶ�
	while (flag->next){
		//temp����flag֮��ĵڶ�����㣬��Ϊflag->next����һ������ָ��a->next����stable
		temp = flag->next->next;
		a->next = flag->next;
		a->next->next = stable;
		//����stableһֱָ��a->next��
		stable = a->next;

		flag->next = temp;
		
	}
	return a;
}

//�ڶ����ǽ���һ���µ�������ȡβ�巨����ԭ������ժһ���ŵ���������
//�ռ�����ΪO(n)
pNode Reverse2(pNode a){
	pNode f1, f2;
	pNode h = (pNode)malloc(sizeof(pNode));
	
	h->ele = -1;
	h->next = NULL;
	f1 = a->next;
	f2 = h;
	while (f1){
		//����temp��������ʼ��
		pNode temp = (pNode)malloc(sizeof(pNode));
		temp->ele = f1->ele;
		//��ʼβ��
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