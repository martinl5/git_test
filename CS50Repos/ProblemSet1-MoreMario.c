#include <cs50.h>
#include <stdio.h>
int get_height();
void print_pyramids(int n);

int main(void)
{
    int height = get_height();
    print_pyramids(height);
}

int get_height()
{
    int n;
    do
    {
        n = get_int("What's the height of the pyramids, from 1 - 8\n");
    } while( n < 1 || n > 8);

    return n;
}
void print_pyramids(int height)
{
    for(int i = 1; i < height+1; i++)
    {
        for(int x = 0; x < height-i; x++)
        {
            printf(" ");
        }

        for(int z = 0; z < i; z++)
        {
            printf("#");
        }
        printf("  ");
        for(int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}