#include "card.h"

struct hand {
	enum hand_value value;
	enum rank ranks[2];
	struct card *cards;
};

/**
 * make a new hand with the community cards
 */
struct hand hand_update(struct hand *start_hand, struct card *com_cards);
