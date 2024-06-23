#include "utils.h"

struct player* settle_ties_hc(struct player *ply1, struct player *ply2)
{
	struct hand *hand1 = ply1->hand;
	struct hand *hand2 = ply2->hand;
	return ply1;
}

struct player* settle_ties(struct player *ply1, struct player *ply2)
{
	struct hand *hand1 = ply1->hand;
	struct hand *hand2 = ply2->hand;
	switch(hand1->value) {
		case HIGH_CARD:
			return settle_ties_hc(ply1, ply2);
		case PAIR:
			//TODO
			break;
		case TP:
			//TODO
			break;
		case TOAK:
			//TODO
			break;
		case STRAIGHT:
			//TODO
			break;
		case FLUSH:
			//TODO
			break;
		case FH:
			//TODO
			break;
		case FOAK:
			//TODO
			break;
		case SF:
			//TODO
			break;
	}
			
	return ply1;
}
