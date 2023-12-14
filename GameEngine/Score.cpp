#include "Score.h"

Score::Score() = default;

int Score::GetScore() const {
    return score;
}

void Score::GiveScoreValue(const int toAdd) {
    score += toAdd;
}

void Score::UpdateScore() {
    score++;
}

void Score::ResetScore() {
    score = 0;
}
