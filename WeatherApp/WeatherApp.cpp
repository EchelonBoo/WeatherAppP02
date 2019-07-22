// P02.cpp : Defines the entry point for the console application.
//
#include <fstream> 


#include <iostream>
using namespace std;

struct date {

	int day;
	int month;
	int year;
};

struct records {
	date date;
	string name;
	double sun;
	double rain;
	double temp;
};

void name(records weather[30]);
void rainy(records weather[30]);
void sunny(records weather[30]);
void average(records weather[30]);
void hottest(records weather[30]);
void shortSun(records weather[30]);


int main()
{

	int option;

	records weather[30];

	ifstream infile("data.dat");

	for (int i = 0; i < 30; i++) {

		infile >> weather[i].date.day;
		infile >> weather[i].date.month;
		infile >> weather[i].date.year;
		infile >> weather[i].name;
		infile >> weather[i].sun;
		infile >> weather[i].rain;
		infile >> weather[i].temp;
	}

	option = 1;

	while (option != 7) {
		cout << "\n\t\t\t****** Weather App******\n";
		cout << "\n\t1. List the dates when a given meteorologist was on duty." << endl
			<< "\t2. Find all the wet days (i.e. rainfall >= 4mm). " << endl
			<< "\t3. Find all the sunny days (i.e. sun hours >= 5 hours). " << endl
			<< "\t4. Find the average rainfall between two dates." << endl
			<< "\t5. Find the hottest day based on the midday temperature. " << endl
			<< "\t6. Find the day with the shortest sunshine. " << endl
			<< "\t7. Exit from the application" << endl << endl;
		cout << "\n\n";
		cin >> option;
		switch (option) {

		case 1:
			name(weather);
			break;

		case 2:
			rainy(weather);
			break;

		case 3:
			sunny(weather);
			break;

		case 4:
			average(weather);
			break;

		case 5:
			hottest(weather);
			break;

		case 6:
			shortSun(weather);
			break;

		case 7:
			break;

		default:
			cout << "Invalid option" << endl;
		}
	}
	return 0;
}

void name(records weather[30]) {

	cout << "Please input a name to search" << endl;
	string name;
	cin >> name;

	for (int i = 0; i < 30; i++) {
		if (weather[i].name == name) {
			cout << weather[i].date.day << " " << weather[i].date.month << " " << weather[i].date.year << endl;
		}

	}
}
void rainy(records weather[30]) {
	for (int i = 0; i < 30; i++) {
		if (weather[i].rain <= 4) {
			cout << weather[i].date.day << " " << weather[i].date.month << " " << weather[i].date.year << endl;
		}
	}
}
void sunny(records weather[30]) {
	for (int i = 0; i < 30; i++) {
		if (weather[i].rain <= 5) {
			cout << weather[i].date.day << " " << weather[i].date.month << " " << weather[i].date.year << endl;
		}
	}
}
void average(records weather[30]) {

	double option1, option2, temp, total;
	total = 0;
	cout << "enter 1st date" << endl;
	cin >> option1;

	cout << "enter 2nd date" << endl;
	cin >> option2;

	option1 -= 1;
	option2 -= 1;


	if (option1 > option2) {
		temp = option1;
		option1 = option2;
		option2 = temp;
	}

	for (int i = option1; i < option2 + 1; i++) {

		total += weather[i].rain;
	}

	cout << total / ((option2 - option1) + 1);
}
void hottest(records weather[30]) {

	double largest = 0;
	largest = weather[0].temp;

	for (int i = 0; i < 30; i++) {

		if (weather[i].temp > largest) {
			weather[i].temp = largest;
			cout << weather[i].date.day << " " << weather[i].date.month << " " << weather[i].date.year << endl;
		}
	}
}
void shortSun(records weather[30]) {
	double smallest = 0;
	smallest = weather[0].sun;

	for (int i = 0; i < 30; i++) {
		if (weather[i].sun < smallest) {
			weather[i].sun = smallest;
			cout << weather[i].date.day << " " << weather[i].date.month << " " << weather[i].date.year << endl;
		}
	}
}