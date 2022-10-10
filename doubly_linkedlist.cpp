#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* prev;
	Node* next;

	//constructor
	Node(int d){
		this->data = d;
		this->prev = NULL;
		this->next = NULL;
	}
};

void print(Node* &head){
	Node* temp = head;
	while(temp){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}


void InsertAtStart(Node* &head, int val){
	Node* node = new Node(val);
	node->next = head;
	head->prev = node;
	head = node;
}

void InsertAtEnd(Node* &head, int val){
	Node* node = new Node(val);
	Node* curr = head;
	while(curr->next!=NULL){
		curr = curr->next;
	}
	curr->next = node;
	node->prev = curr;
	node->next = NULL;
}


void InsertAtPosition(Node* &head, int val, int pos){
	Node* node = new Node(val);
	Node* dummy = new Node(0);
	dummy->next = head;
	Node* prev = dummy;
	Node* curr = head;
	while(pos-1>0){
		prev = curr;
		curr = curr->next;
		pos--;
	}
	prev->next = node;
	node->prev = prev;
	node->next = curr;
	if(curr!=NULL) curr->prev = node;
	head = dummy->next;
}

 void DeleteAtPosition(Node* &head, int pos){
 	Node* dummy = new Node(0);
 	dummy->next = head;
 	Node* prev = dummy;
 	Node* curr = head;
 	while(pos-1>0){
 		prev = curr;
 		curr = curr->next;
 		pos--;
 	}
 	prev->next = curr->next;
 	if(curr->next!=NULL) curr->next->prev = prev;
 	head = dummy->next;
 }



 void DeleteByValue(Node* &head, int val){
 	Node* dummy = new Node(0);
 	dummy->next = head;
 	Node* prev = dummy;
 	Node* curr = head;
 	while(curr){
 		if(curr->data==val){
 			prev->next = curr->next;
 			if(curr->next!=NULL) curr->next->prev = prev;
 			curr = curr->next;
 		}
 		else{
	 		prev = curr;
	 		curr = curr->next;
	 	}
 	}
 	head = dummy->next;
 }



int main(){
	Node* head = new Node(1);
	InsertAtStart(head,3);
	InsertAtEnd(head,2);
	//InsertAtPosition(head,1,4);
	//DeleteByValue(head,3);
	//DeleteAtPosition(head,3);
	print(head);
}