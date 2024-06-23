#include "hand.h"

struct player{
	int id;
	int position;
	struct hand *hand;
	enum blind blind;
	int bet;
	int stack;
	char human;
};

struct player player_init(int id, int stack);
