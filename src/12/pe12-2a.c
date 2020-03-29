#include <stdio.h>

static int cur_mode;
static double distance;
static double fuel;

void set_mode(int mode)
{
    if (mode == 0)
        cur_mode = 0;
    else if (mode == 1)
        cur_mode = 1;
    else
        printf("Invalid mode specified. Mode %d used\n", cur_mode);
    return;
}

void get_info(void)
{
    /*
    char * distance_pre = "Enter distance traveled in ";
    char * fuel_pre = "Enter fuel consumed in ";
    if (cur_mode == 0)
    {
        char * distance_unit = "kilometers";
        char * fuel_unit = "liters";
    } 
    else if (cur_mode == 1)
    {
        char * distance_unit = "miles";
        char * fuel_unit = "gallons";
    }
    printf("%s%s: ", distance_pre, distance_unit);
    scanf("%lf", &distance);
    printf("%s%s: ", fuel_pre, fuel_unit);
    scanf("%lf", &fuel);
    */

    if (cur_mode == 0)
    {
        printf("Enter distance traveled in kilometers: ");
        scanf("%lf", &distance);
        printf("Enter fuel consumed in liters: ");
        scanf("%lf", &fuel);
    }
    else
    {
        printf("Enter distance traveled in miles: ");
        scanf("%lf", &distance);
        printf("Enter fuel consumed in gallons: ");
        scanf("%lf", &fuel);
    }
    return;
}

void show_info(void)
{
    double consumption;
    if (cur_mode == 0)
        printf("Fuel consumption is %lf liters per 100 km\n", fuel / distance * 100);
    else if (cur_mode == 1)
        printf("Fuel consumption is %lf miles per gallon\n", distance / fuel);
    return;
}
