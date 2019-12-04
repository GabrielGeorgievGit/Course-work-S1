#include<iostream>
#include<fstream>

#include<vector>
#include<string>
#include <windows.h>
#include<algorithm>
#include<ctime>
#include<chrono>
using namespace std;

struct Travel {
	
	int cruiseNum;
	string route;
	string ship;
	string captain;
	
	double priceClass1 = 0.0, priceClass2 = 0.0;
	
	int numPassengersClass1, numPassengersClass2;
	
	string dateStart, dateEnd;
	
};

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
	if(Cruises.size() >= 100) return true;
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

//Date..........................................

struct Date {unsigned day, month, year, hour, min;};

Date getDateValue(string s) {
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

bool isBiggerDate(string date1, string date2) {
	
	if(date1 == "" || date2 == "") return false;
	
	Date D1, D2;
	D1 = getDateValue(date1);
	D2 = getDateValue(date2);
	
	if(D1.year > D2.year) return true;
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

bool isForbiddenDate(vector<Travel> Cruises, Travel Cruise) {
	
	Date Start = getDateValue(Cruise.dateStart);	
	Date End = getDateValue(Cruise.dateEnd);
	
	vector<Travel> sameName;
	
	for(int i = 0; i < Cruises.size(); ++i)
	{
		if(Cruise.cruiseNum == Cruises.at(i).cruiseNum)
			continue;
		
		if(Cruise.ship == Cruises.at(i).ship || 
			Cruise.captain == Cruises.at(i).captain)	
			
			sameName.push_back(Cruises.at(i));
	}
		
	//printVector(sameName);
	for(int i = 0; i < sameName.size(); ++i)
	
		if(isBiggerDate(sameName.at(i).dateStart, Cruise.dateEnd) ||
			isBiggerDate(Cruise.dateStart, sameName.at(i).dateEnd))
			
			continue;
				
		else return true;
		
	return false;
}

string dateValidation(string print, string minDate = "") {
	
	unsigned day, month, year, maxDaysOfMonth;
	unsigned dayMin = 0, monthMin = 0, yearMin = 0, hourMin = 0, minutesMin = 0;
	
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
					maxDaysOfMonth = 31; break;
				
				case 4: case 6: case 9: case 11:
					maxDaysOfMonth = 30; break;
					
				default: maxDaysOfMonth = year % 4 == 0 ? 29 : 28; 
			}
			
			if(day > maxDaysOfMonth)
			{
				cout << "Invalid date!\n";
				system("pause");	
			}
		}
		while(day > maxDaysOfMonth);
		
		date += to_string(day) + '/';
		date += to_string(month) + '/';
		date += to_string(year);
		
		
		do	hour = intValidation("hour: ");
		while(hour > 23);
		
		do minutes = intValidation("minutes: ");
		while(minutes > 59);
		
		string sHour = to_string(hour), 
			sMinutes = to_string(minutes);
			
		if(sHour.length() == 1) sHour = "0" + sHour;
		if(sMinutes.length() == 1) sMinutes = "0" + sMinutes;
		
		date = date + " " + sHour + ":" + sMinutes;
		
		if(isBiggerDate(minDate, date))
		{
			cout << "Enter a bigger date than " << minDate << '\n';
			system("pause");
		}
	}
	while(isBiggerDate(minDate, date));

	return date;
}

bool isGoneCruise(string startDate) {
	
	time_t t = time(NULL);
	tm *Today = localtime(&t);

    string time = to_string(Today->tm_mday) + '/' +
				to_string(Today->tm_mon + 1) + '/' +
				to_string(Today->tm_year + 1900) + ' ' +
				to_string(Today->tm_hour) + ':' +
				to_string(Today->tm_min);
	
	if(isBiggerDate(time, startDate)) 
	{
		cout << "\n\nToday is " << time << '\n';
		return true;
	}
	
	return false;
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
		updateFile << Cruises.at(i).cruiseNum << '\n';
		updateFile << Cruises.at(i).route << '\n';
		updateFile << Cruises.at(i).ship << '\n';
		updateFile << Cruises.at(i).captain << '\n';
		updateFile << Cruises.at(i).priceClass1 << '\n';
		updateFile << Cruises.at(i).priceClass2 << '\n';
		updateFile << Cruises.at(i).numPassengersClass1 << '\n';
		updateFile << Cruises.at(i).numPassengersClass2 << '\n';
		updateFile << Cruises.at(i).dateStart << '\n';
		updateFile << Cruises.at(i).dateEnd << '\n';
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

//B. Dobavqne na morski pytuvaniq

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
	
	cout << "Cruise " << newCruise.cruiseNum << '\n'
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
	
	bool forbidden = false;
	do
	{
		newCruise.dateStart = dateValidation("Starting date of cruise: \n");
		
		newCruise.dateEnd =
			dateValidation("Ending date of cruise: \n", newCruise.dateStart);
		if(isForbiddenDate(*Cruises, newCruise))
		{
			forbidden = true;
			
			cout << "\n\n\nThis date is forbidden!\n" << 
				"The ship or captain of cruise is busy at this time.\n" <<
				"Try entering different starting date and ending date of cruise.\n\n" <<
				"Do you want to try different date?(yes/no)('no' will cancel";
				if(cruiseNum == 0) cout << " adding ";
				else cout << " changing ";
				cout << "cruise)\n";
			
			if(!YN())
			{
				newCruise.dateEnd = "";
				Cruises->push_back(newCruise);
				
				cout << "\n\nAdding cruise is canceled\n";
				system("pause");
				return;
			}
			else cout << "\n\n\n";
		}
		else forbidden = false;
		
	}
	while(forbidden);
	
	ofstream addToFile;
	addToFile.open("memory.txt", ios::out | ios::app);
	
	addToFile << newCruise.cruiseNum << '\n';
	addToFile << newCruise.route << '\n';
	addToFile << newCruise.ship << '\n';
	addToFile << newCruise.captain << '\n';
	addToFile << newCruise.priceClass1 << '\n';
	addToFile << newCruise.priceClass2 << '\n';
	addToFile << newCruise.numPassengersClass1 << '\n';
	addToFile << newCruise.numPassengersClass2 << '\n';
	addToFile << newCruise.dateStart << '\n';
	addToFile << newCruise.dateEnd << '\n';
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
			if(!YN()) return;
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

//C. Izvezdane na vsichki pytuvaniq

void printVector(vector<Travel> Cruises, int cruiseNum = -1) {
	
	int i = 0;
	if(cruiseNum == -1)
	{
		system("cls");
		cruiseNum = Cruises.size();
		i = 0;
	}
	else
	{
		i = cruiseNum;
		++cruiseNum;
	}
	
	if(!areCruises(Cruises))
	{
		cout << "There are no cruises.\n";
		system("pause");
		return;
	}
	
	for(i; i < cruiseNum; ++i)
	{
		
		cout << "Cruise " << Cruises.at(i).cruiseNum << '\n' 
			<< "Route: " << Cruises.at(i).route << '\n'
			<< "Ship name: " << Cruises.at(i).ship << '\n'
			<< "Captain: " << Cruises.at(i).captain << '\n'
			<< "Class 1 price: " << Cruises.at(i).priceClass1 << '\n'
			<< "Class 2 price: " << Cruises.at(i).priceClass2 << '\n'
			<< "Class 1 passengers: " << Cruises.at(i).numPassengersClass1 << '\n'
			<< "Class 2 passengers: " << Cruises.at(i).numPassengersClass2 << '\n'
			<< "Start date: " << Cruises.at(i).dateStart << '\n'
			<< "End date: " << Cruises.at(i).dateEnd << "\n\n";
			
			if(i != cruiseNum - 1)
			{
				separate(30);	
				cout << "\n\n";
			}
	}
}

//D. Korekciq na danni za pytuvane

void changeCruise(vector<Travel> *Cruises) {//TODO--------------------------------------Ako lipsvat danni: syobshtenie
	
	system("cls");
	
	if(!areCruises(*Cruises))
	{
		cout << "You can't change cruises, because there are none.\n";
		return;
	}
	
	cout << "You choosed to change a cruise\n"
		<< "There are currently " << Cruises->size() << " cruise(s)\n"
		<< "Do you want to print all cruises?(yes/no)\n";
		
	if(YN()) printVector(*Cruises);
	
	separate(strlen("Choose which cruise you want to change"));
	cout << "\n\nChoose which cruise you want to change\n";
	
	int cruiseToChange;
	do 
		cruiseToChange = intValidation("Between 1 and " + to_string(Cruises->size()) +
							 "\nNumber of cruise: ");
							 
	while(cruiseToChange < 1 || cruiseToChange > Cruises->size());
	
	if(isGoneCruise(Cruises->at(cruiseToChange - 1).dateStart))
	{
		cout << "\nThis cruise cannot be changed, because it's gone\n\n";
		return;
	}
	
	addCruise(Cruises,cruiseToChange);
	
	if(Cruises->at(Cruises->size() - 1).dateEnd != "")
	{
		Cruises->at(cruiseToChange - 1) = Cruises->at(Cruises->size() - 1);
		
		Cruises->at(cruiseToChange - 1).cruiseNum = cruiseToChange;
		
		Cruises->erase(Cruises->end());
		cout << "\nCruise " << cruiseToChange << " successfully changed.\n\n";
		
		return;
	}
	Cruises->erase(Cruises->end());
	cout << "\nCruise " << cruiseToChange << " didn't changed.\n";
}

//E. Sparvki za:

void lowestTotalPrice(vector<Travel> Cruises) {
	
	system("cls");
	
	if(!areCruises(Cruises))
	{
		cout << "There are no cruises.\n";
		return;
	}
	
	int index = 0;
	unsigned lowest =
		(Cruises.at(0).priceClass1 + Cruises.at(0).priceClass2);
	unsigned avrg;
		
	for(int i = 1; i < Cruises.size(); ++i)
	{	
		avrg = (Cruises.at(i).priceClass1 + Cruises.at(i).priceClass2);
		
		if(avrg < lowest)
		{
			index = i;
			lowest = avrg;
		}
	}
	
	cout << "Cruise with the lowest total price:\n\n";
	printVector(Cruises, index);
	
	cout << "\n\nLowest total price: " << lowest << "\n\n";
}

void cruiseMostPassengers(vector<Travel> Cruises) {
	
	system("cls");
	
	if(!areCruises(Cruises))
	{
		cout << "There are no cruises.\n";
		return;
	}
	
	int index = 0;
	unsigned theMost =
		Cruises.at(0).numPassengersClass1 + Cruises.at(0).numPassengersClass2;
	unsigned current;
		
	for(int i = 1; i < Cruises.size(); ++i)
	{	
		current =
			Cruises.at(i).numPassengersClass1 + Cruises.at(i).numPassengersClass2;
		
		if(current > theMost)
		{
			index = i;
			theMost = current;
		}
	}
	cout << "Cruise with the most passengers:\n\n";
	printVector(Cruises, index);
	cout << "\nPassengers: " << theMost << "\n\n";
}

void shipMostCruises(vector<Travel> Cruises) {
	
	system("cls");
	
	if(!areCruises(Cruises))
	{
		cout << "There are no cruises.\n";
		return;
	}
	
	string a[100][2];
	
	for(int i = 0; i < Cruises.size(); ++i)
	{
		a[i][0] = Cruises.at(i).ship;
		a[i][1] = "0";
	}
	
	for(int i = 0; i < Cruises.size(); ++i)
	{
		for(int j = 0; j < Cruises.size(); ++j)
		
			if(a[i][0] == Cruises.at(j).ship)
				a[i][1] = to_string(stoi(a[i][1]) + 1);
	}
	
	unsigned max = stoi(a[0][1]);
	unsigned index = 0;
	string shipName = a[0][0];
	
	for(int i = 1; i < Cruises.size(); ++i)
		
		if(max < stoi(a[i][1]))
		{
			max = stoi(a[i][1]);
			index = i;
			shipName = a[i][0];
		}
	
	cout << "Ship with the most cruises: " << shipName
		<< "\n\nNumber of cruises: " << max
		
		<< "\n\nDo you want to show all " << shipName << "'s cruises?(yes/no)\n";
	if(YN())
	{
		cout << "\n\nAll " << shipName << "'s cruises(" << max << "):\n\n";
		
		for(int i = 0; i < Cruises.size(); ++i)
			
			if(Cruises.at(i).ship == shipName)
				printVector(Cruises, i);
	}
}

//F. Odit na morskite putuvaniq:

struct LessThanShip {
    
    /*
	bool operator()(Travel ship1, Travel ship2) {
		return transform(ship1.ship.begin(), ship1.ship.end(), ship1.ship.begin(), ::tolower) < 
			transform(ship2.ship.begin(), ship2.ship.end(), ship2.ship.begin(), ::tolower);}//------------------------Oh no :(
			*/
    
	bool operator()(Travel &ship1, Travel &ship2) {
		return ship1.ship < ship2.ship;}
    
    bool month(Date month1, Date month2) {return true;}//TODO..............................................
};

vector<Travel> ShipsToLowercase(vector<Travel> ToLower) {
	for(int i = 0; i < ToLower.size(); ++i)
		//ToLower.at(i).ship = to_lower(ToLower.at(i).ship);
		transform(ToLower.at(i).ship.begin(), ToLower.at(i).ship.end(), ToLower.at(i).ship.begin(), ::tolower);//delete M8 else Oh no :(
	
	return ToLower;
}

void sortByShip(vector<Travel> Cruises) {
	
	system("cls");
	
	if(!areCruises(Cruises))
	{
		cout << "There are no cruises.\n";
		return;
	}
	
	//Cruises = ShipsToLowercase(Cruises);
	
	sort(Cruises.begin(), Cruises.end(), LessThanShip());
	
	printVector(Cruises);
	
	cout << "There are " << Cruises.size() << " cruises " 
		<< ", sorted by their ship name.\n\n";
}

//...................................................

struct LessThanDate {
	bool operator()(Travel &date1, Travel &date2) {
		return !isBiggerDate(date1.dateStart, date2.dateStart);}
};

bool InDatePeriod(string dateStart, string date1, string date2) {
		return isBiggerDate(dateStart, date1) && !isBiggerDate(dateStart, date2);
}

vector<Travel> getCruisesInPeriod(vector<Travel> Cruises, string date1, string date2) {
	
	vector<Travel> inPeriod;
	
	for(int i = 0; i < Cruises.size(); ++i)
	
		if(InDatePeriod(Cruises.at(i).dateStart, date1, date2))
			inPeriod.push_back(Cruises.at(i));
	
	return inPeriod;
}

void sortByPeriod(vector<Travel> Cruises) {
	
	system("cls");
	
	if(!areCruises(Cruises))
	{
		cout << "There are no cruises.\n";
		return;
	}
	
	cout << "Cruises for period, sorted by starting date\n\n";
	
	string date1 = "", date2 = "";
	
	do
	{
	
		date1 = dateValidation("Starting date of period: \n");
	
		date2 =	dateValidation("Ending date of period: \n", date1);
		
		Cruises = getCruisesInPeriod(Cruises, date1, date2);
		
		if(Cruises.size() == 0)
		{
			cout << "There are no cruises in this period\n"
				<< "Do you want to enter a different period?(Y/N)\n";
			
			if(YN())
			{
				system("cls");
				cout << "Cruises for period, sorted by starting date\n\n";
				continue;
			}
			else return;
		}
	} while(Cruises.size() == 0);
	
	sort(Cruises.begin(), Cruises.end(), LessThanDate());
	
	printVector(Cruises);
	
	cout << "There are " << Cruises.size() << " cruises between " 
		<< date1 << " and " << date2 << ", sorted by their starting date.\n\n";
}

//...................................................

void sortByRouteAndMonth(vector<Travel> Cruises) {//TODO-----------------------------------------
	system("cls");
	
	if(!areCruises(Cruises))
	{
		cout << "There are no cruises.\n";
		return;
	}
	
	cout << "Cruises sorted by ship name:\n\n";
	
	sort(Cruises.begin(), Cruises.end(), LessThanDate());
	
	printVector(Cruises);
}

void ODIT(vector<Travel> Cruises) {
	
	system("cls");
	
	cout << "Odit:\n\n" 
		<< "1.Cruises sorted by ship name\n"
		<< "2.Cruises for period, sorted by starting date\n"
		<< "3.Cruises to routes and month sorted by month\n"
		<< "4.Back\n"
		;
	
	int input = 0;
	while(input > 4 || input < 1)
	{
		input = intValidation("\noption: ");
		
		switch(input)
		{
			case 1: sortByShip(Cruises); break;
			case 2: sortByPeriod(Cruises); break;
			case 4: return;
		}
	}
}

//A. Menu

void functions() {
	
	cout << "Main menu:\n\n" 
		<< "1.Add cruise(s)\n"
		<< "2.Show all cruises\n"
		<< "3.Change cruise\n"
		<< "4.Cruise with the lowest average price\n"
		<< "5.Cruise with the most passengers\n"
		<< "6.Ship with the most cruises\n"
		<< "7.Show cruises sorted by...\n"
		<< "8.Exit\n"
		;
}

int main() {
	//test();
	vector<Travel> Cruises;
	loadMemory(&Cruises);
	
	cout << Cruises.size() << " cruises\n";
	
	ifstream fin;//TODO-------------------------------------------------Otdelna funkciq za proverka na faila
	
	fin.open("memory.txt", ios::app);
	
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
			case 4: lowestTotalPrice(Cruises); break;
			case 5: cruiseMostPassengers(Cruises); break;
			case 6: shipMostCruises(Cruises); break;
			case 7: ODIT(Cruises); break;
			case 8: break;
			
			default: cout << "Enter a number between 1 and 8!!!\n";
				system("pause");
		}
		updateFile(Cruises);
		if(input > 1 /*&& input != 7*/ && input != 8) system("pause");
	}
}
