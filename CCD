#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct Imoti
{
	string kvartal, street;
	double area, price;
	int stai;
};
void Menu(Imoti imoti[]);
void Add(Imoti imoti[]);
void Show(Imoti imoti[]);
void Edit(Imoti imoti[]);
void EditCena(Imoti imoti[]);
void Zakupuvane(Imoti imoti[]);
void Search(Imoti imoti[]);
void Close(Imoti imoti[]);
void Kvartal(Imoti imoti[]);
void Spravki(Imoti imoti[]);
void Podrezdane(Imoti imoti[]);
void ByPrice(Imoti imoti[]);
void ByRooms(Imoti imoti[]);
void MaxArea(Imoti imoti[]);
void MinPrice(Imoti imoti[]);
void MinPrice(Imoti imoti[]);
void fileOut(Imoti imoti[]);
void fileIn(Imoti imoti[]);
const int maxI = 50;
int size = 0;
int main()
{
	Imoti imoti[50];
	fileIn(imoti);
	Menu(imoti);
	return 0;
}
void Menu(Imoti imoti[])
{
	while(true)
	{
		system("cls");
		int input = 0;
		cout << "Menu\n";
		cout << "1.Dobavqne\n";
		cout << "2.Izvezdane\n";
		cout << "3.Redakciq\n";
		cout << "4.Tursene\n";
		cout << "5.Spravki\n";
	
		while(input > 5 || input < 1)
		{
			cin >> input;
		}
		switch(input)
		{
			case 1:Add(imoti);break;
			case 2:Show(imoti);break;
			case 3:Edit(imoti);break;
			case 4:Search(imoti);break;
			case 5:Spravki(imoti);break;
		}
		fileOut(imoti);
		if(input == 2)
		{
			system("pause");
		}
	}
}
void Add(Imoti imoti[])
{
	int input = 0;
	cout << "broi imoti:";
	cin >> input;
	if(input > maxI-size || input < 1)
	{
		cout << "nevaliden broi";
		system("pause");
		return;
	}
	for(int i = 0;i < input;i++)
	{
		size++;
		system("cls");
		cout << "Kvartali:\n";
		cout << "1.Mladost\n";
		cout << "2.Chaika\n";
		cout << "3.Levski\n";
		cout << "4.Centur\n";
		cout << "5.Grucki\n";
		cout << "izberi kvartal:";
		int nomer = 0;
		while(nomer > 5 || nomer < 1)
		{
			cin >> nomer;
		}
		switch(nomer)
		{
			case 1:imoti[size-1].kvartal = "Mladost";break;
			case 2:imoti[size-1].kvartal = "Chaika";break;
			case 3:imoti[size-1].kvartal = "Levski";break;
			case 4:imoti[size-1].kvartal = "Centur";break;
			case 5:imoti[size-1].kvartal = "Grucki";break;
		}
		cin.ignore(10000, '\n');
		cout << "ulica:";
		getline(cin, imoti[size-1].street);
		cout << "plosht:";
		cin >> imoti[size-1].area;
		cin.ignore(10000,'\n');
		cout << "Cena:";
		cin >> imoti[size-1].price;
		cin.ignore(10000,'\n');
		cout << "broi stai:";
		cin >> imoti[size-1].stai;
		cin.ignore(10000,'\n');
		if(input + 1 <= maxI)
		{
			cout << "Dobavqne na oshte edin?\n";
			cout << "1.Da\n";
			cout << "2.Ne\n";
			int a = 0;
			while(a > 2 || a < 1)
			{
				cin >> a;
			}
			switch(a)
			{
				case 1:input++;break;
				case 2:return;
			}
		}
	}
	system("pause");
}
void Show(Imoti imoti[])
{
	system("cls");
	if(size == 0)
	{
		cout << "nqma imoti";
		system("pause");
		return;
	}
	for(int i = 0; i < size; i++)
	{
		cout << "\nKvartal:" << imoti[i].kvartal;
		cout << "\nUlica:" << imoti[i].street;
		cout << "\nPlosht:" << imoti[i].area;
		cout << "\nCena:" << imoti[i].price;
		cout << "\nStai:" << imoti[i].stai;
		cout << endl;
//		if(i > size - 4)
//		{
//			cout << "Tova e poslednata stranica\n";
//			return;
//		}
		if(i+1 % 5 == 0)// && i <= size - 4)NOT WORK
		{
			
			cout << "1.Sledvashta stranica\n";
			cout << "2.Kym menu\n";
			int a = 0;
			while(a < 1 || a > 2)
			{
				cin >> a;
			}
			switch(a)
			{
				case 1:break;
				case 2:return;break;
			}
		}
	}
}
void Edit(Imoti imoti[])
{
	cout << "1.Promqna na cena na imot\n";
	cout << "2.Zakupuvane na imot\n";
	int input = 0;
	while(input < 1 || input > 2)
	{
		cin >> input;
	}
	switch(input)
	{
		case 1:EditCena(imoti);break;
		case 2:Zakupuvane(imoti);break;
	}
}
void EditCena(Imoti imoti[])
{
	system("cls");
	cout << "Adres:";
	string adres;
	cin.ignore(10000, '\n');
	getline(cin, adres);
	bool suvpada = false;
	int i;
	for(i = 0;i < size;i++)
	{
		if(adres == imoti[i].street)
		{
			suvpada = true;
			break;
		}
	}
	if(suvpada)
	{
		cout << "Cena:";
		cin >> imoti[i].price;
	}
	else
	{
		cout << "Nqma imot na tozi adres\n";
		system("pause");
	}
}
void Zakupuvane(Imoti imoti[])
{
	system("cls");
	cout << "Adres:";
	string adres;
	cin.ignore(10000, '\n');
	getline(cin, adres);
	int i;
	for(i = 0;i < size;i++)
	{
		if(adres == imoti[i].street)
		{
			size--;
			cout << "Iztrit";
			system("pause");
			return;
		}
	}
	cout << "Nqma imot na tozi adres";
}
void Search(Imoti imoti[])
{
	int input = 0;
	cout << "1.Blizki imoti\n";
	cout << "2.Imoti po kvartal\n";
	while(input < 1 || input > 2)
	{
		cin >> input;
	}
	switch(input)
	{
		case 1:Close(imoti);break;
		case 2:Kvartal(imoti);break;
	}
	system("pause");
}
void Close(Imoti imoti[])
{
	system("cls");
	cout << "Kvartali:\n";
	cout << "1.Mladost\n";
	cout << "2.Chaika\n";
	cout << "3.Levski\n";
	cout << "4.Centur\n";
	cout << "5.Grucki\n";
	cout << "izberi kvartal:";
	int input = 0;
	while(input < 1 || input > 5)
	{
		cin >> input;
	}
	switch(input)
	{
		case 1:
			{
				for(int i = 0;i < size;i++)
				{
					if(imoti[i].kvartal == "Mladost" || imoti[i].kvartal == "Grucki" || imoti[i].kvartal == "Centur")
					{
						cout << "\nKvartal:" << imoti[i].kvartal;
						cout << "\nUlica:" << imoti[i].street;
						cout << "\nPlosht:" << imoti[i].area;
						cout << "\nCena:" << imoti[i].price;
						cout << "\nstai:" << imoti[i].stai;
						cout << endl;
					}
				}
				break;
			}
		case 2:
			{
				for(int i = 0;i < size;i++)
				{
					if(imoti[i].kvartal == "Chaika" || imoti[i].kvartal == "Levski" || imoti[i].kvartal == "Centur")
					{
						cout << "\nKvartal:" << imoti[i].kvartal;
						cout << "\nUlica:" << imoti[i].street;
						cout << "\nPlosht:" << imoti[i].area;
						cout << "\nCena:" << imoti[i].price;
						cout << "\nstai:" << imoti[i].stai;
						cout << endl;
					}
				}
			break;
			}
		case 3:
			{
				for(int i = 0;i < size;i++)
				{
					if(imoti[i].kvartal == "Levski" || imoti[i].kvartal == "Chaika" || imoti[i].kvartal == "Centur")
					{
						cout << "\nKvartal:" << imoti[i].kvartal;
						cout << "\nUlica:" << imoti[i].street;
						cout << "\nPlosht:" << imoti[i].area;
						cout << "\nCena:" << imoti[i].price;
						cout << "\nstai:" << imoti[i].stai;
						cout << endl;
					}
				}
			break;
			}
		case 4:
			{
				for(int i = 0; i < size; i++)
				{
					cout << "\nKvartal:" << imoti[i].kvartal;
					cout << "\nUlica:" << imoti[i].street;
					cout << "\nPlosht:" << imoti[i].area;
					cout << "\nCena:" << imoti[i].price;
					cout << "\nstai:" << imoti[i].stai;
					cout << endl;
				}
				break;	
			}
		case 5:
			{
				for(int i = 0;i < size;i++)
				{
					if(imoti[i].kvartal == "Mladost" || imoti[i].kvartal == "Grucki" || imoti[i].kvartal == "Centur")
					{
						cout << "\nKvartal:" << imoti[i].kvartal;
						cout << "\nUlica:" << imoti[i].street;
						cout << "\nPlosht:" << imoti[i].area;
						cout << "\nCena:" << imoti[i].price;
						cout << "\nstai:" << imoti[i].stai;
						cout << endl;
					}
			}
			break;
			}
	}
}
void Kvartal(Imoti imoti[])
{
	system("cls");
	cout << "Kvartali:\n";
	cout << "1.Mladost\n";
	cout << "2.Chaika\n";
	cout << "3.Levski\n";
	cout << "4.Centur\n";
	cout << "5.Grucki\n";
	cout << "izberi kvartal:";
	int input = 0;
	while(input < 1 || input > 5)
	{
		cin >> input;
	}
	switch(input)
	{
		case 1:
			{
				for(int i = 0;i < size;i++)
				{
					if(imoti[i].kvartal == "Mladost")
					{
						cout << "\nKvartal:" << imoti[i].kvartal;
						cout << "\nUlica:" << imoti[i].street;
						cout << "\nPlosht:" << imoti[i].area;
						cout << "\nCena:" << imoti[i].price;
						cout << "\nstai:" << imoti[i].stai;
						cout << endl;
					}
				}
				break;
			}
		case 2:
			{
				for(int i = 0;i < size;i++)
				{
					if(imoti[i].kvartal == "Chaika")
					{
						cout << "\nKvartal:" << imoti[i].kvartal;
						cout << "\nUlica:" << imoti[i].street;
						cout << "\nPlosht:" << imoti[i].area;
						cout << "\nCena:" << imoti[i].price;
						cout << "\nstai:" << imoti[i].stai;
						cout << endl;
					}
				}
			break;
			}
		case 3:
			{
				for(int i = 0;i < size;i++)
				{
					if(imoti[i].kvartal == "Levski")
					{
						cout << "\nKvartal:" << imoti[i].kvartal;
						cout << "\nUlica:" << imoti[i].street;
						cout << "\nPlosht:" << imoti[i].area;
						cout << "\nCena:" << imoti[i].price;
						cout << "\nstai:" << imoti[i].stai;
						cout << endl;
					}
				}
			break;
			}
		case 4:
			{
				for(int i = 0; i < size; i++)
				{
					if(imoti[i].kvartal == "Centur")
					{
						cout << "\nKvartal:" << imoti[i].kvartal;
						cout << "\nUlica:" << imoti[i].street;
						cout << "\nPlosht:" << imoti[i].area;
						cout << "\nCena:" << imoti[i].price;
						cout << "\nstai:" << imoti[i].stai;
						cout << endl;
					}
				}
				break;	
			}
		case 5:
			{
				for(int i = 0;i < size;i++)
				{
					if(imoti[i].kvartal == "Grucki")
					{
						cout << "\nKvartal:" << imoti[i].kvartal;
						cout << "\nUlica:" << imoti[i].street;
						cout << "\nPlosht:" << imoti[i].area;
						cout << "\nCena:" << imoti[i].price;
						cout << "\nstai:" << imoti[i].stai;
						cout << endl;
					}
			}
			break;
			}
	}
}
void Spravki(Imoti imoti[])
{
	int input = 0;
	cout << "1.Podrezdane\n";
	cout << "2.Imot s nai-golqma kvadratura\n";
	cout << "3.Nai evtin imot po cena za kvadrat\n";
	while(input < 1 || input > 3)
	{
		cin >> input;
	}
	switch(input)
	{
		case 1:Podrezdane(imoti);break;
		case 2:MaxArea(imoti);break;
		case 3:MinPrice(imoti);break;
	}
}
void Podrezdane(Imoti imoti[])
{
	int input = 0;
	cout << "1.Po cena\n";
	cout << "2.Po stai\n";
	while(input < 1 || input > 2)
	{
		cin >> input;
	}
	switch(input)
	{
		case 1:ByPrice(imoti);break;
		case 2:ByRooms(imoti);break;
	}
	system("pause");
}
void ByPrice(Imoti imoti[])
{
	Imoti a[size];
	Imoti sw;
	for(int i = 0;i < size;i++)
	{
		a[i] = imoti[i];
	}
	for (int i = 0;i < size-1;i++) 
	{
		for (int j = 0;j < size-i-1;j++) 
     	{ 
	        if (a[j].price > a[j+1].price) 
			{
				sw = a[j];
				a[j] = a[j+1];
				a[j+1] = sw;
				//swap(&a[j], &a[j+1]);
			}
	    }
	}
	Show(a);
}
void ByRooms(Imoti imoti[])
{
	Imoti a[size];
	Imoti sw;
	for(int i = 0;i < size;i++)
	{
		a[i] = imoti[i];
	}
	
	for (int i = 0;i < size-1;i++) 
	{
		for (int j = 0;j < size-i-1;j++) 
     	{ 
	        if (a[j].stai > a[j+1].stai) 
			{
				sw = a[j];
				a[j] = a[j+1];
				a[j+1] = sw;
				//swap(&a[j], &a[j+1]);
			}
	    }
	}
	Show(a);
}
void MaxArea(Imoti imoti[])
{
	double max = imoti[0].area;
	int a = 0;
	for(int i = 1;i < size;i++)
	{
		if(imoti[i].area > max)
		{
			max = imoti[i].area;
			a = i;
		}
	}
		cout << "\nKvartal:" << imoti[a].kvartal;
		cout << "\nUlica:" << imoti[a].street;
		cout << "\nPlosht:" << imoti[a].area;
		cout << "\nCena:" << imoti[a].price;
		cout << "\nstai:" << imoti[a].stai;
		cout << endl;
		system("pause");
}
void MinPrice(Imoti imoti[])
{
	double min_kvadrat = imoti[0].price / imoti[0].area;
	int a = 0;
	for(int i = 0;i < size;i++)
	{
		if(imoti[i].price / imoti[i].area > min_kvadrat)
		{
			min_kvadrat = imoti[i].price / imoti[i].area;
			a = i;
		}
	}
		cout << "\nKvartal:" << imoti[a].kvartal;
		cout << "\nUlica:" << imoti[a].street;
		cout << "\nPlosht:" << imoti[a].area;
		cout << "\nCena:" << imoti[a].price;
		cout << "\nstai:" << imoti[a].stai;
		cout << endl;
		system("pause");
}
void fileOut(Imoti imoti[])
{
	ofstream fout;
	fout.open("save.txt", ios::out);
	for(int i = 0; i < size; i++)
	{
		fout << imoti[i].kvartal << endl;
		fout << imoti[i].street << endl;
		fout << imoti[i].area << endl;
		fout << imoti[i].price << endl;
		fout << imoti[i].stai << endl;
	}
	fout.close();
}
void fileIn(Imoti imoti[])
{
	ifstream fin;
	fin.open("save.txt", ios::in);
	string a;
	while(getline(fin, a))
	{
		imoti[size].kvartal = a;
		getline(fin, a);
		imoti[size].street = a;
		getline(fin, a);
		imoti[size].area = stoi(a);
		getline(fin, a);
		imoti[size].price = stoi(a);
		getline(fin, a);
		imoti[size].stai = stoi(a);
		size++;
	}
	fin.close();
}
