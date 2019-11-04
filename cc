#include<iostream>
#include<fstream>
#include<vector>
#include <windows.h>
using namespace std;

struct Travel {
	
	//public:
	int cruiseNum;
	string route;
	string ship;
	string captain;
	
	double priceClass1 = 0.0, priceClass2 = 0.0;
	
	int numPassengersClass1, numPassengersClass2;
	
	int day, month, year;
	string dateStart, dateEnd;
	
	
};

void lineEraser(int propertyIndex, Travel Obj) {
	
	system("cls");
	cout << "Adding cruise:\n"
		<< "\nRoute: " << Obj.route
		<< "\nShip : " << Obj.route
		<< "\nCaptain name: " << Obj.captain << endl;
	
	switch(propertyIndex)
	{
		case 1:
			cout << "Price for class 1: ";
			if(propertyIndex == 1)
			{
				cout << Obj.priceClass1 << endl;
				break;
			}
		case 2: cout << "Price for class 2: ";
				if(propertyIndex == 2)
				{
					cout << Obj.priceClass2 << endl;
					break;
				}
		
		case 3: cout << "Number of passengers in class 1: ";
					if(propertyIndex == 3)
				{
					cout << Obj.numPassengersClass1 << endl;
					break;
				}
		
		case 4: cout << "Number of passengers in class 2: ";
					if(propertyIndex == 4)
				{
					cout << Obj.numPassengersClass2 << endl;
					break;
				}
		

	}
	int input;
	cout << "IVAN: ";
		cout << "\b\b\b\b\b\b";
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = {5 , 0};//24 7		 
	SetConsoleCursorPosition(hStdOut,coord);
	//cout << "\n\b\b";
	

	//printf("\b");printf("\b");printf("\b");
	//const string a = spaces;
//	cout << spaces;
}

bool maxCruisesValidation(vector<Travel> Cruises) {
	if(Cruises.size() >= 2)return true;
	return false;
}
void maxCruisesValidation() {
	cout << "Maximum size of cruises reached!!!\n"
		<<"If you want to add cruse, change one\n";
		system("pause");
}

int intValidation(string print) {
	
	cout << print;
	int input;
	cin >> input;
	while(!cin)
	{
		//cout << "Enter an integer!!!\n";
		cin.clear();
		cin.ignore(10000, '\n');
	//	system("pause");
	//	lineEraser(3,print.size());
		cout << endl << print;
		cin >> input;	
	}
	return input;
}

void addCruise(vector<Travel> *Cruises) {
	
	system("cls");
	
	if(maxCruisesValidation(*Cruises))
	{
		maxCruisesValidation();
		return;
	}
	
	cout << "Adding cruise:\n\n";
	Travel newCruise;
	newCruise.cruiseNum = Cruises->size() + 1;
	cout << "Cruise " << newCruise.cruiseNum << endl
		<< "Route: ";
	getline(cin >> ws, newCruise.route);
	
	cout << "Ship : ";
	getline(cin >> ws, newCruise.ship);
	
	cout << "Captain name: ";
	getline(cin >> ws, newCruise.captain);
	
	int input = 0;
	
	newCruise.priceClass1 = intValidation("Price for class 1: ");
//	cout << "Price for class 1: ";
//	cin >> newCruise.priceClass1;
	
	cout << "Price for class 2: ";
	cin >> newCruise.priceClass2;
	
	cout << "Number of passengers in class 1: ";
	cin >> newCruise.numPassengersClass1;
	
	cout << "Number of passengers in class 2: ";
	cin >> newCruise.numPassengersClass2;
	
	cout << "Starting date of cruise: ";
	cin >> newCruise.dateStart;
	
	cout << "Ending date of cruise: ";
	cin >> newCruise.dateEnd;
	
	Cruises->push_back(newCruise);
}

void printVector(vector<Travel> Cruises) {
	
	system("cls");
	if(Cruises.size() == 0)
	{
		cout << "There are no cruises.\n";
		system("pause");
		return;
	}
	//vector<Travel>::iterator it;
	for(int i = 0; i < Cruises.size(); i++)
	{
		
		cout << "Cruise " << Cruises.at(i).cruiseNum << endl 
			<< "Route: " << Cruises.at(i).route << endl
			<< "Ship name: " << Cruises.at(i).ship << endl
			<< "Captain: " << Cruises.at(i).captain << endl
			<< "Class 1 price: " << Cruises.at(i).priceClass1 << endl
			<< "Class 2 price: " << Cruises.at(i).priceClass2 << endl
			<< "Class 1 passengers: " << Cruises.at(i).numPassengersClass1 << endl
			<< "Class 2 passengers: " << Cruises.at(i).numPassengersClass2 << endl
			<< "Start date: " << Cruises.at(i).dateStart << endl
			<< "End date: " << Cruises.at(i).dateEnd << endl
			
			
			;
		cout << "\n\n\n";
	}
	system("pause");
}

void ODIT() {
	system("cls");
	
	cout << "Odit:\n\n" << "1.Cruises sorted by ship nVme\n"
		<< "2.Cruises for a period sorted by date\n"
		<< "3.Cruises to routes and month sorted by month\n"
		<< "4.Back\n"
		;
	int input = 1;
	while(input > 0 && input < 3)
	cin >> input;
	switch(input)
	{
		
		case 4: return;
	}
}

void functions() {
	
	cout << "Main menu:\n\n" 
		<< "1.Add a cruise\n"
		<< "2.Show all cruises\n"
		<< "3.Change a cruise\n"
		<< "4.Cruise with lowest price\n"
		<< "5.Cruise with the most passengers\n"
		<< "6.Ship with the most cruises\n"
		<< "7.Show cruises sorted by...\n"
		<< "8.Exit\n"
		;
}

int main() {
	
	vector<Travel> Cruises;
	Travel A;// = new Travel;
	ofstream fout;
	ifstream fin;
	fout.open("memory.txt", ios::out | ios::app);
	fin.open("memory.txt", ios::in);
	//fout << "ivan" << endl;
	if (fin.is_open())
	{
		cout << "13\n";
		system("pause");
		//fin.close();
	}
	
	else 
	{
		cout << "Unable to open file\n";
		system("pause");
		return 0;
	}
	//if(fout.bad())return 0;
	fout << "KYS";
	int input = 0;
	
	while(input != 8)
	{
		system("cls");
		functions();
		
		cout << "\noption: ";
		cin >> input;
		switch(input)
		{
			case 1: addCruise(&Cruises); break;
			case 2: printVector(Cruises); break;
			
			case 7: ODIT(); break;
			case 8: break;
		}
	}
	
}
