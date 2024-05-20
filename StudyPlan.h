#ifndef STUDYPLAN_H
#define STUDYPLAN_H

#include "Semester.h"
#include <vector>
#include <string>

class StudyPlan {
private:
    std::vector<Semester> semesters;
    Student student;  // Declare the student member if necessary

public:
    StudyPlan() = default;
    void addSemester(const Semester& newSemester);
    void addCourseToSemester(const std::string& semesterName, const std::string& courseCode);
    bool isStudentOnProbation() const;
    bool canOverload() const;
    std::vector<Semester>& getSemesters();  // Add this method
};

#endif
