#include "Car.h"
#include <iostream>
#include <deque>

using namespace std;

const int START_SIZE = 2;

int main() {
    srand(time(0));

    deque<Car> toll_booth;

    for (int i = 0; i < START_SIZE; i++) {
        toll_booth.push_back(Car());
    }

    while (toll_booth.size() != 0) {
        int num = rand() % 100 + 1;
        if (num <= 55) {

        } else {
            
        }
    }
    cout << "Hello World!";
    return 0;
}