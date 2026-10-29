#include <clocale>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

string numbers = "1234567890";

bool word_check(string& word) {
	if (word == "-") {
		return false;
	}
	if (word[0] == '-') {
		if ((word.find_first_not_of(numbers, 1)) == string::npos)
			return true;
	}
	if ((word.find_first_not_of(numbers, 0)) == string::npos) {
		return true;
	}
	return false;
}

vector<string> split_string(string& text, string& delimiters) {
	vector<string> words;
	string::size_type beg_index = 0, end_index = text.find_first_of(delimiters, beg_index);
	while (beg_index != string::npos) {
		string word = text.substr(beg_index, end_index - beg_index);
		if (!word.empty()) {
			words.push_back(word);
		}
		beg_index = text.find_first_not_of(delimiters, end_index);
		end_index = text.find_first_of(delimiters, beg_index);
	}

	return words;
}

vector<int> str_to_int(vector<string>& words) {
	vector<int> chisla_iz_str;
	for (int i = 0; i < words.size(); i++) {
		if (word_check(words[i])) {
			chisla_iz_str.push_back(std::stoi(words[i]));
		}
	}
	return chisla_iz_str;
}

int sum_vec(vector<int>& chisla) {
	int sum = 0;
	for (int i = 0; i < chisla.size(); i++) {
		sum += chisla[i];
	}
	return sum;
}

int max_abs_vec(vector<int>& chisla) {
	int max = chisla[0];
	for (int i = 0; i < chisla.size(); i++) {
		if (abs(max) < abs(chisla[i]))
			max = chisla[i];
	}
	return max;
}

void output_vec(vector<int>& chisla) {
	for (int i = 0; i < chisla.size(); i++) {
		cout << " " << chisla[i] << " ";
	}
}

void output_vec(vector<string>& words) {
	for (int i = 0; i < words.size(); i++) {
		cout << " " << words[i] << " ";
	}
}

bool isDelimiter(string& str, ssize_t index, string& delimiters) {
	if (index < 0 || index >= static_cast<ssize_t>(str.length())) {
		return true;
	}
	return delimiters.find(str[index]) != string::npos;
}

void replace_target_number(string& text, string& from, string& to, string& delimiters) {
	if (from.empty())
		return;
	string::size_type start_pos = 0;

	while ((start_pos = text.find(from, start_pos)) != string::npos) {
		ssize_t left_idx = static_cast<ssize_t>(start_pos) - 1;
		ssize_t right_idx = static_cast<ssize_t>(start_pos + from.length());
		if (isDelimiter(text, left_idx, delimiters) && isDelimiter(text, right_idx, delimiters)) {
			text.replace(start_pos, from.length(), to);
			start_pos += to.length();
		} else {
			start_pos += 1;
		}
	}
}

int main() {
	setlocale(LC_ALL, "ru-RU.UTF-8");
	cout << "Введите строку\n";
	string input;
	getline(cin, input);
	cout << "Введите разделители ";
	string delimiters;
	getline(cin, delimiters);
	vector<string> words = split_string(input, delimiters);
	vector<int> chisla = str_to_int(words);
	if (chisla.empty()) {
		cout << "В строке не найдено целых чисел.\n";
		return 0;
	}
	output_vec(chisla);
	cout << std::endl;
	int sum = sum_vec(chisla);
	cout << "Сумма чисел = " << sum << std::endl;
	int max_abs = max_abs_vec(chisla);
	string from_str = std::to_string(max_abs);
	string to_str = std::to_string(sum);
	replace_target_number(input, from_str, to_str, delimiters);
	cout << "Строка после замены\n " << input << std::endl;
	return 0;
}