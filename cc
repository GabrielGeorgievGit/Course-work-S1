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
	for(int i = 0; i < (minuses - 2) / 2; i++)
		cout << " - ";
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

//bool isNegative(double a) {return a < 0 ? true : false;}

int intValidation(string print) {
	
	cout << print;
	int input;
	cin >> input;
	
	while(!cin || input < 0)
	{
		cout << "Enter a positive number!\n";
		cin.clear();
		cin.ignore(10000, '\n');
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
	
	while(!cin || input < 0)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Enter a value, equal or bigger than zero!\n" << print;
		cin >> input;	
	}
	return input;
}

struct Date {unsigned day, month, year, hour, min;};

Date getDateValue(string s) //1/3/6 07:03  // IT WAS EZI
{	//s = "22/11/2019 19:02";
	Date date;
	int secondSlashPos;
	
	date.day = stoi(s.substr(0, s.find('/')));
	
	if(s.at(s.find('/') + 2) == '/')
	{
		date.month = stoi(s.substr(s.find('/') + 1, 1));
		secondSlashPos = s.find('/') + 2;
	}
	else 
	{
		date.month = stoi(s.substr(s.find('/') + 1, 2));
		secondSlashPos = s.find('/') + 3;
	}
	
	
	date.year = stoi(s.substr(secondSlashPos + 1, s.find(' ') - secondSlashPos));
	
	date.hour = stoi(s.substr(s.find(' ') + 1, 2));
	date.min = stoi(s.substr(s.find(':') + 1, 2));
	
	return date;
}

bool isBiggerDate(string date1, string date2) { // IT WAS FUN
	
	if(date1 == "" || date2 == "") return false;
	
	Date D1, D2;
	D1 = getDateValue(date1);
	D2 = getDateValue(date2);
	
	if(D1.year > D2.year) return true;//  14/2/6 07:03 || 14/3/6 07:03
	if(D1.year < D2.year) return false;
	
	if(D1.month > D2.month) return true;
	if(D1.month < D2.month) return false;
	
	if(D1.day > D2.day) return true;
	if(D1.day < D2.day) return false;
	
	if(D1.hour > D2.hour) return true;
	if(D1.hour < D2.hour) return false;
	
	if(D1.min > D2.min) return true;
	if(D1.min < D2.min) return false;
	
	return true;
}

string dateValidation(string print, string minDate = "") {
						//TODOTODOTODOTODOTODOTODOTODOTODOTODOTODOTODOTODOTODOTODO
	unsigned day, month, year, maxDaysOfMonth;
	unsigned dayMin = 0, monthMin = 0, yearMin = 0, hourMin = 0, minutesMin = 0;;
	
	int hour, minutes;
	
	string date;
	if(minDate != "")
	{
		dayMin = getDateValue(minDate).day;
		monthMin = getDateValue(minDate).month;
		yearMin = getDateValue(minDate).year;
		hourMin = getDateValue(minDate).hour;
		minutesMin = getDateValue(minDate).min;
	}
	do
	{
		date = "";
		do
		{
			cout << print;
			
			do
				day = intValidation("day: ");
			while(day < 1 || day > 31);
			
			do
				month = intValidation("month: ");
			while(month < 1 || month > 12);
			do
				year = intValidation("year: ");
			while(year < 1);
			
			switch(month)
			{
				case 1: case 3: case 5: case 7: case 8: case 10: case 12:
					maxDaysOfMonth = 31;break;
				
				case 4: case 6: case 9: case 11:
					maxDaysOfMonth = 30;break;
					
				default: maxDaysOfMonth = year % 4 == 0 ? 29 : 28; 
			}
			
			if(day > maxDaysOfMonth)
			{
				cout << "Invalid date!\n";
				system("pause");	
			}
		}
		while(day > maxDaysOfMonth);//Cruise start date:\n
		
		date += to_string(day) + '/';
		date += to_string(month) + '/';
		date += to_string(year);
		
		
		do	hour = intValidation("hour: ");
		while(hour > 23);
		
		do minutes = intValidation("minutes: ");
		while(minutes > 59);
		
		string sHour = to_string(hour), 
			sMinutes = to_string(minutes);
		if(sHour.length() == 1)sHour = "0" + sHour;
		if(sMinutes.length() == 1)sMinutes = "0" + sMinutes;
		
		//date += " " + hour + ':' + minutes;
		date = date + " " + sHour + ":" + sMinutes;
		
		if(isBiggerDate(minDate, date))
		{
			cout << "Enter a bigger date than " << minDate << endl;
			system("pause");
		}
	}
	while(isBiggerDate(minDate, date));
	
	return date;
}

bool areCruises(vector<Travel> Cruises) {
	return Cruises.size() == 0 ? false : true;
}

void updateFile(vector<Travel> Cruises) {
	
	ofstream updateFile;
	updateFile.open("memory.txt", ios::out);// | ios::app);
	//cout<<"\nUpdating...\n";
	//system("pause");
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
	updateFile.close();
}

void loadMemory(vector<Travel> *Cruises) {
	
	ifstream getFile;
	getFile.open("memory.txt", ios::in);
	
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
	getFile.close();/////////////////////////////////////////////////////
}

void addCruise(vector<Travel> *Cruises, int cruiseNum = 0) {
	
	system("cls");
	
	if(cruiseNum == 0)
	{
		cruiseNum = Cruises->size() + 1;
		cout << "Adding cruise:\n\n";
	}
	else cout << "Changing cruise " << cruiseNum << "\n\n";
	
	cout << "There are currently " << Cruises->size() << " cruises\n";//DELETE
	
	Travel newCruise;
	
	newCruise.cruiseNum = cruiseNum;
	
	cout << "Cruise " << newCruise.cruiseNum << endl
		<< "Route: ";
	
	getline(cin >> ws, newCruise.route);
	
	cout << "Ship : ";
	getline(cin >> ws, newCruise.ship);
	
	cout << "Captain name: ";
	getline(cin >> ws, newCruise.captain);
	
	newCruise.priceClass1 = doubleValidation("Price for class 1: ");
	
	newCruise.priceClass2 = doubleValidation("Price for class 2: ");
	
	newCruise.numPassengersClass1 = 
				intValidation("Number of passengers in class 1: ");
	
	newCruise.numPassengersClass2 = 
				intValidation("Number of passengers in class 2: ");
	
	newCruise.dateStart = dateValidation("Starting date of cruise: \n");
	
	newCruise.dateEnd =
		dateValidation("Ending date of cruise: \n", newCruise.dateStart);
	
	
	ofstream addToFile;
	addToFile.open("memory.txt", ios::out | ios::app);
	
	addToFile << newCruise.cruiseNum << endl;
	addToFile << newCruise.route << endl;
	addToFile << newCruise.ship << endl;
	addToFile << newCruise.captain << endl;
	addToFile << newCruise.priceClass1 << endl;
	addToFile << newCruise.priceClass2 << endl;
	addToFile << newCruise.numPassengersClass1 << endl;
	addToFile << newCruise.numPassengersClass2 << endl;
	addToFile << newCruise.dateStart << endl;
	addToFile << newCruise.dateEnd << endl;
	addToFile.close();
	
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
		<< "2.Add more than one cruises\n"
		<< "3.Back\n";
		
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
			case 3: return;
			
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
		if(i != input - 1)
			if(!YN()) break;
	}
	
}

void printVector(vector<Travel> Cruises) {//, bool pause = true) {
	
	system("cls");
	if(!areCruises(Cruises))
	{
		cout << "There are no cruises.\n";
		system("pause");
		return;
	}
	//vector<Travel>::iterator it;
	for(int i = 0; i < Cruises.size(); ++i)
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
			
			if(i != Cruises.size() - 1) separate(30);
			cout << "\n\n";
		//cout << "\n\n\n";
	}
	//if(pause)system("pause");
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
		
	if(YN())printVector(*Cruises);
	
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
	//cout << isBiggerDate("14/3/6 18:59", "14/3/6 18:58");
	//cout << "\nout of date\n";
	//system("pause");
	//return 0;
	vector<Travel> Cruises;
	loadMemory(&Cruises);
	//trya(Cruises);
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
	cout << Cruises.size() << " cruises\n";
	//ofstream fout;
	ifstream fin;
	//fout.open("memory.txt", ios::out | ios::app);
	fin.open("memory.txt", ios::app);//ios::in
	
	if (fin.is_open())
	{
		cout << "File is ready\n";
		system("pause");
	}
	else 
	{
		cout << "Unable to open file\n";
		system("pause");
		return 0;
	}
	fin.close();
	
	int input = 0;
	
	while(input != 8)
	{
		system("cls");
		functions();
		
		input = intValidation("\noption: ");
		
		switch(input)
		{
			case 1: addCruises(&Cruises); break;
			case 2: printVector(Cruises); break;
			case 3: changeCruise(&Cruises); break;
			case 7: ODIT(); break;
			case 8: break;
			
			default: cout << "Enter a number between 1 and 8!!!\n";
				//system("pause");
		}
		updateFile(Cruises);
		if(input == 2)system("pause");
	}
	
}
