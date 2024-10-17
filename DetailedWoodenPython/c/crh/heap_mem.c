#include <stdio.h>
#include <stdlib.h>

int global_var;

int global_initialized_var = 5;

void func() {
  int stack_var;
  printf("The function's stack_var is at address 0x%08x\n", &stack_var);
}

int main() {
  int stack_var; //stesso nome
  static int static_var;
  static int static_initialized_var = 5;
  int *heap_var_ptr;

  heap_var_ptr = (int *)malloc(4);

  //variabili nel data segment
  printf("global_initialized_var si trova nell'indirizzo 0x%08x\n", &global_initialized_var);
  printf("static_initialized_var si trova nell'indirizzo 0x%08x\n", &static_initialized_var);

  //variabili nel bss segment
  printf("global_var si trova nell'indirizzo 0x%08x\n", &global_var);
  printf("static_var si trova nell'indirizzo 0x%08x\n", &static_var);

  //variabili nell'heap segment
  printf("heap_var si trova nell'indirizzo 0x%08x\n", &heap_var_ptr);

  //variabili nello stack segment
  printf("stack_var si trova nell'indirizzo 0x%08x\n", &stack_var);

  func();
}