#include <stdio.h>

int main(void) {    
   print_drink_type(60, 3);
   return 0;
}
void print_drink_type(int temperature, int shots_of_coffee) {
    if (temperature > 50) {
        if (shots_of_coffee > 0) {
            printf("That's Coffee!\n");
        } else if (shots_of_coffee == 0) {
            printf("That's Tea!\n");
        }
    } else {
        printf("That's a refreshing cool drink!\n");
    }
}


