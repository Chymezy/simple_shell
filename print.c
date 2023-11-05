#include "shell.h"

/**
 * print - writes a character or string to the given fd and flushes the buffer.
 * @data: A character or a null-terminated string to print
 * @fd: The file descriptor to write to
 *
 * Return: On success, 1. On error, -1 is returned, and errno is set appropriately.
 */
int print(const char *data, int fd) {
    ssize_t r;
    static char buf[WRITE_BUF_SIZE];

    while (*data) {
        if (i >= WRITE_BUF_SIZE) {
            r = write(fd, buf, i);
            if (r == -1) {
                perror("write failed");
                return -1;
            }
            i = 0;
        }

        buf[i++] = *data++;
    }

    return 1;
}

