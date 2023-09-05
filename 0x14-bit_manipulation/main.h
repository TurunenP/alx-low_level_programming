#ifndef MAIN_H
#define MAIN_H

unsigned int binary_to_uint(const char *b);
void print_binary(unsigned long int r);
int get_bit(unsigned long int a, unsigned int ind);
int set_bit(unsigned long int *a, unsigned int ind);
int clear_bit(unsigned long int *a, unsigned int ind);
unsigned int flip_bits(unsigned long int a, unsigned long int b);
int _atoi(const char *s);
int _putchar(char c);
int get_endianness(void);

#endif

