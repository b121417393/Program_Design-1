#include <stdio.h>
#include <string.h>

//耞琌才Α
void usage(int a, char *b[], int *c) {

	int i = 0, count = 0;

	for (i = 1; i < a; i++)
		if (strcmp(b[i], "-c") == 0 || strcmp(b[i], "-m") == 0 || strcmp(b[i], "-v") == 0)
			count++;

	if (count != 1) {
		printf("please input a correct option\n-c: print pattern counts\n-m: find lines containing a pattern\n-v: find lines not containing a pattern\n");
		*c = 1;
	}
}

//祘Α
int main(int argc, char *argv[]) {

	char words[100][1000] = { {0} }, temp[10] = { 0 };
	int i = 0, j = 0, count = 0, flag = 0;
	int Num = 0, paralen = 0, wordslen = 0;
	int k = 0, l = 0, m = 0, same = 0;

	while (fgets(words[i], 1000, stdin) != NULL) {
		i++;
		count++;
	}

	usage(argc, argv, &flag);

	if (flag == 0) {

		for (i = 1; i < argc; i++) {
			if (strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "-m") == 0 || strcmp(argv[i], "-v") == 0)
				break;
		}

		for (j = 1; j < argc; j++) {
			if (strcmp(argv[j], "-c") != 0 && strcmp(argv[j], "-m") != 0 && strcmp(argv[j], "-v") != 0)
				break;
		}

		strcpy(temp, argv[j]);
		paralen = strlen(temp);

		//把计-c
		if (strcmp(argv[i], "-c") == 0) {

			for (k = 0; k < count; k++) {
				wordslen = strlen(words[k]);
				for (l = 0; l < wordslen - paralen; l++) {
					for (m = 0, same = 1; m < paralen; m++) {
						if (words[k][l + m] != temp[m]) {
							same = 0;
							break;
						}
					}

					if (same == 1)
						Num++;
				}
			}
			printf("%s: %d\n", temp, Num);
		}

		//把计-m
		else if (strcmp(argv[i], "-m") == 0) {

			for (k = 0; k < count; k++) {
				wordslen = strlen(words[k]);
				for (l = 0; l < wordslen - paralen; l++) {
					for (m = 0, same = 1; m < paralen; m++) {
						if (words[k][l + m] == temp[m])
							continue;
						else {
							same = 0;
							break;
						}
					}

					if (same == 1) {
						printf("%s", words[k]);
						break;
					}
				}
			}
		}

		//把计-v
		else if (strcmp(argv[i], "-v") == 0) {

			for (k = 0; k < count; k++) {
				same = 0;
				wordslen = strlen(words[k]);
				for (l = 0; l < wordslen - paralen; l++) {
					for (m = 0, same = 1; m < paralen; m++) {
						if (words[k][l + m] == temp[m])
							continue;
						else {
							same = 0;
							break;
						}
					}
					if (same == 1)
						break;
				}
				if (same != 1)
					printf("%s", words[k]);
			}
		}
	}

	return 0;
}
