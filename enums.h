enum action {
	FOLD,
	RAISE,
	CALL,
	BET,
	ALLIN,
};

enum blind {
	SB,
	BB,
};

enum street {
	PREFLOP=0,
	FLOP=1,
	TURN=2,
	RIVER=3,
};

enum hand_value {
	HVUK = -1, // unknown
	HVHC,
	HVPAIR,
	HVTP, // two pairs
	HVTOAK, // three of a kind
	HVSTRAIGHT, // sequence in increasing value (ace can precede 2)
	HVFLUSH, // 5 cards of the same suit
	HVFH, // full house - three of a kind and a pair
	HVFOAK, // four of a kind
	HVSF, // straight flush
};

enum suit {
	DIAMOND = 'D',
	CLUBS = 'C',
	HEART = 'H',
	SPADE = 'S',
};

enum rank {
	TWO = 0,
	THREE = 1,
	FOUR = 2,
	FIVE = 3,
	SIX = 4,
	SEVEN = 5,
	HEIGHT = 6,
	NINE = 7,
	TEN = 8,
	JACK = 9,
	QUEEN = 10,
	KING = 11,
	ACE = 12,
};
