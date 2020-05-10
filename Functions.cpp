#include "Functions.h"



void flush()
{
	cin.clear();
	while (cin.get() != '\n');
}



void NodeList::push_back(int num, int power)
{
	if (head == NULL)
	{
		head = new Node;

		head->number = num;
		head->pow = power;

		head->next = NULL;
	}
	else
	{
		//Node* tail = head;
		
		if (head->pow >= power)
		{
			Node* temp = new Node;
			temp->number = num;
			temp->pow = power;

			temp->next = head;
			head = temp;
		}
		else
		{
			Node* temp = head;
			while (true)
			{
				if (temp->next == NULL)
				{
					temp->next = new Node;
					temp->next->number = num;
					temp->next->pow = power;
					temp->next->next = NULL;
					break;
				}
				else if (temp->next->pow >= power)
				{
					Node* ttemp = new Node;
					ttemp->number = num;
					ttemp->pow = power;

					ttemp->next = temp->next;
					temp->next = ttemp;
					break;
				}
				else
				{
					temp = temp->next;
				}
			}
		}

		/*while (tail->next != NULL)
		{
			tail = tail->next;
		}

		tail->next = new Node;
		tail = tail->next;

		tail->number = num;
		tail->pow = power;

		tail->next = NULL;*/
	}
}




void NodeList::Print()
{
	Node* show = head;

	if (show == NULL)
	{
		cout << "List is empty" << endl;
	}

	while (show)
	{
		if (show->next == NULL)
		{
			cout << show->number << " * (10 ^ " << show->pow << ")";
		}
		else
		{
			cout << show->number << " * (10 ^ " << show->pow << ") + ";
		}
		show = show->next;
	}
	cout << endl;
}




/*void NodeList::SwapAndPow()
{
	NodeList templist;

	Node* a = head;

	while (a != NULL)
	{
		templist.push_back(a->number, a->pow);
		a = a->next;
	}

	int tempsize = size, tpow = 0;

	a = head;

	while (a != NULL)
	{
		Node* b = templist.head;

		for (int i = 0; i < tempsize - 1; i++)
		{
			b = b->next;
		}

		a->number = b->number;
		a->pow = tpow;

		tempsize--;
		tpow++;
		a = a->next;
	}
}



void PrintTheRest(NodeList a)
{
	int* arr = new int[a.size];

	Node* point = a.head;

	arr[a.size - 1] = a.head->number;
	point = a.head->next;

	for (int i = a.size - 2; i >= 0; i--)
	{
		arr[i] = point->number;
		point = point->next;
	}

	cout << endl;

	bool exit = false;
	
	for (int i = a.size - 1; ; )
	{
		for (int j = 0; j < a.size; j++)
		{
			if (arr[j] == 0 || arr[j] == -1)
			{
				arr[j] = -1;

			}
			else
			{
				exit = false;
				break;
			}
			exit = true;
		}
		if (exit == true)
		{
			break;
		}
		if (arr[i] != 0)
		{
			arr[i]--;

			for (int j = 0; j < a.size; j++)
			{
				if (arr[j] != -1) 
					cout << arr[j];
			}
			cout << endl;
		}
		else
		{
			for (int j = a.size - 2; j >= 0; j--)
			{
				if (arr[j] != -1)
				{
					if (arr[j] != 0)
					{
						arr[j]--;
						break;
					}
					else
					{
						arr[j] = 9; 
					}
				}
			}
			arr[i] = 9;

			for (int j = 0; j < a.size; j++)
			{
				if (arr[j] == 0 || arr[j] == -1)
				{
					arr[j] = -1;
				}
				else
				{
					break;
				}
			}

			for (int j = 0; j < a.size; j++)
			{
				if (arr[j] != -1)
					cout << arr[j];
			}
			cout << endl;
		}
	}
}*/


void NodeList::AddTheStruct()
{
	while (true)
	{
		system("cls");
		cout << "Write the multiplier (From 1 up to 9)" << endl;

		int num = 0;
		bool cont = true;

		cin >> num;

		if (cin.fail())
		{
			cout << "Incorrect input" << endl;
			flush();
			system("pause");
			continue;
		}
		flush();

		if (num < 1 || num > 9)
		{
			cout << "It cannot be a multiplier" << endl;
			system("pause");
			continue;
		}

		int power = 0;

		while (true)
		{
			system("cls");

			cout << "Write the power (Up to 18)" << endl;

			cout << num << " * " << "10 ^ ";

			cin >> power;

			if (cin.fail())
			{
				cout << "Incorrect input" << endl;
				flush();
				continue;
			}
			flush();

			if (power < 0)
			{
				cout << "Power cannot be a negative" << endl;
				continue;
			}
			if (power > 18)
			{
				cout << "Too large power" << endl;
				continue;
			}

			if (head != NULL)
			{
				Node* a = head;
				if (head->pow == power)
				{
					cout << "A structure with such power is already exist" << endl;
					system("pause");
					continue;

				}

				a = a->next;
				bool ex = false;

				while (a != NULL)
				{
					if (a->pow == power)
					{
						cout << "A structure with such power is already exist" << endl;
						system("pause");
						ex = true;
						break;
					}
					a = a->next;
				}

				if (ex == true)
				{
					continue;
				}
			}

			break;
		}

		push_back(num, power);

		system("cls");
		cout << num << " * " << "10 ^ " << power << endl;
		system("pause");
		
		break;
	}
}


int menu()
{
	int key = 0;
	int code;

	do {
		system("cls");

		cout << "One more element ?" << endl;

		key = (key + 2) % 2;

		if (key == 0) cout << "-> Yes" << endl;
		else  cout << "   Yes" << endl;
		if (key == 1) cout << "-> No" << endl;
		else  cout << "   No" << endl;

		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}

	} while (code != 13);
	system("cls");
	return key;
}


long long Number(NodeList a)
{
	long long b = 0;

	Node* temp = a.head;

	b += temp->number * (long long)pow(10, temp->pow);

	temp = temp->next;
	while (temp != NULL)
	{
		b += temp->number * (long long)pow(10, temp->pow);
		temp = temp->next;
	}

	return b;
}