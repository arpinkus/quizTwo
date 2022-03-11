#include <stdio.h>
#include <stddef.h>

typedef struct { // struct holding Employee
    long number;
    char *name;
    char *phone;
    double salary;
} Employee, *PtrToEmployee; // two names

typedef const Employee *PtrToConstEmployee; // pointer of type Employee that is constant