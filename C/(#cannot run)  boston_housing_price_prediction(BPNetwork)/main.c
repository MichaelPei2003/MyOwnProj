#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define Data 400                //Data used for training
#define testData 107            //Data to be tested
#define In 13
#define Out 1
#define Neuron 40
#define TrainC 4000
#define w_alta 0.1
#define v_alta 0.2

double d_in[Data][In];
double d_out[Data][Out];
double t_in[testData][In];
double t_out[testData][Out];
double pre[testData][Out];
double v[Neuron][In];
double y[Neuron];
double w[Out][Neuron];
double maxIn[In], minIn[In];
double maxOut[Out], minOut[Out];
double outputData[Out];
double dw[Out][Neuron], dv[Neuron][In];
double mse;
double rmse;

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
            d_in[j][i] = (d_in[j][i] - minIn[i]);
        }
    }
    for (i = 0; i < Out; i++) {
        for (j = 0; j < Data; j++) {
            d_out[j][i] = (d_out[j][i] - minOut[i]) / (maxOut[i] - minOut[i]);
        }
    }
    for (i = 0; i < Neuron; i++) {
        for (j = 0; j < In; j++) {
            v[i][j] = rand() * 2 / RAND_MAX - 1;
            dv[i][j] = 0;
        }
    }
    for (i = 0; i < Out; i++) {
        for (j = 0; j < Neuron; j++) {
            w[i][j] = rand() * 2 / RAND_MAX - 1;
            dw[j][i] = 0;
        }
    }
}

void Comput(int var) {
    double sum;
    int i, j;
    for (i = 0; i < Neuron; i++) {
        sum = 0;
        for (j = 0; j < In; j++) {
            sum += v[i][j] * d_in[var][j];
        }
        y[i] = 1 / (1 + exp(-1 * sum));
    }
    for (i = 0; i < Out; i++) {
        sum = 0;
        for (j = 0; j < Neuron; j++) {
            sum += w[i][j] * y[j];
        }
        outputData[i] = 1 / (1 + exp(-1 * sum));
    }
}

void BackUpdate(int var) {
    double t;
    int i, j;
    for (i = 0; i < Neuron; i++) {
        t = 0;
        for (j = 0; j < Out; j++) {
            dw[j][i] = w_alta * (d_out[var][j] - outputData[j]) * outputData[j] * (1 - outputData[j]) * y[i];
            w[j][i] += dw[j][i];
            t += (d_out[var][j] - outputData[j]) * outputData[j] * (1 - outputData[j]) * w[j][i];
        }
        for (j = 0; j < In; j++) {
            dv[i][j] = v_alta * t * y[i] * (1 - y[i]) * d_in[var][i];
            v[i][j] += dv[i][j];
        }
    }
}

void TrainNetwork() {
    int cnt = 1;
    int i, j;
    do {
        mse = 0;
        for (i = 0; i < Data; i++) {
            Comput(i);
            BackUpdate(i);
            for (j = 0; j < Out; j++) {
                double tmp1 = outputData[j] * (maxOut[0] - minOut[0]) + minOut[0];
                double tmp2 = d_out[i][j] * (maxOut[0] - minOut[0]) + minOut[0];
                mse += (tmp1 - tmp2) * (tmp1 - tmp2);
            }
        }
        mse = mse / Data * Out;
        if (cnt % 1000 == 0) {
            printf("%d  %lf", cnt, mse);
        }
        cnt++;
    } while (cnt <= TrainC && mse >= 1);
    printf("Training finished.");
}

void TestNetwork() {
    FILE *fp;
    int i, j, k;
    if ((fp = fopen("../testData.txt", "rb")) == NULL) {
        printf("Failed to open file testData.txt, exit program.");
        exit(0);
    }
//    printf("tag");
    for (i = 0; i < testData; i++) {
        for (j = 0; j < In; j++) {
            fscanf(fp, "%lf", &t_in[i][j]);
            printf("tag1\n");
        }
        printf("tag2\n");
        fscanf(fp, "%lf", &t_out[i][Out-1]);
        printf("tag3\n");
    }
    fclose(fp);
//    printf("tag1");
    double sum;
    for (i = 0; i < In; i++) {
        for (j = 0; j < testData; j++) {
            t_in[j][i] = (t_in[j][i] - minIn[i]) / (maxIn[i] - minIn[i]);
        }
    }
//    printf("tag2");
    for (k = 0; k < testData; k++) {
        for(i = 0; i < Neuron; i++) {
            sum = 0;
            for(j = 0; j < In; j++){
                sum += v[i][j]*t_in[k][j];
            }
            y[i] = 1/(1+exp(-1*sum));
        }
        sum = 0;
        for(j = 0; j < Neuron; j++){
            sum+=w[0][j]*y[j];
        }
        pre[k][0] = 1/(1+exp(-1*sum))*(maxOut[0]-minOut[0])+minOut[0];
        printf("No.%d  prediction_val:%.2lf  actual_val:%.2lf\n", k+1, pre[k][0], t_out[k][0]);
    }
    rmse = sqrt(rmse/testData);
    printf("rmse: %.4lf\n", rmse);
}

int main() {
    ReadData();
//    printf("%lf\n", d_out[0][0]);
    InitBPNetwork();
    TrainNetwork();
    TestNetwork();
//    printf("%lf", t_out[0][0]);
    return 0;
}
