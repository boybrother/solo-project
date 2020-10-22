#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include "ReadWriteFile.h"
#include "StudentRecord.h"
using namespace std;

int main() {
  // Define neccessary variables to later store .txt file input
  vector<string> firstName;
  vector<string> lastName;
  vector<vector<float>> testScores;
  vector<char> letterGrades;
  vector<float> testAverages;
  string fileName;

  // Prompt user to enter the full .txt file name containing student names 
  //  and scores
  cout << "Please enter file name:" << endl;
  cin >> fileName;

  // Call function to read in the .txt file and store in appropriate variables
  ReadInFile(fileName, firstName, lastName, testScores);

  // Call Student Record function to iterate through outside vector of vectors 
  // for test scores. Nested within Student Record function - Student Grade
  // Average and Letter Grade are called, calculated, and added to the end of each
  // students' vector
  StudentRecord(testScores, letterGrades);

  // Call function to calculate the average score for each individual test
  TestAverage(testScores, testAverages);

  // Declare variable to store average score of all tests combined and
  // call function to calculate average of all test scores
  float allTestAvg = AllTestAvg(testScores);

  // Call function to return the element position for the student with the 
  // highest score
  int highestStudent = HighScoreStudent(testScores);
  
  // Declare vector to store highest grade for each test and call function
  // to calculate and assign highest scores for each test
  vector<float> highestTestGrade;
  HighestTestGrade(testScores, highestTestGrade);

  // Call function to write all calculations to an organized tabular
  // grade report
  WriteFile(firstName, lastName, testScores, letterGrades, testAverages, 
            allTestAvg, highestTestGrade, highestStudent);

}