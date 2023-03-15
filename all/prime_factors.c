//2/5/2021
//z5340468
//Factorise a Number to Primes

#include <stdio.h>

int isPrime(int i) {

    int counter = 2;
    int result = 1;
    while (counter < i) {
        if (i % counter == 0) {
            result = 0;
        }
        counter++;
    }
    return result;
}

int main() {
    int number;
    printf("Enter number: ");
    scanf("%d", &number);

    int _number = number; 
    int counter = 2;
    int print = 0; 
    while (counter < _number + 1) {
        if (isPrime(counter) && _number % counter == 0 && counter != number) {
            if (!print) {
                print = 1;
                printf("The prime factorization of %d is:\n", number);
            } 
            else { 
                printf(" * "); 
            } 
            printf("%d", counter); 
            _number /= counter; 
        } 
        else {
            counter++;
        }
    }
    if (print) {
        printf(" = %d\n", number);
    } else {
        printf("%d is prime\n", number);
    }

    return 0;
}
