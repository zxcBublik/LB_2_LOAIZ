#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
//#define ARR_SIZE 1000
#define LEIGHT 10000

void first_task() {
	clock_t start, end, start_code; // объявляем переменные для определения времени выполнения
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	int ARR_SIZE[] = {100, 200, 300, 320, 340, 350, 360};
	for (int z = 0; z < (sizeof(ARR_SIZE) / sizeof(ARR_SIZE[0])); z++) {
		start_code = clock();
		int** a = (int**)malloc(ARR_SIZE[z] * sizeof(int*));
		for (int i = 0; i < ARR_SIZE[z]; i++) {
			a[i] = (int*)malloc(ARR_SIZE[z] * sizeof(int));
			for (int j = 0; j < ARR_SIZE[z]; j++) {
				a[i][j] = rand() % 100 + 1;
			}
		}
		int** b = (int**)malloc(ARR_SIZE[z] * sizeof(int*));
		for (int i = 0; i < ARR_SIZE[z]; i++) {
			b[i] = (int*)malloc(ARR_SIZE[z] * sizeof(int));
			for (int j = 0; j < ARR_SIZE[z]; j++) {
				b[i][j] = rand() % 100 + 1;
			}
		}
		int** c = (int**)malloc(ARR_SIZE[z] * sizeof(int*));
		for (int i = 0; i < ARR_SIZE[z]; i++) {
			c[i] = (int*)malloc(ARR_SIZE[z] * sizeof(int));
			for (int j = 0; j < ARR_SIZE[z]; j++) {
				c[i][j] = 0;
			}
		}
		start = clock();
		for (int i = 0; i < ARR_SIZE[z]; i++) {
			for (int j = 0; j < ARR_SIZE[z]; j++) {
				for (int r = 0; r < ARR_SIZE[z]; r++) {
					c[i][j] += a[i][r] * b[r][j];
				}
			}
		}
		end = clock();
		for (int i = 0; i < ARR_SIZE[z]; i++) {
			free(a[i]); free(b[i]); free(c[i]);
		}
		free(a); free(b); free(c);
		double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
		double time_spent_code = (double)(end - start_code) / CLOCKS_PER_SEC;
		cout << "Для матрицы размером "<<ARR_SIZE[z] << " элементов:\n" << "Время выполнения программы: " << time_spent_code << "\nВремя выполнения умножения матриц: " << time_spent << "\n\n";
	}
}
void shell(int* items, int count)
{
	int i, j, gap, k;
	int x, a[5];
	a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;
	for (k = 0; k < 5; k++) {
		gap = a[k];
		for (i = gap; i < count; ++i) {
			x = items[i];
			for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
				items[j + gap] = items[j];
			items[j + gap] = x;
		}
	}
}
void qs(int* items, int left, int right) //вызов функции: qs(items, 0, count-1);
{
	int i, j;
	int x, y;
	i = left; j = right;

	/* выбор компаранда */
	x = items[(left + right) / 2];

	do {
		while ((items[i] < x) && (i < right)) i++;
		while ((x < items[j]) && (j > left)) j--;

		if (i <= j) {
			y = items[i];
			items[i] = items[j];
			items[j] = y;
			i++; j--;
		}
	} while (i <= j);

	if (left < j) qs(items, left, j);
	if (i < right) qs(items, i, right);
}
int comp(const void* a, const void* b) {
	return (*(int*)a) - (*(int*)b);
}
void second_task() {
	int point, arr[LEIGHT], arr_2[LEIGHT], arr_3[LEIGHT];
	clock_t start, end;
	do {
		cout << "Введите пункт задания (1-4), 0 - назад: \n";
		cin >> point;
		if (point < 1 || point > 4) {
			if (point == 0)
				continue;
			cout << "Такого пункта нет!\n";
			continue;
		}
		switch (point) {
		case 1:
			for (int i = 0; i < LEIGHT; i++) {
				arr[i] = rand() % 10000;
				arr_2[i] = arr[i];
				arr_3[i] = arr[i];
			}
			break;
		case 2:
			for (int i = 0; i < LEIGHT; i++) {
				arr[i] = i + 1;
				arr_2[i] = arr[i];
				arr_3[i] = arr[i];
			}
			break;
		case 3:
			for (int i = 0; i < LEIGHT; i++) {
				arr[i] = LEIGHT - i;
				arr_2[i] = arr[i];
				arr_3[i] = arr[i];
			}
			break;
		case 4:
			for (int i = 0; i < LEIGHT; i++) {
				if (i < (LEIGHT / 2)) {
					arr[i] = i + 1;
					arr_2[i] = arr[i];
					arr_3[i] = arr[i];
				}
				else {
					arr[i] = LEIGHT - i;
					arr_2[i] = arr[i];
					arr_3[i] = arr[i];
				}
			}
			break;
		}
		start = clock();
		shell(arr, LEIGHT);
		end = clock();
		double time_spend = (double)(end - start) / CLOCKS_PER_SEC;
		cout << "Время работы функции SHELL: " << time_spend;
		start = clock();
		qs(arr_2, 0, LEIGHT - 1);
		end = clock();
		time_spend = (double)(end - start) / CLOCKS_PER_SEC;
		cout << "\nВремя работы функции QS: " << time_spend << '\n';
		start = clock();
		qsort(arr_3, LEIGHT, sizeof(int), comp);
		end = clock();
		time_spend = (double)(end - start) / CLOCKS_PER_SEC;
		cout << "Время работы функции qsort: " << time_spend << '\n';
	} while (point != 0);
}
int main(void)
{
	setlocale(LC_ALL, "Russian");
	unsigned short number;
	bool flag = 1;
	while (flag != 0) {
		cout << "Введите номер задания:\n";
		cin >> number;
		switch (number) {
		case 1:
			first_task();
			break;
		case 2:
			second_task();
			break;
		}
		cout << "\nВведите 1, чтобы продолжить выбирать задания (0, чтобы выйти):\n";
		cin >> flag;
	}


	return(0);
}
