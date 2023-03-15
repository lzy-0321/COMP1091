#include <stdio.h>
#define MIN_RATING 7
int main(void) {

int cat_rating;
int dog_rating;

// input is: 8 10
scanf("%d %d", &cat_rating, &dog_rating);
char name[50] = "Tom";

if (dog_rating < MIN_RATING || cat_rating < MIN_RATING) {
    printf("%s is no fun.", name);
} else if (cat_rating > dog_rating) {
    printf("%s prefers cats.", name);
} else if (dog_rating > cat_rating) {
    printf("%s prefers dogs.", name);
} else {
    printf("%s can't decide.", name);
}

    return 0;
}
