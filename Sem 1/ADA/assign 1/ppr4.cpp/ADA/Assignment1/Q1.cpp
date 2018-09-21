#include <iostream>
#include <string>
using namespace std;


class IDCard{
		int id;
		string name, filename;
	public:
	IDCard(){} // default constructor
	
	IDCard(string _name, int _id, string _filename):id(_id), 		\
													name(_name),	\
												filename(_filename)
	{} // overloaded constructor
	
	~IDCard(){} // destructor
	
	string getName(){ // accessor
		return name;
	}
	
	void setName(string _name){ // mutator
		name = _name;
		return;
	}
	
	int getID(){
		return id;
	}
	
	void setID(int _id){
		id = _id;
		return;
	}
	
	string getFilename(){
		return filename;
	}
	
	void setFilename(string _filename){
		filename = _filename;
		return;
	}
	
	void dispInfo(){
		cout<<"\n\nID Card info:";
		cout<<"\n Name: "<<name;
		cout<<"\n ID: "<<id;
		cout<<"\n Photo filepath: "<<filename;
		return;
	}
};

int menu(){
	int choice;
	cout<<"\n\n\n\n::Menu::\n\n";
	cout<<"1. Change name\n";
	cout<<"2. Change ID\n";
	cout<<"3. Change photo file path";
	cout<<"\n\nEnter Choice: ";
	cin>>choice;
	return choice;
}

int main(){
	// A token driver function
	
	// Initializing using dummy data to demonstrate constructor
	IDCard somebody("Some Body", 556661, "~\\photo1.jpeg");
	
	cout<<"Somebody's IDCard info:\n";
	cout<<"\nName: "<<somebody.getName();
	cout<<"\nID: "<<somebody.getID();
	cout<<"\nPhoto file path: "<<somebody.getFilename();
	cout<<"\n\nChange any info? (Y/n)  ";
	char info_change;
	cin>>info_change;
	if(tolower(info_change)=='y'){
		string stmp;
		int itmp;
		while(tolower(info_change)=='y'){
			int choice = menu();
			cin.ignore();
			switch(choice){
				case 1:	cout<<"\nEnter new name: ";
						getline(cin, stmp, '\n');
						somebody.setName(stmp);
						break;
				case 2: cout<<"\nEnter new ID number: ";
						cin>>itmp;
						somebody.setID(itmp);
						break;
				case 3: cout<<"\nEnter new filepath: ";
						getline(cin, stmp, '\n');
						somebody.setFilename(stmp);
						break;
				default:
						cout<<"\nINVALID ENTRY!";
			}
			somebody.dispInfo();
			cout<<"\n\nWant to change again? (Y/n)  ";
			cin>>info_change;
			cin.ignore();
		}
	}
	return 0;
}
