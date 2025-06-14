#include <stdio.h>
#include <stdlib.h>
#define CLIENTS 3  //no of clients
#define WEIGHTS 2 // no of weights 
float global[WEIGHTS] = {0.5, 0.3};
float client[CLIENTS][WEIGHTS];
//we have assumed the update to be random but it will be calculated as per calculations on individual devices by training data

void client_update(int client_id) {
    for (int i = 0; i < WEIGHTS; i++) {
       client[client_id][i] = global[i] + (rand() % 10) * 0.01;  
    }
}
void avg() {
    for (int i = 0; i < WEIGHTS; i++) {
        float sum = 0;
        for (int c = 0; c < CLIENTS; c++) {
            sum += client[c][i];
        }
        global[i] = sum / CLIENTS;
    }
}

int main() {
    
    printf("Initial: [%f, %f]\n", global[0], global[1]);
    for (int round = 0; round < 3; round++) {
     
        for (int c = 0; c < CLIENTS; c++) {
            client_update(c);
        }
        avg();
        printf("Round %d: [%f, %f]\n", round+1, global[0], global[1]);
    }
     return 0;
}
