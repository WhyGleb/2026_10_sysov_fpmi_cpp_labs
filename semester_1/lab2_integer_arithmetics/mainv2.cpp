#include <climits>
#include <clocale>
#include <cmath>
#include <iostream>

// 9223372036854775807

bool prov(long long p) {
	for (long long i = 2; i < sqrt(p); i++) {
		if (p % i == 0)
			return false;
	}
	return true;
}
int main() {
	setlocale(LC_ALL, "ru-RU.UTF-8");
	long long n;
	std::cout << "Введите число N. Если хотите использовать максимальное доступное введите 0\n";
	if (!(std::cin >> n)) {
		std::cout << "Ошибка! Вы ввели не число." << std::endl;
		std::exit(0);
	}
	if (n == 0)
		n = LLONG_MAX;
	if (n < 0) {
		std::cout << "число <=0 :(";
		std::exit(0);
	}

	for (long long i = 2; i <= log2(n); i++) {
		if (prov(i)) {
			if (prov((long long)pow(2, i) - 1)) {
				std::cout << (long long)(pow(2, i) - 1) << " ";
			}
		}
	}

	return 0;
}
