/*
Sanket Ganesh Jhavar
Roll no.:21138
SE-1     F-1  Batch
*/
#include <iostream>
using namespace std;

class Hashing
{
	long int phone_number;
	string name;

public:
	Hashing()
	{
		phone_number = 0;
		name = " ";
	}
	Hashing(long int phone_number, string name)
	{
		this->phone_number = phone_number;
		this->name = name;
	}
	friend class HashTable;
};

class HashTable
{
	Hashing table[100];

public:
	int Hash_Function(long int key)
	{
		return (key % 100);
	}
	void insertWithReplacement(long int number, string name)
	{
		int i = Hash_Function(number);
		if (number == table[i].phone_number)
		{
			cout<<"Please enter unique number"<<endl<<endl;
		}

		if (table[i].phone_number == 0)
		{
			table[i].phone_number = number;

			table[i].name = name;
		}
		else
		{
			if (i == table[i].phone_number % 100)
			{
				i++;
				i = i % 100;
				while (i <= 100 && table[i].phone_number != 0)
				{
					i++;
				}
				table[i].phone_number = number;
				table[i].name = name;
			}
			else
			{
				int number_temp = table[i].phone_number;
				string temp_name = table[i].name;
				table[i].phone_number = number;
				table[i].name = name;
				i++;
				i = i % 100;
				while (i <= 100 && table[i].phone_number != 0)
				{
					i++;
				}
				table[i].phone_number = number_temp;
				table[i].name = temp_name;
			}
		}
	}
	void insertwithoutReplacement(long int key, string name)
	{
		int index = Hash_Function(key);

		if (key == table[index].phone_number)
		{
			cout<<"Please enter unique number"<<endl;
		}

		if (table[index].phone_number == 0)
		{
			table[index].phone_number = key;

			table[index].name = name;
		}
		else
		{
			int i = index;
			while (i <= 100 && table[i].phone_number != 0)
			{
				i++;
			}
			table[i].phone_number = key;
			table[i].name = name;
		}
	}
	void searching(long int key)
	{
		int index = key % 100;
		int count = 1;
		if (key == table[index].phone_number)
		{
			cout << "Record found" << endl;
			cout << "Number of comparisons: " << count << endl;
			cout << "Name: " << table[index].name << endl;
			cout << "Telephone number: " << table[index].phone_number << endl<<endl;
		}
		else
		{
			index++;
			index = index % 100;
			while (index <= 100 && table[index].phone_number != key)
			{
				count++;
				index++;
			}
			if (index < 100)
			{
				cout << "Record found" << endl;
				cout << "Number of comparisons: " << count << endl;
				cout << "Name: " << table[index].name << endl;
				cout << "Telephone number: " << table[index].phone_number << endl<<endl;
			}
			else
			{
				cout << "Record not found" << endl<<endl;
			}
		}
	}
	void display()
	{
		cout<<"Telephone record!!!!!!!!"<<endl<<endl;
		for(int i=0;i<100;i++)
		{
			if(table[i].phone_number)
			{
				cout<<"index: "<<i<<endl;
				cout<<"Telephone number: "<<table[i].phone_number<<endl;
				cout<<"Name: "<<table[i].name<<endl;
			}
		}
		cout<<"--------------------------------------"<<endl;
	}
};

int main()
{
	HashTable wor;
	HashTable wr;
	int entries = 0;
	long int telephone_number;
	string name;

	while (true)
	{
		cout << "1. Create Entry" << endl;
		cout << "2. Search Entry" << endl;
		cout << "3. Display Entry" << endl;
		cout << "4. Exit" << endl;

		int choice;
		cout << "Enter your choice: ";
		cin >> choice;

		if (choice == 1)
		{
			entries++;
			if (entries > 100)
			{
				cout << "You can create only 100 entries";
				continue;
			}
			cout << "Enter your Telephone number: ";
			cin >> telephone_number;
			
			cout << "Enter your name: ";
			cin >> name;

			cout << "Insertion with replacement done!!!!!!!" << endl<<endl;
			wr.insertWithReplacement(telephone_number, name);

			cout << "Insertion without replacement done!!!!!!" << endl<<endl;
			wor.insertwithoutReplacement(telephone_number, name);
		}
		else if (choice == 2)
		{
			if (entries == 0)
			{
				cout << "Entries not created yet" << endl<<endl;
				continue;
			}
			cout << "Enter the telephone number to be searched: ";
			cin >> telephone_number;

			cout << "Linear probing with replacement" << endl<<endl;
			wr.searching(telephone_number);

			cout << "Linear probing without replacement" << endl<<endl;
			wor.searching(telephone_number);
		}
		else if(choice == 3)
		{
			if (entries == 0)
			{
				cout << "Entries not created yet" << endl<<endl;
				continue;
			}
			cout<<"Entries with replacement!!!!!"<<endl<<endl;
			wr.display();
			cout<<"Entries without replacement!!!!!"<<endl<<endl;
			wor.display();
		}
		else
		{
			break;
		}
	}
	return 0;
}
