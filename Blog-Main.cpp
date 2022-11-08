#include "Blog.h"
#include <iostream>

#pragma warning(disable:4996)

int main() {

	int blogSize;
	char blogName[100];
	char ind = 'y';
	char menu = 'y';
	char choice;
	
	printf("Enter blog name: ");
	scanf("%s", blogName);
	printf("Enter blog size: ");
	scanf("%d", &blogSize);
	
	Blog* myBlog = new Blog(blogName, blogSize);
	
	// user response menu
	while (menu == 'y') {
		printf("What do you want to do?\n");
		printf("1. Add line\n");
		printf("2. Print blog\n");
		printf("3. Load from file\n");
		printf("4. Save in file\n");
		printf("5. Exit\n");
		
		scanf(" %c", &choice);
		
		switch (choice) {
		case '1':
			while (ind == 'y') {

				char line[100];
				printf("Enter line: ");
				scanf("%s", line);
				myBlog->AddLine(line);
				printf("Another line? (y/n): ");
				scanf("%s", &ind);
			}
			break;
		case '2':
			myBlog->Print();
			break;
		case '3':
			myBlog->loadFromFile();
			break;
		case '4':
			myBlog->saveInFile();
			break;
		case '5':
			menu = 'n';
			break;
		default:
			printf("Invalid choice\n");
			break;
		}
	}

}