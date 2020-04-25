/*
 * A text file holds information about a softball team. Each line has data
 * arranged as follows:
 *
 * 4 Jessie Joybat 5 2 1 1
 *
 * The first item is the player’s number, conveniently in the range 0–18. The
 * second item is the player’s first name, and the third is the player’s last
 * name. Each name is a single word. The next item is the player’s official
 * times at bat, followed by the number of hits, walks, and runs batted in
 * (RBIs). The file may contain data for more than one game, so the same player
 * may have more than one line of data, and there may be data for other players
 * between those lines. Write a program that stores the data into an array of
 * structures. The structure should have members to represent the first and last
 * names, the at bats, hits, walks, and RBIs (runs batted in), and the batting
 * average (to be calculated later). You can use the player number as an array
 * index. The program should read to end- of-file, and it should keep cumulative
 * totals for each player.
 *
 * The world of baseball statistics is an involved one. For example, a walk or
 * reaching base on an error doesn’t count as an at-bat but could possibly
 * produce an RBI. But all this program has to do is read and process the data
 * file, as described next, without worrying about how realistic the data is.
 *
 * The simplest way for the program to proceed is to initialize the structure
 * contents to zeros, read the file data into temporary variables, and then add
 * them to the contents of the corresponding structure. After the program has
 * finished reading the file, it should then calculate the batting average for
 * each player and store it in the corresponding structure member. The batting
 * average is calculated by dividing the cumulative number of hits for a player
 * by the cumulative number of at-bats; it should be a floating-point
 * calculation. The program should then display the cumulative data for each
 * player along with a line showing the combined statistics for the entire team.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 256

struct player {
    int number;
    char firstname[MAXLEN];
    char lastname[MAXLEN];
    int ab;
    int h;
    int b;
    int rbi;
    double avg;
};

int main (void)
{
    struct player team[19];
    struct player tmp;
    struct player team_all;
    FILE * fp;

    for (int i = 0; i < 19; i++)
    {
        team[i].number = i;
        team[i].ab = 0;
        team[i].h = 0;
        team[i].b = 0;
        team[i].rbi = 0;
        team[i].avg = 0;
    }
    
    if ((fp = fopen("data.txt", "r")) == NULL)
    {
        fprintf(stderr, "Error opening data file\n");
        exit(EXIT_FAILURE);
    }

    while (fscanf(fp, "%d %s %s %d %d %d %d", 
                &tmp.number,
                tmp.firstname,
                tmp.lastname,
                &tmp.ab,
                &tmp.h,
                &tmp.b,
                &tmp.rbi) == 7)
    {
        for (int i = 0; i < 19; i++)
        {
            if (team[i].number == tmp.number)
            {
                // If AB are 0, copy name
                if (team[i].ab == 0)
                {
                    strcpy(team[i].firstname, tmp.firstname);
                    strcpy(team[i].lastname, tmp.lastname);
                }
                team[i].ab += tmp.ab;
                team[i].h += tmp.h;
                team[i].b += tmp.b;
                team[i].rbi += tmp.rbi;
                break;
            }
        }
    }

    for (int i = 0; i < 19; i++)
    {
        team_all.ab += team[i].ab;
        team_all.h += team[i].h;
        team[i].b += team[i].b;
        team[i].rbi += team[i].rbi;
        team[i].avg = (double) team[i].h / (double) team[i].ab;
    }
    return 0;    
}

