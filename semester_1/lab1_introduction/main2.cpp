#include <iostream>
#include <clocale>
int main(){
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int n;
    std::cout << "Введите N\n";
    std::cin >> n;
    int sum = 0;
    for(int i = 1;i <=n; ){
        sum +=i;
        i+=2;
    }
    std::cout << "\nСумма нечетных до N = "<< sum;
    return 0;
}