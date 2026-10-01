#include <clocale>
#include <cstdlib>
#include <iostream>
#include <random>
#include <string>
using std::string;

const int MAX_Length = 2000;

void input_arr(int* arr, int n) {
	std::cout << "Введите массив\n" << std::endl;
	for (int i = 0; i < n; i++) {
		if (!(std::cin >> arr[i])) {
			std::cout << "Вы ввели не число\n";
			exit(-1);
		}
	}
}

void output_arr(int* arr, int n) {
	std::cout << "Ваш массив:\n";
	for (int i = 0; i < n; i++) {
		if (!(i % 20))
			std::cout << "\n";
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
void random_input_arr(int a, int b, int n, int* arr, std::mt19937& gen) {
	int t = 0;
	if (a > b) {
		t = b;
		b = a;
		a = t;
	}
	std::uniform_int_distribution<int> dist(a, b);
	for (int i = 0; i < n; i++) {
		arr[i] = dist(gen);
	}
}
void choice(string k, int* arr, int n, std::mt19937& gen) {

	if (k == "0")
		input_arr(arr, n);
	else {
		std::cout << "Введите промежуток для генерации\n";
		int a, b;
		if (!(std::cin >> a >> b)) {
			std::cout << "Вы ввели не число\n";
			exit(-1);
		}
		random_input_arr(a, b, n, arr, gen);
	}
}
void selection(int a, int b, int n, int* arr) {
	int t = 0;
	if (a > b) {
		t = b;
		b = a;
		a = t;
	}
	int count1 = 0;
	int count2 = 0;
	int arr_ab[n];
	int arr_ne_ab[n];
	for (int i = 0; i < n; i++) {
		if (arr[i] >= a && arr[i] <= b) {
			arr_ab[count1] = arr[i];
			count1++;
		} else {
			arr_ne_ab[count2] = arr[i];
			count2++;
		}
	}
	for (int i = 0; i < count1; i++) {
		arr[i] = arr_ab[i];
	}
	for (int i = count1; i < count1 + count2; i++) {
		arr[i] = arr_ne_ab[i - count1];
	}
}
int main() {
	setlocale(LC_ALL, "ru-RU.UTF-8");
	std::random_device rd;
	std::mt19937 gen(rd());
	int arr[MAX_Length];
	int n;
	std::cout << "Введите размер массива\n";
	if (!(std::cin >> n)) {
		std::cout << "Вы ввели не число \n";
		return -1;
	}
	if (n < 0) {
		std::cout << "Количество не может быть меньше 0\n";
		return -1;
	}
	if (n > MAX_Length) {
		std::cout << "Нету места";
		return -1;
	}
	string k;
	std::cout << "Введите 0 если хотите ввести массив вручную. Иначе введеётся рандомно\n";
	std::cin >> k;
	choice(k, arr, n, gen);
	// input_arr(arr, n);
	output_arr(arr, n);
	std::cout << "Введите начало и конец промежутка\n";
	int a, b;
	if (!(std::cin >> a >> b)) {
		std::cout << "Ввели не число\n";
		return -1;
	};
	selection(a, b, n, arr);
	output_arr(arr, n);

	return 0;
}