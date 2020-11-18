#ifndef CONVNET_H
#define CONVNET_H

typedef struct ConvNetInput
{
    int convImageDim;
    int convKernelDim;
    int **convImage;
    int **convKernel;
    int convStride;
    int fullyConnWeightsNum;
    int *fullyConnWeights;
} ConvNetInput;


typedef struct convParam{
        int start_x;
        int start_y;
        struct ConvNetInput conv;
} convParam;

typedef struct ConvNetOutput
{
    int convOutputDim;
    int **convOutput;
} ConvNetOutput;

int convNet(char *fileName);
void getData(FILE *inputFile, ConvNetInput *ConvNetInput);


void* printMatrix(void* param);
void* Convolve(void* param);
void* printOutputMatrix(void* param);


#endif