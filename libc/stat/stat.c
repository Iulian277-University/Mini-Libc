/* SPDX-License-Identifier: BSD-3-Clause */

#include <sys/stat.h>
#include <internal/syscall.h>
#include <fcntl.h>
#include <errno.h>

int stat(const char *restrict path, struct stat *restrict buf)
{
	/* TODO: Implement stat() system call. */
	int eax = syscall(__NR_stat, path, buf);
	if (eax < 0) {
		errno = -eax;
		return -1;
	}
	return 0;
}
