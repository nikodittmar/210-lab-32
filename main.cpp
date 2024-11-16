// COMSC 210 | Lab 33 | Niko Dittmar
#include "Car.h"
#include <iostream>
#include <deque>

using namespace std;

const int NUM_LANES = 4;

const int START_SIZE_MIN = 1;
const int START_SIZE_MAX = 3;

const int CHANCE_PAID = 55;
const int CHANCE_JOIN = 45;

int main() {
    srand(time(0));

    cout << "Initial queue:" << endl;

    deque<Car> plaza[NUM_LANES];

    for (int i = 0; i < NUM_LANES; i++) {
        cout << "Lane " << i + 1 << ":" << endl;
        int initial_car_count = rand() % START_SIZE_MAX + START_SIZE_MIN;
        for (int j = 0; j < initial_car_count; j++) {
            Car toAdd = Car();
            plaza[i].push_back(toAdd);
            cout << "   ";
            toAdd.print();
        }
    }

    int time = 0;
    while (toll_booth.size() != 0) {
        time += 1;
        cout << "Time: " << time << " Operation: ";
        int num = rand() % 100 + 1;
        if (num <= CHANCE_PAID) {
            cout << "Car paid: ";
            Car removed = toll_booth.front();
            removed.print();
            toll_booth.pop_front();
        } 
        num = rand() % 100 + 1;
        if (num <= CHANCE_JOIN) {
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