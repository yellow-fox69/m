#include <stdio.h>
#define MAX_ITEMS 100
double computeMaxValue(double W, double weight[], double value[], double ratio[], int nItems);
int getNextItem(double weight[], double value[], double ratio[], int nItems);
int main() {
    int nItems;
    double W;
    double weight[MAX_ITEMS];
    double value[MAX_ITEMS];
    double ratio[MAX_ITEMS];
    printf("Enter the number of items: ");
    scanf("%d", &nItems);
    printf("Enter the weights of the items:\n");
    for (int i = 0; i < nItems; i++) {
        scanf("%lf", &weight[i]);
    }
    printf("Enter the values/profits of the items:\n");
    for (int i = 0; i < nItems; i++) {
        scanf("%lf", &value[i]);
    }
    for (int i = 0; i < nItems; i++) {
        ratio[i] = value[i] / weight[i];
    }
    printf("Enter the Capacity of the knapsack: ");
    scanf("%lf", &W);
    printf("\nThe maximum value in a knapsack of capacity %.2f is: %.2f\n", W,
           computeMaxValue(W, weight, value, ratio, nItems));
    return 0;
}
double computeMaxValue(double W, double weight[], double value[], double ratio[], int nItems) {
    double cW = 0; 
    double cV = 0; 
    printf("\nItems considered are: ");
    while (cW < W) {
        int item = getNextItem(weight, value, ratio, nItems); 
        if (item == -1) {
            break;
        }
        printf("%d ", item + 1);  
        if (cW + weight[item] <= W) {
            cW += weight[item];
            cV += value[item];
            ratio[item] = 0; 
        } else {
            cV += (ratio[item] * (W - cW)); 
            cW += (W - cW);
            break; 
        }
    }
    return cV;
}
int getNextItem(double weight[], double value[], double ratio[], int nItems) {
    double highest = 0;
    int index = -1;
    for (int i = 0; i < nItems; i++) {
        if (ratio[i] > highest) {
            highest = ratio[i];
            index = i;
        }
    }
    return index;
}