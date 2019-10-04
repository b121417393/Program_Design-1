#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(char a[], char b[]) {

	char temp[1200];

	strcpy(temp, a);
	strcpy(a, b);
	strcpy(b, temp);
}

void sort(char **words, int N) {

	int i = 0, j = 0, min = 0;

	for (i = 0; i < N - 1; i++) {
		min = i;
		for (j = i + 1; j < N; j++) 
			if (strcmp(words[j], words[min]) < 0)
				min = j;
		swap(words[min], words[i]);
	}
}

int main(void) {

	char *words[1200], temp[1200];
	int i = 0, count = 0;

	while (fgets(temp, 1200, stdin) != NULL) {
		words[i] = (char*)malloc(1200 * sizeof(char));
		strcpy(words[i], temp);
		i++;
		count++;
	}

	sort(words, count);

	for (i = 0; i < count; i++) {
		printf("%s", words[i]);
		free(words[i]);
	}

	return 0;
}
