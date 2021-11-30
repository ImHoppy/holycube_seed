#include "finders.h"
#include <stdio.h>

int main()
{
    Generator	g;
    uint64_t	seed;

    setupGenerator(&g, MC_1_18, 0);
    for (seed = 0; ; seed++)
    {
        applySeed(&g, 0, 4269000000 + seed);

		Pos	pos = getSpawn(&g);

        int	scale = 1; // scale=1: block coordinates, scale=4: biome coordinates
        int	x = 0, y = 63, z = 0;
        int	biomeID = getBiomeAt(&g, scale, pos.x, y, pos.z);
        if (biomeID == stony_peaks)
        {
            printf("Seed %" PRId64 " has biome at "
                "block position (%d, %d).\n", (int64_t) (4269000000 + seed), x, z);
            break ;
        }
    }
    return (0);
}