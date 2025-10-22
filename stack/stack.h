#ifndef STACK_H_
#define STACK_H_

#include <stdio.h>
#include <stdlib.h>


typedef struct nodo_stack *stack;

stack crear_stack();
stack push(stack s, int x);
stack pop(stack s);
int top(stack s);
bool vacio(stack s);
stack destruir(stack s);

#endif // STACK_H_