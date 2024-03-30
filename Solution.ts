
function minimumLevels(possible: number[]): number {
    const NOT_POSSIBLE_FOR_FIRST_PLAYER_TO_WIN = -1;
    let totalPointsForAllLevels = 0;

    for (let value of possible) {
        totalPointsForAllLevels += (value === 1) ? 1 : -1;
    }

    let minLevelsForFirstPlayerToWin = 0;

    for (let i = 0; i < possible.length - 1; ++i) {
        minLevelsForFirstPlayerToWin += (possible[i] === 1) ? 1 : -1;

        if (minLevelsForFirstPlayerToWin > totalPointsForAllLevels - minLevelsForFirstPlayerToWin) {
            return i + 1;
        }
    }
    return NOT_POSSIBLE_FOR_FIRST_PLAYER_TO_WIN;
};
