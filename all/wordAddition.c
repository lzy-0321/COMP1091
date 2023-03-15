//z5340468
//18/5/2021
//Word Addition

#include <stdio.h>

int main(void) {
    
    int x;
    int y;
    
    printf("Please enter two integers: ");
    scanf("%d %d", &x, &y);

    if (-10 <= x && x < 0) printf("negative ");
    if (x == 0) printf("zero");
    else if (x == 1 || x == -1) printf("one");
    else if (x == 2 || x == -2) printf("two");
    else if (x == 3 || x == -3) printf("three");
    else if (x == 4 || x == -4) printf("four");
    else if (x == 5 || x == -5) printf("five");
    else if (x == 6 || x == -6) printf("six");
    else if (x == 7 || x == -7) printf("seven");
    else if (x == 8 || x == -8) printf("eight");
    else if (x== 9 || x == -9) printf("nine");
    else if (x == 10 || x == -10) printf("ten");
    else printf("%d", x); 

    printf(" + ");

    if (-10 <= y && y < 0) printf("negative ");
    if (y == 0) printf("zero");
    else if (y == 1 || y == -1) printf("one");
    else if (y == 2 || y == -2) printf("two");
    else if (y == 3 || y == -3) printf("three");
    else if (y == 4 || y == -4) printf("four");
    else if (y == 5 || y == -5) printf("five");
    else if (y == 6 || y == -6) printf("six");
    else if (y == 7 || y == -7) printf("seven");
    else if (y == 8 || y == -8) printf("eight");
    else if (y == 9 || y == -9) printf("nine");
    else if (y == 10 || y == -10) printf("ten");
    else printf("%d", y); 

    printf(" = ");

    int sum = x + y; 
    
    if (-10 <= sum && sum < 0) printf("negative ");
    if (sum == 0) printf("zero");
    else if (sum == 1 || sum == -1) printf("one");
    else if (sum == 2 || sum == -2) printf("two");
    else if (sum == 3 || sum == -3) printf("three");
    else if (sum == 4 || sum == -4) printf("four");
    else if (sum == 5 || sum == -5) printf("five");
    else if (sum == 6 || sum == -6) printf("six");
    else if (sum == 7 || sum == -7) printf("seven");
    else if (sum == 8 || sum == -8) printf("eight");
    else if (sum == 9 || sum == -9) printf("nine");
    else if (sum == 10 || sum == -10) printf("ten");
    else printf("%d", sum);

    printf("\n");
    return 0;
}
