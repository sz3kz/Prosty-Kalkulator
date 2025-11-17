#include "../include/main.h"

int main(int argc, char * argv[]){
	bool is_interractive = false;
	if (argc != INTERRACTIVE_MODE_ARGUMENT_COUNT){
		puts("Invalid program invocation!");
		printf("Usage: %s -i\n", argv[0]);
		return -1;
	}
	if (argc == INTERRACTIVE_MODE_ARGUMENT_COUNT ){
		if (strcmp(argv[1], "-i") != 0){
			puts("Invalid switch!");
			printf("Usage: %s -i\n", argv[0]);
			return -1;
		}
		is_interractive = true;
	}
	puts("Hello World!");
	return 0;
}
