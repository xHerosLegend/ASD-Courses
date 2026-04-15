//
// Created by Carmine Andreozzi on 01/04/2026.
//


/*
* Design and implement a program that uses a Map to
* store the <student ID, grade> pairs contained in a file. Implement
* a method to display the distribution of grades on the screen.
 */
#include <map>
#include <iostream>
#include <string>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

void distribution_of_grades(map<string,int> medium);

int main() {
  fstream file;
  file.open("/Filetxt/Esami_studenti.txt"); //change this to your own directory
  if (!file.is_open()) {
    perror("File not found : ");
    exit(1);
  }
  map<string,int> exam_students;
  string string_file;
  int grade;
  string student_id;
  while (getline(file, string_file)) {
      istringstream ss (string_file);
      ss>>student_id;
      ss>>grade;
      exam_students[student_id] = grade;
  }
    map<string,int>::iterator ii;
    for (ii = exam_students.begin(); ii != exam_students.end();ii++) {
        cout <<"Map: "<<ii->first<<" "<<ii->second<<endl;
    }

    distribution_of_grades(exam_students);
    exam_students.clear();
    return 0;
}

void distribution_of_grades(map<string,int> medium) {
    map<string,int>::iterator ii;
    map<int,int> frequency;
    map<int,int>::iterator ff;

    for (ii = medium.begin(); ii != medium.end();ii++) {
        frequency[ii->second]++;
    }
    for (ff = frequency.begin(); ff != frequency.end();ff++) {
        cout <<"Map Freq: "<<ff->first<<" : "<<ff->second<<endl;
    }
}