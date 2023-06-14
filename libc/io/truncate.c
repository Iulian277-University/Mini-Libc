/* SPDX-License-Identifier: BSD-3-Clause */

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int truncate(const char *path, off_t length)
{
	/* TODO: Implement truncate() system call. */
	int eax = syscall(__NR_truncate, path, length);
	if (eax < 0) {
		errno = -eax;
		return -1;
	}
	return 0;
}
