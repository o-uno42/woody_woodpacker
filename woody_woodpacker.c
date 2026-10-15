#include "woody_woodpacker.h"
int main(int ac, char **av) {
    FILE *ELF_64 = fopen(av[1], "r");
    if (!ELF_64) perror("[!]Error opening file");
    parse_elf(ELF_64);
    fclose(ELF_64);
    return 0;
}