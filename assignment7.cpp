#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class seq_file{
	struct student_entry{
		int roll;
		string name;
		string address;
		char div;
	}s;
	public:
	void add_student();
	void display_students();
	void del_student();
	bool search_student();
	void modify_student();
};

void seq_file::add_student(){
	ofstream os;
	os.open("student.data", ios::out|ios::binary);
	char ans='y';
	do{
		cout<<"Enter student name: ";
		cin>>s.name;
		cout<<"Enter roll no: ";
		cin>>s.roll;
		cout<<"Enter div: ";
		cin>>s.div;
		cout<<"Enter address: ";
		cin>>s.address;
		os.write((char*)&s, sizeof(s));
		cout<<"Do you wish to add another record? (y/n): ";
		cin>>ans;
	}while(ans=='y'||ans=='Y');
	
}

void seq_file::display_students(){
	ifstream is;
	is.open("student.data", ios::in|ios::binary);
	int flag=1;
	char ans='y';
	//while(flag==1){
		while(is.read((char*)&s, sizeof(s))){
			cout<<"\n"<<s.name<<" "<<s.roll<<" "<<s.div<<" "<<s.address;
			cout<<"\nPrint more records? (y/n): ";
			cin>>ans;
			if(ans!='y' && ans!='Y'){
				break;
			}
		}
//}
	cout<<"---------end of records-----------"<<endl;
	return;
}

bool seq_file::search_student(){
	ifstream is;
	is.open("student.data", ios::in|ios::binary);
	int key;
	cout<<"Enter roll number of student to be searched for: ";
	cin>>key;
	while(is.read((char*)&s, sizeof(s))){
		if(key==s.roll){
			return true;
		}
	}
	return false;
}

void seq_file::del_student(){
	ifstream is;
	ofstream os;
	os.open("temp.data", ios::out|ios::binary);
	is.open("student.data", ios::in|ios::binary);
	int key;
	cout<<"Enter roll number of student whose record is to be deleted: ";
	cin>>key;
	while(is.read((char*)&s, sizeof(s))){
		if(key!=s.roll){
			os.write((char*)&s, sizeof(s));
		}
	}
	remove("student.data");
	rename("temp.data", "student.data");
	return;
}

void seq_file::modify_student(){
	ifstream is;
	ofstream os;
	os.open("temp.data", ios::out|ios::binary);
	is.open("student.data", ios::in|ios::binary);	
	int key;
	cout<<"Enter roll number of student whose record is to be modified: ";
	cin>>key;
	while(is.read((char*)&s, sizeof(s))){
		if(key!=s.roll){
			os.write((char*)&s, sizeof(s));
		}
		else{
		cout<<"Enter following details to modify the student record."<<endl;
			cout<<"Enter student name: ";
			cin>>s.name;
			cout<<"Enter roll no: ";
			cin>>s.roll;
			cout<<"Enter div: ";
			cin>>s.div;
			cout<<"Enter address: ";
			cin>>s.address;
			os.write((char*)&s, sizeof(s));
			cout<<"Record modified!!!"<<endl;
		}
	}
	remove("student.data");
	rename("temp.data", "student.data");
	return;
}

int main(){
	seq_file S;
	
	int flag=1;
	while(flag==1){
		cout<<"----------------STUDENT DATABASE OPERATIONS---------------"<<endl;
		cout<<"Press the following keys to perform adjacent actions: "<<endl;
		cout<<"1. Add student\n";
		cout<<"2. Del record of student\n";
		cout<<"3. Display records\n";
		cout<<"4. Modify a particular record\n";
		cout<<"5. Seach for a record\n";
		cout<<"6. Exit database\n";
		cout<<"Your choice: ";
		int choice;
		cin>>choice;
		
		switch(choice){
		
		case 1:
		S.add_student();
		break;
		
		case 2:
		S.del_student();
		break;
		
		case 3:
		S.display_students();
		break;
		
		case 4:
		S.modify_student();
		break;
		
		case 5:
		bool ans;
		ans= S.search_student();
		if(ans){
			cout<<"Student records are present!!!"<<endl;;
		}
		else{
			cout<<"Student records not found"<<endl;
		}
		break;
		
		case 6:
		cout<<"Exiting database :)"<<endl;
		flag=0;
		break;
		
		default:
		cout<<"Enter valid choice"<<endl;
		}
	
	}
	
	
}
