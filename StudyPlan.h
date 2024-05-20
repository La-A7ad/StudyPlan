#ifndef STUDYPLAN_H
#define STUDYPLAN_H

#include "Semester.h"
#include <vector>
#include <string>

class StudyPlan {
private:
    std::vector<Semester> semesters;

public:
    StudyPlan() = default;  // Default constructor
    void addSemester(const Semester& semester);
    void addCourseToSemester(const std::string& semesterName, const std::string& courseCode);
    bool isStudentOnProbation() const;
    bool canOverload() const;
};

#endif
