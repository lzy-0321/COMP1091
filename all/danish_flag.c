//z5340468
//3/7/2021
//Draw a Danish flag using ASCII characters

#include <stdio.h>
int main()
{
    int size;
    
    printf("Enter the flag size: ");
    scanf("%d", &size);
    
    int width = 9 * size;
    int height = 4 * size;
    

    int i = 1;

    while (i <= height) {
        int j = 1;
        while (j <= width) {
        
            //The rectangle has blank spaces beginning where
            // the col = 1/3 * width and row = 1/2 * height
            
            
            if ((j == width / 3) || (i == (height / 2) + 1) ||
            (i == height / 2) || (j ==
             (width / 3) + 1)) {
                printf(" ");
            }
            else {
                printf("#");
            } 
            
            j++;
        }
        printf("\n");
        i++;
    }
    return 0;
}
