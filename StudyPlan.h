#ifndef STUDYPLAN_H
#define STUDYPLAN_H

#include "Semester.h"
#include "Student.h"
#include <vector>
#include <string>

class StudyPlan {
private:
    std::vector<Semester*> semesters;
    Student* student;

public:
    StudyPlan(Student* stud) : student(stud) {}
    void addCourseToSemester(const std::string& semesterName, const std::string& courseCode);
    void addSemester(Semester& newSemester);
    bool isStudentOnProbation() const;
    bool canOverload() const;
    const std::vector<Semester*>& getSemesters() const { return semesters; }
};

#endif
