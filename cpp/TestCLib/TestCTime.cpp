#include <ctime>
#include <cstdio>

#include "TestCTime.h"

void wait(int seconds) {
	clock_t endwait;
	endwait = clock() + seconds * CLOCKS_PER_SEC;
	while (clock() < endwait) {
	}
}

void timeManipulation() {

	printf("CLOCKS_PER_SEC : %d, clock() : %lud\n", CLOCKS_PER_SEC, clock());

	int n;
	printf("Starting countdown...\n");
	for (n = 3; n > 0; n--) {
		printf("%d\n", n);
		wait(1);
	}
	printf("FIRE!!!\n");

	time_t rawtime;
	time ( &rawtime );
	struct tm* tInfo = localtime(&rawtime);
	tInfo->tm_year = 2013 - 1900;
	tInfo->tm_mon = 8 - 1;
	tInfo->tm_mday = 3;
	mktime(tInfo);
	printf("2013.8.3 week : %d\n", tInfo->tm_wday);

	time_t now;
	time(&now);
	printf("now time() : %ld\n", now);
	struct tm* timeinfo;
	timeinfo = localtime(&now);
	printf("y : %d, m : %d, d : %d, week : %d\n", timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday, timeinfo->tm_wday);

}

#define MST (-7)
#define UTC (0)
#define CCT (+8)

void conversion() {
	time_t rawtime;
	time ( &rawtime );
	struct tm* timeinfo = localtime ( &rawtime );

	// Www Mmm dd hh:mm:ss yyyy
	// The string is followed by a new-line character ('\n') and the terminating null-character
	printf ( "The current date/time is: %s", asctime (timeinfo) );
	printf ( "The current local time is: %s", ctime (&rawtime) );

	tm* ptm = gmtime ( &rawtime );
	puts ("Current time around the World:");
	printf ("Phoenix, AZ (U.S.) :  %2d:%02d\n", (ptm->tm_hour+MST)%24, ptm->tm_min);
	printf ("Reykjavik (Iceland) : %2d:%02d\n", (ptm->tm_hour+UTC)%24, ptm->tm_min);
	printf ("Beijing (China) :     %2d:%02d\n", (ptm->tm_hour+CCT)%24, ptm->tm_min);

	time ( &rawtime );
	char buffer [80];
	strftime (buffer, 80, "Now is %Y-%m-%d %H:%M:%S", localtime(&rawtime));
	puts (buffer);

}
