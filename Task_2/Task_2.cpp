#include <iostream>
#define ROOKIE 10

using namespace std;

/*НОВОБРАНЦЫ. Новобранцы выстроены в шеренгу. По команде НАЛЕ–ВО!
одни из них поворачиваются налево, а другие – направо. 
Это есть начальное положение шеренги. 
Далее каждый новобранец действует следующим образом:
увидев перед собой лицо соседа, он ровно через секунду поворачивается кругом.
В конце концов повороты прекратятся.Тогда сержант подает звуковой сигнал.*/

void rankEnter(char array[]);
char enterStep(char number, int step);
void turnsRank(char array[]);
void rankCout(char array[]);
int partingRookies(char array[], int rookies);
int secondCout(int second);

int main()
{
	char line[ROOKIE];

	rankEnter(line);

	turnsRank(line);

	return 0;
}


void rankEnter(char array[])
{
	char number = 0;

	for (int rookie = 0; rookie < ROOKIE; rookie++)
	{
		array[rookie] = enterStep(number, rookie);
	}
}

char enterStep(char number, int rookie)
{
	while (true) {
		cout << "Specify the turn of " << rookie + 1 << " recruit in the line (< or >): ";
		cin >> number;

		if (number == '>' or number == '<') {
			break;
		} 
		else {
			cin.clear();
			while (cin.get() != '\n');
		}
	}

	return number;
}


void turnsRank(char array[])
{
	int second = 1;

	cout << "Starting position of the line: ";

	while (true)
	{
		int rookies = 1;

		rankCout(array);

		rookies = partingRookies(array, rookies);

		if (rookies == ROOKIE)
		{
			cout << "Signal!" << endl;
			break;
		}

		second = secondCout(second);
	}
}

void rankCout(char array[])
{
	for (int rookie = 0; rookie < ROOKIE; rookie++)
	{
		cout << array[rookie] << " ";
	}
	cout << endl;
}

int partingRookies(char array[], int rookies)
{
	for (int rookie = 1; rookie < ROOKIE; rookie++)
	{
		if ((array[rookie - 1] == '>') and (array[rookie] == '<'))
		{
			array[rookie - 1] = '<';
			array[rookie] = '>';
			rookie++;
		}
		else
		{
			rookies++;
		}
	}

	return rookies;
}

int secondCout(int second)
{
	cout << "After " << second << " second: ";

	return second + 1;
}