#ifndef STUDENTRECORD_H
#define STUDENTRECORD_H

void StudentRecord(std::vector<std::vector<float>> &testScores, 
                   std::vector<char> &letterGrades);
void TestAverage(std::vector<std::vector<float>> allTestScores, 
                 std::vector<float> &testAverages);
float AllTestAvg(std::vector<std::vector<float>> allTestScores);
int HighScoreStudent(std::vector<std::vector<float>> allScores);
void HighestTestGrade(std::vector<std::vector<float>> allScores, 
                      std::vector<float> &highestTestGrade);

#endif