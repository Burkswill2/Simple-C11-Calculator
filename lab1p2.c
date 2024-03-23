#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <float.h>


/*
Calculates the sum of elements in a given dataset.
If not fetching for average calculation, prints the sum.
Parameters: dataSet (array of floats), dataSetSize (int), fetchingAverage (bool)
Returns: sum (float)
*/
float getSum(float dataSet[], int dataSetSize, bool fetchingAverage)
{
    float sum = 0.0;
    for(int i=0;i<dataSetSize;i++)
    {
        sum += dataSet[i];
    }
    if (!fetchingAverage) printf("Sum: %f\n", sum);
    return sum;
}

/*
Calculates and prints the average of the dataset.
Parameters: dataSet (array of floats), dataSetSize (int)
*/
void getAverage(float dataSet[], int dataSetSize)
{
    float average = getSum(dataSet, dataSetSize, true)/ (float)dataSetSize;
    printf("Average: %f\n", average);
}

/*
Finds and prints the maximum value in the dataset.
Parameters: dataSet (array of floats), dataSetSize (int)
*/
void getMaximum(float dataSet[], int dataSetSize)
{
    float maximum = FLT_MIN;
    for(int i=0;i<dataSetSize;i++)
    {
        maximum = maximum > dataSet[i] ? maximum : dataSet[i];
    }
    printf("Maximum: %f\n", maximum);
}

/*
Finds and prints the minimum value in the dataset.
Parameters: dataSet (array of floats), dataSetSize (int)
*/
void getMinimum(float dataSet[], int dataSetSize)
{
    float minimum = FLT_MAX;

    for(int i=0;i<dataSetSize;i++)
    {
        minimum = minimum < dataSet[i] ? minimum : dataSet[i];
    }
    printf("Minimum: %f\n", minimum);
}

/*
Prints all values in the dataset.
Parameters: dataSet (array of floats), dataSetSize (int)
*/
void printDataSet(float dataSet[], int dataSetSize)
{
    for(int i=0;i<dataSetSize;i++)
    {
        printf("%f\n", dataSet[i]);
    }
}

/*
Prints a message and exits the program.
*/
void exiting(void)
{
    printf("Exiting.\n");
}

/*
Prints an error message for invalid choices.
*/
void errorMessage(void)
{
    printf("Invalid entry.\n");
}

/*
Handles the user's choice of operation on the dataset.
Parameters: choice (int), dataSet (array of floats), dataSetSize (int)
*/
void handleChoice(int choice, float dataSet[], int dataSetSize) {
    switch (choice)
    {
        case 1:
            getSum(dataSet, dataSetSize, false);
            printf("\n");
            break;
        case 2:
            getAverage(dataSet, dataSetSize);
            printf("\n");
            break;
        case 3:
            getMaximum(dataSet, dataSetSize);
            printf("\n");
            break;
        case 4:
            getMinimum(dataSet, dataSetSize);
            printf("\n");
            break;
        case 5:
            printDataSet(dataSet, dataSetSize);
            printf("\n");
            break;
        case 6:
            exiting();
            break;
        default:
            errorMessage();
            printf("\n");
            break;
    }
}

/*
Displays the menu of options and handles user input.
Parameters: dataSet (array of floats), dataSetSize (int)
*/
void menu(float dataSet[], int dataSetSize)
{
    int choice = -1;
    while (choice != 6)
    {
        printf("Enter a number to choose one of the following options: \n");
        printf("1. Calculate the sum of all the values.\n");
        printf("2. Calculate the average of all the values.\n");
        printf("3. Find the maximum value.\n");
        printf("4. Find the minimum value.\n");
        printf("5. Print the values in the data set.\n");
        printf("6. Exit the program.\n");
        scanf("%d", &choice);
        handleChoice(choice, dataSet, dataSetSize);
    }
}

/*
Initiates user input for the dataset and calls the menu function.
Parameters: dataSet (array of floats), dataSetSize (int)
*/
void input(float dataSet[], int dataSetSize)
{
    for(int i=0;i<dataSetSize;i++)
    {
        printf("Enter a value: ");
        scanf("%f", &dataSet[i]);
    }
    menu(dataSet, dataSetSize);
}

/*
 * Dynamically allocates memory for the data set array.
 * Parameters: **dataSetPtr (float), dataSetSize (int)
 */
void setDataSetPtr(float **dataSetPtr, int dataSetSize)
{
    *dataSetPtr = (float*)calloc(dataSetSize, sizeof(float));

   if (*dataSetPtr == NULL) {
       fprintf(stderr, "Memory allocation error \n");
       exit(EXIT_FAILURE);
   }
}

/*
 * Prompts and validates the dataset size input from the user.
 * Parameter: dataSetSize (int*)
 */
void setDataSetSize(int *dataSetSize)
{
    while (*dataSetSize < 1)
    {
        printf("Enter the size of the dataset:");
        scanf("%d", dataSetSize);
    }
}

int main(void)
{
    /*
     * Init data
     */
    float *dataSetPtr = NULL;
    int dataSetSize = 0;
    setDataSetSize(&dataSetSize);
    setDataSetPtr(&dataSetPtr, dataSetSize);

    /*
     * Handle Application
     */
    input(dataSetPtr, dataSetSize);
}
