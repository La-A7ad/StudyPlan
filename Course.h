#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>

class Course {
private:
    std::string code;
    int credits;
    std::vector<std::string> prerequisites;

public:
    Course(std::string c, int cr, std::vector<std::string> prereqs)
        : code(c), credits(cr), prerequisites(prereqs) {}

    std::string getCode() const { return code; }
    int getCredits() const { return credits; }
    const std::vector<std::string>& getPrerequisites() const { return prerequisites; }

    static std::map<std::string, Course> CourseCatalog;
};

#endif
