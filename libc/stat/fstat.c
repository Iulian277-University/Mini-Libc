/* SPDX-License-Identifier: BSD-3-Clause */

#include <sys/stat.h>
#include <errno.h>
#include <internal/syscall.h>

int fstat(int fd, struct stat *st)
{
	/* TODO: Implement fstat() system call. */
	int eax = syscall(__NR_fstat, fd, st);
	if (eax < 0) {
		errno = -eax;
		return -1;
	}
	return 0;
}
