
#include <cstdio>

void operationOnFiles();

int main(int argn, char** argv)
{
	operationOnFiles();
	return 0;
}

void operationOnFiles() {

	if (remove("abc.txt") != 0) {
		perror("remove error");
	} else {
		puts("remove succ");
	}

	if (rename("abc.txt", "cba.txt") != 0) {
		perror("rename error");
	} else {
		puts("rename succ");
	}

	FILE * pFile = tmpfile();
	if (pFile != NULL) {
		puts("create tmp file succ");
		fclose(pFile);
	}

	char buffer[L_tmpnam];
	if (tmpnam(buffer) != NULL) {
		printf("create tmp file %s succ", buffer);
	}

}
