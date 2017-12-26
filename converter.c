#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if(argc < 2){
        return 0;
    }
    

    if(argc == 2){
        double temp = atof(argv[1]);
        if(temp < 273.15){
            return 1;
        }
        printf("%.2f %s", temp, "C\n");
        printf("%.2f %s", temp + 273.15, "K\n");
        printf("%.2f %s", 9 * (temp + 32) / 5, "F\n\n");
    }

    if(argc == 3){
        double temp = atof(argv[1]);
        char scale = *argv[2];
        if(((temp < 273.15) && (scale == 'C')) || ((temp <= -459,67) && (scale == 'F')) || ((temp <= 0) && (scale == 'K'))){
            return 1;
        }
        switch (scale) {
            case 'C':
                printf("%.2f %s", temp, "C\n");
                printf("%.2f %s", temp + 273.15, "K\n");
                printf("%.2f %s", 9 * (temp + 32) / 5, "F\n\n");
                break;
            case 'K':
                printf("%.2f %s", temp, "K\n");
                printf("%.2f %s", temp - 273.15, "C\n");
                printf("%.2f %s", 9 * (temp - 273.15) / 5 + 32, "F\n\n");
                break;
            case 'F':
                printf("%.2f %s", temp, "F\n");
                printf("%.2f %s", 5 * (temp - 32) / 9, "C\n");
                printf("%.2f %s", 5 * (temp - 32) / 9 + 273.15, "K\n");
                break;
        }
    }

    return 0;
}
