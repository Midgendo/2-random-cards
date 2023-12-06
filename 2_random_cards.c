#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
	char type;
	char symbol;
}Card;

char classify(int i){
	switch(i){
		case 0: return 'A';
		case 9: return '0';
		case 10: return 'J';
		case 11: return 'Q';
		case 12: return 'K';
		default: return i + 49;
	}
}

void swap(Card *c1, Card *c2){
    Card temp = *c1;
    *c1 = *c2;
    *c2 = temp;
}

char* stype(Card *card){
	if((card->type <= '7' && card->type >= '2') || card->type == '9'){
		static char str[3];
		sprintf(str, " %c", card->type);
		return str;
	}else{
		switch(card->type){
			case 'A': return "n ace";
			case '0': return " 10";
			case '8': return "n 8";
			case 'J': return " jack";
			case 'Q': return " queen";
			case 'K': return " king";
		}
	}
}

char* ssymbol(Card *card){
	switch(card->symbol){
		case 'S': return "spades";
		case 'D': return "diamonds";
		case 'H': return "hearts";
		case 'C': return "clubs";
	}
}

int main(){
	srand(time(NULL));
	Card cards[52];
	int j, type, dcard1, dcard2;

	for(int i = 0; i < 52; i++){
		type = i / 13;
		switch(type){
			case 0: cards[i].symbol = 'S'; j = 0; break;
			case 1: cards[i].symbol = 'D'; j = 13; break;
			case 2: cards[i].symbol = 'H'; j = 26; break;
			case 3: cards[i].symbol = 'C'; j = 39;
		}
		cards[i].type = classify(i - j);
	}

	for(int i = 0; i < 100; i ++){
		swap(&cards[rand() % 52], &cards[rand() % 52]);
	}
	

	for(int i = 0; i < 52; i++){
		if(i != 0 && i % 13 == 0){
			printf("\n");
		}
		printf("%c%c ", cards[i].type, cards[i].symbol);
	}
	printf("\n");

	dcard1 = rand() % 52;
	do{
		dcard2 = rand() % 52;
	}while(dcard2 == dcard1);

	printf("A%s of %s and a%s of %s was drawn\n", 
		stype(&cards[dcard1]), ssymbol(&cards[dcard1]), stype(&cards[dcard2]), ssymbol(&cards[dcard2]));
	return 0;
}