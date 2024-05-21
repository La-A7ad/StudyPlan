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
    void addSemester(const Semester& semester);
    void addCourseToSemester(const std::string& semesterName, const std::string& courseCode);
    void listCoursesInSemester(const std::string& semesterName) const;
};

#endif // STUDYPLAN_H
