 /**
 * @file elves.c
 * @author Patrik Hermansson (hermansson.patrik@gmail.com)
 * @brief Advent Of Code 2002, day 1
 * Input is a given list with Elfs that carries food with various calories. 
 * Each Elf has different amount of food items, and each food item has a different amount of calories. 
 * The task is to find how many calories the Elf who carries the most calories is carrying. 
 * Each Elf in the list is separated by an empty row. 
 * So we read the list line by line and adds the calories carried by each Elf. Then we save the 
 * highest calorie count and present it to the user. 
 * 
 * @version 0.1
 * @date 2022-12-01
 * 
 * @copyright Copyright (c) Patrik Hermansson 2022
 * 
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tot_cal, tot_cal_max = 0;
    FILE * fp;
    char str[10];
    char *ptr;
    long ret;
    short elf_no=1;

    fp = fopen("data/input", "r");
    if(fp == NULL) 
    {
        perror("Error opening file");
        return(-1);
    }
    while( fgets (str, 60, fp)!=NULL ) 
    {
        ret = strtol(str, &ptr, 10);    // String to int
        tot_cal += ret;

        if(str[0]=='\n')    // An empty line
        {
            printf ("Elf no: %d, total calories: %d\n", elf_no, tot_cal);
            if(tot_cal > tot_cal_max)
                tot_cal_max = tot_cal;
            tot_cal=0;
            elf_no++;
        }
    }
    printf ("totCal: %d\n", tot_cal);   // Do not miss the last one!
    fclose(fp);
    printf ("Elf no %d has most calories: %d\n", elf_no, tot_cal_max);
    return 0;
}