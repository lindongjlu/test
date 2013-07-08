#include <cstring>
#include <cstdio>
#include <cerrno>

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

void concatenation() {

	char str[80];
	strcpy(str, "these ");
	strcat(str, "strings ");
	strcat(str, "are ");
	strcat(str, "concatenated.");
	puts(str);

	char str1[20];
	char str2[20];
	strcpy(str1, "To be ");
	strcpy(str2, "or not to be");
	strncat(str1, str2, 6);
	puts(str1);

}

void comparison() {
	char str1[] = "building";
	char str2[] = "book";
	size_t len1 = strlen(str1);
	size_t len2 = strlen(str2);
	int n1 = memcmp(str1, str2, len1 < len2 ? len1 : len2);
	int n2 = strcmp(str1, str2);
	int n3 = strncmp(str1, str2, 1);
	printf("memcmp : %d, strcmp : %d, strncmp : %d\n", n1, n2, n3);
}

void searching() {

	char str[] = "Example string123";
	char* pch = (char*) memchr(str, 'p', strlen(str));
	if (pch != NULL) {
		printf("'p' found at position %d.\n", pch - str + 1);
	} else {
		printf("'p' not found.\n");
	}

	char* pch1 = strchr(str, 's');
	if (pch1 != NULL) {
		printf("'s' found at position %d.\n", pch1 - str + 1);
	} else {
		printf("'s' not found.\n");
	}

	char keys[] = "1234567890";
	int i = strcspn(str, keys);
	printf("The first number in str is at position %d.\n", i + 1);

	printf("Vowels in '%s': ", str);
	pch = strpbrk(str, keys);
	while (pch != NULL) {
		printf("%c ", *pch);
		pch = strpbrk(pch + 1, keys);
	}
	printf("\n");

	pch = strrchr(str, 's');
	printf("Last occurence of 's' found at %d \n", pch - str + 1);

	char strtext[] = "129th";
	char cset[] = "1234567890";

	i = strspn(strtext, cset);
	printf("The length of initial number is %d.\n", i);

	pch = strstr (str,"string");
	strncpy (pch,"sample",5);
	puts (str);


	char strText[] = "- This, a sample str,,ing.";
	char * p;
	printf("Splitting string \"%s\" into tokens:\n", strText);
	p = strtok(strText, " ,.-");
	while (p != NULL) {
		printf("%s\n", p);
		p = strtok(NULL, " ,.-");
	}

}

void other() {
	char str[] = "almost every programmer should know memset!";
	memset(str, '-', 6);
	puts(str);

	FILE * pFile;
	pFile = fopen("unexist.ent", "r");
	if (pFile == NULL) {
		printf("Error opening file unexist.ent: %s\n", strerror(errno));
	}
}
