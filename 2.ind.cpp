#include <iostream>
#include <fstream>
#include <cmath>
#include<string>
using namespace std;
ofstream result;
ofstream fout;
ifstream fin;

struct pupil
{
	string full_name = {};
	string adress = {};
	string marks = {};
};
int main() 
{
	fout.open("data.txt");
	result.open("result.txt");
	if (!fout)
		cerr << "cannot open file\n";
	if(!result)
		cerr << "cannot open file\n";

	fin.open("result.txt");
	if (!fin.is_open())
		cerr << "cannot open file";
	int size;	int action;
	void bubble_sort(pupil * a, int s);
	void input(pupil * a, int s);
	pupil* add_pupil(pupil * data, int s);
	void show(pupil * a, int s);
	void func(pupil * a, int s);
	void change_pupil(pupil * a, int p);
	pupil* delete_pupil(pupil * data, int s, int p);
	void output(pupil * data, int s);

	printf("Enter the number of pupils: ");
	scanf_s("%d", &size);
	pupil* data = new pupil[size];
	input(data, size);
	do {
		printf("To add pupils enter 2, to show pupils from Minsk with average score > 4.5 enter 7, show results - 8, show whole data - 1, , to find information by full name - 3, delete - 4, change - 5, sort - 6,  exit - 0\n");
		scanf_s("%d", &action);
		if (action == 0)
		{
			break;
		}
		else if (action == 1)
		{
			show(data, size);
		}
		else if (action == 2)
		{
			data = add_pupil(data, size);
			size++;
		}
		else if (action == 3)
		{
			output(data, size);
		}
		else if (action == 4)
		{
			string delete1;
			int pointer = 0;
			printf("Enter full name of pupil you want to delete from database: ");
			cin >> delete1;
			for (int i = 0; i < size; i++)
			{
				if (data[i].full_name == delete1)
				{
					pointer = i;
				}
				data = delete_pupil(data, size, pointer);
				size--;
			}
		}
		else if (action == 5)
		{
			string change;
			printf("Enter the full name of pupil you want to change in database: ");
			cin >> change;
			int pointer = 0;
			for (int i = 0; i < size; i++)
			{
				if (data[i].full_name == change)
				{
					pointer = i;
				}
			}
			change_pupil(data, pointer);
		}
		else if (action == 6)
		{
			bubble_sort(data, size);
			printf("pupils are sorted by full name\n");
		}
		else if (action == 7)
		{
			func(data, size);
		}
		else if (action == 8)
		{
			string str;
			ifstream in("result.txt");
			while (getline(in, str))
				cout << str;
		}

	} while (action != 0);
}
void output(pupil* a, int size)
{
	string outp;
	printf("enter full name: ");
	cin >> outp;
	for (int i = 0; i < size; i++)
	{
		if (a[i].full_name == outp)
		{
			cout<<"full name:"<< a[i].full_name;
			cout<<"adress:"<< a[i].adress;
			cout<<"marks:"<< a[i].marks;
			break;
		}
	}
}
void bubble_sort(pupil* a, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (a[j].full_name[0] > a[j + 1].full_name[0])
			{
				swap(a[j], a[j + 1]);
			}
		}
	}
}
void input(pupil* a, int size)
{
	for (int i = 0; i < size; i++)
	{
		fout << "\n";
		printf("Full name: ");
		cin >> a[i].full_name;
		fout << a[i].full_name<<"\n";
		printf("adress: ");
		cin >>a[i].adress;
		fout << a[i].adress<<"\n";
		printf("3 marks: ");
		cin >> a[i].marks ;
		for (int j = 0; j < 3; j++)
		    fout << a[i].marks[j] << " ";
		fout << "\n";
	}
}
pupil* add_pupil(pupil* data, int size)
{
	pupil* newdata = new pupil[size + 1];
	for (int i = 0; i < size; i++)
	{
		newdata[i] = data[i];
	}
	printf("\nFull name: ");
	cin >> newdata[size].full_name;
	printf("adress: ");
	cin >> newdata[size].adress;
	printf("marks: ");
	     cin >> newdata[size].marks;
	cout << endl;
	return newdata;
}

void show(pupil* a, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << endl;
		printf("Full name: ");
		cout << a[i].full_name << "\n";
		printf("adress: ");
		cout << a[i].adress << "\n";
		printf("marks: ");
		cout << a[i].marks << "\n";
		cout << endl;
	}
}

void func(pupil* a, int size)
{
	for (int i = 0; i < size; i++)
	{
		double average = 0;
		for(int j = 0; j< 3; j++)
		{
			average +=( a[i].marks[j] - '0');
		}
		average /= 3;
		if (average > 4.5 && (a[i].adress == "Minsk" || a[i].adress == "minsk"))
		{
			result<< a[i].full_name<<"\n";
			result<<a[i].adress<<"\n";
			for (int j = 0; j< 3; j++)
			    result << a[i].marks[j];
			result << "\n";
		}
	}
	cout << "added to result.txt\n";
}

void change_pupil(pupil* a, int p)
{
	cout << endl;
	printf("Full name: ");
	cin >> a[p].full_name;
	printf("adress: ");
	cin >> a[p].adress;
	printf("marks: ");
	    cin >> a[p].marks;
	cout << endl;
}

pupil* delete_pupil(pupil* data, int size, int p)
{
	pupil* data2 = new pupil[size - 1];
	for (int i = 0; i < p; i++) 
	{
		data2[i] = data[i];
	}
	for (int i = p; i < size - 1; i++) 
	{
		data2[i] = data[i + 1];
	}
	return data2;
}
