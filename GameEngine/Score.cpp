#include "Score.h"

#include <SDL_log.h>

Score::Score() = default;

int Score::GetScore() const {
    return score;
}

void Score::AddScoreValue(const int toAdd) {
    score += toAdd;
}

void Score::UpdateScore() {
    score++;
    SDL_Log("Score: %i" + score, SDL_LOG_CATEGORY_TEST);
}

void Score::ResetScore() {
    score = 0;
}
