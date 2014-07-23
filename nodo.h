#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

//questa è la struttura da editare
static struct info_nodo{
	char *nome;
	uint8_t eta;
	uint32_t periodo;
	uint32_t incontri;
}
array_backend[] =
{
    //quì inizializziamo i nostri elementi
    {
        "mario", 16, 2, 0
    },
    {
        "giovanni", 13, 3, 0
    },
    {
        "lucia", 12, 5, 0
    }
};

#endif // NODO_H_INCLUDED
