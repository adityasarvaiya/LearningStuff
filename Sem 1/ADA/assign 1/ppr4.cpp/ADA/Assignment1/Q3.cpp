#include <bits/stdc++.h>
using namespace std;


class Person{
	string name;
	int age;
	char gender; // male/female
	
	public:
	Person(string _name, int _age, char _gender) : name(_name), age(_age),\
													gender(_gender)
	{}
	
	string getName()
	{
		return name;
	}
	
	int getAge()
	{
		return age;
	}
	
	char getGender()
	{
		return gender;
	}
	
	void setName(string _name)
	{
		name = _name;
		return;
	}
	
	void setAge(int _age)
	{
		age = _age;
		return;
	}
	
	void setGender(char _gender)
	{
		gender = _gender;
		return;
	}
};


class Money{
	public:
	static double basic_fee;
	Money(){}
};
double Money::basic_fee = 1000.00;


class Patient : public Person{
	string id;
	string hospital_name;
	string patient_address;
	int joining_year, medical_fees, curr_year;
	
	public:
	Patient(string _name, int _age, char _gender, 						\
			string _id, string _hospital_name, string _patient_address, \
			int _joining_year) : Person(_name, _age, _gender), id(_id), \
								hospital_name(_hospital_name), 			\
								patient_address(_patient_address),		
								joining_year(_joining_year), curr_year(2018)
	{}
	
	void setHospital(string _hname)
	{
		hospital_name = _hname;
		return;
	}
	
	void setYearOfJoining(int y)
	{
		joining_year = y;
		return;
	}
	
	void setAddress(string address) //patient's address
	{
		patient_address = address;
		return;
	}
	
	string getHospital()
	{
		return hospital_name;
	}
	
	int getYearOfJoining()
	{
		return joining_year;
	}
	
	string getAddress() //patient's address
	{
		return patient_address;
	}
	
	double calcMedFees(Money x)
	{
		medical_fees = x.basic_fee * (curr_year - joining_year);
		return medical_fees;
	}
};


int main(){
	Patient p("Jayce", 25, 'M', "LOL007", "League Health", "Apartment 5, Briggs Apartments, Antartica", 2016);
	
	cout<<"\n\nPatient name: "<<p.getName();
	cout<<"\n Age: "<<p.getAge();
	cout<<"\n Gender: "<<p.getGender();
	cout<<"\nAdmitted at: "<<p.getHospital();
	Money basicfees;
	cout<<"\nMedical fees: "<<p.calcMedFees(basicfees);
	
	return 0;
}
