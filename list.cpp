#include <iostream>
#include <chrono>

#include "deque.h"

using namespace std;
int main(){
for (int i=1000; i<=10000000; i=i*10){
        workWithGeneratedFile(i);
        cout << "failas uzdaromas, tesiama su 10 kartu didesniu failu." << endl;
    }
}
