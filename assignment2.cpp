#include <iostream>

using namespace std;


class BST{
	struct node{
		int data;
		node *lc, *rc;
	}*root;
	
	public:

	node* createNode(){

		node *newnode, *l, *r;
		int d;
		cout<<"Enter data: ";
		cin>>d;
		newnode->data= d;
		newnode->lc=nullptr;
		newnode->rc=nullptr;
		
		return newnode;
		
	}
	
	void createBST();
	void search();
	void display();
	void pre_order_display();
	
};

void BST::createBST(){
	node *temp, *cur;
	temp= createNode();
	if(root==NULL){
		cout<<"Tree is urrently empty. Start by adding at least one element to it."<<endl;
		root=temp;
	}
	else{
		cur=root;
		if(cur->data < temp->data){
			if(cur->rc!=nullptr){
				cur=cur->rc;
			}
			else{
				cur->rc=temp;
			}
		}
		else if( cur->data > temp->data){
			if(cur->lc!=nullptr){
				cur= cur->lc;
			}
			else{
				cur->lc = temp;
			}
		}
		else{
			//add equal data condition handling
		}
	}
}

void BST::search(){
	node *cur;
	cur= root;
	int d;
	cout<<"Enter element to search for: ";
	cin>>d;
	if(cur->data < d){
			if(cur->rc!=nullptr){
				cur=cur->rc;
			}
			else{
				cout<<"Not found"<<endl;
				return;
			}
		}
		else if( cur->data > d){
			if(cur->lc!=nullptr){
				cur= cur->lc;
			}
			else{
				cout<<"Not found"<<endl;
				return;
			}
		}
		else{
			cout<<"Element found in the BST!!!"<<endl;
		}
	
}

int main(){
	BST bst;
	bst.createBST();
	bst.createBST();
	bst.createBST();
	bst.createBST();
	bst.createBST();
	bst.search();
	
}



