#include "woody_woodpacker.h"

static int error(const char *msg, int fd) {
    LOG_ERROR(msg);
    close(fd);
    return -1;
} 

int parse_elf(FILE *ELF_64) {
    struct stat st={0};
    int fd = fileno(ELF_64);

    if (fstat(fd, &st) < 0) {
        return (error("fstat error", fd));
    }

    void *map = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (map == MAP_FAILED) {
        return (error("mmap error", fd));
    }

    if (st.st_size < sizeof(Elf64_Ehdr)) {
        munmap(map, st.st_size);
        return (error("Not a valid ELF file (too small)", fd));
    }

    Elf64_Ehdr *ehdr = (Elf64_Ehdr *)map;
    if (memcmp(ehdr->e_ident, ELFMAG, SELFMAG) != 0) {
        munmap(map, st.st_size);
        return (error("Not a valid ELF file", fd));
    }

    if (ehdr->e_ident[EI_CLASS] != ELFCLASS64) {
        munmap(map, st.st_size);
        return(error("Only x86_64 is supported", fd));
    }

    printf("[*] Valid ELF file\n[*] Type: %d, Machine: %d\n", ehdr->e_type, ehdr->e_machine);

    munmap(map, st.st_size);
    return 0;
}