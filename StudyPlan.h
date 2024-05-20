#ifndef STUDYPLAN_H
#define STUDYPLAN_H

#include <vector>
#include <string>
#include "Semester.h"
#include "Student.h"

class StudyPlan {
private:
    std::vector<Semester> semesters;
    Student student;

public:
    StudyPlan() = default;
    void addSemester(const Semester& semester);
    void addCourseToSemester(const std::string& semesterName, const std::string& courseCode);
    bool isStudentOnProbation() const;
    bool canOverload() const;
    const std::vector<Semester>& getSemesters() const; 
};

#endif
