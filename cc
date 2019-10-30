#include<iostream>
#include<vector>
using namespace std;

class Travel {
	string destination;
	string ship;
	string captain;
	double priceClass1, priceClass2;
	int numPassengersClass1, numPassengersClass2;
	string dateStart, dateEnd;
	
};

void add()
{
	
}

void ODIT() {
	
	cout << "1.Cruises sorted by ship name\n"
		<< "2.Cruises for a period sorted by date\n"
		<< "3.Cruises to destinations and month sorted by month\n"
		
		;
	int input;
	cin >> input;
	switch(input)
	{
		
	}
}

void functions() {
	cout << "1.add\n"
		<< "2.All cruises\n"
		<< "3.Cruise with lowest price\n"
		<< "4.Cruise with the most passengers\n"
		<< "5.Ship with the most cruises\n"
		<< "6.Show cruises sorted by...\n"
		
		;
}

int main() {
	vector<Travel>Cruises;
	Travel A;
	A.
	Cruises.push_back(new Travel);
	int input;
	
	while(true)
	{
		functions();
		
		cin >> input;
		switch(input)
		{
			case 1: add; break;
		}
	}
}
