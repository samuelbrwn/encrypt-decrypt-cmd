#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Global Variable declaration*/
char str1[50];
int i;
FILE* fptr;

/*FUNCTIONS*/
void anythingelse(); /*prototype*/

/*Time delay function*/
void delay(double seconds) {

	double milli_seconds = 1000 * seconds;

	clock_t start_time = clock();

	while (clock() < start_time + milli_seconds);

}

int welcome() {
	int val;

	for (i = 0; i < 25; i++) {
		delay(.01);
		printf("*");
	}
	i = 0;
	printf("WELCOME");
	for (i = 0; i < 25; i++) {
		delay(.01);
		printf("*");
	}
	printf("\n");

	val = encrypt_decrypt();

	return val;
}

/*File Handling Function*/
FILE* open_file(int x) {
	
	if (x == 1) {
		printf("Enter the name of the file you wish to encrypt: ");
		scanf("%49s", str1);
		printf("\n\n");

		fptr = fopen(str1, "r");
	}
	else {
		printf("Enter the name of the file you wish to decrypt: ");
		scanf("%49s", str1);
		printf("\n\n");

		fptr = fopen(str1, "r");
	}

	return fptr;
}

/*Encryption & Decryption Functions*/
void encrypt(int x) {

	FILE* file = open_file(x);

	if (file == NULL) {						/*if null pointer to file, error out.*/
		printf("Error! No file by this name was found.\n");
	} else {

		int c;
		int ch1;
		char name[64];

		int* pointer_ch1 = &ch1;


		printf("Your original file will be deleted. Do you wish to continue [1 for yes || 2 for no]: ");
		scanf("%d", pointer_ch1);


		if (ch1 == 1) {

			printf("Please name your new encrypted file to be created: ");
			scanf("%63s", name);

			FILE* new_file = fopen(name, "w");

			printf("\n\n Encrypting");
			for (i = 0; i < 3; i++) {
				delay(.5);
				printf(". ");
			}

			c = fgetc(file);
			while (c != EOF)
			{
				c = c + 255;
				fprintf(new_file, "%c", c);
				c = fgetc(file);
			}

			fclose(new_file);
			fclose(file);

			printf("\n Successfully Encrypted.");

			int ret = remove(str1);

			if (ret == 0) {
				printf("\nFile Deleted.");
			}
			else {
				printf("\nCould not delete file.");
			}
		}
		else {
			
			fclose(file);
			printf("\n Thank you. Goodbye!");
			exit(0);
		}
	}

	anythingelse();
}

void decrypt(int x) {

	FILE* file = open_file(x);

	if (file == NULL) {						/*if null pointer to file, error out.*/
		printf("Error! No file by this name was found.\n");
	}
	else {
		int c;
		int ch1;
		char name[64];

		int* pointer_ch1 = &ch1;

	/*	if (c = fgetc(file) > 255) {
			printf("File is already decrypted.\n");
			exit(0);
		}*/

		printf("Your encrypted file will be deleted. Do you wish to continue [1 for yes || 2 for no]: ");
		scanf("%d", pointer_ch1);

		if (ch1 == 1) {

			printf("Please name your new encrypted file to be created: \n");
			scanf("%63s", name);

			FILE* new_file = fopen(name, "w");

			printf("\n\n Decrypting");
			for (i = 0; i < 3; i++) {
				delay(.5);
				printf(". ");
			}

			
			c = fgetc(file);
			while (c != EOF)
			{
				c = c - 255;
				fprintf(new_file, "%c", c);
				c = fgetc(file);
			}

			fclose(new_file);
			fclose(file);

			printf("\n Successfully decrypted.");

			int ret = remove(str1);

			if (ret == 0) {
				printf("\nFile Deleted.");
			}
			else {
				printf("\nCould not delete file.");
			}
		}
		else {

			fclose(file);
			printf("\n Thank you. Goodbye!");
			exit(0);
		}
	}

	anythingelse();
}


int encrypt_decrypt() {

	int option = 0;
	int *poption = NULL;

	poption = &option;
	
	printf("Would you like to encrypt or decrypt a file? [1 for encrypt || 2 for decrypt]: \n");
	scanf("%d", poption);

	if (option == 1) {
		return 1;
	}
	else if (option == 2) {
		return 2;
	}
	else {
		printf("Entry invalid, please enter a valid input\n");
		encrypt_decrypt();
		return 0;
	}


}

void anythingelse() {
	int option = 0;
	int* poption = NULL;

	poption = &option;

	printf("\nWould you like to encrypt or decrypt more files? [1 for Encrypt || 2 for Decrypt || 3 for NO]: ");
	scanf("%d", poption);

	if (option == 1) {
		encrypt(option);
	}
	else if (option == 2) {
		decrypt(option);
	}
	else if (option == 3) {
		printf("Thank you!\n");

		for (i = 0; i < 25; i++) {
			delay(.01);
			printf("*");
		}
		i = 0;
		printf("GOODBYE");
		for (i = 0; i < 25; i++) {
			delay(.01);
			printf("*");
		}
		printf("\n");
	}
}

main() {
	int val = 0;

	val = welcome();

	if (val == 1) {
		encrypt(val);
	}
	else {
		decrypt(val);
	}

}