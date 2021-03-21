#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"
#define MIN_PER_HR 60.0
#define SIZE 2

bool newcustomer(double x);
Item customertime(long when);

int main(void)
{
    Queue lines[SIZE];
    Item temp;
    int hours;
    int perhour;
    long cycle, cyclelimit;
    long turnaways = 0;
    long customers = 0;
    long served = 0;
    long sum_line = 0;
    int wait_time0 = 0;
    int wait_time1 = 0;
    double min_per_cust;
    long line_wait0 = 0;
    long line_wait1 = 0;

    for (int i = 0; i < SIZE; i++)
        InitializeQueue(&lines[i]);
    srand((unsigned int) time(0));
    puts("Case Study: Sigmund Lander's advice Booth");
    puts("Enter the number of simulation hours:");
    scanf("%d", &hours);
    cyclelimit = MIN_PER_HR * hours;
    puts("Enter the average number of customers per hour:");
    scanf("%d", &perhour);
    min_per_cust = MIN_PER_HR / perhour;

    for (cycle = 0; cycle < cyclelimit; cycle++)
    {
        if (newcustomer(min_per_cust))
        {
            if (QueueIsFull(&lines[0]) && QueueIsFull(&lines[1]))
                turnaways++;
            else
            {
                customers++;
                temp = customertime(cycle);
                if (lines[0].items > lines[1].items)
                    EnQueue(temp, &lines[1]);
                else
                    EnQueue(temp, &lines[0]);
            }
        }
        if (wait_time0 <= 0)
        {
            if (!QueueIsEmpty(&lines[0]))
            {
                DeQueue(&temp, &lines[0]);
                wait_time0 = temp.processtime;
                line_wait0 += cycle - temp.arrive;
                served++;
            }    
            else if (!QueueIsEmpty(&lines[1]))
            {
                DeQueue(&temp, &lines[1]);
                wait_time0 = temp.processtime;
                line_wait0 += cycle - temp.arrive;
                served++;                
            }
        }
        if (wait_time1 <= 0)
        {
            if (!QueueIsEmpty(&lines[1]))
            {
                DeQueue(&temp, &lines[1]);
                wait_time1 = temp.processtime;
                line_wait1 += cycle - temp.arrive;
                served++;
            }    
            else if (!QueueIsEmpty(&lines[0]))
            {
                DeQueue(&temp, &lines[0]);
                wait_time1 = temp.processtime;
                line_wait1 += cycle - temp.arrive;
                served++;               
            }            
        }
        if (wait_time0 > 0)
            wait_time0--;
        if (wait_time1 > 0)
            wait_time1--;
        sum_line += QueueItemCount(&lines[0]) + QueueItemCount(&lines[1]);
    }
    if (customers > 0)
    {
        printf("customers accepted: %ld\n", customers);
        printf("  customers served: %ld\n", served);
        printf("     turnaways: %ld\n", turnaways);
        printf("average queue size: %.2f\n", (double) sum_line / cyclelimit);
        printf("  average wait time: %.2f minutes\n", (double)(line_wait0 + line_wait1) / served);
    } else
    {
        puts("No customers!");
    }
    for (int i = 0; i < SIZE; i++)
        EmptyTheQueue(&lines[i]);
    puts("Bye!");

    return 0;
}

bool newcustomer(double x)
{
    if (rand() * x / RAND_MAX < 1)
        return true;
    else
        return false;
}

Item customertime(long when)
{
    Item cust;

    cust.processtime = rand() % 3 + 1;
    cust.arrive = when;

    return cust;
}