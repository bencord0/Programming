#include <stdio.h>
#include <stdlib.h>

void printchar(char c) {
	int i;
	int end = sizeof(char) * 8;
	for(i=0; i<end; ++i) {
		if(0x80 & c) printf("1");
		else printf("0");

		c = c << 1;
	}
	printf("\n");

}

void printint(int c) {
	int i, split = 7;
	int end = sizeof(int) * 8;

	for(i=0; i<end; ++i) {
		if(0x80000000 & c) printf("1");
		else printf("0");

		c = c << 1;

		/* Space out each byte */
		if(!split--) {
			printf(" ");
			split = 7;
		}
	}

	printf("\n");
}

int main() {
	int i;
	for(i=0x0F8811EE;i<0x0f8811ff;++i)
		printint(i);

	printf("\n");
	return 0;
}
