#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// Function to read in all information from .txt file and use string streams 
// to store information into vectors
void ReadInFile(string fileName, vector<string> &firstName, vector<string> &lastName, 
                vector<vector<float>> &testScores) {
string first, last, line;
float t1, t2, t3, t4, tf;
stringstream ss;
ifstream inFS;
inFS.open(fileName);

if (inFS.is_open()) {
  while (!inFS.eof() && inFS.good()) {
    inFS >> first >> last >> t1 >> t2 >> t3 >> t4 >> tf;
    firstName.push_back(first);
    lastName.push_back(last);
    vector<float> temp = {t1, t2, t3, t4, tf};
    testScores.push_back(temp);
  }
}
  inFS.close();
}

// Function to output all calculations and student records into organized, tabular
// Grade Report
void WriteFile(std::vector<std::string> firstName, std::vector<std::string> lastName, 
               std::vector<std::vector<float>> testScores, std::vector<char> letterGrades, 
               std::vector<float> testAverages, float allTestAvg, 
               std::vector<float> highestTestGrade, int highestStudent) {
  ofstream outFS;
  outFS.open ("Class Grade Report.txt");

  // Lines 42 - 46 build the top of the template for the tabular grade report

  outFS << "GRADE REPORT" << endl;
  outFS << setw(110) << setfill('-') << "-" << endl;
  outFS << "Student Name        |  1st Test  |  2nd Test  |  3rd Test  |  4th Test  | ";
  outFS << "Final Exam | Final Grade |  Grade  " << endl;
  outFS << setw(110) << setfill('-') << "-" << endl;
  outFS << fixed << setprecision(2);

  // Lines 52 - 58: Outside for loop outputs student name and final letter grade
  // Inside for loop outputs test grades and final numerical grade

  for (size_t i = 0; i < firstName.size(); i++) {
    outFS << firstName[i] << " " << lastName[i] << setw(20 - (firstName[i].size() + lastName[i].size())) << setfill(' ');
    for (size_t j = 0; j < 6; j++) {
      outFS << "|" << setw(9) << setfill(' ') << testScores[i][j] << "   ";  
    }
    outFS << " |    " << letterGrades[i];
    outFS << endl;
  }
  outFS << endl;

  // Lines 64 - 72: Output the average grades of each test and overall test average

  for (size_t i = 0; i < testAverages.size(); i++) {
    if (i < (testAverages.size() - 1)) {
      outFS << "Test " << i + 1 << " Average Grade: " << testAverages[i] << endl;
    } else {
      outFS << "Final Exam Average Grade: " << testAverages[i] << endl;
    }
  }
  outFS << "Average of All Test Grades: " << allTestAvg << endl;
  outFS << endl;

  // Lines 76-77: Outputs highest grade in the class for each test

  for (size_t i = 0; i < highestTestGrade.size(); i++) {
    outFS << "Test " << i + 1 << " Highest Grade: " << highestTestGrade[i] << endl;
  }
  outFS << endl;

  // Lines 83-84: Outputs student with the highest final grade

  outFS << "Student with Highest Grade: " << firstName[highestStudent] << " ";
  outFS << lastName[highestStudent] << endl;
}