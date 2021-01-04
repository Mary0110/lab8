#include <iostream>
#include <cmath>
#include<string>
using namespace std;
struct employer
{
	string full_name = {};
	int service_code = 0 ;  
	int hours_per_month = 0;
	int hourly_rate = 0;
};
int main() {
	int size;	int action;
	void bubble_sort(employer* a, int s);
	void input(employer* a, int s);
	employer* add_employer(employer* data, int s);
	void show(employer* a, int s);
	void salary(employer* a, int s);
	void change_employer(employer* a, int p);
	employer* delete_employer(employer* data, int s, int p);
	void output(employer * data, int s);

	printf("Enter the number of employees: ");
	scanf_s("%d", &size);
	employer* data = new employer[size];
	input(data, size);
	do {
		printf("To show data enter 1, add - 2, to find information by service code - 3, delete - 4, change - 5, sort - 6, salary - 7, exit - 0\n");
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
			data = add_employer(data, size);
			size++;
		}
		else if (action == 3)
		{
			output(data, size);
		}
		else if (action == 4) 
		{
			int delete1;
			int pointer = 0;
			printf("Enter the service number of employer you want to delete from database: ");
			scanf_s("%d", &delete1);
			for (int i = 0; i < size; i++)
			{
				if (data[i].service_code == delete1)
				{
					pointer = i;
				}
					data = delete_employer(data, size, pointer);
					size--;
			}
		}
		else if (action == 5)
		{
			int change;
			printf("Enter the service number of employer you want to change in database: ");
			cin >> change;
			int pointer = 0;
			for (int i = 0; i < size; i++) 
			{
				if (data[i].service_code == change)
				{
					pointer = i;
				}
			}
			change_employer(data, pointer);
		}
		else if (action == 6)
		{
			bubble_sort(data, size);
			printf("employees are sorted by service code\n");
		}
		else if (action == 7) 
		{
			salary(data, size);
		}
	} while (action != 0);
}
void output(employer* a, int size)
{
	int outp;
	printf("enter servise code: ");
	cin >> outp;
	for (int i = 0; i < size; i++)
	{
		if (a[i].service_code == outp) 
		{
			printf("Service code: %d\n", a[i].service_code);
			cout<<"Full name:"<< a[i].full_name<<endl;
			printf("Hours per month: %d\n", a[i].hours_per_month);
			printf("Hourly rate: %d\n", a[i].hourly_rate);
			break;
		}
	}
	
}
void bubble_sort(employer* a, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (a[j].service_code > a[j + 1].service_code)
			{
				swap(a[j], a[j + 1]);
			}
		}
	}
}void input(employer* a, int size)
{
	for (int i = 0; i < size; i++) 
	{
		cout << endl;
		printf("Full name: ");
		cin >> a[i].full_name;
		printf("Service code: ");
		cin >> a[i].service_code;
		printf("Hours per month: ");
		cin >> a[i].hours_per_month;
		printf("Hourly rate: ");
		cin >> a[i].hourly_rate;
		cout << endl;
	}
}

employer* add_employer(employer* data, int size)
{
	employer* newdata = new employer[size + 1];
	for (int i = 0; i < size; i++) 
	{
		newdata[i] = data[i];
	}
	printf("\nFull name: ");
	cin >> newdata[size].full_name;
	printf("Service code: ");
	cin >> newdata[size].service_code;
	printf("Hours per month: ");
	cin >> newdata[size].hours_per_month;
	printf("Hourly rate: ");
	cin >> newdata[size].hourly_rate;
	cout << endl;
	return newdata;
}

void show(employer* a, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << endl;
		printf("Full name: ");
		cout << a[i].full_name;
		printf("Service code: ");
		cout << a[i].service_code;
		printf("Hours per month: ");
		cout << a[i].hours_per_month;
		printf("Hourly rate: ");
		cout << a[i].hourly_rate;
		cout << endl;
	}
}

void salary(employer* a, int size) 
{
	int serv_num;
	printf("enter service code");
	scanf_s("%d", &serv_num);
	for (int i = 0; i < size; i++)
	{
		int salary = 0;
		if (a[i].service_code == serv_num) 
		{
			salary += a[i].hours_per_month * a[i].hourly_rate;
			printf("Salary: %d\n", salary);
			break;
		}
	}
}

void change_employer(employer* a, int p)
{
	cout << endl;
	printf("Full name: ");
	cin >> a[p].full_name;
	printf("Service code: ");
	cin >> a[p].service_code;
	printf("Hours per month: ");
	cin >> a[p].hours_per_month;
	printf("Hourly rate: ");
	cin >> a[p].hourly_rate;
	cout << endl;
}

employer* delete_employer(employer* data, int size, int p) 
{
	employer* data2 = new employer[size - 1];
	for (int i = 0; i < p; i++) {
		data2[i] = data[i];
	}
	for (int i = p; i < size - 1; i++) {
		data2[i] = data[i + 1];
	}
	return data2;
}
