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
	int flag=1;
	while(flag){
		cout<<"------------------MENU-----------------"<<endl;
		cout<<"Choose any one of the following options: "<<endl;
		cout<<"1. Add a node to the BST.\n";
		cout<<"2. Search for an element in the BST,\n";
		cout<<"3.Display the BST in preorder manner.\n";
		cout<<"4. Display the minimum element in the BST\n";
		cout<<"5. Display the maximum element in the BST\n";
		cout<<"6. Exit\n";
		cout<<"Your choice: ";
		int choice;
		cin>>choice;
		switch(choice){
			case 1:
			bst.addtoBST();
			break;
			
			case 2:
			bst.search();
			break;
			
			case 3:
			bst.display();
			break;
			
			case 4:
			bst.min();
			break;
			
			case 5:
			bst.max();
			break;
			
			case 6:
			cout<<"Exiting...\n";
			flag=0;
			break;
			
			default:
			cout<<"Please enter a valid option!!!\n";
			break;
			
		}
	}
}



