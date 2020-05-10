#include "Functions.h"
#include <iostream>

int main()
{
	while (true)
	{
		NodeList list;

		system("cls");
		list.AddTheStruct();
		list.size++;

		while (true)
		{
			bool exit = false;

			int answ = menu();

			switch (answ)
			{
			case 0:
				list.AddTheStruct();
				list.size++;
				break;
			case 1:
				exit = true;
				break;
			default:
				break;
			}

			if (exit == true)
			{
				break;
			}
		}
		
		//list.SwapAndPow();

		//cout << endl;

		//list.Print();

		cout << endl;

		long long Num = Number(list);
		int div = 0;

		while (true)
		{
			system("cls");
			list.Print();
			cout << endl;

			cout << "Write the number to divide on" << endl;

			cin >> div;
			if (cin.fail())
			{
				flush();
				continue;
			}
			if (div <= 0)
			{
				cout << "Only positive integer !" << endl;
				system("pause");
				continue;
			}
			break;
		}

		int rest = Num % div;

		cout << "The rest is " << rest;
	
		//PrintTheRest(list);

		cout << endl << endl;

		system("pause");
	}
	
}

