#include <iostream>
#include <clocale>
int main(){
    setlocale(LC_ALL,"ru-RU.UTF-8");
    int a, b, d, ai, k;
    k=0;
    std::cout << "Введите концы отрезка и разность последовательности\n";
    std::cin >> a >> b >> d;
    ai = a;
    for(int i =0; ai<= b; i++){
        if(ai % 3 ==0){
            std::cout << ai<< " "; k++;
        }
        ai +=d; 
    }
    if(k==0)
        std::cout <<"Нету кратных 3";
return 0;
}