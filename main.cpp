// COMSC 210 | Lab 33 | Niko Dittmar
#include "Car.h"
#include <iostream>
#include <deque>

using namespace std;

const int NUM_LANES = 4;

const int START_SIZE_MIN = 1;
const int START_SIZE_MAX = 3;

const int CHANCE_PAID = 46;
const int CHANCE_JOIN = 39;
const int CHANCE_SWITCH = 15;

const int CHANCE_JOIN_EMPTY = 50;

const int SIMULATION_LENGTH = 20;

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

    cout << endl;

    int time = 0;
    while (time < SIMULATION_LENGTH) {
        time += 1;
        cout << "Time: " << time << endl;

        for (int i = 0; i < NUM_LANES; i++) {
            int num = rand() % 100 + 1;
            cout << "Lane: " << i + 1;

            if (plaza[i].size() == 0) {
                if (num <= CHANCE_JOIN_EMPTY) {
                    cout << " Joined: ";
                    Car toAdd = Car();
                    toAdd.print();
                    plaza[i].push_back(toAdd);
                } else {
                    cout << " Nothing happened" << endl;
                }
                continue;
            }

            if (num <= CHANCE_JOIN) {
                cout << " Joined: ";
                Car toAdd = Car();
                toAdd.print();
                plaza[i].push_back(toAdd);
            } else if (num <= CHANCE_JOIN + CHANCE_PAID) {
                cout << " Paid: ";
                Car removed = plaza[i].front();
                removed.print();
                plaza[i].pop_front();
            } else {
                cout << " Switched: ";
                int rand_index = rand() % NUM_LANES;
                while (rand_index == i && NUM_LANES != 1) {
                    rand_index = rand() % NUM_LANES;
                }
                Car switched = plaza[i].back();
                switched.print();
                plaza[rand_index].push_back(switched);
                plaza[i].pop_back();
            } 
        }
        
        for (int i = 0; i < NUM_LANES; i++) {
            cout << "Lane " << i + 1 << " Queue: " << endl;
            if (plaza[i].size() == 0) {
                cout << "   Empty" << endl;
            } else {
                for (Car car : plaza[i]) {
                    cout << "   ";
                    car.print();
                }
            }
        }
        
        cout << endl;
    }
    return 0;
}