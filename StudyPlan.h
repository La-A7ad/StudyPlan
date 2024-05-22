#ifndef STUDYPLAN_H
#define STUDYPLAN_H

#include "Semester.h"
#include <vector>
#include <set>
#include <string>

class StudyPlan {
private:
    std::vector<Semester> semesters;
    std::set<std::string> completedCourses; // Set of completed courses

public:
    void addSemester(const Semester& semester);
    void addCourseToSemester(const std::string& semesterName, const std::string& courseCode);
    void listCoursesInSemester(const std::string& semesterName) const;
    bool hasCompletedCourse(const std::string& courseCode) const;
    void markCourseAsCompleted(const std::string& courseCode);

    const std::vector<Semester>& getSemesters() const;  // Getter for semesters
};

#endif
