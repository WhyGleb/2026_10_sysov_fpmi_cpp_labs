
#include <clocale>
#include <iostream>
#include <random>
#include <string>

using std::cin;
using std::cout;
using std::string;

void cleaner(int**& arr, int n_l) {
	for (int i = 0; i < n_l; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	arr = nullptr;
}
void input_arr(int**& arr, int n_l, int n_c) {
	cout << "Введите массив\n";
	for (int i = 0; i < n_l; i++) {
		for (int j = 0; j < n_c; j++) {
			if (!(cin >> arr[i][j])) {
				cout << "Вы ввели не число\n";
				cleaner(arr, n_l);
				exit(-1);
			}
		}
	}
}

void random_input_arr(int a, int b, int n_l, int n_c, int** arr, std::mt19937& gen) {
	int t = 0;
	if (a > b) {
		t = b;
		b = a;
		a = t;
	}
	std::uniform_int_distribution<int> dist(a, b);
	for (int i = 0; i < n_l; i++)
		for (int j = 0; j < n_c; j++)
			arr[i][j] = dist(gen);
}

void output_arr(int** arr, int n_l, int n_c) {
	cout << "Ваш массив\n";
	for (int i = 0; i < n_l; i++) {
		for (int j = 0; j < n_c; j++) {
			cout << " " << arr[i][j];
		}
		cout << std::endl;
	}
}

void choice(string k, int**& arr, int n_l, int n_c, std::mt19937& gen) {

	if (k == "0")
		input_arr(arr, n_l, n_c);
	else {
		cout << "Введите промежуток для генерации\n";
		int a, b;
		if (!(cin >> a >> b)) {
			cout << "Вы ввели не число\n";
			cleaner(arr, n_l);
			exit(-1);
		}
		random_input_arr(a, b, n_l, n_c, arr, gen);
	}
	output_arr(arr, n_l, n_c);
}

int line_min(int* arr, int n_c) {
	int temp = arr[0];
	for (int i = 0; i < n_c; i++) {
		if (arr[i] <= temp)
			temp = arr[i];
	}
	return temp;
}
int column_max(int** arr, int n_l, int k) {
	int temp = arr[0][k];
	for (int i = 0; i < n_l; i++) {
		if (arr[i][k] >= temp)
			temp = arr[i][k];
	}
	return temp;
}

void saddle(int** arr, int n_l, int n_c) {
	int counter = 0;
	for (int i = 0; i < n_l; i++) {
		int min_l = line_min(arr[i], n_c);
		for (int j = 0; j < n_c; j++) {
			int max_c = column_max(arr, n_l, j);
			if ((arr[i][j] == min_l) && (arr[i][j] == max_c)) {
				cout << "Точка(" << j + 1 << ", " << i + 1 << ") - седловая\n";
				counter++;
			}
		}
	}
	if (counter == 0) {
		cout << "Нет седловых точек";
	}
}

int main() {

	setlocale(LC_ALL, "ru-RU.UTF-8");
	std::random_device rd;
	std::mt19937 gen(rd());
	cout << "Введите количество строк\n";
	int count_line;
	if (!(cin >> count_line)) {
		cout << "Вы ввели не число \n";
		return (-1);
	}
	cout << "Введите количество столбцов\n";
	int count_column;
	if (!(cin >> count_column)) {
		cout << "Вы ввели не число \n";
		return (-1);
	}
	if (count_column <= 0 || count_line <= 0) {
		cout << "неверные данные\n";
	}
	int** arr = new int*[count_line];
	for (int i = 0; i < count_line; i++) {
		arr[i] = new int[count_column];
	}
	string k;
	cout << "Введите 0 если хотите ввести массив вручную. Иначе введеётся рандомно\n";
	cin >> k;
	choice(k, arr, count_line, count_column, gen);
	saddle(arr, count_line, count_column);
}