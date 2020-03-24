/*
 * Write a program that requests the download speed in megabits per second (Mbs)
 * and the size of a file in megabytes (MB). The program should calculate the 
 * download time for the file. Note that in this context one byte is eight bits.
 * Use type float, and use / for division. The program should report all three 
 * values (download speed, file size, and download time) showing two digits to
 * the right of the decimal point, as in the following:
 *  At 18.12 megabits per second, a file of 2.20 megabytes downloads in 0.97 
 *  seconds.
 */
#include <stdio.h>

int main (void)
{
    float download_speed;
    float file_size;
    
    printf("Enter the download speed (Mbps):\n");
    scanf("%f", &download_speed);
    printf("Enter the file size (MB):\n");
    scanf("%f", &file_size);

    printf("At %.2f megabits per second, a file of %.2f megabytes "
            "downloads in %.2f seconds\n", download_speed, file_size,
            file_size * 8 / download_speed);
    return 0;
}
