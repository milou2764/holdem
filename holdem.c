#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define DECK_SIZE 52
#define BOARD_SIZE 5

struct Card{
	char rank;
	char suit; // diamond (D), clubs (C), heart (H) or spade (S)
	char printable[3];
	bool out; // wether the card is out of the deck
};

struct Card deck[DECK_SIZE];
char ranks[13] = {'2','3','4','5','6','7','8','9','T','J','Q','K','1'};
char suits[4] = {'D','C','H','S'};
struct Card board[BOARD_SIZE];

struct Card deck_draw_card() {
	char card_id = rand() % DECK_SIZE;
	while (deck[card_id].out==true){
		card_id = rand() % DECK_SIZE;
	}
	deck[card_id].out = true;
	return deck[card_id];
}

struct Card *deck_draw_n_cards(int n) {
	struct Card *cards = malloc(sizeof(struct Card) * n);
	int i;
	for (i=0; i<n; i++) {
		cards[i] = deck_draw_card();
	}
	return cards;
}

struct Card *deck_draw_hand() {
	return deck_draw_n_cards(2);
}

void print_n_cards(int n, struct Card *cards) {
	int i;
	for (i=0; i<n-1; i++) {
		printf(cards[i].printable);
		printf(" - ");
	}
	printf(cards[n-1].printable);
	printf("\n");
}

void deck_draw_flop() {
	int i;
	for (i=0; i<BOARD_SIZE; i++) {
		board[i] = deck_draw_card();
	}
mprintf("flop: ");
	print_n_cards(3,board);
}

void deck_pick_up_cards() {
	int i;
	for (i=0; i<DECK_SIZE; i++) {
		deck[i].out = false;
	}
}

void deck_init() {
	int i;
	for (i=0; i<DECK_SIZE; i++) {
		char rank_id = i%13;
		char suit_id = i/13;
		char suit = suits[suit_id];
		deck[i].rank = rank_id;
		deck[i].suit = suit;
		deck[i].printable[0] = ranks[rank_id];
		deck[i].printable[1] = suit;
		deck[i].printable[2] = '\0';
		deck[i].out = false;
	}
}

void board_init() {
	memset(&board, 0, sizeof(struct Card) * BOARD_SIZE);
}

void print_hand(struct Card hand[2]) {
	print_n_cards(2,hand);
}

int main(void) {
	// initialization shoud be called once
	srand(time(NULL));
	deck_init();
	board_init();

	struct Card *hand = deck_draw_hand();
	printf("your hand: ");
	print_hand(hand);
	deck_draw_flop();
}
