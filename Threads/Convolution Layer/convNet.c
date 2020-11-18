#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#include "convNet.h"

void getData(FILE *inputFile, ConvNetInput *convNetInput)
{
    // Image input.
    fscanf(inputFile, "%d", &convNetInput->convImageDim);
    convNetInput->convImage = malloc(sizeof(int *) * convNetInput->convImageDim);
    for (int i = 0; i < convNetInput->convImageDim; i++)
    {
        (convNetInput->convImage)[i] = (int *) malloc(sizeof(int) * convNetInput->convImageDim);
        for (int j = 0; j < convNetInput->convImageDim; j++)
        {
            fscanf(inputFile, " %d", &convNetInput->convImage[i][j]);
        }
    }

    // Kernel Input.
    fscanf(inputFile, "%d", &convNetInput->convKernelDim);
    convNetInput->convKernel = malloc(sizeof(int *) * convNetInput->convKernelDim);
    for (int i = 0; i < convNetInput->convKernelDim; i++)
    {
        convNetInput->convKernel[i] = (int *) malloc(sizeof(int) * convNetInput->convKernelDim);
        for (int j = 0; j < convNetInput->convKernelDim; j++)
        {
            fscanf(inputFile, " %d", &convNetInput->convKernel[i][j]);
        }
    }

    fscanf(inputFile, "%d", &convNetInput->convStride);

    return;
}

int convNet(char *fileName){
    struct ConvNetInput convNetInput;
    FILE* fp;
    fp = fopen(fileName, "r");
    getData(fp, &convNetInput);
    /*
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
    */
    

    // Calculate Size of output based on image, kernel and stride
    int outputDimension = (convNetInput.convImageDim - convNetInput.convKernelDim)/(convNetInput.convStride) + 1;
    // Create an output array (CLOut) in heap
    int* CLOut[outputDimension];
    for(int i=0; i<outputDimension; i++){
        CLOut[i] = (int*)malloc(outputDimension*sizeof(int));
    }

    //Create a detachable thread for printing 2 input matrices (Image and kernel)
    pthread_t tid_print;  
    pthread_attr_t attr; 
    pthread_attr_init(&attr);
    pthread_create(&tid_print, &attr, printMatrix, &convNetInput);
    pthread_join(tid_print, NULL);

    // Create outputDimension*outputDimension (k^2) number of threads for computing output (CLOut) parallely

    /*
    For doing the convolution operation, we need 3 things in each iteration,
        1-> Image array and size
        2-> Kernel array and size
        3-> Stride
        4-> Starting point 

    The first 3 things (1,2,3) are there in the convNetInput structure
    But 4th one we have to set according to the iteration
    Therefore we need another structure for holding these 2 things together, so that it can be passed as param

    Therefore convParam structure id declared in convNet.h
    */

    struct convParam param_arr[outputDimension][outputDimension];

    int x = 0;
    int y = 0;
    for(int i=0; i<outputDimension; i++){
        for(int j=0; j<outputDimension; j++){
            param_arr[i][j].start_x = x;
            param_arr[i][j].start_y = y;
            param_arr[i][j].conv = convNetInput;

            x = x + convNetInput.convStride;
        }

        y = y + convNetInput.convStride;
        x = 0;
    }

    // Creating CL threads

    pthread_t tid[outputDimension][outputDimension];
    for(int i=0; i<outputDimension; i++){
        for(int j=0; j<outputDimension; j++){
            pthread_attr_t attr; 
            pthread_attr_init(&attr);
            pthread_create(&tid[i][j], &attr, Convolve, &param_arr[i][j]);
        }
    }

    // Joining Back all CL threads

    for(int i=0; i<outputDimension; i++){
        for(int j=0; j<outputDimension; j++){
            pthread_join(tid[i][j],(void *) &CLOut[j][i]);
        }
    }

    // Printing the output 
    struct ConvNetOutput cno;
    cno.convOutputDim = outputDimension;
    cno.convOutput = &CLOut[0];

    pthread_t tid_print_output;
    pthread_attr_t attr1; 
    pthread_attr_init(&attr1);
    pthread_create(&tid_print_output, &attr1, printOutputMatrix, &cno);
    pthread_join(tid_print_output, NULL);

    //create 1d array in heap (OneDOut)
    int *OneDOut = (int *)malloc(outputDimension*outputDimension*sizeof(int));

    return 0;
}

void* printMatrix(void* param){
    int** mat1;
    int** mat2;
    mat1 = ((struct ConvNetInput*) param)->convImage;
    mat2 = ((struct ConvNetInput*) param)->convKernel;
    int dim1 = ((struct ConvNetInput*) param)->convImageDim;
    int dim2 = ((struct ConvNetInput*) param)->convKernelDim;
    //detach thread
    pthread_detach(pthread_self());

    // print Image
    printf("Image Input : \n");
    for(int i=0; i<dim1; i++){
        for(int j=0; j<dim1; j++){
            printf("%d ", *(mat1[i] + j));
        }
        printf("\n");
    }

    // print Kernel
    printf("Kernel Input : \n");
    for(int i=0; i<dim2; i++){
        for(int j=0; j<dim2; j++){
            printf("%d ", *(mat2[i] + j));
        }
        printf("\n");
    }

}

void* printOutputMatrix(void* param){
    int** mat1;
    mat1 = ((struct ConvNetOutput*) param)->convOutput;
    int dim1 = ((struct ConvNetOutput*) param)->convOutputDim;
    char ask;

    //detach thread based on user input
        // Asking user input for deachable or not
    printf("Do you want output printing string to detach? [y/n] (smallcase): ");
    scanf("%c", &ask);

    if(ask == 'y'){
        pthread_detach(pthread_self());
    }

    // print CLOut
    printf("CLOut : \n");
    for(int i=0; i<dim1; i++){
        for(int j=0; j<dim1; j++){
            printf("%d ", *(mat1[i] + j));
        }
        printf("\n");
    }

}

void* Convolve(void* param){
    struct convParam *p = (struct convParam*) (param);
    int x = p->start_x;
    int y = p->start_y;
    struct ConvNetInput cni = p->conv;

    int** mat1 = cni.convImage;
    int** mat2 = cni.convKernel;
    // compute the convolution and store in 'val'
    int val = 0;
    for(int i=0; i<cni.convKernelDim; i++){
        for(int j=0; j<cni.convKernelDim; j++){
            val += (*(mat2[i] + j)) * (*(mat1[i+x] + j+y));
        }
    }
    return((void *) val);

}


