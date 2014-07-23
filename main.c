#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "coda.h"

const int numeroEstrazioni = 200;

int main()
{
    printf("\nInizio test A");
    init_list();
    int count=0;
    for (count=0; count < numeroEstrazioni; count++){
        /*BEGIN: EXTRACTION, WEIGHT RECALCULATION, REINSERT*/
        struct list_node *ele = poll_head(); //get and remove head
        ele->peso += array_backend[ele->array_index].periodo;
        add_sorted(ele); //put head back, but sorted by peso
        /*END: EXTRACTION, WEIGHT RECALCULATION, REINSERT*/

        array_backend[ele->array_index].incontri++;
        printf("\n%s, eta %d, periodo %d", array_backend[ele->array_index].nome, array_backend[ele->array_index].eta, array_backend[ele->array_index].periodo);
    }

    printf("\nFine conteggi, numero di visualizzazioni per elemento");

    size_t list_size = sizeof(array_backend)/sizeof(array_backend[0]);
    size_t i;

    for (i = 0; i < list_size; i++ ){
        float stima_incontri = numeroEstrazioni/(float)array_backend[i].periodo;
        printf("\n%s, incontri %d, stima incontri %.2f", array_backend[i].nome, array_backend[i].incontri, stima_incontri );
        array_backend[i].incontri = 0;
    }
    printf("\nFine test A");

    printf("\nInizio test B");
    init_list();
    for (count=0; count < numeroEstrazioni; count++){
        printf("\n\nperiodo %d", count);

        struct list_node *ele = NULL;
        do{
            ele = poll_head_time(count); //get and remove head
            /*BEGIN: EXTRACTION, WEIGHT RECALCULATION, REINSERT*/
            if (ele != NULL){
                ele->peso += array_backend[ele->array_index].periodo;
                add_sorted(ele); //put head back, but sorted by peso
                /*END: EXTRACTION, WEIGHT RECALCULATION, REINSERT*/

                array_backend[ele->array_index].incontri++;
                printf("\n%s, eta %d, periodo %d", array_backend[ele->array_index].nome, array_backend[ele->array_index].eta, array_backend[ele->array_index].periodo);
            }
        }while(ele!=NULL);
    }
    printf("\nFine conteggi, numero di visualizzazioni per elemento");
    for (i = 0; i < list_size; i++ ){
        float stima_incontri = numeroEstrazioni/(float)array_backend[i].periodo;
        printf("\n%s, incontri %d, stima incontri %.2f", array_backend[i].nome, array_backend[i].incontri, stima_incontri );
        array_backend[i].incontri = 0;
    }
    printf("\nFine test B");

    return 0;
}
