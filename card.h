#include "enums.h"

struct card{
	enum rank rank;
	enum suit suit; // diamond (D), clubs (C), heart (H) or spade (S)
	char printable[3];
	char out; // wether the card is out of the deck
};


