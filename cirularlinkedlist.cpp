#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* next;

	//constructor
	Node(int val){
		this->data = val;
		this->next = NULL;
	}
};

void InsertAtStart(Node* &head,Node* &tail, int val){
	if(head==NULL){
		Node* node = new Node(val);
		head = node;
		tail = node;
		tail->next = head;
	}
	else{
		Node* node = new Node(val);
		node->next = head;
		head = node;
		tail->next = head;
	}
}

void Print(Node* &head){
	Node* temp = head;
	while(temp->next!=head){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<temp->data;
}

int main(){
	Node* head = new Node(2);
	Node* tail = head;
	//cout<<head->data<<" "<<tail->data<<"\n";
	//cout<<tail->next->data<<" "<<head->data<<"\n";
	
	InsertAtStart(head,tail,1);
	//cout<<head->data<<" "<<tail->data<<"\n";
	cout<<tail->next->data<<" "<<head->data<<"\n";


	InsertAtStart(head,tail,3);
	//cout<<head->data<<" "<<tail->data<<"\n";
	cout<<tail->next->data<<" "<<head->data<<"\n";
	

	Print(head);
}