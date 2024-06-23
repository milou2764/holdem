#include "player.h"

struct player player_init(int id, int stack)
{
	struct player ply;
	ply.id = id;
	ply.stack = stack;
	return ply;
}
