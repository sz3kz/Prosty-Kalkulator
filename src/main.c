#include "../include/main.h"
#include "../include/interractive.h"

int main(int argc, char * argv[]){
	bool is_interractive = false;
	if (argc != INTERRACTIVE_MODE_ARGUMENT_COUNT){
		puts("Invalid program invocation!");
		print_help(argv);
		return -1;
	}
	if (argc == INTERRACTIVE_MODE_ARGUMENT_COUNT ){
		if (strcmp(argv[INTERRACTIVE_SWITCH], "-i") != 0){
			puts("Invalid switch!");
			print_help(argv);
			return -1;
		}
		is_interractive = true;
	}
	puts("Hello World!");
	return 0;
}
