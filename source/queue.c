#include "queue.h"

//direction; 0=ned, 1=opp

void queue_add(int direction, int floor_current){
    if(direction == 2) {
    	down_queue[floor_current] = 1;
	up_queue[floor_current] = 1;
    }
    if (direction == 0){
        down_queue[floor_current]=1;
    }

    else if (direction == 1) {
        up_queue[floor_current]=1;
    }
}

void queue_remove(int floor){
    down_queue[floor]=0;
    up_queue[floor]=0;
}

int queue_get_next(int direction, int floor_current){
    if(direction == 0){ 
        for (int i=floor_current; i >= 0; i--){
            if(down_queue[i]==1){
                return i;
            }
        }
         for (int i=0; i < HARDWARE_NUMBER_OF_FLOORS; i++){
            if(up_queue[i]==1){
                return i;
            }
        }
        for (int i=HARDWARE_NUMBER_OF_FLOORS-1; i >= 0; i--){
            if(down_queue[i]==1){
                return i;
            }
        }
        
    }
    if(direction == 1){
         for (int i=floor_current; i < HARDWARE_NUMBER_OF_FLOORS; i++){
            if(up_queue[i]==1){
                return i;
            }
        }
        for (int i=HARDWARE_NUMBER_OF_FLOORS-1; i >= 0; i--){
            if(down_queue[i]==1){
                return i;
            }
        }
        for (int i=0; i < HARDWARE_NUMBER_OF_FLOORS; i++){
            if(up_queue[i]==1){
                return i;
            }
        }

    }
    return -1;
}
