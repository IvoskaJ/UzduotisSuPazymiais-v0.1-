#include <iostream>
#include <chrono>

#include "deque1.h"

using namespace std;
int main() {
    for (int i = 1000; i <= 10000000; i = i * 10) {
        cout << "pradedamas darbas su " << i << " dydzio failu." << endl;
        workWithGeneratedFile(i);
        cout << "failas uzdaromas, tesiama su 10 kartu didesniu failu." << endl;
    }
}
