#include<bits/stdc++.h>
using namespace std;

//�����ṹ 
struct node{
	int val;
	struct node *next;
};

class LinkList {
private:
	node *head;
public:
	LinkList() { 
		head=new node; head->val=0; head->next=NULL; 
	}
	~LinkList();
	bool isEmpty();		//�ж��Ƿ�Ϊ�� 
	int getLength();	//��ó��� 
	void getElem(int idx,node *e);		//���ָ��λ�õ�Ԫ�ط���e 
	int findElem(int val);	//Ѱ��ֵΪval��Ԫ�� 
	void insertToEnd(int val);		//���뵽����β 
	void insertNode(node *e,int val);	//��e������һ���� 
	void insertByIndex(int idx,int val);	//���뵽ָ��λ�� 
	void deleteNode(node *e);  	//ɾ�����e����һ����� 
	void deleteByIndex(int idx);	//ɾ��ָ��λ��Ԫ�� 
	node* reverse();	//��ת���� 
	void print();	//��ӡ���� 
};

LinkList::~LinkList() {
	while (head->next!=NULL) deleteByIndex(0);
	delete(head);
} 

bool LinkList::isEmpty() {
	return head->next==NULL;
}

int LinkList::getLength() {
	int len=0; node *p=head;
	while (p->next!=NULL) {
		p=p->next;
		len++;
	} 
	return len;
}

void LinkList::getElem(int idx,node *e) {
	node *p=head; e=NULL; int k=0;
	while (p->next!=NULL) {
		p=p->next;
		if (k==idx) e=p;
		k++;
	}
}

int LinkList::findElem(int val) {
	int k=0; node *p=head;
	while (p->next!=NULL) {
		p=p->next; 
		if (p->val==val) return k;
		k++;
	}
	return -1;  //�Ҳ��� 
}

void LinkList::insertNode(node *p,int val) {
	node *pre=p; 
	node *nxt=pre->next;
	node *newNode=new node;
	newNode->val=val;
	newNode->next=nxt;
	pre->next=newNode;
}

void LinkList::insertToEnd(int val) {
	if (isEmpty()) insertNode(head,val);
	else insertByIndex(getLength()-1,val);
} 

void LinkList::insertByIndex(int idx,int val) {
	node *p=head; idx++;
	if (idx>getLength()) return;
	while (idx>0) { idx--; p=p->next; }
	insertNode(p,val);
}

void LinkList::deleteNode(node *e) {
	node *pre=e->next;
	node *nxt=pre->next;
	e->next=nxt;
	delete pre;
}

void LinkList::deleteByIndex(int idx) {
	node *p=head;
	if (idx>getLength()) return;
	while (idx>0) { p=p->next; idx--; }
	deleteNode(p);
}

node* LinkList::reverse() {
	if (getLength()==0 || getLength()==1) return head;
	node *p1=NULL;
	node *p2=head->next;
	node *p3=p2->next;
	while (p2!=NULL) {
		p2->next=p1;
		p1=p2; p2=p3; 
		if (p3!=NULL) p3=p3->next;
	}
	head->next=p1;
	return head;
}

void LinkList::print() {
	node *p=head;
	while (p->next!=NULL) {
		p=p->next;
		cout<<p->val<<"->";
	}
	cout<<"NULL"<<endl;
}

int main()
{
	LinkList link;
	
	link.insertToEnd(1); link.insertToEnd(2); link.insertToEnd(3); link.insertToEnd(4); link.insertToEnd(5);  
	link.print();
	
	link.insertByIndex(link.findElem(3),9);
	link.insertByIndex(link.findElem(1),7);
	link.print();
	
	link.deleteByIndex(link.findElem(1));
	link.deleteByIndex(link.findElem(4));
	link.print();
	
	link.reverse();
	link.print();
	return 0;
} 
