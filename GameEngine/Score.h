#pragma once
#include <xstring>

class Score {
    float Time = -1;
    
public:
    Score();
    float GetScore() const;
    std::string GetScoreAsString();
    void GiveScoreValue(float toAdd);
    void UpdateScore(float DeltaTime);
    void ResetScore();
};
