#include<iostream>
#include<fstream>
#include<limits>
#include<vector>
#include<string>
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

bool YN() {
	
	string input = "";
	
	while(true)
	{
		cout << "Answer: ";
		cin >> input;
		
		if(input == "YES" || input == "Yes" || input == "Y" ||
								 input == "yes" || input == "y")
			return true;
		
		if(input == "NO" || input == "No" || input == "N" ||
								 input == "no" || input == "n")
			return false;
	}
}

void separate(int minuses) { // cosmetic
	cout << "<";
	for(int i = 0; i < minuses - 2; i++)
		cout << "-";
	cout << ">";
}

bool maxCruisesValidation(vector<Travel> Cruises) {
	if(Cruises.size() >= 100)return true;
	return false;
}

void maxCruisesValidation() {
	cout << "Maximum size of cruises reached!(100)\n"
		<<"If you want to add cruse, change one\n";
		system("pause");
}

int intValidation(string print) {
	
	cout << print;
	int input;
	cin >> input;
	while(!cin)
	{
		cout << "Enter a number!!!";
		cin.clear();
		cin.ignore(10000, '\n');
	//	system("pause");
	//	lineEraser(3,print.size());
		cout << print;
		cin >> input;	
	}
	//cin.clear();
	cin.ignore(10000, '\n');
	return input;
}
double doubleValidation(string print) {
	cout << print;
	double input;
	cin >> input;
	while(!cin)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Choose a number!\n" << print;
		cin >> input;	
	}
	return input;
}

bool areCruises(vector<Travel> Cruises) {
	return Cruises.size() == 0 ? false : true;
}

void updateFile(vector<Travel> Cruises) {
	
	ofstream updateFile("memory.txt");
	for(int i = 0; i < Cruises.size(); ++i)
	{
		updateFile << Cruises.at(i).cruiseNum << endl;
		updateFile << Cruises.at(i).route << endl;
		updateFile << Cruises.at(i).ship << endl;
		updateFile << Cruises.at(i).captain << endl;
		updateFile << Cruises.at(i).priceClass1 << endl;
		updateFile << Cruises.at(i).priceClass2 << endl;
		updateFile << Cruises.at(i).numPassengersClass1 << endl;
		updateFile << Cruises.at(i).numPassengersClass2 << endl;
		updateFile << Cruises.at(i).dateStart << endl;
		updateFile << Cruises.at(i).dateEnd << endl;
	} 
}

void loadMemory(vector<Travel> *Cruises) {
	
	ifstream getFile("memory.txt");
	
	Travel loader;
	
	string line;
	while(getline(getFile, line))
	{
		//getline(getFile, line);
		loader.cruiseNum= stoi(line);
		
		getline(getFile, loader.route);
		getline(getFile, loader.ship);
		getline(getFile, loader.captain);
		
		getline(getFile, line);
		loader.priceClass1 = stoi(line);
		
		getline(getFile, line);
		loader.priceClass2 = stoi(line);
		
		getline(getFile, line);
		loader.numPassengersClass1 = stoi(line);
		
		getline(getFile, line);
		loader.numPassengersClass2 = stoi(line);
		
		getline(getFile, loader.dateStart);
		getline(getFile, loader.dateEnd);
		
		Cruises->push_back(loader);
	}
	getFile.close();
}

void addCruise(vector<Travel> *Cruises, int cruiseNum = 0) {
	
	system("cls");
	
	if(cruiseNum == 0)
	{
		cruiseNum = Cruises->size() + 1;
		cout << "Adding cruise:\n\n";
	}
	else cout << "Changing cruise " << cruiseNum << "\n\n";
	
	ofstream fout;
	ifstream fin;
	fout.open("memory.txt", ios::out | ios::app);
	fin.open("memory.txt", ios::in);
	
	Travel newCruise;
	
	newCruise.cruiseNum = cruiseNum;
	
	cout << "Cruise " << newCruise.cruiseNum << endl
		<< "Route: ";
	fout << newCruise.cruiseNum << endl;
	
	getline(cin >> ws, newCruise.route);
	fout << newCruise.route << endl;
	
	cout << "Ship : ";
	getline(cin >> ws, newCruise.ship);
	fout << newCruise.ship << endl;
	
	cout << "Captain name: ";
	getline(cin >> ws, newCruise.captain);
	fout << newCruise.captain << endl;
	
	int input = 0;
	
	newCruise.priceClass1 = doubleValidation("Price for class 1: ");
	fout << newCruise.priceClass1 << endl;
	
	newCruise.priceClass2 = doubleValidation("Price for class 2: ");
	fout << newCruise.priceClass2 << endl;
	
	newCruise.numPassengersClass1 = 
				intValidation("Number of passengers in class 1: ");
	fout << newCruise.numPassengersClass1 << endl;
	
	cout << "Number of passengers in class 2: ";
	cin >> newCruise.numPassengersClass2;
	fout << newCruise.numPassengersClass2 << endl;
	
	cout << "Starting date of cruise: ";
	cin >> newCruise.dateStart;
	fout << newCruise.dateStart << endl;
	
	cout << "Ending date of cruise: ";
	cin >> newCruise.dateEnd;
	fout << newCruise.dateEnd << endl;
	
	Cruises->push_back(newCruise);
}

void addCruises(vector<Travel> *Cruises) {
	
	system("cls");
	
	if(maxCruisesValidation(*Cruises))
	{
		maxCruisesValidation();
		return;
	}

	
	cout << "Add cruise\n\n"
		<< "1.Add one cruise\n"
		<< "2.Add more than one cruises\n";
		
	int input = 0;
	while(input !=1 && input != 2)
	{
		input = intValidation("Answer: ");//Choose 1 or 2\n");
		
		switch(input)
		{
			case 1: 
				addCruise(Cruises);
				return;
			case 2: break;
			
			
			default: cout << "Choose 1 or 2\n";
		}
	}
	
	input = 0;
	
	while(input > 100 - Cruises->size() || input == 0)
	{
		system("cls");
		
		cout << "You can enter maximum " << 100 - Cruises->size();
		if(100 - Cruises->size() == 1)
		{
			cout << " cruise.\n\n";
			cout << "Do you want to enter one cruise?(yes/no)\n";
			if(!YN())return;
			input = 1;
		}
		else
		{
			cout << " cruises.\n";	
			input = intValidation("Number of cruises you want to enter: ");
		} 
		
		
	}
	
	for(int i = 0; i < input; ++i)
	{
		if(maxCruisesValidation(*Cruises))
		{
			maxCruisesValidation();
			return;
		}
		
		addCruise(Cruises);
		
		cout << '\n';
		
		separate(strlen("Continue adding cruises?(yes/no)"));
		
		cout << "\n\nContinue adding cruises?(yes/no)\n";
		
		if(!YN())break;
	}
	
}

void printVector(vector<Travel> Cruises, bool pause = true) {
	
	system("cls");
	if(!areCruises(Cruises))
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
			<< "End date: " << Cruises.at(i).dateEnd << "\n\n";
			
			if(i != Cruises.size() - 1)separate(30);
			cout << "\n\n";
		//cout << "\n\n\n";
	}
	if(pause)system("pause");
}

void changeCruise(vector<Travel> *Cruises) {
	
	system("cls");
	
	if(!areCruises(*Cruises))
	{
		cout << "You can't change cruises, because there are none.\n";
		system("pause");
		return;
	}
	
	
	cout << "You choosed to change a cruise\n"
		<< "There are currently " << Cruises->size() << " cruise(s)\n"
		<< "Do you want to print all cruises?(yes/no)\n";
		
	if(YN())printVector(*Cruises,false);
	
	separate(strlen("Choose which cruise you want to change"));
	cout << "\n\nChoose which cruise you want to change\n";
	
	int cruiseToChange;
	
	do 
		cruiseToChange = intValidation("Between 1 and " +
							to_string(Cruises->size()) +
							 "\nNumber of cruise: ");
							 
	while(cruiseToChange < 1 || cruiseToChange > Cruises->size());
	
	addCruise(Cruises,cruiseToChange);
	
	Cruises->at(cruiseToChange - 1) = Cruises->at(Cruises->size() - 1);
	
	Cruises->at(cruiseToChange - 1).cruiseNum = cruiseToChange;
	
	Cruises->erase(Cruises->end());
	
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
		<< "1.Add cruise(s)\n"
		<< "2.Show all cruises\n"
		<< "3.Change cruise\n"
		<< "4.Cruise with the lowest price\n"
		<< "5.Cruise with the most passengers\n"
		<< "6.Ship with the most cruises\n"
		<< "7.Show cruises sorted by...\n"
		<< "8.Exit\n"
		;
}

int main() {
	
	vector<Travel> Cruises;
	loadMemory(&Cruises);
	/*
	Travel A;
	A.cruiseNum = 1;
	A.captain = "Ivan";
	Cruises.push_back(A);
	Travel B;
	B.cruiseNum = 2;
	B.captain = "Zoro";
	Cruises.push_back(B);
	
	Travel C;
	C.cruiseNum = 3;
	C.captain = "Gosho";
	Cruises.push_back(C);
	*/
	ofstream fout;
	ifstream fin;
	fout.open("memory.txt", ios::out | ios::app);
	fin.open("memory.txt", ios::in);
	
	if (fin.is_open())
	{
		cout << "File is ready\n";
		system("pause");
		//fin.close();
	}
	else 
	{
		cout << "Unable to open file\n";
		system("pause");
		return 0;
	}
	//string a;
	//getline(fin, a);
	//cout << a;
	//Cruises.at(0).route = a;
	
	int input = 0;
	
	while(input != 8)
	{
		system("cls");
		functions();
		
		//cout << "\noption: ";
		input = intValidation("\noption: ");
		
		switch(input)
		{
			case 1: addCruises(&Cruises); break;
			case 2: printVector(Cruises); break;
			case 3: changeCruise(&Cruises);break;
			case 7: ODIT(); break;
			case 8: break;
			
			default: cout << "Enter a number between 1 and 8!!!\n";
				system("pause");
		}
		updateFile(Cruises);
	}
	
}
