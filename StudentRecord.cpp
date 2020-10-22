#include <string>
#include <vector>
using namespace std;

// Function to calculate the final grade average 
// Last iteration multiplies the final exam score by 2 
// divides final sum of test scores and divides by 6
void StudentGradeAverage(std::vector<float> &testScores) {
    float gradeTotal = 0;
    float gradeAverage = 0;
    for (size_t i = 0; i < testScores.size(); i++) {
        if (i == testScores.size() - 1) {
            gradeTotal += (testScores[i] * 2);
        } else {
            gradeTotal += testScores[i];
        }
    }   
    gradeAverage = gradeTotal / 6;
    testScores.push_back(gradeAverage);
}

// Function to pull in the final grade of a student
// and assign appropriate letter grade for the class
// Adds letter grade in a separate vector 
void LetterGrade(std::vector<float> &allScores, 
                 std::vector<char> &letterGrades) {
    char letterGrade;
    float gradeAvg = allScores[5];
    if (gradeAvg > 89) {
        letterGrade = 'A';
    } 
    else if (gradeAvg > 79 && gradeAvg < 90) {
        letterGrade = 'B';
    }
    else if (gradeAvg > 74 && gradeAvg < 80) {
        letterGrade = 'C';
    }
    else if (gradeAvg > 69 && gradeAvg < 75) {
        letterGrade = 'D';
    }
    else if (gradeAvg < 70) {
        letterGrade = 'F';
    }
    letterGrades.push_back(letterGrade);
}

// Function to iterate through the outside vector of allScores (allows program to
// cycle through student-by-student)
// Calls Student Grade Average and Letter Grade functions to calculate 
// final grade and letter grade for each student
void StudentRecord(std::vector<std::vector<float>> &allScores, 
                   std::vector<char> &letterGrades) {
    for (size_t i = 0; i < allScores.size(); i++) {
        StudentGradeAverage(allScores[i]);
        LetterGrade(allScores[i], letterGrades);
    }
}

// Function to calculate the average of each test
// Adds each test average to a vector
void TestAverage(std::vector<std::vector<float>> allTestScores, 
                 std::vector<float> &testAverages) {
    for (size_t i = 0; i < 5; i++) {
        float totalTestScore = 0;
        float testAverage = 0;
        float numScores = allTestScores.size();
        for (size_t j = 0; j < numScores; j++) {
            totalTestScore += allTestScores[j][i];
        }
        testAverage = totalTestScore / numScores;
        testAverages.push_back(testAverage);
    }
}

// Function to find student with the highest final grade in the 
// class. Returns the element position for the student's records
int HighScoreStudent(std::vector<std::vector<float>> allScores) {
    int highScoreStudent = 0;
    for (int i = 0; i < allScores.size(); i++) {
        if (allScores[highScoreStudent][5] < allScores[i][5]){
            highScoreStudent = i;
        }
    }
    return highScoreStudent;
}

// Function to calculate the sum of all test scores and divide by 
// the number of tests taken to find the overall average for all tests
float AllTestAvg(std::vector<std::vector<float>> allTestScores) {
    float totalScores = 0;
    int counter = 0;
    for (int i = 0; i < allTestScores.size(); i++) {
        for (int j = 0; j < allTestScores[i].size(); j++) {
            totalScores += allTestScores[i][j];
            counter++;
        }
    }
    float allTestAvg = totalScores / counter;
    return allTestAvg;
}

// Function to find the highest test score for each test and
// add the score to a vector 
void HighestTestGrade(std::vector<std::vector<float>> allScores, 
                      std::vector<float> &highestTestGrade) {
    for (int i = 0; i < 5; i++) {
        float highestGrade = allScores[0][i];
        for (int j = 0; j < allScores.size(); j++) {
            float testTemp = allScores[j][i];
            if (highestGrade < testTemp) {
                highestGrade = testTemp;
            }
        }
        highestTestGrade.push_back(highestGrade);
    }
}