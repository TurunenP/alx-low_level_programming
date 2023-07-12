#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

#define BUF_SIZE 128

/**
 * error_exit - Print error message and exit with status code 98.
 * @message: The error message to display.
 */
void error_exit(char *message)
{
	dprintf(2, "%s\n", message);
	exit(98);
}

/**
 * print_elf_header - Print the information contained in the ELF header.
 * @elf_header: The ELF header structure.
 */
void print_elf_header(Elf64_Ehdr *elf_header)
{
	int i;

	printf("ELF Header:\n");
	printf("  Magic:");
	for (i = 0; i < EI_NIDENT; i++)
		printf(" %02x", elf_header->e_ident[i]);
	printf("\n");
	printf("  Class:\t\t\tELF%d\n", (elf_header->e_ident[EI_CLASS] == ELFCLASS32) ? 32 : 64);
	printf("  Data:\t\t\t%s\n", (elf_header->e_ident[EI_DATA] == ELFDATA2MSB) ? "2's complement, big endian" : "2's complement, little endian");
	printf("  Version:\t\t\t%d (current)\n", elf_header->e_ident[EI_VERSION]);
	printf("  OS/ABI:\t\t\t");
	switch (elf_header->e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV: printf("UNIX - System V\n"); break;
		case ELFOSABI_HPUX: printf("HP-UX\n"); break;
		case ELFOSABI_NETBSD: printf("NetBSD\n"); break;
		case ELFOSABI_LINUX: printf("Linux\n"); break;
		case ELFOSABI_SOLARIS: printf("Solaris\n"); break;
		case ELFOSABI_IRIX: printf("IRIX\n"); break;
		case ELFOSABI_FREEBSD: printf("FreeBSD\n"); break;
		case ELFOSABI_TRU64: printf("TRU64 UNIX\n"); break;
		case ELFOSABI_ARM: printf("ARM architecture\n"); break;
		case ELFOSABI_STANDALONE: printf("Standalone (embedded) application\n"); break;
		default: printf("<unknown: %02x>\n", elf_header->e_ident[EI_OSABI]); break;
	}
	printf("  ABI Version:\t\t\t%d\n", elf_header->e_ident[EI_ABIVERSION]);
	printf("  Type:\t\t\t\t");
	switch (elf_header->e_type)
	{
		case ET_NONE: printf("NONE (Unknown type)\n"); break;
		case ET_REL: printf("REL (Relocatable file)\n"); break;
		case ET_EXEC: printf("EXEC (Executable file)\n"); break;
		case ET_DYN: printf("DYN (Shared object file)\n"); break;
		case ET_CORE: printf("CORE (Core file)\n"); break;
		default: printf("<unknown: %x>\n", elf_header->e_type); break;
	}
	printf("  Entry point address:\t\t0x%lx\n", elf_header->e_entry);
}

/**
 * main - Entry point of the program.
 * @argc: The argument count.
 * @argv: The argument vector.
 *
 * Return: 0 on success, 98 on error.
 */
int main(int argc, char **argv)
{
	int fd;
	Elf64_Ehdr elf_header;

	if (argc != 2)
		error_exit("Usage: elf_header elf_filename");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_exit("Error: Cannot open file");

	if (read(fd, &elf_header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
		error_exit("Error: Cannot read ELF header");

	if (lseek(fd, (off_t)0, SEEK_SET) == -1)
		error_exit("Error: Cannot reset file offset");

	print_elf_header(&elf_header);

	close(fd);
	return 0;
}
