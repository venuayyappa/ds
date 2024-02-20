#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int big;
    int medium;
    int small;
} ParkingSystem;

ParkingSystem* parkingSystemCreate(int big, int medium, int small) {
    ParkingSystem* park = calloc(1, sizeof(ParkingSystem));
    if (park == NULL) {
        perror("Malloc park");
        return NULL;
    }
   
    park->big = big;
    park->medium = medium;
    park->small = small;
    return park;
}
bool parkingSystemAddCar(ParkingSystem* obj, int carType) {
   
    if (carType == 1 && obj->big != 0) {
        obj->big -= 1;
        return true;
    }
   
    if (carType == 2 && obj->medium != 0) {
        obj->medium -= 1;
        return true;
    }
    
    if (carType == 3 && obj->small != 0) {
        obj->small -= 1;
        return true;
    }
    return false;
}

void parkingSystemFree(ParkingSystem* obj) { free(obj); }
