#include<stdio.h>
#include<stdlib.h>
void *training_data_generate(int *Numbers)
{
    printf("Generating Training Data : ");
    for (int i = 0; i < 10; i++)
    {
        Numbers[i]=i+1;
    }
    return Numbers;
}
float weight_generate()
{
    // srand(time(NULL));
    // int weight;
    // weight = rand() % 10;
    // return weight;
    float weight;
    weight = 0.0;
    return weight;
}
int generate_correct_values(int input)
{
    int corr_out;
    if (input >= 5)
    {
        corr_out = 1;
    } else {
        corr_out = 0;
    }
    return corr_out;
}
// int training_algorithm(int input,int corr_out)
// {
//     int new_weight;
//     if (input == corr_out)
//     {
        
//     }
//     else
//     {

//     }
// }
int neurone(int input,float weight)
{
    int output;
    //float up_count;
    if (((input*weight) - 1) > 0)
    {
        output = 1;
    }
    else
    {   
        output = 0;
    }
    //printf("\n[nurone] weight = %f [nurone] output = %d",weight);
    return output;
    //training neurone

}
//void without_train()
int main()
{
    printf("\\..Artificial Neurone Program../ \n");
    int *trdata;
    float wdata;
    int input_data = 0;
    int output = 0;
    int return_array[10];
    int corr_out[10];
    int Count;
    float wdatanew = 0.0;
    Count = 0;
    int testx = 0;
    wdata = 0.0;
    //int *TD[10];
    int Numbers[10];
    int correct_check[256];
    //wdata = weight_generate();
    trdata = training_data_generate(Numbers);
    //for (int i = 0; i < 10; i ++){ trdata[i] = training_data_generate()[i]; }
    //printf("here");
    printf("Generating Training Data...\n");
    for (int i = 0; i < 9; i++){ printf("%d",trdata[i]); }
    printf("\nWeight = %d", wdata);
    printf("\nFeeding Data to known algorithm and getting output...\n");
    for (int i = 0; i < 9; i++){ corr_out[i] = generate_correct_values(trdata[i]); printf("\n TD[%d] :  ND [%d] \n",trdata[i],corr_out[i]); }
    printf("\nFeeding Data to neurone and getting output...\n");
    for (int i = 0; i < 9; i++){ return_array[i] = neurone(trdata[i], wdatanew); printf("\n TD[%d] :  ND [%d] \n",trdata[i],return_array[i]); }
    system("read -p Press any key to continue....");
    while (Count < 8) 
    {
         printf("\nComparing outputs...\n");
         for(int i = 0; i < 9; i++)
         {
            if (return_array[i] == corr_out[i])
            {
                correct_check[i] = 1;
            }
            else
            {
                correct_check[i] = 0;
            }
         }
         for(int i = 0; i < 9; i++)
         {
            if (correct_check[0] == 1 && correct_check[1] == 1 && correct_check[2] == 1 && correct_check[3] == 1 && correct_check[4] == 1 && correct_check[5] == 1&& correct_check[6] == 1 && correct_check[7] == 1 && correct_check[8] == 1)
            {
                printf("\nOutputs matched !\n");
                for (int i = 0; i < 9; i++){ printf("\nNEURON PREDICTION [%d] = %d : Weight = [%f]\n",i,return_array[i],wdatanew);}
                printf("\nNeuron Trained !\n");
                printf("\nInput Any Number between 0 - 10 to predict its greater or less than 5 : ");
                scanf("%d",&input_data);
                printf("\nPrediction loading...");
                output = neurone(input_data, wdatanew);
                printf(": [%d]\n",output);
                if(output > 0)
                {
                    printf("\nNumber you enterd is greater than 5\n\n");
                }
                else{
                    printf("\nNumber you enterd is less than 5\n\n");
                }
                system("read -p Press any key to continue...");
                Count = 10;
            }
            else
            {
                printf("Predicted output vs True Output Missmatch !...\n");
                printf("RECALIBRATING...\n");
                // testx = testx+1;
                // wdatanew = wdatanew + (1/10);
                wdatanew = wdatanew + 0.001;
                printf("%f",wdatanew);
                for (int i = 0; i < 9; i++){ return_array[i] = neurone(trdata[i], wdatanew); printf("\n TD[%d] :  ND [%d] : WEIGHT [%f] \n",trdata[i],return_array[i],wdatanew); }
                Count = 0;
            }
         }
    }
    return 0;
}


// Zerone Brianstorm AKA Ometh Abeyrathne, 2020
