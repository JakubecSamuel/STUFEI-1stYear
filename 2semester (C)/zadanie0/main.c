#include <stdio.h>


int i = 1;
int f() { return 2*i;}
int main() {
    i = 3;
    printf("%i", f());
}