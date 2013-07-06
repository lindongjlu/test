
#include <cstdio>
#include <cstdlib>

void operationOnFiles();
void fileAccess();
void formattedInputOuput();
void characterInputOutput();
void directInputOutput();
void filePositioning();

int main(int argn, char** argv)
{
	// operationOnFiles();
	// fileAccess();
	// formattedInputOuput();
	// characterInputOutput();
	// directInputOutput();
	filePositioning();
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

void fileAccess() {

	// r, w, a, r+, w+, a+
	// t : text, b : binary
	FILE * file = fopen("myfile.txt", "wt");
	if (file != NULL) {
		puts("file open succ");
		fclose(file);
	}

	freopen("myfile.txt", "wt", stdout);
	printf("wakaka");
	fclose(stdout);

	// fflush(); arg file or NULL(all file) . empty read buf, flush write buf
	// setbuf / setvbuf
}

void formattedInputOuput() {

	// stdio, file, string
	// printf, fprintf, sprintf
	// %[flags][width][.precision][length]specifier
	// flags : - + # 0
	// lenght : h, l, L
	// specifier : c, d or i, e or E, f, u, o x X, s, p, n

	printf("Characters: %c %c \n", 'a', 65);
	printf("Decimals: %d %ld\n", 1977, 650000L);
	printf("Preceding with blanks: %10d \n", 1977);
	printf("Preceding with zeros: %010d \n", 1977);
	printf("Some different radixes: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
	printf("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
	printf("Width trick: %*d \n", 5, 10);
	printf("%s \n", "A string");

	// stdio, file, string
	// scanf, fscanf, sscanf
	//
	char input[] = "name: Soulie , age: 29 . a hexadecimal number: ff ";
	char str[80];
	int i;
	int x;
	sscanf (input, "name: %s , age: %d . a hexadecimal number: %x", str, &i, &x);

	printf ("Mr. %s , %d years old.\n", str, i);
	printf ("You have entered %#x (%d).\n", x, x);

}

void characterInputOutput() {

	// stdio, file . char , string
	// getchar gets putchar puts, fgetc fgets fputc fputs

	FILE * pFile;
	int c;
	int n = 0;
	pFile = fopen ("myfile.txt", "rt");
	if (pFile==NULL) {
		perror ("Error opening file");
	} else {
		do {
	    	c = fgetc (pFile);
	    	if (c == '$') n++;
	    } while (c != EOF);
	    fclose (pFile);
	    printf ("File contains %d$.\n",n);
	}
}

void directInputOutput() {

	FILE* file = fopen("myfile.bin", "wb+");
	if (file == NULL) {
		fputs("File error", stderr);
		return;
	}

	char data[] = {'x', 'y', 'z'};
	fwrite(data, sizeof(char), sizeof(data), file);

	size_t size;

	//obtain file size
	fseek(file, 0, SEEK_END);
	size = ftell(file);
	rewind(file);

	char* buffer = (char*) malloc (sizeof(char) * size);
	if (buffer == NULL) {
		fputs("Memory error", stderr);
		return;
	}

	size_t result = fread(buffer, sizeof(char), size, file);
	if (result != size) {
		fputs("Reading error", stderr);
		return;
	}

	printf("file size : %d", result);

	fclose (file);
	free(buffer);
}

void filePositioning() {

	FILE* file = fopen("myfile.txt", "r");
	if (file == NULL) {
		perror("Error opening file");
	} else {
		fpos_t pos = 2;
		fsetpos(file, &pos);
		fgetpos(file, &pos);
		printf("file pos %lld, value %c.", pos, fgetc(file));

		long size;
		//obtain file size
		fseek(file, 0, SEEK_END);
		size = ftell(file);
		rewind(file);

		printf("file size %ld.", size);
	}

}
