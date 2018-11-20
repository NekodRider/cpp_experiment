#include "stack_op.h"

int main(int argc, char *argv[])
{
    STACK *p;
    int i = 1;
    while (i < argc)
    {
        if (strcmp(argv[i], "-S") == 0)
        {
            i++;
            int s = 0;
            for (int j = 0; j < strlen(argv[i]); j++)
                s = s * 10 + (argv[i][j] - '0');
            p = new STACK(s);
            printf("S  %d  ", p->size());
            continue;
        }
        else if (strcmp(argv[i], "-C") == 0)
        {
            p = new STACK(*p);
            printf("C  ");
        }
        else if (strcmp(argv[i], "-I") == 0)
        {
            i++;
            while (i < argc && argv[i][0] >= '0' && argv[i][0] <= '9')
            {
                int s = 0;
                for (int j = 0; j < strlen(argv[i]); j++)
                    s = s * 10 + (argv[i][j] - '0');
                try
                {
                    *p << s;
                    i++;
                }
                catch (...)
                {
                    printf("I  E");
                    return 0;
                }
            }
            i--;
            printf("I  ");
        }
        else if (strcmp(argv[i], "-O") == 0)
        {
            i++;
            int tmp, s = 0;
            for (int j = 0; j < strlen(argv[i]); j++)
                s = s * 10 + (argv[i][j] - '0');
            for (int j = 0; j < s; j++)
            {
                try
                {
                    *p >> tmp;
                }
                catch (...)
                {
                    printf("O  E");
                    return 0;
                }
            }
            printf("O  ");
        }
        else if (strcmp(argv[i], "-A") == 0)
        {
            i++;
            int s = 0;
            for (int j = 0; j < strlen(argv[i]); j++)
                s = s * 10 + (argv[i][j] - '0');
            STACK *q = new STACK(s);
            *q = *p;
            delete p;
            p = q;
            printf("A  ");
        }
        else if (strcmp(argv[i], "-N") == 0)
        {
            printf("N  %d", *p);
            i++;
            continue;
        }
        else if (strcmp(argv[i], "-G") == 0)
        {
            i++;
            int s = 0;
            for (int j = 0; j < strlen(argv[i]); j++)
                s = s * 10 + (argv[i][j] - '0');
            try
            {
                printf("G  %d  ", (*p)[s]);
                i++;
            }
            catch (...)
            {
                printf("G  E");
                return 0;
            }
            continue;
        }
        p->print();
        i++;
    }
    delete p;
    return 0;
}
