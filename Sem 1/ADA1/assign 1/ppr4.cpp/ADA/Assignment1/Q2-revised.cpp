/* Merged this revised edition with Q2.cpp
 * */

#include <bits/stdc++.h>
using namespace std;

inline char int2char(int x){
	return (char)(x+48);
}

class CD{
	string title;
	int id;
	double price;
	
	public:
	CD(){}
	
	~CD(){}
	
	CD(string _title, int _id, double _price): 	title(_title), id(_id),	\
												price(_price)
	{}
	
	friend std::ostream& operator<<(std::ostream& os, const CD& cd){
		os<<cd.id<<",";
		os<<cd.title<<",";
		os<<cd.price<<",";
		return os;
	}
	
	friend std::istream& operator>>(std::istream& is, CD& cd){
		is>>cd.id;
		is>>cd.title;
		is>>cd.price;
		return is;
	}
	
	string getTitle(){
		return title;
	}
	
	void setTitle(string _title){
		title=_title;
		return;
	}
	
	double getPrice(){
		return price;
	}
	
	void setPrice(double _price){
		price=_price;
		return;
	}
	
	int getID(){
		return id;
	}
	
	void setID(int _id){
		id=_id;
		return;
	}
};


class Transaction;

class MusicWorld;


class CDList{
	map<int, CD> setofCDs; //id, CD
	map< int, int > listofIDs; //id, quantity
	friend class MusicWorld;
	public:
	
	CDList(){}
	~CDList(){}
	
	CDList(const CDList &t){ // copy constructor
		setofCDs = t.setofCDs;
		listofIDs = t.listofIDs;
	}
	
	friend std::ostream& operator<<(std::ostream& os, const CDList& cl){
		//os<<cl.listofIDs;
		//os<<cl.setofCDs;
		int quantity, id;
		
		os<<cl.listofIDs.size()<<",";
		
		for(auto a : cl.listofIDs){
			id = a.first;
			quantity = a.second;
			os<<id<<",";
			os<<quantity<<",";
		}
		
		os<<cl.setofCDs.size()<<",";
		
		for(auto a: cl.setofCDs){
			//os<<a.first<<",";  because id is already stored in second
			os<<a.second;
		}
		
		return os;
	}
	
	friend std::istream& operator>>(std::istream& is, CDList& cl){
		int quantity, id;
		int n;
		is>>n;
		for(int i=0; i<n; ++i){
			is>>id;
			is>>quantity;
			cl.listofIDs[id] = quantity;
		}
		is>>n;
		CD cd;
		for(int i=0; i<n; ++i){
			is>>id;
			is>>cd;
			cl.setofCDs[id] = cd;
		}
		return is;
	}
	
	void addCD(string name, int id, double price, int quantity){
		if(setofCDs.find(id)==setofCDs.end()){
			CD cd(name, id, price);
			setofCDs[id]=cd;
		}
		listofIDs[id] = quantity;
		return;
	}
	
	void delCD(int id){
		listofIDs.erase(id);
		setofCDs.erase(id);
		return;
	}
	
	double subtotal(){
		double sum=0;
		int id, quantity;
		for(auto a : listofIDs){
			id = a.first;
			quantity = a.second;
			sum+=(setofCDs[id].getPrice()*quantity);
		}
		return sum;
	}
	
	void showList(){
		cout<<"\n\n\n\tLIST OF CDs: ";
		int i=1, id, quantity;
		for(auto a : listofIDs){
			id = a.first;
			quantity = a.second;
			CD currCD = setofCDs[id];
			cout<<"\n\n"<<i<<".\tID: "<<id;
			cout<<"\n\tTitle: "<<currCD.getTitle();
			cout<<"\n\tQuantity: "<<quantity;
			cout<<"\n\tPrice per unit: "<<currCD.getPrice();
			cout<<"\n\tNet Price: "<<quantity*currCD.getPrice();
			++i;
		}
	}
	
	void clearList(){
		listofIDs.clear();
	}
};


class Transaction{
	public:
	string transID;
	CDList listofCDs;
	string timeOfTransaction;
	
	Transaction(){}
	
	Transaction(CDList _listofCDs):listofCDs(_listofCDs)
	{}
	
	static string formattedTime(){
		time_t now = time(0);
		tm *gmt = localtime(&now);
		int year = gmt->tm_year + 1900;
		int mon = gmt->tm_mon + 1;
		int day = gmt->tm_mday;
		int hour = gmt->tm_hour;
		int min = gmt->tm_min;
		int sec = gmt->tm_sec;
		
		string t = "DD/MM/YY HH:MM:SS IST";
		
		t[0] = int2char(day/10);
		t[1] = int2char(day%10);
		
		t[3] = int2char(mon/10);
		t[4] = int2char(mon%10);
		//cout<<"\nyear: "<<year<<"\n";
		year = year%100;
		t[6] = int2char(year/10);
		t[7] = int2char(year%10);
		
		t[9] = int2char(hour/10);
		t[10]= int2char(hour%10);
		
		t[12]= int2char(min/10);
		t[13]= int2char(min%10);
		
		t[15]= int2char(sec/10);
		t[16]= int2char(sec%10);
		
		return t;
	}
	
	string commitTransaction(){
		timeOfTransaction = formattedTime();
		transID = "DDMMYYHHMMSS";
		transID[0] = timeOfTransaction[0];
		transID[1] = timeOfTransaction[1];
		
		transID[2] = timeOfTransaction[3];
		transID[3] = timeOfTransaction[4];
		
		transID[4] = timeOfTransaction[6];
		transID[5] = timeOfTransaction[7];
		
		transID[6] = timeOfTransaction[9];
		transID[7] = timeOfTransaction[10];
		
		transID[8] = timeOfTransaction[12];
		transID[9] = timeOfTransaction[13];
		
		transID[10] = timeOfTransaction[15];
		transID[11] = timeOfTransaction[16];
		return transID;
	}
};


class MusicWorld{
	CDList cdList;
	map< string, Transaction* > transactions;
	
	public:
	MusicWorld()
	{
		ifstream f;
		f.open("transaction_history.dat");
		if(!f){
			cout<<"\nERROR reading file.\n";
			return;
		}
		Transaction *T;
		string tmp;
		while(f){
			T = new Transaction();
			getline(f, tmp, '\n');
			if(tmp.length()<2) break;
			stringstream ss(tmp);
			
			getline(ss, T->transID, ',');
			
			getline(ss, T->timeOfTransaction, ',');
			
			getline(ss, tmp, ',');
			
			int n, id, quantity;
			n = stoi(tmp);
			//cout<<" "<<tmp<<".\n";
			
			unordered_map< int, int > qofcds; //quantity of cds
			
			for(int i=0; i<n; ++i){
				getline(ss, tmp, ',');
				id = stoi(tmp);
				
				getline(ss, tmp, ',');
				quantity = stoi(tmp);
				
				qofcds[id] = quantity;
			}
			
			getline(ss, tmp, ','); 
			n = stoi(tmp);
			string title;
			
			CDList cdList;
			int price;
			for(int i=0; i<n; ++i){
				getline(ss, tmp, ',');
				id = stoi(tmp);
				
				getline(ss, tmp, ',');
				title = tmp;
				
				getline(ss, tmp, ',');
				price = stoi(tmp);
				
				cdList.addCD(title, id, price, qofcds[id]);
			}
			T->listofCDs = cdList;
			transactions[T->transID] = T;
		}
		f.close();
	}
	~MusicWorld(){}
	
	void addCD(){
		int id, quantity;
		string title;
		double price;
		cout<<"\n\nEnter CD details:";
		cout<<"\n\tID: ";
		cin>>id;
		cin.ignore();
		cout<<"\n\tTitle: ";
		//cin>>title;
		getline(cin, title, '\n');
		cout<<"\n\tPrice: ";
		cin>>price;
		cout<<"\n\tQuantity: ";
		cin>>quantity;
		cdList.addCD(title, id, price,quantity);
		return;
	}
	
	void delCD(){
		int id;
		cout<<"\n\nEnter id of CD entry to be deleted: ";
		cin>>id;
		cdList.delCD(id);
		return;
	}
	
	double total(){
		double total = cdList.subtotal();
		total=total+total*0.0625;
		return total;
	}
	
	void resetList(){
		cdList.clearList();
	}
	
	void save(Transaction *T){
		ofstream f;
		f.open("transaction_history2.dat", ios::app);
		f<<T->transID<<",";
		f<<T->timeOfTransaction<<",";
		f<<T->listofCDs<<"\n";
		f.close();
		return;
	}
	
	void storeTransaction(){
		Transaction *T = new Transaction(cdList);
		T->commitTransaction();
		transactions[T->transID]=T;
		save(T);
		return;
	}
	
	void showCDs(){
		cdList.showList();
		return;
	}
	
	string transaction_submenu(){
		string transaction_ID="";
		char choice;
		cout<<"\n\nDo you want to look at any transaction? (Y/n)  ";
		cin>>choice;
		if(tolower(choice)=='y'){
			cout<<"\nEnter transaction ID: ";
			cin>>transaction_ID;
		}
		return transaction_ID;
	}
	
	void transactionHistory(){
		int i=1;
		cout<<"\n\n\t\t\tTransaction History\n";
		for(auto x : transactions){
			cout<<"\n "<<i<<".\tTransaction ID: "<<x.first;
			Transaction *t = x.second;
			cout<<"\tTime of Transaction: "<<t->timeOfTransaction;
			++i;
			cout<<"\n";
			//t->listofCDs.showList();
		}
		string transaction_ID = transaction_submenu();
		if(transaction_ID.compare("") == 0){
			return;
		} else {
			transactions[transaction_ID]->listofCDs.showList();
			cout<<"\nPress any key and hit enter to continue... ";
			string hold;
			cin>>hold;
		}
	}
};

int menu(){
	int choice;
	cout<<"\n\t\t\tMusic World transaction management tool\n";
	cout<<"\n 1. New Transaction";
	cout<<"\n 2. Add CD to cart";
	cout<<"\n 3. Delete CD from cart";
	cout<<"\n 4. Show list of CDs in cart";
	cout<<"\n 5. Show Total";
	cout<<"\n 6. Commit Transaction (After payment by customer)";
	cout<<"\n 7. Show Transaction history";
	cout<<"\n 8. Exit";
	cout<<"\n\nEnter your choice: ";
	cin>>choice;
	return choice;
}

int main(){
	/* if(is_trivially_copyable<CDList>::value) 
    cout << "CDList is  trivially copyable\n"; 
	else cout << "CDList is not trivially copyable\n"; */
	
	cout<<"Current Date & Time: "<<Transaction::formattedTime();
	MusicWorld m;
	int choice = 1;
	char option;
	while(choice!=8){
		cout<<"\nCurrent cart total: "<<m.total()<<"\n";
		choice=menu();
		string hold;
		switch(choice){
			case 1: cout<<"\n\nAre you sure? (Y/n)  ";
					cin>>option;
					if(tolower(option)=='y') m.resetList();
					break;
			case 2: m.addCD();
					break;
			case 3: m.delCD();
					break;
			case 4: m.showCDs();
					cout<<"\nPress any key and hit enter to continue... ";
					cin>>hold;
					break;
			case 5: cout<<"Total price (including tax): "<<m.total();
					break;
			case 6: m.storeTransaction();
					cout<<"\nStored transaction in secondary storage\n";
					break;
			case 7: m.transactionHistory();
					break;
			case 8:break;
			default: cout<<"Invalid Entry! Try again.";
		}
	}
	return 0;
}
