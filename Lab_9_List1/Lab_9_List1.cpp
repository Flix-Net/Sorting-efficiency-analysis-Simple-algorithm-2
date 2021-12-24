#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

//------------------Прототипы------------------------------
void BubbleSort(int arr[], int row);
void SelectionSort(int arr[], int row);
void InsertionSort(int arr[], int row);
void CocktailSort(int a[], int row);
void Print_Arr(int* arr, int row);
string Power(int row);
string InCase();
//---------------------------------------------------------

int main()
{
	setlocale(0, "");
start:
	int row = 0, cin_sort; string variant;
	system("cls");
	cout
		<< "\n\t\t\t\t---> Массив <---\n"
		<< "Выберите мощность \n"
		<< "10 - 10 \n"
		<< "50 - 50 \n"
		<< "100 - 100 \n"
		<< "1000 - 1,000 \n"
		<< "10000 - 10,000 \n"
		<< "100000 - 100,000 \n"
		<< "\n\tВыбор: "; cin >> row;

	variant = Power(row) + InCase() + ".txt";
	cout << "\n\t\tБудет выполнен " << variant;

	int* arr = new int[row];

	ifstream fin;
	fin.open(variant);

	if (!fin.is_open())
	{
		cout << "\n\t\tНе удалось открыть файл!\n" << endl; return 0;
	}
	else
	{
		for (int i = 0; i < row; i++)
		{
			fin >> arr[i];
		}
		cout << "\n\t\tФайл загружен!\n\n";
	}

	cout
		<< "\n\t\t\t\t---> Массив <---\n"
		<< "Выберите сортировку \n"
		<< "1 - Пузырек\n"
		<< "2 - Вставка\n"
		<< "3 - Выбор\n"
		<< "4 - Шейкер\n"
		<< "\n\tВыбор: "; cin >> cin_sort;

	switch (cin_sort)
	{
	case 1:
	{
		bool var;
		system("cls");
		double start = clock();
		BubbleSort(arr, row);
		double stop = clock();
		cout << "\n\t\tВремя сортировки: " << (stop - start) / CLK_TCK << "сек.\n\n";

		cout << "Распечатать данные? (1-да/0-нет)  "; cin >> var;
		if (var)
		{
			Print_Arr(arr, row);
			system("pause");
		}
		goto start;
	}

	case 2:
	{
		bool var;
		system("cls");
		double start = clock();
		InsertionSort(arr, row);
		double stop = clock();
		cout << "\n\t\tВремя сортировки: " << (stop - start) / CLK_TCK << "сек.\n\n";

		cout << "Распечатать данные? (1-да/0-нет)  "; cin >> var;
		if (var)
		{
			Print_Arr(arr, row);
			system("pause");
		}
		goto start;
	}

	case 3:
	{
		bool var;
		system("cls");
		double start = clock();
		SelectionSort(arr, row);
		double stop = clock();
		cout << "\n\t\tВремя сортировки: " << (stop - start) / CLK_TCK << "сек.\n\n";

		cout << "Распечатать данные? (1-да/0-нет)  "; cin >> var;
		if (var)
		{
			Print_Arr(arr, row);
			system("pause");
		}
		goto start;
	}

	case 4:
	{
		bool var;
		system("cls");
		double start = clock();
		CocktailSort(arr, row);
		double stop = clock();
		cout << "\n\t\tВремя сортировки: " << (stop - start) / CLK_TCK << "сек.\n\n";

		cout << "Распечатать данные? (1-да/0-нет)  "; cin >> var;
		if (var)
		{
			Print_Arr(arr, row);
			system("pause");
		}
		goto start;
	}
	}

	return 0;
}



void Print_Arr(int* arr, int row)
{
	for (int i = 0; i < row; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n\n\t\tВывод завершен!\n\n";
}

void SelectionSort(int arr[], int row)
{
	int i, j, min_idx, temp;
	unsigned long long comp = 0, swaps = 0;

	// One by one move boundary of unsorted subarray  
	for (i = 0; i < row - 1; i++)
	{
		// Find the minimum element in unsorted array  
		min_idx = i;
		for (j = i + 1; j < row; j++)
		{
			comp++;
			if (arr[j] < arr[min_idx])
			{
				min_idx = j;

			}

		}
		// Swap the found minimum element with the first element  
		if (min_idx != i)
		{
			temp = arr[min_idx];
			arr[min_idx] = arr[i];
			arr[i] = temp;
			swaps++;
		}

	}
	cout << "Сравнений " << comp << " ,перестановок " << swaps << endl;
}

void InsertionSort(int arr[], int row)
{
	int i, key, j, temp;
	unsigned long long sravn = 0, swaps = 0, flag;
	for (i = 1; i < row; i++)
	{
		flag = 0;
		key = arr[i];

		j = i - 1;
		/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */

		while (j >= 0 && arr[j] > key)
		{
			swaps++;
			sravn++;
			arr[j + 1] = arr[j];
			j = j - 1;
			flag = 1;
		}
		sravn++;
		if (flag)
			arr[j + 1] = key;

	}

	cout << "Сравнений " << sravn << " ,перестановок " << swaps << endl;
}

void CocktailSort(int a[], int row)
{
	bool swapped = true;
	int start = 0, sravn = 0, tempStore;
	unsigned long long swaps = 0;
	int end = row - 1;

	while (swapped) {
		// reset the swapped flag on entering 
		// the loop, because it might be true from 
		// a previous iteration. 
		swapped = false;

		// loop from left to right same as 
		// the bubble sort 
		for (int i = start; i < end; ++i) {
			sravn++;
			if (a[i] > a[i + 1]) {
				tempStore = a[i];
				a[i] = a[i + 1];
				a[i + 1] = tempStore;
				swapped = true;
				swaps++;
			}
		}

		// if nothing moved, then array is sorted. 
		if (!swapped)
			break;

		// otherwise, reset the swapped flag so that it 
		// can be used in the next stage 
		swapped = false;

		// move the end point back by one, because 
		// item at the end is in its rightful spot 
		--end;

		// from right to left, doing the 
		// same comparison as in the previous stage 
		for (int i = end - 1; i >= start; --i) {
			sravn++;
			if (a[i] > a[i + 1]) {
				tempStore = a[i];
				a[i] = a[i + 1];
				a[i + 1] = tempStore;
				swapped = true;
				swaps++;
			}
		}

		// increase the starting point, because 
		// the last stage would have moved the next 
		// smallest number to its rightful spot. 
		++start;
	}
	cout << "Сравнений " << sravn << " ,перестановок " << swaps << endl;
}

void BubbleSort(int arr[], int row)
{
	int  Temp, flag;
	unsigned long long shifts = 0, sravn = 0;

	for (int i = 0; i < row; i++) {
		flag = 1;
		for (int j = 0; j < row - i - 1; j++) {
			sravn++;
			if (arr[j] > arr[j + 1]) {
				Temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = Temp;
				shifts++;
				flag = 0;
			}

		}
		if (flag) break;
	}
	cout << "\n\t\tКол-во сравнений: " << sravn
		<< "\n\t\tКол-во перестановок: " << shifts
		<< endl << endl;
}

string Power(int row)
{
	string result;

	switch (row)
	{
	case 10:
	{
		return result = "10";
	}
	case 50:
	{
		return result = "50";
	}
	case 100:
	{
		return result = "100";
	}
	case 1000:
	{
		return result = "1000";
	}
	case 10000:
	{
		return result = "10000";
	}
	case 100000:
	{
		return result = "100000";
	}

	default:
	{
		cout << "\n\t\tВы указали не верный вариант!\n По умолчанию будет выбран первый вариант\n";
		system("pause");
		return result = "10";
	}

	}
}

string InCase()
{
	string result;
	int cin_case = 0;
	cout << "---> Массив <---\n"
		<< "Выберите случай \n"
		<< "-1 - Наихудший \n"
		<< "0  - Средний \n"
		<< "1  - Наилучший \n"
		<< "\n\tВыбор: "; cin >> cin_case;
	if (cin_case == -1)
	{
		return result = "_hard";
	}
	if (cin_case == 0)
	{
		return result = "_medium";
	}
	if (cin_case == 1)
	{
		return result = "_low";
	}
	else
	{
		cout << "\n\n\tНе верный выбор, по умолчанию выполнится первое условие\n\n";
		return result = "_low";
	}
}