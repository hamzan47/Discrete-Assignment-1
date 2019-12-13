#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	fstream data("Data Sheet.txt", ios::in);
	fstream assignment("Encryption.txt", ios::in);
	fstream assignment1("Encrypted.txt", ios::out);
	string line;
	int key = 0,val,shift;
	char shifts[66];
	for (int i = 0; i < 66; i++)
	{
		if (i == 26)
			shifts[i] = ' ';
		else if (i == 29)
			shifts[i] = '\n';
		else
			data >> shifts[i];	
	}
	cout << "Enter key: ";
	cin >> key;
	while (key <= 0 || key == 66 || key == 132)
	{
		cout << "Invalid Input\nRe-Enter: ";
		cin >> key;
	}
	key = key % 66;
	val=-99;
	while (getline(assignment, line))
	{
		if(val!=-99)
		{
			shift=(29+key) % 66;
			assignment1<<shifts[shift];
		}
		val=0;
		for (int i = 0; i < line.length(); i++)
		{
			for (int j = 0; j < 66; j++)
			{
				if (shifts[j] == line[i])
				{
					j = (j + key) % 66;
					assignment1 << shifts[j];
					break;
				}
			}
		}
//		assignment1 << endl;
	}
	data.close();
	assignment.close();
	assignment1.close();
}
