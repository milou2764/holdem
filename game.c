#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define DECK_SIZE 52
#define BOARD_SIZE 5
#include "player.h"



struct game{
	struct card deck[DECK_SIZE];
	struct Player players[2];
};

char ranks[13] = {'2','3','4','5','6','7','8','9','T','J','Q','K','1'};
struct card board[BOARD_SIZE];

struct card game_draw_card(struct game *game) {
	int card_id = rand() % DECK_SIZE;
	while (game->deck[card_id].out==true){
		card_id = rand() % DECK_SIZE;
	}
	game->deck[card_id].out = true;
	return game->deck[card_id];
}

struct card *game_draw_n_cards(struct game *game, int n) {
	struct Card *cards = malloc(sizeof(struct Card) * n);
	int i;
	for (i=0; i<n; i++) {
		cards[i] = game_draw_card(game);
	}
	return cards;
}

struct Card *game_draw_hand(struct game *game) {
	return game_draw_n_cards(game, 2);
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

void game_draw_flop(struct game *game) {
	int i;
	for (i=0; i<BOARD_SIZE; i++) {
		board[i] = game_draw_card(game);
	}
	printf("flop: ");
	print_n_cards(3,board);
}

void game_pick_up_cards(struct game *game) {
	int i;
	for (i=0; i<DECK_SIZE; i++) {
		game->deck[i].out = false;
	}
}

void game_init(struct game *game) {
	int i;
	for (i=0; i<DECK_SIZE; i++) {
		int rank_id = i%13;
		int suit_id = i/13;
		char suit = suits[suit_id];
		game->deck[i].rank = rank_id;
		game->deck[i].suit = suit;
		game->deck[i].printable[0] = ranks[rank_id];
		game->deck[i].printable[1] = suit;
		game->deck[i].printable[2] = '\0';
		game->deck[i].out = false;
	}
}

void board_init() {
	memset(&board, 0, sizeof(struct Card) * BOARD_SIZE);
}

void print_hand(struct Card hand[2]) {
	print_n_cards(2,hand);
}

int main(void) {
	struct game game;
	// initialization shoud be called once
	srand(time(NULL));
	game_init(&game);
	board_init();

	struct Card *hand = game_draw_hand(&game);
	printf("your hand: ");
	print_hand(hand);
	game_draw_flop(&game);
}
