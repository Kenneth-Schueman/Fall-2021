#include <stdio.h>
#include <math.h>
#define PI 3.141592653589

//./ds4rd-3 -d 054c:09cc -D DS4_USB -t -g -bt | ./lab7

int read_line(double* g_x, double* g_y, double* g_z, int* time, int* Button_T, int* Button_X, int* Button_S, int* Button_C);
double roll(double x_mag);
double pitch(double y_mag);
int scaleRadsForScreen(double rad);
void print_chars(int num, char use);
void graph_line(int number);

int main()
{

    double x, y, z;                             
    int b_Triangle, b_X, b_Square, b_Circle;    
    double roll_rad, pitch_rad;                 
    int scaled_value, t;  
    int triCounter = 0;

    do
    {
        read_line(&x, &y, &z, &t, &b_Triangle, &b_X, &b_Square, &b_Circle);
        if (b_Triangle == 1) { ///increment
            triCounter++;
        }
		
        if (triCounter % 2 == 0) { //roll
            graph_line(scaleRadsForScreen(roll(x)));
        }
        else { //pitch
            graph_line(scaleRadsForScreen(pitch(z)));
        }

        fflush(stdout);

    } while (b_Square != 1); //change for square

    return 0;

}


int read_line(double* g_x, double* g_y, double* g_z, int* time, int* Button_T, int* Button_X, int* Button_S, int* Button_C) {
    scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d", time, g_x, g_y, g_z, Button_T, Button_C, Button_X, Button_S);

    if (*Button_S == 1) {
        return 1;
    }

    else {
       return 0;
    }
}


double roll(double x_mag) {

    x_mag = ((x_mag >= 1) ? (1) : ((x_mag <= -1) ? (-1) : (x_mag)));
    return asin(x_mag); //x

}


double pitch(double y_mag) {

    y_mag = ((y_mag >= 1) ? (1) : ((y_mag <= -1) ? (-1) : (y_mag)));
    return asin(y_mag); //z

}


int scaleRadsForScreen(double rad) {

    //scales roll value
    return (int)(rad * (2/PI) * 39);

}


void print_chars(int num, char use) {

    //printf in this function
    //for num, print use character

    char str[80];
    for (int i = 0; i < 80; i++) {
        str[i] = ' ';

    }

    if (use == 'r') {
        for (int i = 40; i < num + 40; i++) {
            str[i] = use;
        }
    }

    else if (use == 'l') {
        for (int i = 40; i > 40 - num; i--) {
            str[i] = use;
        }
    }

    else {
        str[39] = use;
    } 
    printf("%s\n", str);
}


void graph_line(int number) {
    char character;
    int printNum = fabs(number);

    if (number < 0) {
        character = 'r';
    }

    else if (number > 0) {
        character = 'l';
    }

    else {
        character = '0';
    }

    print_chars(printNum, character);

}