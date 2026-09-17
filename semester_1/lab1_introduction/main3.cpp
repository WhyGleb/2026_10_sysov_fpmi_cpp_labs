#include <iostream>
#include <clocale>

int main (){
    setlocale(LC_ALL,"ru-RU.UTF-8");
    int dig, a1,a2,a3,a4;
    std::cout << "Введите 4-х значное число\n";
    std::cin >> dig;
    a1 = dig / 1000;
    if(a1==0){
        std::cout << "Не четырехзначное";
        std::exit(0);
    }
    a2 = (dig / 100)%10;
    a3 = (dig / 10)%10;
    a4 = dig % 10;
    if((a1 == a4) && (a2==a3))
        std::cout << dig<< " - Полиндром";
    else
        std::cout << dig<< " - Не полиндром";
        return 0;
}