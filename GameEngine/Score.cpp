#include "Score.h"

#include <format>
#include <string>

Score::Score() = default;

float Score::GetScore() const {
    return Time;
}

std::string Score::GetScoreAsString() {
    return std::format("{:.2f}", Time);
}

void Score::GiveScoreValue(float toAdd) {
    Time += toAdd;
}

void Score::UpdateScore(float DeltaTime) {
    Time += DeltaTime;
}

void Score::ResetScore() {
    Time = 0;
}
