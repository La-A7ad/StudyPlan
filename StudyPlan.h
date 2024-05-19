#ifndef STUDYPLAN_H
#define STUDYPLAN_H

#include <vector>
#include <string>
#include "Semester.h"
#include "Student.h"

class StudyPlan {
private:
    std::vector<Semester*> semesters;
    Student* student;  // Pointer to the student

public:
    // Constructor
    StudyPlan(Student* stud) : student(stud) {}

    // Methods
    void addSemester(Semester& newSemester);
    void addCourseToSemester(const std::string& semesterName, const std::string& courseCode);
    bool isStudentOnProbation() const;
    bool canOverload() const;
    const std::vector<Semester*>& getSemesters() const { return semesters; }
};

#endif
