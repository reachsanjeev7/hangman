#include<stdio.h>
#include<string.h>
#define SIZE 10
#define stages 7
void hangmans(int miss_count)
{
	if (miss_count == 1) {
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("-+-\n");
	}
	if (miss_count == 2) {
		printf("\n");
		printf(" |\n");
		printf(" |\n");
		printf(" |\n");
		printf("-+-\n");
	}
	if (miss_count == 3) {
		printf(" +---\n");
		printf(" |\n");
		printf(" |\n");
		printf(" |\n");
		printf("-+-\n");
	}
	if (miss_count == 4) {
		printf(" +--+\n");
		printf(" |  O\n");
		printf(" |\n");
		printf(" |\n");
		printf("-+-\n");
	}
	if (miss_count == 5) {
		printf(" +--+\n");
		printf(" |  O\n");
		printf(" |  |\n");
		printf(" |\n");
		printf("-+-\n");
	}
	if (miss_count == 6) {
		printf(" +--+\n");
		printf(" |  O\n");
		printf(" | /|\\\n");
		printf(" |\n");
		printf("-+-\n");
	}
	if (miss_count == 7) {
		printf(" +--+\n");
		printf(" |  O\n");
		printf(" | /|\\\n");
		printf(" | / \\\n");
		printf("-+-\n");
	}
}
int main(void)
{
	srand(time(NULL));
	int count = 1, i, randindex, temp;
	char words[][SIZE] = {"INDIA", "ZILOGIC", "VECTOR", "AUSTRALIA",
				"ASIA", "CHENNAI", "BEACH", "CENTRAL",
				"EMBEDDED", "SYSTEMS"};
	char randword[SIZE], ch, tempstring[SIZE];

	for (i = 0; i < SIZE; i++)
		tempstring[i] = ' ';
	randindex = rand()%SIZE;
	strcpy(randword, words[randindex]);
	printf("random word = %s\n", randword);
	tempstring[strlen(randword)] = '\0';
	while (1) {
		temp = 0;
		printf("enter a letter :\n");
		scanf(" %c", &ch);
		for (i = 0; i < strlen(randword); i++) {
			if (ch == randword[i]) {
				tempstring[i] = randword[i];
				temp++;
			}
		}
		for (i = 0; i < strlen(randword); i++)
			printf("%c ", tempstring[i]);
		printf("\n");
		if (temp == 0)
			hangmans(count++);
		if ((strcmp(randword, tempstring)) == 0)
			break;
		if (count > stages)
			break;
	}
}
