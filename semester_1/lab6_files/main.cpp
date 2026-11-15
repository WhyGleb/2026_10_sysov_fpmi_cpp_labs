
#include <chrono>
#include <clocale>
#include <cmath>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <locale>
#include <sstream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

struct number_info {
	int value;
	string num_text;
};

string numbers = "1234567890";

std::time_t Now() {
	auto now = std::chrono::system_clock::now();
	return std::chrono::system_clock::to_time_t(now);
}

auto FormatTime(time_t time, bool is_utc_format) {
#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4996)
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif

	return is_utc_format ? std::put_time(std::gmtime(&time), "%Y.%m.%d %H:%M:%S")
						 : std::put_time(std::localtime(&time), "%Y.%m.%d %H:%M:%S"); //"%x %X

#if defined(_MSC_VER)
#pragma warning(pop)
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
}

bool word_check_on_number(const string& word) {
	if (word == "-" || word == "+") {
		return false;
	}
	if (word[0] == '-' || word[0] == '+') {
		return (word.find_first_not_of(numbers, 1)) == string::npos;
	}
	return (word.find_first_not_of(numbers, 0)) == string::npos;
}
void log_print(std::ofstream& log_fout) {
	log_fout << FormatTime(Now(), false) << " | ";
}

void output_vec(std::ofstream& log_fout, vector<string>& words) {
	log_print(log_fout);
	log_fout << "words found:";
	for (int i = 0; i < words.size(); i++) {
		log_fout << " " << words[i] << " ";
	}
	log_fout << std::endl;
}

vector<string> split_string(std::ofstream& log_fout, string& text, string& delimiters) {
	log_print(log_fout);
	log_fout << "finding words in string\n";
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
	output_vec(log_fout, words);
	return words;
}

vector<number_info> str_to_int(std::ofstream& log_fout, const vector<string>& words) {
	log_print(log_fout);
	log_fout << "finding numbers in words\n";
	vector<number_info> chisla_iz_str;
	for (int i = 0; i < words.size(); i++) {
		if (word_check_on_number(words[i])) {
			chisla_iz_str.push_back({std::stoi(words[i]), words[i]});
		}
	}
	log_fout << FormatTime(Now(), false) << " | numbers found:";
	for (int i = 0; i < chisla_iz_str.size(); i++) {
		log_fout << " " << chisla_iz_str[i].value;
	}
	log_fout << "\n";
	return chisla_iz_str;
}

int sum_vec(const vector<number_info>& chisla) {
	int sum = 0;
	for (int i = 0; i < chisla.size(); i++) {
		sum += chisla[i].value;
	}
	return sum;
}

int max_abs_vec(std::ofstream& log_fout, vector<number_info>& chisla) {
	log_print(log_fout);
	log_fout << "finding number with biggest absolute value\n";
	int max = chisla[0].value;
	for (int i = 0; i < chisla.size(); i++) {
		if (abs(max) < abs(chisla[i].value))
			max = chisla[i].value;
	}
	log_print(log_fout);
	log_fout << "number with biggest absolute value\" " << max << "\"\n";
	return max;
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
void open_file(std::ofstream& log_fout, std::ofstream& fout, const string& filename) {
	log_print(log_fout);
	log_fout << "opening file \"" + filename + "\"\n";
	if (!fout.is_open()) {
		log_print(log_fout);
		log_fout << "file \"" + filename + "\" hasn't been opened successfully\n";
		throw "Error: could not open file \"" + filename + "\"!!!";
	}
	log_print(log_fout);
	log_fout << "file \"" + filename + "\" has been opened successfully\n";
}
void open_file(std::ofstream& log_fout, std::ifstream& fin, const string& filename) {
	log_print(log_fout);
	log_fout << "opening file \"" + filename + "\"\n";
	if (!fin.is_open()) {
		log_print(log_fout);
		log_fout << "file \"" + filename + "\" hasn't been opened successfully\n";
		throw "Error: could not open file \"" + filename + "\"!!!";
	}
	log_print(log_fout);
	log_fout << "file \"" + filename + "\" has been opened successfully\n";
}
void open_file(std::ofstream& log_fout, const string& filename) {
	if (!log_fout.is_open()) {
		throw "Error: could not open file \"" + filename + "\"!!!";
	}
}
void is_empty_file(std::ifstream& fin, const string& filename) {
	if (fin.peek() == EOF) {
		throw "Error: file \"" + filename + "\" is empty";
	}
}

int main() {
	const string input_filename = "input.txt";
	const string output_filename = "output.txt";
	const string log_filename = "log.txt";
	std::ifstream fin{input_filename};
	std::ofstream log_fout{log_filename};
	std::ofstream fout{output_filename};
	string delimiters;
	try {
		setlocale(LC_ALL, "ru-RU.UTF-8");
		open_file(log_fout, log_filename);
		open_file(log_fout, fin, input_filename);
		open_file(log_fout, fout, output_filename);
		is_empty_file(fin, input_filename);
	} catch (const std::string& e) {
		std::cerr << e << std::endl;
		if (log_fout.is_open()) {
			log_print(log_fout);
			log_fout << e << "\n";
			log_fout << FormatTime(Now(), false) << " | program has ended with code 1\n";
		}
		return 1;
	}
	log_print(log_fout);
	log_fout << "reading from \"" + input_filename + "\"\n";
	getline(fin, delimiters);
	log_print(log_fout);
	log_fout << "got delimiters:\"" + delimiters + "\"\n";
	string line;
	while (getline(fin, line)) {
		log_print(log_fout);
		log_fout << "got line:\"" + line + "\"\n";
		vector<string> words = split_string(log_fout, line, delimiters);
		vector<number_info> chisla = str_to_int(log_fout, words);
		try {
			if (chisla.empty()) {
				throw "Error: string haven't integers";
			}
			int sum = sum_vec(chisla);
			int max_abs = max_abs_vec(log_fout, chisla);
			string to_str = std::to_string(sum);
			for (int i = 0; i < chisla.size(); i++) {
				if (chisla[i].value == max_abs) {
					replace_target_number(line, chisla[i].num_text, to_str, delimiters);
				}
			}
			log_print(log_fout);
			log_fout << "writing result to \"" + output_filename + "\"\n";
			fout << line << std::endl;
		} catch (const char* e) {
			if (log_fout.is_open()) {
				log_print(log_fout);
				log_fout << e << "\n";
			}
			if (fout.is_open()) {
				log_print(log_fout);
				fout << line << " | line haven't numbers\n";
			}
		}
	}
	fout.close();
	fin.close();
	log_print(log_fout);
	log_fout << "progam has ended with code 0";
	log_fout.close();
	return 0;
}
