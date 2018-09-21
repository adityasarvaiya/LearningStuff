#include <iostream>
#include <vector>
#include <string.h> // for strcpy and all
#include <string> // for getline(cin,var_name);

using namespace std;

static int const totalCapacity = 100;

class Publication{
    private:
    
        string title;
        int price;
        int copies;

    

    public:
        Publication(){
            title = "";
            price = 0;
            copies = 0;
        }

        void sellCopy(int i){
            copies -= i;
        }

        string getTitle(){ return title ;}
        int getPrice(){ return price ;}
        int getCopies(){ return copies ;}


        void updateTitle(string name){ 
            title = name;
        }
        void updatePrice(int pr){ 
            price = pr;
        }
        void updateCopies(int cp){
            copies = cp;
        }
};

class Book : public Publication{

    private:
        string author;

    public:
        string getAuthor(){
            return author;
        }

        void updateAuthor(string au){
            author = au;
        }

        void orderCopies(){

        }

};


class Magzine : public Publication{
    private:
        int orderQty=0;
        double currIssue = 1;

    public:
        int getOrderQty(){
            return orderQty;
        }

        double getCurrIssue(){
            return currIssue;
        }

        void updateOrderQty(int oq){
            orderQty = oq;
        }

        void updateCurrIssue(double ci){
            currIssue = ci;
        }

        void adjustQty(int qty, int f){
            if (f==1){
                this->updateCopies(this->getCopies() + qty );
            }else if(f==2){
                this->updateCopies(this->getCopies() - qty );
            }
        }

        void recvNewIssue(double iss){
            updateCurrIssue(iss);
        }
};

class DiscMag : public Magzine{
    
    public:
        void recvNewIssue(double iss){
            this->updateCurrIssue(iss);
            cout << "IMPORTANT NOTICE : Please check if this magazine have a disk or not.";
        }
};

int main(){

    int n;

    vector <Magzine> mag(100);
    int i = 0;

    vector <DiscMag> discmag(100);
    int p = 0;

    vector <Book> book(100);
    int r = 0;

    mag[i].updateOrderQty(10);
    mag[i].updateCurrIssue(1.05);
    mag[i].updateTitle("Steve Jobs");
    mag[i].updatePrice(800);
    mag[i].updateCopies(10);
    i++;

    while(true){
        cout <<endl<<endl<<endl<<endl;
        cout << "1. Press 1 to see stock"<<endl;
        
        cout << "----------------------------------------------------------------------------------"<<endl;        
        cout << "2. Press 2 to Add Magzine."<<endl;
        cout << "3. Press 3 to Adjust Magazine Quantity."<<endl;
        cout << "4. Press 4 to Add New Magzine Issue."<<endl;
        cout << "5. Press 5 to Order Magzine"<<endl;
        
        cout << "----------------------------------------------------------------------------------"<<endl;
        cout << "6. Press 6 to Add Disk Magzine"<<endl;
        cout << "7. Press 7 to Add New Disk Magzine Issue."<<endl;
        cout << "8. Press 8 to Order Disk Magzine Issue."<<endl;

        cout << "----------------------------------------------------------------------------------"<<endl;
        cout << "9. Press 9 to Add Book"<<endl;
        cout << "10. Press 10 to Delete Book"<<endl;
        cout << "11. Break"<<endl;

        cin >> n;
        cin.ignore(); // skips char in buffer usually "\n" Enter

        if(n==1){
            int tmp;
            cout << "Press 1 to see Magzines."<<endl;
            cout << "Press 2 to see Disk Magzines."<<endl;
            cout << "Press 3 to see Books."<<endl;
            cin >> tmp;
            if(tmp == 1){
                cout <<endl<<endl;
                for(int k=0; k<i; k++){
                    cout <<k<<". Title : "<< mag[k].getTitle() <<endl;
                    cout <<k<<". Price : "<< mag[k].getPrice() <<endl;
                    cout <<k<<". Copies : "<< mag[k].getCopies() <<endl;
                    cout <<k<<". Current Issue : "<< mag[k].getCurrIssue()<<endl;
                    cout <<endl<<endl;
                }
            }else if(tmp==2){
                cout <<endl<<endl;
                for(int k=0; k<p; k++){
                    cout <<k<<". Title : "<< discmag[k].getTitle() <<endl;
                    cout <<k<<". Price : "<< discmag[k].getPrice() <<endl;
                    cout <<k<<". Copies : "<< discmag[k].getCopies() <<endl;
                    cout <<k<<". Current Issue : "<< discmag[k].getCurrIssue()<<endl;
                    cout <<endl<<endl;
                }
            }else if(tmp==3){
                cout <<endl<<endl;
                for(int k=0; k<r; k++){
                    cout <<k<<". Title : "<< book[k].getTitle() <<endl;
                    cout <<k<<". Price : "<< book[k].getPrice() <<endl;
                    cout <<k<<". Copies : "<< book[k].getCopies() <<endl;
                    cout <<k<<". Author : "<< book[k].getAuthor()<<endl;
                    cout <<endl<<endl;
                }
            }


        }else if(n==2){
            string t;
            int prs;
            int cps;
            double cris;

            cout << "Enter title :";
            getline(cin,t);
            mag[i].updateTitle(t);

            cout <<"Enter price : ";
            cin >> prs;
            mag[i].updatePrice(prs);

            cout << "Enter num copies : ";
            cin >> cps;
            mag[i].updateCopies(cps);

            cout << "Enter current issue : ";
            cin >> cris;
            mag[i].updateCurrIssue(cris);
            
            i++;


        }else if(n==3){
            int j = 0;
            int f = 0;
            int update_qty = 0;
            cout << "Select the book to be update. Press from 0 to "<<i-1 <<endl;
            for(j=0; j<i; j++){
                cout << j << " : " << mag[j].getTitle() << "  " << mag[j].getCurrIssue() << endl;
            }

            cin >> j;
            cout << "Press 1 to Add to the quantity and Press 2 to Subtract to the quantity." << endl;
            cin >> f;
            cout << "Enter the change in quantity.: " << endl;
            cin >> update_qty;
            mag[j].adjustQty(update_qty,f);


        }else if(n==4){
            int j = 0;
            double issue_num;

            cout << "Select the book to be update. Press from 0 to "<<i<<endl;
            for(j=0; j<i; j++){
                cout << j << " : " << mag[j].getTitle() << "  " << mag[j].getCurrIssue() << endl;
            }

            cin >> j;
            cout << "Enter new issue number : ";
            cin >> issue_num;
            
            // Update jth element by issue number = issue_num
            mag[j].recvNewIssue(issue_num);
        
        }else if(n==5){
            
            for(int k=0; k<i; k++){
                cout <<k<<". Title : "<< mag[k].getTitle() <<endl;
                cout <<k<<". Price : "<< mag[k].getPrice() <<endl;
                cout <<k<<". Copies : "<< mag[k].getCopies() <<endl;
                cout <<k<<". Current Issue : "<< mag[k].getCurrIssue()<<endl;
                cout <<endl<<endl;
            }

            int tmp, num_books;
            cout << "Enter the serial number of the Magzine to be ordered. : ";
            cin >> tmp;
            cout << "Enter the number of Magzine to be ordered. : ";
            cin >> num_books;
            if(num_books > mag[tmp].getCopies()){
                cout << "Sorry we can not complete this transaction due to stock unavailability. Please try again later.";   
            }else{
                mag[tmp].updateCopies( mag[tmp].getCopies() - num_books);
                cout << "Congratulations, Your order is confirmed."<<endl;
            }

        }else if(n==6){
            string t1;
            int prs1;
            int cps1;
            double cris1;

            cout << "Enter title :";
            getline(cin,t1);
            discmag[p].updateTitle(t1);

            cout << "Enter price : ";
            cin >> prs1;
            discmag[p].updatePrice(prs1);

            cout << "Enter num copies : ";
            cin >> cps1;
            discmag[p].updateCopies(cps1);

            cout << "Enter current issue : ";
            cin >> cris1;
            discmag[p].updateCurrIssue(cris1);
            
            p++;


        }else if(n==7){
            int j = 0;
            double issue_num;

            cout << "Select the book to be update. Press from 0 to "<<p<<endl;
            for(j=0; j<p; j++){
                cout << j << " : " << discmag[j].getTitle() << "  " << discmag[j].getCurrIssue() << endl;
            }

            cin >> j;
            cout << "Enter new issue number : "<<endl;
            cin >> issue_num;
            
            // Update jth element by issue number = issue_num
            discmag[j].recvNewIssue(issue_num);
        
        }else if(n==8){
            for(int k=0; k<p; k++){
                cout <<k<<". Title : "<< discmag[k].getTitle() <<endl;
                cout <<k<<". Price : "<< discmag[k].getPrice() <<endl;
                cout <<k<<". Copies : "<< discmag[k].getCopies() <<endl;
                cout <<k<<". Current Issue : "<< discmag[k].getCurrIssue()<<endl;
                cout <<endl<<endl;
            }

            int tmp, num_books;
            cout << "Enter the serial number of the Disc Magzine to be ordered. : ";
            cin >> tmp;
            cout << "Enter the number of Disc Magzine to be ordered. : ";
            cin >> num_books;
            if(num_books > discmag[tmp].getCopies()){
                cout << "Sorry we can not complete this transaction due to stock unavailability. Please try again later.";   
            }else{
                discmag[tmp].updateCopies( discmag[tmp].getCopies() - num_books);
                cout << "Congratulations, Your order is confirmed."<<endl;
            }
        }
        
            
        
        else if(n==9){
            string t;
            int prs;
            int cps;
            string aut;

            cout << "Enter title :";
            getline(cin,t,'\n');
            book[r].updateTitle(t);

            cout << "Enter price : " << endl;
            cin >> prs;
            book[r].updatePrice(prs);

            cout << "Enter num copies : " << endl;
            cin >> cps;
            book[r].updateCopies(cps);

            cout << "Enter Author name : " << endl;
            cin >> aut;
            book[r].updateAuthor(aut);
            
            r++;


        }else if(n==10){
            for(int k=0; k<r; k++){
                cout <<k<<". Title : "<< book[k].getTitle() <<endl;
                cout <<k<<". Price : "<< book[k].getPrice() <<endl;
                cout <<k<<". Copies : "<< book[k].getCopies() <<endl;
                cout <<k<<". Author : "<< book[k].getAuthor()<<endl;
                cout <<endl<<endl;
            }
    
            int tmp, num_books;
            cout << "Enter the serial number of the Books to be ordered. : ";
            cin >> tmp;
            cout << "Enter the number of Books to be ordered. : ";
            cin >> num_books;
            if(num_books > book[tmp].getCopies()){
                cout << "Sorry we can not complete this transaction due to stock unavailability. Please try again later.";   
                cout << "Congratulations, Your order is confirmed."<<endl;
            }else{
                book[tmp].updateCopies( book[tmp].getCopies() - num_books);
            }
        
        }else if(n==11){
            break;
        }
    }

    return 0;
}