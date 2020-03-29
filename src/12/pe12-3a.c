#include <stdio.h>

void get_info(int mode, double * p_distance, double * p_fuel)
{
    if (mode == 0)
    {
        printf("Enter distance traveled in kilometers: ");
        scanf("%lf", p_distance);
        printf("Enter fuel consumed in liters: ");
        scanf("%lf", p_fuel);
    }
    else
    {
        printf("Enter distance traveled in miles: ");
        scanf("%lf", p_distance);
        printf("Enter fuel consumed in gallons: ");
        scanf("%lf", p_fuel);
    }
    return;
}

void show_info(int mode, double distance, double fuel)
{
    if (mode == 0)
        printf("Fuel consumption is %lf liters per 100 km\n", fuel / distance * 100);
    else if (mode == 1)
        printf("Fuel consumption is %lf miles per gallon\n", distance / fuel);
    return;
}
