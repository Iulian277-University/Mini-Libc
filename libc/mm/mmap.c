/* SPDX-License-Identifier: BSD-3-Clause */

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

#define UNIT 8192ULL
#define OFF_MASK ((-0x2000ULL << (8*sizeof(long)-1)) | (UNIT-1))
#define MAX_ALLOC (-0x7fffffff - 1)

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	/* TODO: Implement mmap(). */
	// We don't like `addr` (address shouldn't be `NULL`)
	if (addr != NULL)
	{
		errno = EINVAL;
		return MAP_FAILED;
	}

	// We don't like `offset` (not aligned on a page boundary)
	if (offset & OFF_MASK)
	{
		errno = EINVAL;
		return MAP_FAILED;
	}

	// We don't like `length` (too large)
	if (length >= (size_t) MAX_ALLOC)
	{
		errno = ENOMEM;
		return MAP_FAILED;
	}


	// `fd` is not a valid file descriptor (and `MAP_ANONYMOUS` was not set)
	if (fd != -1 && !(flags & MAP_ANONYMOUS))
	{
		errno = EBADF;
		return MAP_FAILED;
	}

	// `flags` contained none of `MAP_PRIVATE` or `MAP_SHARED`
	if (!(flags & (MAP_PRIVATE | MAP_SHARED)))
	{
		errno = EINVAL;
		return MAP_FAILED;
	}

	return (void *) syscall(__NR_mmap, addr, length, prot, flags, fd, offset);
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	if (new_size >= (size_t) MAX_ALLOC)
	{
		errno = ENOMEM;
		return MAP_FAILED;
	}

	return (void *) syscall(__NR_mremap, old_address, old_size, new_size, flags);
}

int munmap(void *addr, size_t length)
{
	int eax = syscall(__NR_munmap, addr, length);
	if (eax < 0)
	{
		errno = -eax;
		return -1;
	}
	
	return eax;
}
