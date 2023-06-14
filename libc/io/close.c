/* SPDX-License-Identifier: BSD-3-Clause */

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int close(int fd)
{
	/* TODO: Implement close() system call. */
	int eax = syscall(__NR_close, fd);
	if (eax < 0) {
		errno = -eax;
		return -1;
	}
	return 0;
}
