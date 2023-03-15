//8/6/2021
//z5340468
//Compute the Euclidean Distance Between Two Vectors of Integers

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_LENGTH 1024

void vector_distance(int size, int array1[MAX_LENGTH], int array2[MAX_LENGTH]);

int main(int argc, char *argv[]) {
    
    int size;
    printf("Enter vector length: ");
    scanf("%d", &size);
    
    int array1[MAX_LENGTH], array2[MAX_LENGTH];
    
    printf("Enter vector 1: ");
    int i = 0;
    while (i < size) {
        scanf("%d", &array1[i]);
        i = i + 1;
    }
     printf("Enter vector 2: ");
    i = 0;
    while (i < size) {
        scanf("%d", &array2[i]);
        i = i + 1;
    }


   int x = 0, y = 0, z = 0;
   int sum = 0;
   while (x < size) {
       z = (array1[x] - array2[y]) * (array1[x] - array2[y]);
       sum = sum + z;
       x++;
       y++;
   }
   double result;
   result = sqrt(sum);
   printf("Euclidean distance = %lf\n", result);
   
   return 0;
}   
