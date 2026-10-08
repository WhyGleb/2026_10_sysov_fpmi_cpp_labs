
#include <clocale>
#include <cstdlib>
#include <iostream>
#include <random>
#include <string>
using std::string;

void input_arr(double* arr, int n) {
	std::cout << "Введите массив\n" << std::endl;
	for (int i = 0; i < n; i++) {
		if (!(std::cin >> arr[i])) {
			std::cout << "Вы ввели не число\n";
			exit(-1);
		}
	}
}

void output_arr(double* arr, int n) {
	std::cout << "Ваш массив:\n";
	for (int i = 0; i < n; i++) {
		if (!(i % 10))
			std::cout << "\n";
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void random_input_arr(int a, int b, int n, double* arr, std::mt19937& gen) {
	int t = 0;
	if (a > b) {
		t = b;
		b = a;
		a = t;
	}
	std::uniform_real_distribution<double> dist(a, b);
	for (int i = 0; i < n; i++) {
		arr[i] = dist(gen);
	}
}
void choice(string k, double* arr, int n, std::mt19937& gen) {

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

void remove_del(double* arr, int n, int N) {
	for (int k = 0; k < N; ++k) {
		int len = n - k;
		int minPos = 0;

		for (int i = 1; i < len; ++i) {
			if (arr[i] < arr[minPos]) {
				minPos = i;
			}
		}
		for (int i = minPos; i < len - 1; i++) {
			arr[i] = arr[i + 1];
		}
		arr[len - 1] = 0.0;
	}
}
int main() {
	setlocale(LC_ALL, "ru-RU.UTF-8");
	std::random_device rd;
	std::mt19937 gen(rd());
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
	double* arr = new double[n];
	string k;
	std::cout << "Введите 0 если хотите ввести массив вручную. Иначе введеётся рандомно\n";
	std::cin >> k;
	choice(k, arr, n, gen);
	// input_arr(arr, n);
	output_arr(arr, n);
	std::cout << "Введите количество которое нужно удалить\n";
	int N;
	if (!(std::cin >> N)) {
		std::cout << "Вы ввели не число \n";
		return -1;
	}
	if (n <= 0) {
		std::cout << "Количество не может быть меньше 0\n";
		return -1;
	}
	remove_del(arr, n, N);
	output_arr(arr, n);

	return 0;
}