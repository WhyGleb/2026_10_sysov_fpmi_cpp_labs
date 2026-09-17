#include <iostream>
#include <clocale>

int main (){
    setlocale(LC_ALL,"ru-RU.UTF-8");
    int dig, sum1, sum2, c;
    std::cout << "Введите шестизначное число\n";
    std::cin >> dig;
    c=dig;
    sum1=0; sum2=0;

    for(int i =0; i <= 5;i++){
        if(i<=2)
            sum1 += dig%10;
        else
            sum2 += dig%10;
        dig /=10;
    }
    if(sum1==sum2)
        std::cout << c << " - число счастливое\n";
    else
        std::cout << c << " - число не счастливое\n";
return 0;
}