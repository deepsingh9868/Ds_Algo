#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* next;

	Node(int data){
		this->data = data;
		this->next = NULL;
	}
};


void Insert_beginning(Node* &head, int val){
	Node* node = new Node(val);
	node->next = head;
	head = node;
}


void Insert_end(Node* &head, int val){
	Node* node = new Node(val);
	Node* temp = head;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = node;
	node->next = NULL;
}


void Insert_middle(Node* &head, int val){
	Node* node = new Node(2);
	Node* fast = head;
	Node* slow = head;
	while(fast->next!=NULL){
		fast = fast->next->next;
		slow = slow->next;
	}
	node->next = slow->next;
	slow->next = node;
}


void Reverse_linkedlist(Node* &head){
	Node* prev = NULL;
	Node* curr = head;
	Node* next= NULL;
	while(curr!=NULL){
		next = curr->next;
		curr->next = prev;
		prev=curr;
		curr=next;
	}
	head = prev;
}


void delete_node(Node* &head, int val){
	Node* dummy = new Node(0);
	dummy->next = head;
	Node* prev = dummy;
	Node* curr = head;
	while(curr!=NULL){
		if(curr->data==val){
			prev->next = curr->next;
			curr = curr->next;
		}
		else{
			prev = prev->next;
			curr = curr->next;
		}
	}
	head = dummy->next;
}


void InsertAtPosition(Node* &head, int val, int pos){
	Node* node = new Node(val);
	Node* dummy = new Node(0);
	dummy->next = head;
	Node* curr = head;
	Node* prev = dummy;
	while(pos-1>0){
		prev = curr;
		curr = curr->next;
		pos--;
	}
	prev->next = node;
	node->next = curr;
	head = dummy->next;
}



void print(Node* &head){
	Node* temp = head;
	while(temp!= NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}




//remove duplicate from the linkedlist
// unordered_map<int,int> mp;
// void Duplicate(Node* head){
//     Node* temp = head;
//     while(temp->data!=-1){
//         int d = temp->data;
//         mp[d]++;
//         temp =temp->next;
//     }
// }

// void Delete_Node(Node* &head, int val){
//     Node* dummy = new Node(0);
//     dummy->next = head;
//     Node* prev = dummy;
//     Node* curr = head;
//     while(curr!=NULL){
//         if(curr->data==val){
//             prev->next = curr->next;
//             curr = curr->next;
//             break;
//         }
//         else{
//             prev = curr;
//             curr = curr->next;
//         }
//     }
//     head = dummy->next;
// }

// void lastAppearance(Node* &head){
//     // Write your code here.
//     Duplicate(head);
//     for(auto c: mp){
//         int val = c.second;
//         if(val>1) Delete_Node(head,c.first);
//     }
//    // return head;
// }

int main(){
	Node* head = new Node(1);
    //cout<<head->data;
	Node* second = new Node(2);
	Node* third = new Node(3);

	head->next = second;
	second->next = third;
	third->next = NULL;

	//Insert_middle(head,2);
	//Reverse_linkedlist(head);
	//delete_node(head,3);
	//InsertAtPosition(head,2,4);

	print(head);
}
