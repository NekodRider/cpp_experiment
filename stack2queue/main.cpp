#include <cstdio>
#include <cstring>
#include "stack2queue.h"
int main(int argc, char *argv[])
{
    QUEUE *p;
    int i = 1, s = 0, j = 0;
    while (i < argc)
    {
        if (strcmp(argv[i], "-S") == 0)
        {
            i++;
            s = 0;
            for (j = 0; j < strlen(argv[i]); j++)
                s = s * 10 + (argv[i][j] - '0');
            p = new QUEUE(s);
            printf("S  %d  ", s);
            continue;
        }
        else if (strcmp(argv[i], "-C") == 0)
        {
            QUEUE *p_n = new QUEUE(*p);
            delete p;
            p = p_n;
            printf("C  ");
        }
        else if (strcmp(argv[i], "-I") == 0)
        {
            i++;
            while (i < argc && argv[i][0] >= '0' && argv[i][0] <= '9')
            {
                s = 0;
                for (j = 0; j < strlen(argv[i]); j++)
                    s = s * 10 + (argv[i][j] - '0');
                try
                {
                    (*p) << s;
                    i++;
                }
                catch (...)
                {
                    printf("I  E  ");
                    return 1;
                }
            }
            i--;
            printf("I  ");
        }
        else if (strcmp(argv[i], "-O") == 0)
        {
            int tmp;
            i++;
            s = 0;
            for (j = 0; j < strlen(argv[i]); j++)
                s = s * 10 + (argv[i][j] - '0');

            try
            {
                for (j = 0; j < s; j++)
                    (*p) >> tmp;
            }
            catch (...)
            {
                printf("O  E  ");
                return 1;
            }
            printf("O  ");
        }
        else if (strcmp(argv[i], "-A") == 0)
        {
            i++;
            s = 0;
            for (j = 0; j < strlen(argv[i]); j++)
                s = s * 10 + (argv[i][j] - '0');
            QUEUE *n_p = new QUEUE(*p);
            delete p;
            p = n_p;
            printf("A  ");
        }
        else if (strcmp(argv[i], "-N") == 0)
        {
            printf("N  %d", int(*p));
            i++;
            continue;
        }
        else if (strcmp(argv[i], "-G") == 0)
        {
            i++;
            s = 0;
            for (j = 0; j < strlen(argv[i]); j++)
                s = s * 10 + (argv[i][j] - '0');
            try
            {
                printf("G  %d  ", (*p)[s]);
                i++;
                continue;
            }
            catch (...)
            {
                printf("G  E  ");
                return 1;
            }
        }
        (*p).print();
        i++;
    }
    delete (p);
    return 0;
}
