#include <iostream>
#define N 10

using namespace std;

/*СИСТЕМА НАБЛЮДЕНИЯ. В массиве хранятся значения высот профиля местности
с постоянным шагом по горизонтали. Найдите области (точки высот),
невидимые для наблюдателя, находящегося в первой точке.*/

double arrayEnter(double array[N]);
double enterStep(double number, int step);
void systemSurveillance(double array[N]);
bool isDetectionHighPoint(double max, double first, double value, int step);
int checkingInvisibleAreas(bool isCheak, double value, int step);
void printPoints(int step, double value);
double meaningMax(double max, double value);
void noInvisibleDots(int points);

int main()
{
	double array[N];

	arrayEnter(array);

	systemSurveillance(array);

	return 0;
}

double arrayEnter(double array[N])
{
	double number = 0;

	for (int step = 0; step < N; step++)
	{
		array[step] = enterStep(number, step);
	}

	return array[N];
}

double enterStep(double number, int step)
{
	cout << "Enter the height of the plain at point " << step + 1 << ": ";
	cin >> number;
	return number;
}

void systemSurveillance(double array[N])
{
	int invisiblePoints = 0;
	double max = array[0];

	cout << "Invisible points: ";

	for (int step = 1; step < N; step++)
	{
		invisiblePoints += checkingInvisibleAreas(isDetectionHighPoint(max, array[0], array[step], step), array[step], step);

		max = meaningMax(max, array[step]);
	}

	noInvisibleDots(invisiblePoints);
}

bool isDetectionHighPoint(double max, double first, double value, int step)
{
	if (((max >= value) and (step > 1)) and (max != first))
	{
		return true;
	}
	else return false;
}

int checkingInvisibleAreas(bool isCheak, double value, int step)
{
	if (isCheak)
	{
		printPoints(step, value);

		return 1;
	}
	else return 0;
}

void printPoints(int step, double value)
{
	cout << "At point " << step + 1 << " with a height of " << value << endl;
}

double meaningMax(double max, double value)
{
	if (max > value)
	{
		return max;
	}
	else return value;
}

void noInvisibleDots(int points)
{
	if (points == 0)
	{
		cout << "there are no such things in the array" << endl;
	}
}