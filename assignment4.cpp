#include <iostream>

using namespace std;

class graphMatrix{
	private:
	int size;
	int graph[10][10];
	
	
	public:
	
		graphMatrix(int n) {
        size = n;
    	}
	
	
	void initialize();
	void create();
	int minCost();
	void display();
	
};

void graphMatrix::initialize(){
		for(int i=0; i<size; i++){
			for(int j=0; j<size; j++){
				//initialize the matrix with 0
				graph[i][j]=0;
			}
		}
	create();
}

void graphMatrix::create(){
	int i,j;
	bool ans= true;
	cout<<"To enter the cost of connected offices with established connections-------"<<endl;
	do{
		cout<<"Enter office numbers (2- space separated): ";
		cin>>i>>j;
		cout<<"Enter cost: ";
		cin>>graph[i][j];
		char choice;
		cout<<"Enter more costs?(y/n): ";
		cin>>choice;
		if(choice=='y' || choice=='Y'){
			continue;
		}
		else if(choice=='n' || choice=='N'){
			ans=false;
		}
		else{
			cout<<"Invalid answer!!!\n";
		}
	}while(ans);
}

void graphMatrix::display(){
	cout<<"Adjacency matrix: \n";
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			cout<<graph[i][j]<<" ";
		}
		cout<<endl;
	}
}

int graphMatrix::minCost(){
	int ans=0;
	
	int visited[size];
	for(int i=0; i<size; i++){
		visited[i]=0;
	}
	for(int i=0; i<size; i++){
		int v1,v2;
		if(visited[i]==1){
		int minimum=999;
			for(int j=0; j<size; j++){
				if(visited[j]==0){
					if(graph[i][j]<minimum && graph[i][j]!=0){
						minimum=graph[i][j];
						v1=i;
						v2=j;
					}
				}
			}
		}
		ans+=minimum;
		visited[v2]=1;
	}
}



int main(){
	int n;
	cout<<"Enter number of cities to connect: ";
	cin>>n;
	graphMatrix g(n);
	
	g.initialize();
	g.display();
	
}
