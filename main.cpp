// COMSC 210 | Lab 32 | Niko Dittmar
#include "Car.h"
#include <iostream>
#include <deque>

using namespace std;

const int START_SIZE = 2;

int main() {
    srand(time(0));

    deque<Car> toll_booth;

    cout << "Initial queue:" << endl;

    for (int i = 0; i < START_SIZE; i++) {
        Car toAdd = Car();
        toll_booth.push_back(toAdd);
        cout << "   ";
        toAdd.print();
    }

    int time = 0;
    while (toll_booth.size() != 0) {
        time += 1;
        cout << "Time: " << time << " Operation: ";
        int num = rand() % 100 + 1;
        if (num <= 55) {
            cout << "Car paid: ";
            Car removed = toll_booth.front();
            removed.print();
            toll_booth.pop_front();
        } else {
            cout << "Joined lane: ";
            Car toAdd = Car();
            toAdd.print();
            toll_booth.push_back(toAdd);
        }
        cout << "Queue: " << endl;
        if (toll_booth.size() == 0) {
            cout << "   Empty" << endl;
        } else {
            for (Car car : toll_booth) {
                cout << "   ";
                car.print();
            }
        }
        cout << endl;
    }
    return 0;
}