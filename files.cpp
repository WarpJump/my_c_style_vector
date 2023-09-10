#include<stdio.h>
#include<stdlib.h>

#include "myvector.h"

define_vector(int);
define_vector(dynamic_array(int));

int main()
{
    dynamic_array(int) a;
    dynamic_array(dynamic_array(int)) b;

    printf("%d", a.size);
    resize(&a, 10);
    printf("%d", a.size);

    destroy(&a);
}