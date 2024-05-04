#include <iostream>
#include <iomanip>

using namespace std;

class Presidential;
class Villa;
class Double;

float getPrice();

// The class of staff
class Staff
{
	private : 
		int id , age;
		string name, pw;
		string position;
	
	public : 
		Staff(string name, int id, int age, string position, string pass)
		{
			this->name = name;
			this->id = id;
			this->age = age;
			this->position = position;
			this->pw = pass;
		}
		
		void setName(string n)
		{
			name = n;
		}
		
		void setID(int id)
		{
			id = id;
		}
		
		void setAge(int a)
		{
			age = a;
		}
		
		void setPosition(string p)
		{
			position = p;
		}
		
		string getName()
		{
			return name;
		}
		
		int getID()
		{
			return id;
		}
		
		int getAge()
		{
			return age;
		}
		
		string getPosition()
		{
			return position;
		}

		string getPassword()
		{
			return pw;
		}
		
};



// Function that verifies if staff is valid in the system.
int verifystaff(Staff s[], int size)
{
	int id;
	string pw;
	cout << "\n                                                                        Enter your Staff ID : ";
	cin >> id;
	cin.ignore();
	cout << "\n                                                                        Enter your password : ";
	getline(cin, pw);
	cout << endl;
	
	for(int i = 0; i < size; i++)
	{
		if(id == s[i].getID() && pw == s[i].getPassword())
		{
			return 1;
		}
	}
	
	return 0;
}

//Function to get the total sales of the hotel
float printTotal(Double d[], Presidential p[], Villa v[]){
	float total = 0;
	for(int i = 0; i < 10; i++){
		total += d[i].getPrice() * d[i].getNights();
		total += p[i].getPrice() * p[i].getNights();
		total += v[i].getPrice() * v[i].getNights();
	}
	return total;
}
