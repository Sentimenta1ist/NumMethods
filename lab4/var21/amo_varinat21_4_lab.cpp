#include "Task.h"

int main(){
    printf("\terr\t\th\treal err\n");
    runge(1e-2);
    runge(1e-3);
    runge(1e-4);
    runge(1e-5);
    runge(1e-6);
}
