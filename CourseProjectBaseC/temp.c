
#include "temp_functions.h"

FILE *f;

int main(int argc, char *argv[])
{
    opterr = 0;
    int option = 0;

    //printf("\nARG %d\n", argc);

    if (argc == 1)
    {
        hlp_func();
    }
    else if (argc == 3)
    {
        printf("\nError in specified arguments! Use the key '-h' to get help.\n");
    }
    else if (argc > 5)
    {
        printf("\nToo many arguments! Use the key '-h' to get help.\n");
        hlp_func();
    }
    else
    {
        while ((option = getopt(argc, argv, "hf:ym:")) != -1)
        {
            switch (option)
            {
            case 'h':
            {
                hlp_func();
                break;
            }
            case 'f':
            {
                f = fopen(optarg, "r");
                break;
            }

            case 'y':
            {
                stat_year(f);
                break;
            }

            case 'm':
            {
                stat_mounth(f, optarg);
                break;
            }
            case '?':
                printf("Unknown argument. Use the key '-h' to get help.\n");
                break;
            }
        }
    }
}