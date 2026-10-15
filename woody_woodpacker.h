#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <elf.h>
#include <string.h>

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define RESET   "\x1b[0m"

#define LOG_INFO(msg) fprintf(stdout, GREEN "[*] %s\n" RESET, msg);
#define LOG_ERROR(msg) fprintf(stderr, RED "[ERROR] %s\n" RESET, msg);

int parse_elf(FILE *ELF_64);