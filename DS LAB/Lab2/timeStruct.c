#include <stdio.h>

struct time
{
    int hour;
    int min;
    int sec;
};

struct time addTime(struct time t1, struct time t2);
struct time diffTime(struct time t1, struct time t2);
void readTime(struct time *t);
void displayTime(struct time t);

int main()
{
    struct time time1, time2, sum, difference;

    printf("Enter the first time:\n");
    readTime(&time1);

    printf("Enter the second time:\n");
    readTime(&time2);

    sum = addTime(time1, time2);
    difference = diffTime(time1, time2);

    printf("\nTime 1: ");
    displayTime(time1);

    printf("Time 2: ");
    displayTime(time2);

    printf("Sum of times: ");
    displayTime(sum);

    printf("Difference of times: ");
    displayTime(difference);

    return 0;
}

struct time addTime(struct time t1, struct time t2)
{
    struct time sum;
    sum.hour = t1.hour + t2.hour;
    sum.min = t1.min + t2.min;
    sum.sec = t1.sec + t2.sec;

    if (sum.sec >= 60)
    {
        sum.min += sum.sec / 60;
        sum.sec %= 60;
    }

    if (sum.min >= 60)
    {
        sum.hour += sum.min / 60;
        sum.min %= 60;
    }

    return sum;
}

struct time diffTime(struct time t1, struct time t2)
{
    struct time difference;
    int totalSeconds1 = t1.hour * 3600 + t1.min * 60 + t1.sec;
    int totalSeconds2 = t2.hour * 3600 + t2.min * 60 + t2.sec;

    int diffSeconds = totalSeconds1 - totalSeconds2;
    if (diffSeconds < 0)
    {
        diffSeconds = -diffSeconds;
    }

    difference.hour = diffSeconds / 3600;
    difference.min = (diffSeconds % 3600) / 60;
    difference.sec = diffSeconds % 60;

    return difference;
}

void readTime(struct time *t)
{
    printf("Enter hour: ");
    scanf("%d", &t->hour);
    printf("Enter minute: ");
    scanf("%d", &t->min);
    printf("Enter second: ");
    scanf("%d", &t->sec);
}

void displayTime(struct time t)
{
    printf("%02d:%02d:%02d\n", t.hour, t.min, t.sec);
}

