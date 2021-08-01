//
//  main.c
//  取款机新
//
//  Created by yongya on 2021/4/29.
//
#include <stdio.h>
#include <unistd.h>
int main()
{
    char p1;
    char p2;
    char p3;
    char p4;
    int money = 2456;
    int out;
    int i, m, n, k;
    int yue;
    printf("欢迎来到C语言ATM机\n");
    printf("请您设定您的账户密码（4位）\n");
    for (i = 1; i < 5; i++)
    {
        p1 = getpass("\0");
        putchar('*');
    }
    fflush(stdin);
    printf("请您再次输入确认密码\n");
    for (m = 1; m < 5; m++)
    {
        p2 = getpass("\0");
        putchar('*');
    }
    fflush(stdin);
    if (p1 == p2)
    {
        printf("您的账户余额为%d\n", money);
        printf("您可以设置取款金额\n");
        scanf("%d", &out);
        if (out > money)
        {
            printf("取款金额超过账户余额，取款失败\n");
        }
        else
        {
            printf("取款成功，您的账户余额为%d\n", yue = money - out);
        }
    }
    else
    {
        printf("密码输入错误，请再次输入密码\n");
        for (n = 1; n < 5; n++)
        {
            p3 = getpass("\0");
            putchar('*');
        }
        fflush(stdin);
        if (p1 == p3)

        {
            printf("您的账户余额为%d\n", money);
            printf("您可以设置取款金额\n");
            scanf("%d", &out);
            if (out > money)

            {
                printf("取款金额超过账户余额，取款失败\n");
            }
            else

            {
                printf("取款成功，您的账户余额为%d\n", yue = money - out);
            }
        }
        else
        {
            printf("密码输入错误，请再次输入密码\n");
            for (k = 1; k < 5; k++)
            {
                p4 = getpass("\0");
                putchar('*');
            }
            fflush(stdin);
            if (p1 == p4)

            {
                printf("您的账户余额为%d\n", money);
                printf("您可以设置取款金额\n");
                scanf("%d", &out);
                if (out > money)

                {
                    printf("取款金额超过账户余额，取款失败\n");
                }
                else

                {
                    printf("取款成功，您的账户余额为%d\n", yue = money - out);
                }
            }
            else
            {
                printf("密码输入错误三次，退出ATM系统\n");
            }
        }
    }
    return 0;
}