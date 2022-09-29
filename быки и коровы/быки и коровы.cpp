#include <iostream>
#include <stdlib.h>
#include <vector>
#include <cmath> //для команды pow

using namespace std;

int randomize(int n)
{
	vector<int> numbers = { 1,2,3,4,5,6,7,8,9 };
	vector <int> numbers1;

	int decades = pow(10, n - 1);
	int number = 0;
	int rmd = 0;
	int rnd = 10;

	if (n == 1) numbers.push_back(0);

	for (int i = 0; i < n; i++)
	{

		if (i % 2 == 0) numbers1.clear();
		else numbers.clear();

		if (i % 2 == 0) rmd = numbers[rand() % rnd];
		else rmd = numbers1[rand() % rnd];

		number += rmd * decades;
		decades /= 10;

		cout << endl << endl;

		if (n > 1 && i == 0) numbers.push_back(0);

		if (i % 2 == 0)
		{
			for (int i = 0; i < numbers.size(); i++)
			{
				if (numbers[i] != rmd)
					numbers1.push_back(numbers[i]);
			}
		}
		else
		{
			for (int i = 0; i < numbers1.size(); i++)
			{
				if (numbers1[i] != rmd)
					numbers.push_back(numbers1[i]);
			}
		}
		rnd--;
	}

	return number;
}

int main()
{
	setlocale(LC_ALL, "russian");

	int way = 0;

	cout << "1 - Угадываете самостоятельно" << endl;
	cout << "2 - Угадывает компьютер (перебором)" << endl;
	cout << endl << "Введите число (1 или 2): ";

	cin >> way;

	if (way < 1 || way > 2)
	{
		cout << "ERROR: OUT OF RANGE";
		return 0;
	}

	if (way == 1)
	{

		vector <int> numbers_gen;
		vector <int> numbers_input;

		int number_length;
		int number_gen;
		int number_gen_rmd;
		int number_input = 0;
		int number_input_rmd = -1e8;

		cout << "Введите длинну числа (от 1 до 9): ";
		cin >> number_length;
		cout << endl;

		if (number_length < 0 || number_length > 9)
		{
			cout << "ERROR: OUT OF RANGE";
			return 0;
		}

		number_gen = randomize(number_length);
		number_gen_rmd = number_gen;
		cout << number_gen_rmd << endl;

		while (number_gen > 0)
		{
			numbers_gen.push_back(number_gen % 10);
			number_gen /= 10;
		}

		cout << "Попробуйте угадать число (введите число, длинной " << number_length << "): ";
		cin >> number_input;
		number_input_rmd = number_input;
		cout << endl;

		while (number_input > 0)
		{
			numbers_input.push_back(number_input % 10);
			number_input /= 10;
		}

		int bulls = 0;
		int cows = 0;

		for (int i = 0; i < number_length; i++)
			if (numbers_gen[i] == numbers_input[i]) bulls++;

		for (int i = 0; i < number_length; i++)
		{
			for (int a = 0; a < number_length; a++)
				if (numbers_gen[i] == numbers_input[a])
					cows++;
		}

		cout << "Быки: " << bulls << endl;
		cout << "Коровы: " << cows << endl << endl;


		bulls = 0;
		cows = 0;
		numbers_input.clear();

		while (number_gen_rmd != number_input_rmd)
		{
			cout << "Попробуйте ещё раз: ";

			int zxc;
			cin >> zxc;
			number_input_rmd = zxc;

			while (number_input_rmd > 0)
			{
				numbers_input.push_back(number_input_rmd % 10);
				number_input_rmd /= 10;
			}

			if (numbers_input.size() != number_length)
			{
				cout << numbers_input.size() << endl;
				cout << "ERROR: INVALID NUMBER LENGHT" << endl;
				return 0;
			}

			for (int i = 0; i < number_length; i++)
				if (numbers_gen[i] == numbers_input[i]) bulls++;

			for (int i = 0; i < number_length; i++)
			{
				for (int z = 0; z < number_length; z++)
				{
					if (numbers_gen[i] == numbers_input[z])
						cows++;
				}
			}

			cout << "Быки: " << bulls << endl;
			cout << "Коровы: " << cows << endl << endl;

			if (bulls == numbers_gen.size())
				break;

			numbers_input.clear();
			bulls = 0;
			cows = 0;
		}
		cout << "Вы правы";
		cout << endl;
	}

	if (way == 2)
	{
		int number_gen = 0;
		int number_size = 0;
		int R;
		int L;

		cout << "Введите длинну числа: ";
		cin >> number_size;
		number_gen = randomize(number_size);

		L = pow(10, number_size - 1);
		R = pow(10, number_size);

		for (int i = L; i < R; i++)
			if (i == number_gen)
			{
				cout << "Загаданное число: ";
				cout << i;
				break;
			}
	}
	return 0;
}
