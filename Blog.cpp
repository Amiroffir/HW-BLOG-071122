#include "Blog.h"
#include <iostream>
#pragma warning(disable:4996)

Blog::Blog(char uName[100], int blogSize) {
	strcpy(name, uName);
	strcat(name, ".txt");
	if (blogSize > strlen(text)) {
		printf("Blog size is too big");
		printf("blog size set to %d", strlen(text));
		blogSize = strlen(text);
	}
	lineCount = 0;
};
void Blog:: Print() {
	printf("This is your blog content:\n");
	printf("Blog name: %s\n", name);
	printf("Blog text: %s", text);
}
void Blog::AddLine(char* line) {
	if (lineCount == 0) {
		strcpy(text, line);
	}
	else {
		strcat(text, line);
	}
	strcat(text, "\n");
	lineCount++;
}
void Blog::loadFromFile() {
	FILE* file = fopen(name, "r");
	if (file == NULL) {
		printf("File not found");
		return;
	}
	char line[100];
	while (fgets(line, 100, file) != NULL) {
		AddLine(line);
	}
	fclose(file);
}
void Blog::saveInFile() {
	FILE* file = fopen(name, "w");
	if (file == NULL) {
		printf("File not found");
		return;
	}
	fputs(text, file);
	fclose(file);
}