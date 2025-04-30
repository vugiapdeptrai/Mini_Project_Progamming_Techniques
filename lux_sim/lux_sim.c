#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "my_lib.h" //Thư viện xử lí xâu thành số nguyên

//Xử lí số liệu
int result_processing (int n, int s, int i) { 
    float min = 0.1, max = 100000, value;
    FILE *data = fopen("data.csv", "w");
    fprintf(data, "id,time,value \n");
    time_t now = time(NULL);
    time_t sec = now;
    char time[25];
    struct tm *t = localtime (&now);
    strftime(time, sizeof(time), "%Y:%m:%d %H:%M:%S", t);
    while (1) {
        if (sec > i*3600 + now) {
            break;
        }
        for (int j = 1; j<=n; j++) {
            value = ((float)rand() / RAND_MAX) * (max - min) + min;
            fprintf(data, "%d,%s,%.2f \n", j, time, value);
        }
        sec = sec + s;
        struct tm *t = localtime (&sec);
        strftime(time, sizeof(time), "%Y:%m:%d %H:%M:%S", t);
    }
    return 0;
}

int main (int argc, char *argv[]) {

    //Giá trị mặc định
    int num_sensors = 1;
    int sampling = 60;
    int interval = 24;

    //Kiểm tra điều kiện của đầu vào
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-n") == 0) {
            if (my_atoi(argv[i+1]) <= 0) {
                printf("Invalid number of sensors. Please try again.");
                return 1;
            }
            else {
                i++;
                num_sensors = my_atoi(argv[i]);
            }
        }
        else if (strcmp(argv[i], "-s") == 0) {
            if (my_atoi(argv[i+1]) < 1) {
                printf("Invalid sampling time. Please try again.");
                return 2;
            }
            else {
                i++;
                sampling = my_atoi(argv[i]);
            }
        }
        else if (strcmp(argv[i], "-i") == 0) {
            if (my_atoi(argv[i+1]) <= 0) {
                printf("Invalid sampling interval. Please try again.");
                return 3;
            }
            else {
                i++;
                interval = my_atoi(argv[i]);
            }
        }
        else {
            printf("Invalid input. Please try again.");
            return 0;
        }
    }

    //Xử lí đầu vào
    result_processing(num_sensors, sampling, interval);
    return 0;
}