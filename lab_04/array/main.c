#include "automat.h"
#include "queue.h"
#include "tick.h"
#include <math.h>
#define TIMES 1000
#define MOD 100
int main() {
    automat *a;
    queue_t *q1 = new_queue(ELEM, T1);
    queue_t *q2 = new_queue(ELEM, T2);
    a = init_auto();
    int len1 = 0;
    int len2 = 0;
    float stay1, stay2;
    float t;
    float i = 0;
    int j = 1;
    float ideal;
    float app;
    float measurement_error;
    double duration = 0;
    clock_t t1, t2;
    int addres;
    srand(time(NULL));
    printf("<--------------SETTINGS-------------->\n\n");
    printf("If you want to see memory address print 1, otherwise print 0: ");
    scanf("%d", &addres);
    printf("<-------------MODELING--------------->\n\n");
    while(a->count_t1 < TIMES)
    {
        t1 = clock();
        t = tick_tock(q1, q2, a);
        t2 = clock();
        duration = duration + (double) (t2 - t1)/CLOCKS_PER_SEC;
        if(a->count_t1 % MOD == 0 && i != a->count_t1)
        {
            i = a->count_t1;
            len1 += q1->elts;
            len2 += q2->elts;
            stay1 += q1->data_store[q1->front];
            stay2 += q2->data_store[q2->front];
            printf("<--------------<SUBTOTAL>---------------->\n");
            j++;
            //printf(">>%d items entered\n", q2->ever_elts);
            printf(">>%d items left\n", a->count_t1);
            printf(">>Now lenght of first queue: %d.\n"
            ">>Now lenght of second queue: %d.\n", q1->elts, q2->elts);
            printf(">>Time now is %f.\n",t);
            printf(">>The average length of the first queue is  %f.\n", (float)len1 / (float)j);
            printf(">>The average length of the second queue is  %f.\n", (float)len2 / (float)j);
            printf(">>The average downtime of the first queue is  %lf.\n", fabs(stay1 / j));
            printf(">>The average downtime of the second queue is  %lf.\n", fabs(stay2 / j));
            printf("------------------------------\n");

        }
    }
    app = (T1_MAX + T2_MAX + T1_MIN)/3.0;


    /*printf("\n\n<----------------TESTING------------------->\n\n"
           "Modeling time : %f;\n"
           "The downtime : %f;\n"
           "The number of entered applications in first queue : %d;\n"
           "The number of entered applications in second queue : %d;\n"
           "The number of left applications of first queue: %d;\n"
           "The number of left applications of second queue: %d;\n"
           "The muchine work time is %f;\n"
           "The average time of entering of a single application : %.3f.\n"
           "Estimated work time on the input: %.3f;\n\n\n", t, a->downtime, q1->ever_elts,  q2->ever_elts,
           a->count_t1,a->count_t2, a->work,
           app,app*TIMES);*/

    if (addres == 0)
    {
        printf("\n\n<----------------TESTING------------------->\n\n"
               "Modeling time : %f\n"
               "The number of entered applications in first queue : %d\n"
               "The number of entered applications in second queue : %d\n",t, q1->ever_elts,  q2->ever_elts);
        ideal = t / app;
        measurement_error = ((q1->ever_elts + q2->ever_elts - ideal)/ ideal)/ 100 ;
        printf("Measurement error : %f %%\n", measurement_error);
        printf("It takes time: %g\n", duration);
        printf("Used memory: %d \n", (int)(sizeof(queue_t)*2 + sizeof(automat) + ELEM*2*sizeof(float)));
    }
    else
    {
        printf("\n\n<----------------TESTING------------------->\n\n"
               "Modeling time : %f\n"
               "The number of entered applications in first queue : %d\n"
               "The number of entered applications in second queue : %d\n",t, q1->ever_elts,  q2->ever_elts);
        ideal = t / app;
        measurement_error = ((q1->ever_elts + q2->ever_elts - ideal)/ ideal)/ 100 ;
        printf("Measurement error : %f %%\n", measurement_error);
        printf("It takes time: %g\n", duration);
        printf("Used memory: %d \n", (int)(sizeof(queue_t)*2 + sizeof(automat) + ELEM*2*sizeof(float)));
        printf("Memory addres's:\n");
        printf("First queue            Second queue\n");
        printf("%p       %p\n", (void*)&(q1->data_store[0]), (void*)&(q2->data_store[0]));
        printf("%p       %p\n", (void*)&(q1->data_store[1]), (void*)&(q2->data_store[1]));
        printf("%p       %p\n", (void*)&(q1->data_store[2]), (void*)&(q2->data_store[2]));
        printf("%p       %p\n", (void*)&(q1->data_store[3]), (void*)&(q2->data_store[3]));
    }
    queue_free(q1);
    queue_free(q2);
    return 0;

}
