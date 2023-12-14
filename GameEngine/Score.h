#pragma once

class Score {
    int score;
    
public:
    Score();
    int GetScore() const;
    void AddScoreValue(int toAdd);
    void UpdateScore();
    void ResetScore();
};
