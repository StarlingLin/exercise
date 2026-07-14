#include <cstdlib>

#define ELEMENT_TYPE int

typedef struct DNode
{
    ELEMENT_TYPE data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

bool ListInit(DLinkList& L)
{
    
}