#include <cstring>
#include <cstdio>

#include "TestCString.h"

void copying() {
	char str1[] = "Sample string";
	char str2[40];
	memcpy (str2, str1, strlen(str1) + 1);
	puts(str2);

	// memmove overlap better
	char str[] = "memmove can be very useful......";
	memmove (str+20,str+15,11);
	puts (str);

	// should not overlap
	strcpy(str2, str1);
	puts(str2);

	char strA[] = "To be or not to be";
	char strB[6];
	strncpy(strB, strA, 6);
	strB[5] = '\0';
	puts(strB);

}
