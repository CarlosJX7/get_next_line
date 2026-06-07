*This project has been created as part of the 42 curriculum by carlinaq.*

# get_next_line

## 📋 Description

The **get_next_line** project consists of programming a custom function in C that reads a single line from a valid file descriptor (FD) at each sequential call. The primary objective of this project is to understand the behavior of **static variables** in memory, master dynamic memory allocation, and learn how to manage data streams using a variable-sized buffer (`BUFFER_SIZE`).

The developed function returns the line read from the file descriptor, including the terminating newline character (`\n`) if it was found, and returns `NULL` when there is nothing left to read or if an unexpected error occurs.

---

## 🛠️ Installation and Usage Instructions

### Prerequisites

A UNIX environment (Linux, macOS) is required, along with a basic compiler (`gcc` or `clang`).

### Compiling the Function

Unlike other projects, `get_next_line` does not require a Makefile for its evaluation but is compiled alongside your main application files. The compilation must define the buffer size dynamically using the `-D BUFFER_SIZE=n` flag.

#### For the Standard Version

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl_program
```

#### For the Bonus Version (Multiple File Descriptors)

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main.c -o gnl_bonus_program
```

### Incorporating into Your Own Projects

To use this function in your C script, include the header file and call the function inside a loop to read an entire file:

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int     fd;
    char    *line;

    fd = open("test1.txt", O_RDONLY);
    if (fd < 0)
        return (1);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

A continuación, un ejemplo de `main` para la versión bonus, que lee líneas de dos descriptores de archivo diferentes de forma intercalada:

```c
#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int     fd1;
    int     fd2;
    char    *line1;
    char    *line2;

    fd1 = open("test1.txt", O_RDONLY);
    fd2 = open("test2.txt", O_RDONLY);
    if (fd1 < 0 || fd2 < 0)
    {
        printf("Error al abrir los archivos de prueba.\n");
        return (1);
    }

    line1 = (char *)1;
    line2 = (char *)1;
    while (line1 != NULL || line2 != NULL)
    {
        line1 = get_next_line(fd1);
        if (line1)
        {
            printf("FD1: %s", line1);
            free(line1);
        }
        line2 = get_next_line(fd2);
        if (line2)
        {
            printf("FD2: %s", line2);
            free(line2);
        }
    }
    close(fd1);
    close(fd2);
    return (0);
}
```

## 📐 Technical Decisions: Algorithm and Data Structures

### Justification of the Parsing Algorithm

The algorithm is structured into three highly specialized phases to respect the strict limits of the Norminette and guarantee performance:

1. **Stream Reading (`read_line`)**
   Initiates a loop that executes the `read` system call, extracting blocks of data defined by `BUFFER_SIZE` into a temporary heap allocation. It appends these blocks to the static tracker until a newline character (`\n`) is detected via `ft_strchr` or the End-Of-File (EOF) is reached.

2. **Line Extraction (`get_line`)**
   Measures the distance to the first `\n`, isolates the segment using memory sub-allocation (`ft_substr`), and formats it as a clean, independent string ready to be returned to the user.

3. **State Preservation (`get_rest`)**
   Shifts the remaining, unreturned data back to the beginning of the static memory storage, freeing the obsolete pointer reference to avoid accumulating stale heap allocations.

### Justification of Data Structures

To handle the persistent data stream across multiple execution states, a **Static Pointer Abstraction** is used.

#### Standard Version

A single static pointer:

```c
static char *str;
```

tracks the leftover bytes between independent function cycles. This approach ensures an architectural footprint of **O(1)** memory complexity relative to the state representation.

#### Bonus Version

The single pointer structure is upgraded to a static array:

```c
static char *str[1024];
```

This structure maps individual heap tracking buffers directly to unique index keys matching the system's active File Descriptor table. This allows the program to read from multiple text sources simultaneously without losing track of the individual read heads or mixing up the lines.

## 📚 Resources and Artificial Intelligence Usage

### Consulted References

* UNIX man pages:

  * `man 2 read`
  * `man 2 open`
  * `man 3 free`

* Storage Management Guides:
  Documentation regarding storage duration, linkage, and memory persistence of local static variables in C.

* Kernel Limits Specification:
  POSIX standards concerning maximum open file descriptors per process (`OPEN_MAX`).

---

## 📦 Auxiliary Resources

To facilitate testing of the bonus version, you can create the following files with the content provided below:

### `test1.txt`
```plaintext
Esta es la primera línea del archivo 1.
Esta es la segunda línea del archivo 1.
Esta es la tercera línea del archivo 1.
```

### `test2.txt`
```plaintext
Esta es la primera línea del archivo 2.
Esta es la segunda línea del archivo 2.
Esta es la tercera línea del archivo 2.
```
