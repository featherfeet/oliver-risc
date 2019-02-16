#include <stdlib.h>
#include <string.h>
#include "stringproc.h"

char *stripWhitespace(char *s) {
	int len = strlen(s);
	int spaces = 0;
	for (int i = 0; i < len; i++) {
		if (s[i] == ' ') {
			spaces++;
		}
	}
	char *new_s = malloc(len - spaces + 1);
	int i = 0;
	int j = 0;
	while (i < (len - spaces + 1)) {
		if (s[j] != ' ' && s[j] != '\t' && s[j] != '\n') {
			new_s[i] = s[j];
			i++;
		}
		j++;
	}
	return new_s;
}

void splitOnCharacter(char *s, char ch, char **a, char **b) {
	int len = strlen(s);
	int split_index = 0;
	for (int i = 0; i < len; i++) {
		if (s[i] == ch) {
			split_index = i;
		}
	}
	*a = malloc(split_index + 1);
	strncpy(*a, s, split_index);
	(*a)[split_index] = '\0';
	*b = malloc(len - split_index);
	strcpy(*b, &s[split_index + 1]);
}
