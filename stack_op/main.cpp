#include <cstdio>
#include <cstring>
#include "stack_op.h"
int main(int argc, char *argv[])
{
    STACK *p[100];
    int i = 1, s = 0, j = 0, p_index=0;
    while (i < argc)
    {
        if(p_index==98){
            printf("E  ");
        }
        if (strcmp(argv[i], "-S") == 0)
        {
            i++;
            s = 0;
            for (j = 0; j < strlen(argv[i]); j++)
                s = s * 10 + (argv[i][j] - '0');
            STACK a(s);
            p[p_index]=&a;
            printf("S  %d  ", (*p[p_index]).size());
            continue;
        }
        else if (strcmp(argv[i], "-C") == 0)
        {
            STACK b(*p[p_index]);
            p_index++;
            p[p_index]=&b;
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
                if ((*p[p_index]).size()==int(*p[p_index]))
                {
                    printf("I  E");
                    return 0;
                }
                *p[p_index]<<s;
                i++;
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
            for (j = 0; j < s; j++)
            {
                if(int(*p[p_index])==0){
                    printf("O  E");
                    return 0;
                }
                *p[p_index]>>tmp;
            }
            printf("O  ");
        }
        else if (strcmp(argv[i], "-A") == 0)
        {
            i++;
            s = 0;
            for (j = 0; j < strlen(argv[i]); j++)
                s = s * 10 + (argv[i][j] - '0');
            STACK c(s);
            p[p_index+1]=&c;
            (*p[p_index+1])=(*p[p_index]);
            p_index++;
            printf("A  ");
        }
        else if (strcmp(argv[i], "-N") == 0)
        {
            printf("N  %d", int(*p[p_index]));
            i++;
            continue;
        }
        else if (strcmp(argv[i], "-G") == 0)
        {
            i++;
            s = 0;
            for (j = 0; j < strlen(argv[i]); j++)
                s = s * 10 + (argv[i][j] - '0');
            if (s > int(*p[p_index]) - 1)
            {
                printf("G  E");
                return 0;
            }
            printf("G  %d  ", (*p[p_index])[s]);
            i++;
            continue;
        }
        (*p[p_index]).print();
        i++;
    }
    for(i=0;i<=p_index;i++){
        delete(p[p_index]);
    }
    return 0;
}
