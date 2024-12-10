//
// Created by 2907568338 on 2024/10/23.
//

#include <stdio.h>

int main(void)
{
    int N  = 0;

    scanf("%d",&N);




    for (int k = 1;k <= N;k++)
    {
        for (int j = 1;k >= j;j++)
        {
            printf("%-.1dx%-.1d=%-2.1d",j,k,j * k);

            if (k > j)
            {
                printf(" ");
            }
        }
        printf("\n");

    }



    return 0;
}