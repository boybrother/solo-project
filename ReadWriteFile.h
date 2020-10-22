#ifndef READWRITEFILE_H
#define READWRITEFILE_H

void ReadInFile(std::string fileName, std::vector<std::string> &firstName, 
                std::vector<std::string> &lastName, 
                std::vector<std::vector<float>> &testScores);

void WriteFile(std::vector<std::string> firstName, std::vector<std::string> lastName, 
               std::vector<std::vector<float>> testScores, 
               std::vector<char> letterGrades, std::vector<float> testAverages, 
               float allTestAvg, std::vector<float> highestTestGrade, int highestStudent);

#endif