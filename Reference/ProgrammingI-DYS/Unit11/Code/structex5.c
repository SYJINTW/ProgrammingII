#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int x;
    struct _node *next;
} Node;

/*

head|x|next|

        |

        V

        |x|next|

             |

             V

        np-> |x|next|

              */

int main(void)
{
    Node head;
    Node *np, *nq;

    int i;

    head.x = 0;
    head.next = (Node *) malloc(sizeof(Node));

    np = head.next;

    i = 1;

    while (i < 10) {
        np->x = i;
        np->next = (Node *) malloc(sizeof(Node));
        np = np->next;
        i++;
    }

    np->x = i;
    np->next = NULL;
    np = head.next;

    while (np!=NULL) {
        printf("%d\n", np->x);
        np = np->next;
    }

    np = head.next;

    while (np!=NULL) {
        nq = np;
        np = np->next;
        free(nq);
    }

    return 0;
}
