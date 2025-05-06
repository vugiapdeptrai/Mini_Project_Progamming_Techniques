#include <math.h>
#include "my_lib.h"

int my_atoi (char *a) {
    int i=0, j, m=18;
    int b = 0;
    while (a[i] != '\0') {  
        if ((int)a[i] >= 48 && (int)a[i] <= 57) {
            i++;
            continue;
        }
        if (a[0] == '-' && m == 18) {
            i++;
            m++;
            continue;
        }
        else if (a[i] == '.') {
            break;
        }
        else {
            return -1;
        }
    }
    j = i-1;
    i = 0;
    while (1) {
        if (a[0] == '-') {
            i = 1;
            j = j -1;
            while (1) {
                b = b - ((int)a[i] - 48) * pow(10,j);
                i++;
                j--;
                if (j<0) {
                    break;
                }
            }
            break;
        }
        else {
            b = b + ((int)a[i] - 48) * pow(10,j);
            i++;
            j--;
            if (j<0) {
                break;
            }
        }
    }
    return b;
}