#include <iostream>

int main(int argc, char **argv)
{
    int *array = new int[10];
    int **a2d = new int *[50];

    for (int i = 0; i < 50; i++)
    {
        a2d[i] = new int[10];
    }

    return 0;
}