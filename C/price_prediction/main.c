#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define data 400                //data used for training
#define testData 106            //data to be tested
#define In 13
#define Out 1
#define Neuron 40
#define TrainC 400000
#define w_alta 0.1
#define v_alta 0.2

double d_in[data][In];
double d_out[data][Out];
double t_in[testData][In];
double t_out[testData][Out];
double pre[testData][Out];
double v[Neuron];
double y[Neuron];
double w[Out][Neuron];
double maxIn[In], minIN[In];
double maxOut[Out], minOut[Out];

void ReadData() {
    int i, j;
    FILE *fp;
//    printf("tag1\n");
    fp = fopen("trainData.txt", 'rb');
    if (fp == NULL) {
        printf("Failed to open file trainData.txt, exit program.");
        exit(0);
    }
    for (i = 0; i < data; i++) {
        for (j = 0; j < In; j++) {
            fscanf(fp, "%lf", &d_in[i][j]);
        }
        fscanf(fp, "%lf", &d_out[i][Out - 1]);
        printf("Read\n");
    }
    fclose(fp);
}

int main() {
    ReadData();
}
