#pragma once

class Score {
    int score;
    
public:
    Score();
    int GetScore() const;
    void GiveScoreValue(int toAdd);
    void UpdateScore();
    void ResetScore();
};
