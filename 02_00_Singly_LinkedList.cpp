#include<bits/stdc++.h>
using namespace std;

// -> is equal to (*).

struct Node{
	int data;
	Node* next;
};


int main(){
	Node* head=new Node{10,nullptr};
	head->next=new Node{20,nullptr};
	head->next->next=new Node{30,nullptr};

 Node* temp=head;
	while(temp!=nullptr){
		cout<<(*temp).data<<endl;
		temp=temp->next;
	}
	Node* third=head->next->next;
	head->next->next=nullptr;
	delete third;
	 Node* temp2=head;
	while(temp2!=nullptr){
		cout<<(*temp2).data<<endl;
		temp2=temp2->next;
	}



}