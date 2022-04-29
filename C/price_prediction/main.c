#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define Data 400                //Data used for training
#define testData 106            //Data to be tested
#define In 13
#define Out 1
#define Neuron 40
#define TrainC 400000
#define w_alta 0.1
#define v_alta 0.2

double d_in[Data][In];
double d_out[Data][Out];
double t_in[testData][In];
double t_out[testData][Out];
double pre[testData][Out];
double v[Neuron];
double y[Neuron];
double w[Out][Neuron];
double maxIn[In], minIn[In];
double maxOut[Out], minOut[Out];

void ReadData() {
    int i, j;
    FILE *fp;
//    printf("tag1\n");
    fp = fopen("../trainData.txt", "rb");                   //this address can and should be customized
    if (fp == NULL) {
        printf("Failed to open file trainData.txt, exit program.");
        exit(0);
    }
    for (i = 0; i < Data; i++) {
        for (j = 0; j < In; j++) {
            fscanf(fp, "%lf", &d_in[i][j]);
        }
        fscanf(fp, "%lf", &d_out[i][Out - 1]);
//        printf("Read\n");
    }
    fclose(fp);
}

void InitBPNetwork() {
    int i, j;
    srand((int) time(0));
    for (i = 0; i < In; i++) {
        minIn[i] = maxIn[i] = d_in[0][i];
        for (j = 0; j < Data; j++) {
            maxIn[i] = maxIn[i] > d_in[j][i] ? maxIn[i] : d_in[j][i];
            minIn[i] = minIn[i] < d_in[j][i] ? minIn[i] : d_in[j][i];
        }
    }
    for (i = 0; i < Out; i++) {
        minOut[i] = maxOut[i] = d_out[0][i];
        for (j = 0; j < Data; j++) {
            minOut[i] = minOut[i] < d_out[j][i] ? minOut[i] : d_out[j][i];
            maxOut[i] = maxOut[i] > d_out[j][i] ? maxOut[i] : d_out[j][i];
        }
    }
    for (i = 0; i < In; i++) {
        for (j = 0; j < Data; j++) {
            d_in[j][i] = (d_in = [j][i] - minIn[i])
        }
    }
}

int main() {
    ReadData();
//    printf("%lf", d_out[0][0]);
}
