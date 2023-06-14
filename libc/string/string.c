/* SPDX-License-Identifier: BSD-3-Clause */

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	for (char s = *source; s != '\0'; s = *++source)
		*destination++ = s;
	*destination = '\0';

	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	// Same as `strcpy()` but with `len` check
	for (char s = *source; s != '\0' && len > 0; s = *++source, len--)
		*destination++ = s;

	// If `len` is not 0, add null terminator
	if (len > 0)
		*destination = '\0';
	
	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	for (char d = *destination; d != '\0'; d = *++destination);
	for (char s = *source; s != '\0'; s = *++source)
		*destination++ = s;
	*destination = '\0';

	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	for (char d = *destination; d != '\0'; d = *++destination);
	for (char s = *source; s != '\0' && len > 0; s = *++source, len--)
		*destination++ = s;
	*destination = '\0';

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	while (*str1 && (*str1 == *str2))
	{
		++str1;
		++str2;
	}

	return (*(unsigned char *) str1 - *(unsigned char *) str2);
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	while (len > 0 && *str1 && (*str1 == *str2))
	{
		++str1;
		++str2;
		--len;
	}

	if (len == 0)
		return 0;
	return (*(unsigned char *) str1 - *(unsigned char *) str2);
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++);

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	for ( ; *str != '\0'; ++str)
	{
		if (*str == c)
			return (char *) str;
	}

	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */

	char *last = NULL;
	for ( ; *str != '\0'; ++str)
	{
		if (*str == c)
			last = (char *) str;
	}

	return last;
}

char *strstr(const char *str1, const char *str2)
{
	/* TODO: Implement strstr(). */
	for (int i = 0; str1[i] != '\0'; i++)
	{
		int j = 0;
		while (str1[i + j] == str2[j])
		{
			j++;
			if (str2[j] == '\0')
				return (char *) str1 + i;
		}
	}

	return NULL;
}

char *strrstr(const char *str1, const char *str2)
{
	/* TODO: Implement strrstr(). */
	char *last = NULL;
	for (int i = 0; str1[i] != '\0'; i++)
	{
		int j = 0;
		while (str1[i + j] == str2[j])
		{
			j++;
			if (str2[j] == '\0')
				last = (char *) str1 + i;
		}
	}

	return last;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	for (size_t i = 0; i < num; i++)
		((char *) destination)[i] = ((char *) source)[i];

	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	// This implementation doesn't use an additional `tmp` buffer
	char * dest = (char *) destination;
	char * src = (char *) source;

	if (dest == src || num == 0)
		return dest;

	if (dest > src && dest < src + num)
	{
		for (int i = num - 1; i >= 0; --i)
			dest[i] = src[i];
		return dest;
	}

	if (src > dest && src < dest + num)
	{
		for (size_t i = 0; i < num; ++i)
			dest[i] = src[i];
		return dest;
	}

	memcpy(dest, src, num);
	return dest;
}


// void *memmove(void *destination, const void *source, size_t num)
// {
// 	/* TODO: Implement memmove(). */
// 	// This implementation uses an additional `tmp` buffer
// 	char *src = (char *) source;
// 	char *dest = (char *) destination;

// 	char tmp[1024];
// 	for (int i = 0; i < num; i++)
// 		tmp[i] = src[i];
// 	for (int i = 0; i < num; i++)
// 		dest[i] = tmp[i];
	
// 	return dest;
// }

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	for (size_t i = 0; i < num; i++)
	{
		if (((char *) ptr1)[i] != ((char *) ptr2)[i])
			return ((char *) ptr1)[i] - ((char *) ptr2)[i];
	}

	return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	for (size_t i = 0; i < num; i++)
		((char *) source)[i] = value;
	
	return source;
}
