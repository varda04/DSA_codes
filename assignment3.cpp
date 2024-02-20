#include <iostream>
using namespace std;

class TBT{
	struct node{
		int data;
		node *lc;
		node *rc;
		bool lt;//flag for left thread(0)/ left child (1)
		bool rt;
	}*header, *root;
	

	node* createNode(){
		node *newnode= new node;
		int d;
		if(root==NULL){
			cout<<"Enter root data: ";
		}
		else{
			cout<<"Enter data: ";
		}
		cin>>d;
		newnode->data= d;
		newnode->lc=newnode;
		newnode->rc=newnode;
		newnode->lt=false;
		newnode->rt=false;
		
		return newnode;
		
	}
	public:
	
	TBT(){
		header= new node;
		header->lc= header;
		header->rc= header;
		root=new node;
		root->lc=header;
		root->rc=header;
		root->lt=false;
		root->rt=false;
		header->lc=root;
		cout<<"constructor";
	}
	void addtoTBT();
	void display();
	void preorder(node *t);
	void inorder(node *t);
	void postorder(node *t);
};

void display(){
	int choice;
	cout<<"Press 1 to display inorder sequence\n";
	cout<<"Press 2 to display preorder sequence\n";
	cout<<"Press 3 to display postorder sequence\n";
	cout<<"Your choice: ";
	cin>>choice;
	switch(choice){
		case 1:
		inorder(root);
		break;
		
	}
}


void TBT::addtoTBT(){
	node *temp, *cur;
	temp= createNode();
	
	
	if(root==NULL){
		root=temp;
	}
	else{
		cur=root;
		while(1){
			if(cur->data < temp->data){
				if(cur->rt==true){
					cur=cur->rc;
				}
				else{
					temp->lc= cur;
					temp->rc= cur->rc;
					cur->rc=temp;
					cur->rt=true;
					break;
				}
			}
			else if( cur->data > temp->data){
				if(cur->lt==true){
					cur= cur->lc;
				}
				else{
					temp->rc=cur;
					temp->lc=cur->lc;
					cur->lc = temp;
					cur->lt=true;
					break;
				}
			}
			else{
				//add equal data condition handling
			}
		}
	}
}

void TBT::inorder(node *t){
	if(t!=NULL){
		inorder(t->lc);
		cout<<t->data<<" ";
		inorder(t->rc);
	}
}

int main(){
	TBT tbt;
	int flag=1;
	while(flag){
		cout<<"------------------MENU-----------------"<<endl;
		cout<<"Choose any one of the following options: "<<endl;
		cout<<"1. Add a node to the TBT.\n";
		cout<<"2. Search for an element in the TBT,\n";
		cout<<"3.Display the TBT in preorder manner.\n";
		cout<<"4. Display the minimum element in the TBT\n";
		cout<<"5. Display the maximum element in the TBT\n";
		cout<<"6. Exit\n";
		cout<<"Your choice: ";
		int choice;
		cin>>choice;
		switch(choice){
			case 1:
			tbt.addtoTBT();
			break;
			
			case 2:
		//	tbt.search();
			break;
			
			case 3:
			tbt.display();
			break;
			
			case 4:
		//	tbt.min();
			break;
			
			case 5:
		//	tbt.max();
			break;
			
			case 6:
			cout<<"Exiting...\n";
			flag=0;
			break;
			
			default:
			cout<<"Please enter a valid option!!!\n";
			//getch();
			break;
			
		}
	}
}































