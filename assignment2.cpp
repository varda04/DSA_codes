#include <iostream>

using namespace std;


class BST{
	struct node{
		int data;
		node *lc=nullptr;
		node *rc=nullptr;
	}*root;
	

	node* createNode(){

		node *newnode= new node;
		int d;
		cout<<"Enter data: ";
		cin>>d;
		newnode->data= d;
		newnode->lc=nullptr;
		newnode->rc=nullptr;
		
		return newnode;
		
	}
	public:
	BST(){
		root= NULL;
	}
	
	void addtoBST();
	void search();
	void display();
	void pre_order_display(node*);
	void min();
	void max();
	
};

void BST::addtoBST(){
	node *temp, *cur;
	temp= createNode();
	if(root==NULL){
		cout<<"Tree is currently empty. This data entered is added as th root."<<endl;
		root=temp;
	}
	else{
		cur=root;
		while(1){
			if(cur->data < temp->data){
				if(cur->rc!=nullptr){
					cur=cur->rc;
				}
				else{
					cur->rc=temp;
					break;
				}
			}
			else if( cur->data > temp->data){
				if(cur->lc!=nullptr){
					cur= cur->lc;
				}
				else{
					cur->lc = temp;
					break;
				}
			}
			else{
				//add equal data condition handling
			}
		}
	}
}

void BST::search(){
	node *cur;
	cur= root;
	int d;
	cout<<"Enter element to search for: ";
	cin>>d;
	while(1){
		if(cur->data < d){
			if(cur->rc!=nullptr){
				cur=cur->rc;
			}
			else{
				cout<<"Not found"<<endl;
				break;
			//	return;
			}
		}
		else if( cur->data > d){
			if(cur->lc!=nullptr){
				cur= cur->lc;
			}
			else{
				cout<<"Not found"<<endl;
				break;
			//	return;
			}
		}
		else{
			cout<<"Element found in the BST!!!"<<endl;
			break;
		}
	}
	
}


void BST::display(){
	pre_order_display(root);
}

void BST::pre_order_display(node *temp){
	if(temp!=NULL){
		cout<<" "<<temp->data;
		pre_order_display(temp->lc);
		pre_order_display(temp->rc);
	}
}

void BST::min(){
	node *temp= root;
	while(temp->lc!=nullptr){
		temp= temp->lc;
	}
	cout<<"Minimum value in this BST is: "<<temp->data;
}
void BST::max(){
	node *temp= root;
	while(temp->rc!=nullptr){
		temp= temp->rc;
	}
	cout<<"Maximum value in this BST is: "<<temp->data;
}



int main(){
	BST bst;
	bst.addtoBST();
	bst.addtoBST();
	bst.addtoBST();
	bst.addtoBST();
	bst.addtoBST();
	bst.search();
	bst.display();
	bst.min();
	bst.max();
	
}



