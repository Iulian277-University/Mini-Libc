/* SPDX-License-Identifier: BSD-3-Clause */

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	void *p = NULL;
	p = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	mem_list_add(p, size);

	return p;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	void *p = NULL;
	p = mmap(NULL, nmemb * size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	memset(p, 0, nmemb * size);
	mem_list_add(p, nmemb * size);

	return p;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	munmap(ptr, mem_list_find(ptr)->len);
	mem_list_del(ptr);
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	munmap(ptr, mem_list_find(ptr)->len);
	mem_list_del(ptr);

	void *p = NULL;
	p = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	mem_list_add(p, size);
	memcpy(p, ptr, size);

	return p;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	munmap(ptr, mem_list_find(ptr)->len);
	mem_list_del(ptr);
	
	void *p = NULL;
	p = mmap(NULL, nmemb * size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	mem_list_add(p, nmemb * size);
	memcpy(p, ptr, nmemb * size);

	return p;
}
