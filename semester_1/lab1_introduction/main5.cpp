#include <iostream>
#include <clocale>

int main (){
    using std::cout;
    setlocale(LC_ALL,"ru-RU.UTF-8");
    int n, fi1,fi2,fi3;
    std::cout << "Введите N\n";
    std::cin >> n;
    if(n==0){
        cout << "Тяжело вывести 0 чисел";
        std::exit(0);
    }
    cout << "Первые " << n << " чисел последовательности Фибоначчи:\n";
    for(int i=1; i <=n;i++){
        if(i==1){
            fi1=0;
            cout << fi1<< " ";
        }
        if(i==2){
            fi2=1;
            cout << fi2 << " ";
        }
        if(i >= 3){
            fi3 = fi1 + fi2;
            cout << fi3 <<" ";
            fi1 = fi2;
            fi2 = fi3;
        }
    }
    return 0;
}