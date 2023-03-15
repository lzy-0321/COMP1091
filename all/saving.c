#include <stdio.h>

int main(void) {
    int amount, time;
    double rate,  interest, savings;
   
    printf("Enter Principal Amount: ");
    scanf("%d", &amount);
    
    while (1) {

        printf("Enter interest rate and number of years: ");
        scanf("%lf %d", &rate, &time);
        
        if (amount <= 0 || time <= 0 || rate <= 0) {
            break;
        }
        else { 
            interest = (amount * time * rate) / 100;
            savings = interest + amount;
        
            printf("At %.1lf percent for %d years, your total savings is : %.2lf\n", rate, time, savings);
        }
    }
    return 0;
}
