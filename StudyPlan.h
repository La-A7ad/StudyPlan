#ifndef STUDYPLAN_H
#define STUDYPLAN_H

#include <vector>
#include <string>
#include "Semester.h"
#include "Student.h"

class StudyPlan {
private:
    std::vector<Semester> semesters;
    Student* student;

public:
    void addCourseToSemester(const std::string& semesterName, const std::string& courseCode);
    void addSemester(const Semester& newSemester);
    bool isStudentOnProbation() const;
    bool canOverload() const;
    std::vector<Semester>& getSemesters() const; // Added & for returning reference

};

#endif
