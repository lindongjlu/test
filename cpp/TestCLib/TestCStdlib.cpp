#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cstring>
#include "TestCStdlib.h"

void stringConversion() {

	char dStr[] = "123e-5";
	double d = atof(dStr);
	printf("str '%s' : double value : %lf\n", dStr, d);

	char iStr[] = "12345.1239999";
	int i = atoi(iStr);
	printf("str '%s' : int value : %d\n", iStr, i);

	char lStr[] = "1234599999.1239999";
	long l = atol(lStr);
	printf("str '%s' : long value : %ld\n", lStr, l);

	char szOrbits[] = "365.26 27.32";
	char * pEnd;
	double d1, d2;
	d1 = strtod(szOrbits, &pEnd);
	d2 = strtod(pEnd, NULL);
	printf("The moon completes %.2lf orbits per Earth year.\n", d1 / d2);

	char szNumbers[] = "2001 60c0c0 -1101110100110100100000 0x6fffff";
	long int li1, li2, li3, li4;
	li1 = strtol(szNumbers, &pEnd, 10);
	li2 = strtol(pEnd, &pEnd, 16);
	li3 = strtol(pEnd, &pEnd, 2);
	li4 = strtol(pEnd, NULL, 0);
	printf("The decimal equivalents are: %ld, %ld, %ld and %ld.\n", li1, li2, li3, li4);

}

void pseudoRandom() {

	/* initialize random seed: */
	srand ( time(NULL) );

	/* generate secret number: */
	for (int i=0; i<10; ++i) {
		printf("rand %d : %d\n", i, rand() % 10 + 1);
	}
}

void dynamicMemoryManagement() {

	int n1=100;
	char* buffer = (char*) malloc(sizeof(char) * n1);

	for (int i=0; i<n1-1; ++i) {
		buffer[i] = rand()%26 + 'a';
	}
	buffer[n1-1] = '\0';

	puts(buffer);

	int n2 = 200;
	buffer = (char*) realloc(buffer, n2);

	for (int i=n1-1; i<n2-1; ++i) {
		buffer[i] = rand()%26 + 'a';
	}
	buffer[n2-1] = '\0';

	puts(buffer);

	free(buffer);
}

void environment() {

	char* path = getenv("PATH");
	if (path != NULL) {
		puts(path);
	}

	int ret = system("ls");
	printf("Executing command ls... return: %d\n", ret);

	if (system(NULL)) {
		printf ("Checking if processor is available ok\n");
	}

	// abort(); // abort current process, without calling any atexit function

	atexit(dynamicMemoryManagement); // at least 32 func, exec LIFO
	puts("exit");
	exit(-1);

}

int compare (const void * a, const void * b) {
	return ( *(int*)a - *(int*)b );
}

void searchingAndSorting() {

	char strvalues[][20] = { "some", "example", "strings", "here" };
	char key[20] = "some";

	/* sort elements in array: */
	qsort(strvalues, 4, 20, (int (*)(const void*, const void*)) strcmp);

	for (int i=0; i<4; ++i) {
		printf("%d : %s\n", i, strvalues[i]);
	}

	/* search for the key: */
	char* pItem = (char*) bsearch(key, strvalues, 4, 20, (int (*)(const void*, const void*)) strcmp);

	if(	pItem != NULL) {
		printf ("%s is in the array %d.\n", pItem, (pItem - strvalues[0]) / 20);
	} else {
		printf ("%s is not in the array.\n", key);
	}

	int values[] = { 40, 10, 100, 90, 20, 25 };
	qsort (values, 6, sizeof(int), compare);
	for (int n=0; n<6; n++) {
		printf ("%d ",values[n]);
	}

}

void integerArithmethics() {

	int n = -123;
	printf("abs(%d) = %d\n", n, abs(n));

	div_t r = div(38, 5);
	printf ("38 div 5 => %d, remainder %d.\n", r.quot, r.rem);

}

