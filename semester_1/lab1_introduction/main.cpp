#include <iostream>
#include <clocale>

int main(){
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int a, b;
    using std:: cout;
    using std:: cin;
    cout << "Введите числа ";
    cin >> a >> b;
    cout<<"\nРезультат: ";
    if(a>=b){
        for(int i = 1;b >= i;i++){
            if((a%i==0)&& (b%i==0))
            cout << i<< " ";
        }
    }
    else{
        for(int i = 1;a >=i ; i++ ){
            if((a%i==0)&& (b%i==0))
            cout << i<< " ";
        }

    }
system("pause");
return 0;
}


