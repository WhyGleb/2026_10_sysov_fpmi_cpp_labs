// С клавиатуры вводится натуральное число n.
// Найти все простые числа Мерсенна, не превосходящие n.
// Variant 6
#include <iostream>
#include <clocale>
#include <cmath>
int main(){
    setlocale(LC_ALL,"ru-RU.UTF-8");
    long long n; int k=0;
    int l=0; int m =0;
    int j=0;
    std::cout << "Введите натурально число\n";
    if (!(std::cin >> n)){
        std::cout << "Ошибка! Вы ввели не число (буквы или символы)." << std::endl;
        std::exit(0);
    }
    if(n<=0){
        std::cout<<"число <=0 :(";
        std::exit(0);
    }
    std::cout << "Вы ввели число: "<<n<<"\n";
    double log;
    log = log2(n+1);
    for(int p=2;p<=log;p++){
        for(int i=2; i<=pow(p,0.5);i++){
            if(p%i) k++;
            j++;
        }
        if(k==j){
            for(int i = 2; i<=sqrt(pow(2,p)-1);i++){
                if((long long)(pow(2,p)-1)%i) l++;
                m++;
            }
            if(l==m)
                std::cout << (long long)(pow(2,p)-1) <<" ";
            l=0; m=0;
        }
        k=0; j=0;
    } 
    return 0;
}