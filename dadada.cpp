#include <iostream>
#include <fstream>
using namespace std;

void output(int** a, int n, int m);

void output1(int** a, int n);

void input(int** a, int n);

void life(int** a, int n, int k);

void menu();

void strelki(int** a, int n, int m);

void input1(int** a, int** c, int& n, int& m, int b[], int d[]);

double gaus(double** a, double b[], int n);

int main()
{
	setlocale(LC_ALL, "Russian");
	int i, j, k, n, namber = 1;
	while (namber != 0)
	{
		menu();
		cout << "Задание № ";
		cin >> namber;
		switch (namber) {
		case 1: {
			cout << "Введите размерность квадратной матрицы: ";
			cin >> n;
			cout << "Введите количество поколений: ";
			cin >> k;
			n = n + 2;
			int** a;
			a = new int* [n];
			for (i = 0; i < n; i++)
			{
				a[i] = new int[n];
			}

			input(a, n);
			/*for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					printf("%5d ", a[i][j]);
				}
				cout << endl;
			}
			cout << endl;*/
			cout << "Нулевое поколение: " << endl;
			output1(a, n);
			life(a, n, k);
			delete[] a;
			break;
		}

		case 2:
		{
			int m;
			ifstream F1;
			F1.open("var2.txt", ios::in);
			F1 >> n;
			double** a;
			a = new double* [n];
			for (i = 0; i < n; i++)
			{
				a[i] = new double[n];
			}
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					F1 >> a[i][j];
				}
			}
			double* b = new double[n];
			for (i = 0; i < n; i++)
			{
				F1 >> b[i];
			}
			F1.close();
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					printf("%8f ", a[i][j]);
				}
				cout << endl;
			}
			gaus(a, b, n);
			delete[] a;
			break;
		}

		case 3:
		{
			int m;
			cout << "Количество стрелков: ";
			cin >> n;
			cout << "Количество выстрелов: ";
			cin >> m;
			int** a;
			a = new int* [n];
			for (i = 0; i < n; i++)
			{
				a[i] = new int[m];
			}
			for (i = 0; i < n; i++)
				for (j = 0; j < m; j++)
				{
					a[i][j] = rand() % 11;
				}
			output(a, n, m);
			strelki(a, n, m);
			break;
		}

		case 0:
		{
			cout << "Выход из программы..." << endl;
			return 0;
		}




		}
		//end switch
	}
}

void output(int** a, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%5d ", a[i][j]);
		}
		cout << endl;
	}
	cout << endl;
}

void output1(int** a, int n)
{
	for (int i = 1; i < n - 1; i++)
	{
		for (int j = 1; j < n - 1; j++)
		{
			printf("%5d ", a[i][j]);
		}
		cout << endl;
	}
	cout << endl;
}

void input(int** a, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			a[i][j] = rand() % 2;
		}
	}
	for (j = 0; j < n; j++)
	{
		a[j][0] = 2;
		a[j][n - 1] = 2;
		a[0][j] = 2;
		a[n - 1][j] = 2;
	}
}

void life(int** a, int n, int k)
{
	int y = 0, p = 0;
	for (int c = 0; c < k; c++)
	{
		for (int i = 1; i < n - 1; i++)
		{
			for (int j = 1; j < n - 1; j++)
			{
				y = 0; p = 0;
				if (a[i][j + 1] == 1) y += 1;
				if (a[i][j - 1] == 1) y += 1;
				if (a[i + 1][j] == 1) y += 1;
				if (a[i - 1][j] == 1) y += 1;
				if (a[i + 1][j + 1] == 1) y += 1;
				if (a[i + 1][j - 1] == 1) y += 1;
				if (a[i - 1][j + 1] == 1) y += 1;
				if (a[i - 1][j - 1] == 1) y += 1;
				if (y < 2 && a[i][j] == 1 && p == 0)
				{
					a[i][j] = 0;
					p = 1;
				}
				if (y > 3 && a[i][j] == 1 && p == 0)
				{
					a[i][j] = 0;
					p = 1;
				}
				if ((y == 2 || y == 3) && a[i][j] == 1 && p == 0)
				{
					a[i][j] = 1;
					p = 1;
				}
				if (y == 3 && a[i][j] == 0 && p == 0)
				{
					a[i][j] = 1;
					p = 1;
				}
			}
		}
		cout << c + 1 << "-ое поколение: " << endl;
		output1(a, n);
	}
}

void menu()
{
	cout << "1- Задача 1. «Игра жизнь» " << endl;
	cout << "2- Задача 2. «Решение СЛАУ методом Гаусса» " << endl;
	cout << "3- Задача 3. «Состязания по стрельбе» " << endl;
	cout << "0- Выход из программы " << endl;
}

void strelki(int** a, int n, int m)
{
	int y = 0, i, j, max = 0, z = 0;
	int* b = new int[n];
	for (i = 0; i < n; i++) b[i] = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (a[i][j] > max) max = a[i][j];
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			if (a[i][j] == max)
			{
				y++;
				z = i;
			}
	}
	if (y == 1)
	{
		cout << "Победитель: Стрелок " << z << endl;
	}
	else
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				if (a[i][j] == max) b[i] = 1;
			}
		}
		for (i = 0; i < n; i++)
		{
			if (b[i] == 1)
			{
				b[i] = 0;
				for (j = 0; j < m; j++) b[i] = b[i] + a[i][j];
			}
		}
		cout << endl;
		max = 0;
		for (i = 0; i < n; i++)
		{
			if (b[i] > max) max = b[i];
		}
		for (i = 0; i < n; i++)
			if (b[i] == max) cout << "Победитель: Стрелок " << i << endl;
	}
}



void input1(int** a, int** c, int& n, int& m, int b[], int d[])
{
	int i, j;
	ifstream F1;
	F1.open("mass.txt", ios::in);
	F1 >> n >> m;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			F1 >> a[i][j];
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			F1 >> c[i][j];
		}
	}
	for (i = 0; i < m; i++) F1 >> b[i];
	for (i = 0; i < m; i++) F1 >> d[i];
	F1.close();
}


double gaus(double** a, double b[], int n)
{
	double* x, max;
	int k, index;
	double t;
	const double eps = 0.0000001;  // точность
	x = new double[n];
	k = 0;
	while (k < n)
	{
		// Поиск строки с максимальным элементом
		max = abs(a[k][k]);
		index = k;
		for (int i = k + 1; i < n; i++)
		{
			if (abs(a[i][k]) > max)
			{
				max = abs(a[i][k]);
				index = i;
			}
		}
		if (max < eps)
		{
			// нет ненулевых диагональных элементов
			cout << "Решение получить невозможно из-за нулевого столбца ";
			cout << index << " матрицы A" << endl;
			return 0;
		}
		// Перестановка строк
		for (int j = 0; j < n; j++)
		{
			t = a[k][j];
			a[k][j] = a[index][j];
			a[index][j] = t;
		}
		t = b[k];
		b[k] = b[index];
		b[index] = t;
		// Основное решение
		for (int i = k; i < n; i++)
		{
			t = a[i][k];
			if (abs(t) < eps) continue; // Если ноль, то пропустить
			for (int j = 0; j < n; j++) a[i][j] = a[i][j] / t;
			b[i] = b[i] / t;
			if (i == k)  continue; // чтобы не произошло ошибки в вычитании
			for (int j = 0; j < n; j++) a[i][j] = a[i][j] - a[k][j];
			b[i] = b[i] - b[k];
		}
		k++;
	}
	// обратная подстановка
	for (k = n - 1; k >= 0; k--)
	{
		x[k] = b[k];
		for (int i = 0; i < k; i++)
			b[i] = b[i] - a[i][k] * x[k];
	}
	for (int i = 0; i < n; i++) cout << x[i] << " ";
	cout << endl;
}