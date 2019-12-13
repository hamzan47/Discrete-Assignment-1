#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main()
{
	fstream data("Data Sheet.txt", ios::in);
	fstream assignment("Encrypted.txt", ios::in);
	fstream assignment1("Decrypted.txt", ios::out);
	string line,check = "Discrete";
	int key=0,val,shifter;
	bool found = false;
	char shifts[66],temp;
	for (int i = 0; i < 66; i++)
	{
		if (i == 26)
			shifts[i] = ' ';
		else if (i == 29)
			shifts[i] = '\n';
		else
			data >> shifts[i];	
	}
	getline(assignment, line);
	for (val = 0; val < 66; val++)
	{
		if (shifts[val] == line[0])
			break;
	}
	key = val - 3;
	assignment.seekg(ios::beg);
	val=-99;
	while (getline(assignment, line))
	{
		if(val!=-99)
			{
				val=29-key;
				if(val < 0)
					val=val+66;
				assignment1 << shifts[val];	
			}	
		for (int i = 0; i < line.length(); i++)
		{
			for (val = 0; val < 66; val++)
			{
				if (line[i] == shifts[val])
				{
					val = (val - key)%66;
					if (val < 0)
						val = val + 66;
					assignment1 << shifts[val];	
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
