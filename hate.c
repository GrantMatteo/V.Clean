/*
 * hate.c
 *
 *  Created on: Dec 22, 2017
 *      Author: Grant
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	setvbuf(stdout, NULL, _IONBF, 0);
	int defaults[62]={0, 4, 5, 7, 9, 10, 12, 14, 15, 17, 24, 26,27,28,33,34,35,36,37,38,39,44,47,50,51,52,58,65,66,69,74,75,77,78,84,86,97,104,105,106,112,113,
			114,115,116,142,143,144,161,162,163,164,165,167,168,206,207,208,209,210,211,212};
	if (argc < 3) {
		fprintf(stderr,
				"Error with arguments. Please enter arguments in the following manner:\n"
						"V.Clean <INPUT FILEPATH> <OUTPUT FILEPATH> <COLUMN NUMBER> <COLUMN NUMBER> <COLUMN NUMBER> ...");
		return 1;
	}
	FILE *fi;
	FILE *fo;
	fi = fopen(argv[1], "r");
	fo = fopen(argv[2], "w");
	if (fi == NULL || fo == NULL) {
		fprintf(stderr,
				"Error with arguments. Please enter arguments in the following manner:\n"
						"V.Clean <INPUT FILEPATH> <OUTPUT FILEPATH> <COLUMN NUMBER> <COLUMN NUMBER> <COLUMN NUMBER> ...\n"
						"Additionally:\n"
						"Make sure you are using a single SPACE character to separate your inputs"
						"Make sure you use \"QUOTES\" to enclose any argument containing a space.");
		return 1;
	}
	bool keepers[213] = { 0 };
	bool standard=0;
	for (int i = 3; i < argc; i++) {
		int exemptCol = atoi(argv[i]);
		if (exemptCol < 213 && exemptCol > 0) {
			keepers[exemptCol - 1] = true;
		} else if (exemptCol==0){
			standard=1;
		}
	}
	if (standard){
		for (int i=0; i< 62; i++){
			keepers[defaults[i]]=true;
		}
	}


	char currentString[200];
	memset(currentString, 0, sizeof(currentString));
	bool quoted = false;
	int nextChar;
	while (1) {
		for (int i = 0; i < 212; i++) {
			nextChar = fgetc(fi);
			currentString[0] = nextChar;
			if (nextChar == '\"') {
				for (int j = 1; 1; j++) {
					nextChar = fgetc(fi);
					currentString[j] = nextChar;
					if (nextChar == '\"') {
						quoted = !quoted;

					} else if (nextChar == ',' && quoted) {
						currentString[j + 1] = '\0';
						quoted = false;
						break;
					}
				}
			} else if (nextChar != ',') {
				char temp[200];
				fscanf(fi, "%[^,]", temp);
				fscanf(fi, ",");
				strcat(temp, ",");
				strcat(currentString, temp);
				memset(temp, 0, sizeof(temp));
			}
			if (keepers[i]) {

				fprintf(fo, "%s", currentString);
			}
			memset(currentString, 0, sizeof(currentString));
		}
		fscanf(fi, "%[^\n]", currentString);
		if (keepers[212]) {
			fprintf(fo, "%s", currentString);
		}
		memset(currentString, 0, sizeof(currentString));
		nextChar = fgetc(fi);
		if (!feof(fi)) {
			fprintf(fo, "%c", nextChar);
		} else {
			break;
		}
	}
	fclose(fi);
	fclose(fo);
	return 0;
}

