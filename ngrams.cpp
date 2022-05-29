#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <stdlib.h>

main ()
{
    setlocale(LC_ALL,"rus");
    char str[15000];        //Текст
    char str1[15000];       //Отформатированный текст
    char b;                 //Понадобится для смены регистра
    int count[26];
    int count1;
    int a, j, i, n, k, x, z;    //Индексы
    int num = 0;            //Номер буквы в алфавите
    int mass[676];          //биграммы
    int **mas;              //биграммы
    int mass1[17576];       //триграммы

    printf ("Вставьте текст:\n");
    gets(str);

    for (i = 0; i < 26; i ++ )
        count[i] = 0;

    for (i = 0; i < strlen(str); i ++ )
    {
        num = -1;
        if ( str[i] >= 'a' && str[i] <='z' )
            num = str[i]-'a';
        if ( str[i] >= 'A' && str[i] <='Z' )
            num = str[i]-'A';
        if (num >= 0)
            count[num] ++;
    }

    a=0;

    printf("\nТолько буквы:\n");
    for (i = 0 ; i < strlen(str); i ++ )
    {
        if ((str[i] >= 'a' && str[i] <='z')||(str[i] >= 'A' && str[i] <='Z')||(str[i] == ' '))
        {
            if(str[i] >= 'A' && str[i] <='Z')       //Меняем регистр
            {
                b = str[i];
                str[i]=(char)tolower(b);
            }
            str1[a]=str[i];
            printf("%c", str1[a]);
            a=a+1;
        }
    }


    printf("\n\nМонограммы:\n");
    for (i = 0; i < 26; i ++ )
    {
        if (count[i] > 0)
            printf("%c - %d\n", 'A'+i, count[i]);
    }

//////////////////////////////////  БИГРАММЫ    //////////////////////////////////////////
    printf("\nБиграммы:\n");                                                            //
    for (a = 0 ; a < 675; a++ )                                                         //
        mass[a]=0;                                                                      //
                                                                                        //
    mas=(int**)malloc(26*sizeof(int*));
    for(i=0; i<26; i++)
        {
            mas[i]=(int*)malloc(26*sizeof(int));
        }

//      a = 97  b=98 .... z=123

    n=0;

    for (i=97; i<123; i++)
        for (j=97; j<123; j++)
        {
            for (a = k ; a < strlen(str)-1; a ++ )
            {
                if ((str1[a]==i) && (str1[a+1] == j))
                    mass[n]=mass[n] + 1;
            }
            n=n+1;
        }

    n=0;

    printf("     ");
    for (i=0; i<26; i++)
        printf("%c  ", 'A'+i);
    printf("\n    ");
    for (i=0; i<26; i++)
        printf("__ ");

    for (i=0; i<26; i++)
    {
        printf("\n%c  |",'A'+i);
        for (j=0; j<26; j++)
        {
            mas[i][j]=mass[n];
            n=n+1;

            if (mas[i][j]<1)
                printf("__|");
            if (mas[i][j]<10&&mas[i][j]>0)
                printf("_%d|",mas[i][j]);
            if (mas[i][j]>9)
                printf("%d|",mas[i][j]);
        }                                                                   //
    }                                                                       //
                                                                            //
//////////////////////////////////////////////////////////////////////////////
 printf("\n\nТриграммы:\n");                                               //
                                                                            //
    for (a = 0 ; a < 17576; a++ )                                           //
        mass1[a]=0;

    n=0;
    k=97;

    for (i=97; i<123; i++)
        for (j=97; j<123; j++)
            for (k=97; k<123; k++)
            {
                for (a = 0 ; a < strlen(str)-1; a ++ )
                {
                    if ((str1[a]==i) && (str1[a+1] == j) && (str1[a+2] == k))
                        mass1[n]=mass1[n] + 1;
                }
                if (mass1[n]>3)                     //Частота повторения
                    printf("%c %c %c = %d\n",i, j, k, mass1[n]);
                n=n+1;
            }
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////

    for(i=0; i<26; i++)
        count[i]=0;

        printf ("\nВыберите начало отрывка:\n");
        scanf("%d", &x);
        printf ("\nВведите длину отрывка:\n");
        scanf("%d", &z);


    for ( int i = x; i < x+z; i ++ )
    {
        num = -1;
        if ( str[i] >= 'a' && str[i] <='z' )
            num = str[i]-'a';
        if ( str[i] >= 'A' && str[i] <='Z' )
            num = str[i]-'A';
        if (num >= 0)
            count[num] ++;
    }

    a=0;
////////////////////////////////////////////////////////////////////////////////////////
    printf("\nТолько буквы:\n");
    for (int i = x ; i < x+z; i ++ )
    {
        if ((str[i] >= 'a' && str[i] <='z')||(str[i] >= 'A' && str[i] <='Z')||(str[i] == ' '))
        {
            if(str[i] >= 'A' && str[i] <='Z')       //Меняем регистр
            {
                b = str[i];
                str[i]=(char)tolower(b);
            }

            str1[a]=str[i];
            printf("%c", str1[a]);
            a=a+1;
        }
    }
////////////////////////////////////////////////////////////////////////////////////////
    printf("\n\nМонограммы:\n");
    for ( int i = 0; i < 26; i ++ )
    {
        if (count[i] > 0)
            printf("%c - %d\n", 'A'+i, count[i]);
    }
 /////////////////////////////////////////////////////////////
    printf("\nБиграммы:\n");

    for (a = 0 ; a < 675; a++ )
        mass[a]=0;

    mas=(int**)malloc(26*sizeof(int*));
    for(i=0; i<26; i++)
        mas[i]=(int*)malloc(26*sizeof(int));

    for (i=0; i<26; i++)
        for (j=0; j<26; j++)
            mas[i][j]=0;

//      a = 97      b = 98      c=99 ....   z=123

    n=0;

    for (i=97; i<123; i++)
        for (j=97; j<123; j++)
        {
            for (a = x ; a < x+z; a ++ )
            {
                if ((str1[a]==i) && (str1[a+1] == j))
                    mass[n]=mass[n] + 1;
            }
            n=n+1;
        }

    n=0;

    printf("   ");
    for (i=0; i<26; i++)
        printf("%c  ", 'A'+i);

    for (i=0; i<26; i++)
    {
        printf("\n%c  ",'A'+i);
        for (j=0; j<26; j++)
        {
            mas[i][j]=mass[n];
            n=n+1;
            if (mas[i][j]<1)
                printf("-  ");
            if (mas[i][j]<10 && mas[i][j]>0)
                printf("%d  ",mas[i][j]);
            if (mas[i][j]>9)
                printf("%d ",mas[i][j]);
        }
    }

//////////////////////////////////////////////////////////////////////////////
    printf("\n\nТриграммы:\n");

    for (a = 0 ; a < 17576; a++ )
        mass1[a]=0;

    n=0;
    k=97;

    for (i=97; i<123; i++)
        for (j=97; j<123; j++)
            for (k=97; k<123; k++)
            {
                for (a = x ; a < x+z; a ++ )
                {
                    if ((str1[a]==i) && (str1[a+1] == j) && (str1[a+2] == k))
                    mass1[n]=mass1[n] + 1;
                }
                if (mass1[n]>1)                         //Частота повторения
                    printf("%c %c %c = %d\n",i, j, k, mass1[n]);
                n=n+1;
            }
    getch();

    return 0;
}
