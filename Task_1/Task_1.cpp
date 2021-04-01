#include <iostream>
#define POINTS 10

using namespace std;

/*СИСТЕМА НАБЛЮДЕНИЯ. В массиве хранятся значения высот профиля местности
с постоянным шагом по горизонтали. Найдите области (точки высот),
невидимые для наблюдателя, находящегося в первой точке.*/

void arrayEnter(double array[]);
double enterStep(double number, int step);
void systemSurveillance(double array[]);
bool isDetectionHighPoint(double max, double value, double first, int step, int stepMax);
int checkingInvisibleAreas(bool isCheak, double value, int step);
bool isVisibilityFromAbove(double max, double value, double first, int step, int stepMax);
void printPoints(int step, double value);
double meaningMax(double max, double value);
int stepMaximum(double max, double value, int stepMax, int step);
void noInvisibleDots(int points);

int main()
{
	double array[POINTS];

	arrayEnter(array);

	systemSurveillance(array);

	return 0;
}

void arrayEnter(double array[])
{
	double number = 0;

	for (int step = 0; step < POINTS; step++)
	{
		array[step] = enterStep(number, step);
	}
}

double enterStep(double number, int step)
{
	cout << "Enter the height of the plain at point " << step + 1 << ": ";
	cin >> number;

	return number;
}


void systemSurveillance(double array[])
{
	int invisiblePoints = 0, stepMax = 1;
	double max = array[1];

	cout << "Invisible points: " << endl;

	for (int step = 2; step < POINTS; step++)
	{
		invisiblePoints += checkingInvisibleAreas(isDetectionHighPoint(max, array[step], array[0], step, stepMax), array[step], step);

		stepMax = stepMaximum(max, array[step], stepMax, step);

		max = meaningMax(max, array[step]);
	}

	noInvisibleDots(invisiblePoints);
}

bool isDetectionHighPoint(double max, double value, double first, int step, int stepMax)
{
	if (first >= value and first > max)
	{
		return isVisibilityFromAbove(max, value, first, step, stepMax);
	}
/*  else if (max == value and max == first) // Если принять, что наблюдатель стоя на первой точке имеет свою высоту
	{
		return false;
	}*/
	else if (max < value)
	{
		return false;
	}
	else return true;
}

bool isVisibilityFromAbove(double max, double value, double first, int step, int stepMax)
{
	if (stepMax / abs(first - max) >= step / abs(first - value)) // знак > если принять, что наблюдатель стоя на первой точке имеет свою высоту
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

int stepMaximum(double max, double value, int stepMax, int step)
{
	if (max > value)
	{
		return stepMax;
	}
	else return step;
}

void noInvisibleDots(int points)
{
	if (points == 0)
	{
		cout << "there are no such things in the array" << endl;
	}
	else {}
}