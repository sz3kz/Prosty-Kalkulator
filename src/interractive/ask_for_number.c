#include "../../include/interractive.h"

void ask_for_number(int * number_ptr){
	printf(ASK_NUMBER_PROMPT);
	scanf("%d", number_ptr);
}
