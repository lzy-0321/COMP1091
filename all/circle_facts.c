//1/6/2021
//z5340468
//Fun facts about Circles

#include <stdio.h>
#include <math.h>

#define M_PI 3.14159265358979323846/*pi*/

int main(void) {
    double radius, area(double radius), circumference(double radius), diameter(double radius);
    
    printf("Enter circle radius:");
    scanf("%lf", &radius);
    
    printf("Area          = %lf\n", area(radius));
    printf("Circumference = %lf\n", circumference(radius));
    printf("Diameter      = %lf\n", diameter(radius));
    
    return 0;
}

double area(double radius) {
    return M_PI * radius *radius;
}    

double circumference(double radius) {
    return M_PI * radius * 2;
}  

double diameter(double radius) {
    return 2 *radius;
}      
