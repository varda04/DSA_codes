#include <iostream>
#include <fstream>
#include <string>

using namespace std;



class seq_file{
	struct emp{
		int ID;
		string name;
		string designation;
		int salary;
	}e;
	
	void add_emp();
	bool search_emp(int e);
	void del_emp();
};

void seq_file::add_emp(){
	
	ofstream o("emp.txt", ios::app);
	char ans='y';
	do{
		cout<<"Enter employee name: ";
		cin>>e.name;
		cout<<"Enter unique employee ID: ";
		cin>>e.ID;
		try{
			if(search_emp(e.ID)==true){
				throw 1;
			}
		}
		catch(int i){
			cout<<"Employee ID already exists, please try with a different ID\n";
			break;
		}
		cout<<"Enter designation of employee: ";
		cin>>e.designation;
		cout<<"Enter salary: ";
		cin>>e.salary;
		o<<e.ID<<" "<<e.name<<" "<<e.designation<<" "<<e.salary<<endl;
		cout<<"To add one more record, enter 'y': ";
		cin>>ans;
	}while(ans=='y' || ans=='Y');
	o.close();
	
}

bool seq_file::search_emp(int empid){

	ifstream i("emp.txt");
	while(e.id>>e.name>>e.designation>>e.salary{
		if(e.ID==empid){
			return true;
		}
	}
	return false;
	
}

void seq_search::del_emp(){

	int empid;
	ifstream i("emp.txt");
	ofstream o("temp.txt");
	char ans='y';
	
	do{
	
		cout<<"Enter employee ID to delete from records: ";
		cin>>empid;
		if(search_emp(empid)==false){
			cout<<"Employee records with provided ID not present\n";
			return;
		}
		while(e.id>>e.name>>e.designation>>e.salary){
			if(e.ID!=empid){
				o<<e.ID<<" "<<e.name<<" "<<e.designation<<" "<<e.salary<<endl;
			}
		}
		cout<<"To add one more record, enter 'y': ";
		cin>>ans;
	}while(ans=='y' || ans=='Y');
	
	remove("emp.txt");
	rename("temp.txt","emp.txt");

}

int main(){
	seq_search s;
	s.add_emp();
	s.search();
	s.del_emp();
}


