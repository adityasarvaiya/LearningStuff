#include <bits/stdc++.h>
using namespace std;


class Publication{
	protected:
	string title;
	double price;
	int copies;
	
	public:
	
	Publication(string _title, double _price, int _copies):title(_title),\
														price(_price),	 \
														copies(_copies)
	{}
	
	~Publication(){}
	
	string get_title()
	{
		return title;
	}
	
	void set_title(string _title)
	{
		title = _title;
		return;
	}

	double get_price()
	{
		return price;
	}
	
	void set_price(double _price)
	{
		price = _price;
	}
	
	void restock(int _copies)
	{
		copies += _copies;
	}
	
	bool sellCopy() // returns true if success in selling, i.e., if copies!=0
	{
		if(copies!=0){
			--copies;
			return true;
		} else {
			return false;
		}
	}
};


class Book : public Publication{
	private:
	string author;
	int ordered_copies;
	
	public:
	Book(string _title, string _author, double _price, int _copies): 	\
		Publication(_title, _price, _copies), author(_author), 			\
		ordered_copies(0)
	{}
	
	void orderCopies(int order_qty)
	{
		ordered_copies += order_qty;
		return;
	}
	
	int get_ordered_copies()
	{
		return ordered_copies;
	}
	
	int sellCopies(int sale_qty)
	{
		int unquenched=0; //unsatisfyable sale requests
		if(sale_qty>copies){
			unquenched = sale_qty - copies;
			ordered_copies = 0;
			copies = 0;
		} else {
			copies -= sale_qty;
			ordered_copies=0;
		}
		return unquenched;
	}
};


class Magazine : public Publication{
	protected:	
	int orderQty;
	string currIssue;
	
	public:
	Magazine(string _title, double _price, string _currIssue, int _copies):\
			Publication(_title, _price, _copies), currIssue(_currIssue)
	{}
	
	~Magazine()
	{}
	
	int adjustQty()
	{
		int unquenched = 0;
		if(orderQty>copies){
			unquenched = orderQty - copies;
			orderQty = unquenched;
			copies = 0;
		} else {
			copies -= orderQty;
			orderQty = 0;
		}
		return unquenched;
	}
	
	void orderCopies(int orders)
	{
		orderQty += orders;
		return;
	}
	
	void recvNewIssue(string _currIssue, int qty)
	{
		currIssue = _currIssue;
		copies = qty;
		return;
	}
};


class DiscMag : public Magazine{
	public:
		
	DiscMag(string _title, double _price, string _currIssue, int _copies):\
			Magazine(_title, _price, _currIssue, _copies)
	{}
	
	~DiscMag(){}
	
	void recvNewIssue(string _currIssue, int qty) // overriding previous function
	{
		
		// replace this with code to check if all CDs are in place
		
		currIssue = _currIssue;
		copies = qty;
		return;
	}
};

int main(){
	DiscMag dm("Science World", 59.99, "Volume 51 Issue 3", 5);
	Magazine mg("Outlook", 19.99, "Aug Issue 2", 10);
	Book b("The Shining", "Stephen King", 5.99, 20);
	
	return 0;
}
