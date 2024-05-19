#include "Course.h"

// Static member initialization
std::map<std::string, Course> Course::courseCatalog = {
    {"CSAI100", Course("CSAI100", "Introduction to Computational Sciences and AI", 1, {})},
    {"CSAI101", Course("CSAI101", "Fundamentals of Programming and Computer Science", 2, {})},
    {"CSAI102", Course("CSAI102", "Digital Logic and Computer Architecture", 3, {})},
    {"CSAI151", Course("CSAI151", "Object-Oriented Programming", 3, {"CSAI101"})},
    {"CSAI201", Course("CSAI201", "Data Structures", 3, {"CSAI151"})},
    {"CSAI202", Course("CSAI202", "Introduction to Database Systems", 3, {"CSAI151"})},
    {"CSAI203", Course("CSAI203", "Introduction to Software Engineering", 3, {"CSAI101"})},
    {"CSAI204", Course("CSAI204", "Operating Systems", 3, {"CSAI201"})},
    {"CSAI205", Course("CSAI205", "Fundamentals of Circuits and Electronics", 3, {})},
    {"CSAI251", Course("CSAI251", "Algorithm Design and Analysis", 3, {"CSAI201"})},
    {"CSAI252", Course("CSAI252", "Introduction to Computer Networks", 3, {})},
    {"CSAI253", Course("CSAI253", "Machine Learning", 3, {"CSAI201", "MATH105"})},
    {"CSAI301", Course("CSAI301", "Artificial Intelligence", 3, {"CSAI201"})},
    {"CSAI302", Course("CSAI302", "Advanced Database Systems", 3, {"CSAI202"})},
    {"CSAI351", Course("CSAI351", "Principles and Practices for Secure Computing", 3, {"CSAI201"})},
    {"CSAI399", Course("CSAI399", "Internship", 4, {})},
    {"CSAI498", Course("CSAI498", "Senior Project - Part 1", 1, {})},
    {"CSAI499", Course("CSAI499", "Senior Project - Part 2", 3, {"CSAI498"})},
    {"DSAI103", Course("DSAI103", "Data acquisition in data science (ETL)", 3, {"CSAI101"})},
    {"DSAI104", Course("DSAI104", "Knowledge Representation and Reasoning", 2, {"CSAI101"})},
    {"DSAI201", Course("DSAI201", "Data Mining and Information Retrieval", 3, {"CSAI202"})},
    {"DSAI202", Course("DSAI202", "Data Governance", 2, {"DSAI203"})},
    {"DSAI203", Course("DSAI203", "Data Integration and Visualization", 3, {"DSAI103"})},
    {"DSAI305", Course("DSAI305", "Interpretability & Explainability in AI", 2, {"CSAI301"})},
    {"DSAI307", Course("DSAI307", "Statistical Inference", 3, {"MATH105"})},
    {"DSAI308", Course("DSAI308", "Deep Learning", 3, {"CSAI253"})},
    {"DSAI325", Course("DSAI325", "Introduction to Information Theory", 3, {"MATH105"})},
    {"DSAI352", Course("DSAI352", "Computer Vision", 3, {"DSAI308"})},
    {"DSAI353", Course("DSAI353", "Natural Language Processing", 3, {"DSAI308"})},
    {"DSAI402", Course("DSAI402", "Reinforcement Learning", 3, {"DSAI308"})},
    {"DSAI403", Course("DSAI403", "Nature Inspired Computation", 3, {"CSAI251"})},
    {"DSAI406", Course("DSAI406", "Machine Learning Engineering for Production (MLOps)", 3, {"DSAI308"})},
    {"DSAI413", Course("DSAI413", "Multimedia Analytics", 3, {"DSAI308"})},
    {"DSAI414", Course("DSAI414", "Social Analytics", 3, {"DSAI308"})},
    {"DSAI415", Course("DSAI415", "Cloud software development", 3, {"DSAI308"})},
    {"DSAI416", Course("DSAI416", "GIS and spatial Analytics", 3, {"DSAI308"})},
    {"DSAI417", Course("DSAI417", "Chatbots", 3, {"DSAI456"})},
    {"DSAI418", Course("DSAI418", "Conversational Agents", 3, {"DSAI456"})},
    {"DSAI427", Course("DSAI427", "Big Data Analytics", 3, {"CSAI253"})},
    {"DSAI431", Course("DSAI431", "Fuzzy logic and fuzzy system", 3, {"MATH308"})},
    {"DSAI433", Course("DSAI433", "Game Theory", 3, {"CSAI301"})},
    {"DSAI456", Course("DSAI456", "Speech recognition", 3, {"DSAI308"})},
    {"DSAI473", Course("DSAI473", "Data warehousing", 3, {})},
    {"DSAI490", Course("DSAI490", "Selected Topics in Data science and AI", 3, {})},
    {"ENGL003", Course("ENGL003", "Remedial English for Science", 1, {})},
    {"ENGL004", Course("ENGL004", "Advanced Academic Speaking & Writing", 1, {})},
    {"ENGL156", Course("ENGL156", "Technical English I", 2, {})},
    {"ENGL157", Course("ENGL157", "Technical English II", 2, {"ENGL156"})},
    {"IT101", Course("IT101", "Shell and Script Programming with UNIX", 2, {"CSAI101"})},
    {"IT102", Course("IT102", "Ethical Hacking and Defense", 2, {"CSAI101"})},
    {"IT103", Course("IT103", "Fundamentals of Information and Communication Systems", 2, {})},
    {"IT205", Course("IT205", "Enterprise System Architecture", 2, {})},
    {"IT206", Course("IT206", "Fundamentals of IT Governance and Risk Management", 2, {})},
    {"IT220", Course("IT220", "Networks Installation and Maintenance", 2, {"CSAI252"})},
    {"IT222", Course("IT222", "Fundamentals of Multimedia Creation, Storage and Transfer", 2, {"CSAI252"})},
    {"IT308", Course("IT308", "Cloud Computing Architecture", 2, {"CSAI201"})},
    {"IT309", Course("IT309", "IT User-Experience Design", 3, {})},
    {"IT310", Course("IT310", "Foundations of Cybersecurity and Security Management", 3, {"CSAI252"})},
    {"IT401", Course("IT401", "Data Centers", 3, {"CSAI252"})},
    {"IT402", Course("IT402", "Fundamentals of Cybersecurity and Encryption", 3, {"MATH205"})},
    {"IT411", Course("IT411", "Enterprise Resources Planning", 3, {})},
    {"ITCC301", Course("ITCC301", "Linux System Administration", 2, {})},
    {"ITCC302", Course("ITCC302", "Cloud Infrastructure Administration", 3, {"IT308"})},
    {"ITCC403", Course("ITCC403", "Security Testing for Cloud Applications", 3, {"IT310"})},
    {"ITCC404", Course("ITCC404", "Windows Enterprise Administration", 3, {})},
    {"ITCC405", Course("ITCC405", "Virtualization and Cloud Security", 3, {"IT308"})},
    {"ITCC406", Course("ITCC406", "Migrating Data and Applications to the Cloud", 3, {"IT308"})},
    {"ITCC407", Course("ITCC407", "Cloud Services Management", 3, {"IT308"})},
    {"ITCC408", Course("ITCC408", "Application Development and Scripting in the Cloud", 3, {"IT308"})},
    {"ITCC410", Course("ITCC410", "Software Development Operations in Cloud Environments", 3, {"CSAI203", "IT308"})},
    {"ITCC411", Course("ITCC411", "SaaS, IaaS and PaaS", 3, {})},
    {"ITCC412", Course("ITCC412", "Advanced Cloud Security", 3, {"IT308", "IT310"})},
    {"ITCC413", Course("ITCC413", "IT Security and Policy Planning", 3, {"IT310"})},
    {"ITCC414", Course("ITCC414", "IS Strategy Management and Acquisition", 3, {})},
    {"ITNS301", Course("ITNS301", "Network Administration", 2, {"CSAI252"})},
    {"ITNS302", Course("ITNS302", "IoT Systems and Application Development", 3, {"CSAI252"})},
    {"ITNS403", Course("ITNS403", "Storage Area Networks", 3, {"CSAI252"})},
    {"ITNS404", Course("ITNS404", "Network Performance Monitoring and Troubleshooting", 3, {"CSAI252"})},
    {"ITNS406", Course("ITNS406", "Network Resilience and Hardening", 3, {"CSAI252"})},
    {"ITNS407", Course("ITNS407", "IT Audit and Risk Management", 3, {})},
    {"ITNS408", Course("ITNS408", "Network Security", 3, {"IT310"})},
    {"ITNS410", Course("ITNS410", "Penetration Testing", 3, {})},
    {"ITNS411", Course("ITNS411", "Network Programming", 3, {})},
    {"ITNS412", Course("ITNS412", "IT Compliance and Quality Management", 3, {})},
    {"ITNS413", Course("ITNS413", "Emerging Networking Technologies", 3, {})},
    {"ITNS414", Course("ITNS414", "Cyber Forensics", 3, {"IT310"})},
    {"ITNS415", Course("ITNS415", "Wireless Security", 3, {"IT310"})},
    {"MATH103", Course("MATH103", "Calculus for Computational Sciences", 3, {})},
    {"MATH104", Course("MATH104", "Linear Algebra", 3, {})},
    {"MATH105", Course("MATH105", "Probability and Statistics", 3, {"MATH103"})},
    {"MATH307", Course("MATH307", "Numerical Methods", 3, {"MATH104"})},
    {"MATH205", Course("MATH205", "Discrete Mathematics for Computational Sciences", 3, {})},
    {"MATH404", Course("MATH404", "Linear and Nonlinear Programming", 3, {"MATH103"})},
    {"PHYS103", Course("PHYS103", "Physics 1", 3, {"MATH103"})},
    {"PHYS104", Course("PHYS104", "Physics 2", 3, {"PHYS103"})},
    {"SCH163", Course("SCH163", "Sustainability, Social and Ethical Issues in Computing", 2, {})},
    {"SCH261", Course("SCH261", "Engineering Project Management", 2, {})},
    {"SCH264", Course("SCH264", "Entrepreneurship and Small Business Management", 2, {})},
    {"SCH273", Course("SCH273", "Cognitive Psychology", 2, {})},
    {"SW151", Course("SW151", "Computer Architecture and Organization", 3, {"CSAI102"})},
    {"SW251", Course("SW251", "User Experience and Interaction Design", 3, {"CSAI203"})},
    {"SW252", Course("SW252", "Embedded Systems", 3, {"SW151"})},
    {"SW301", Course("SW301", "Object-Oriented Analysis and Design", 3, {"CSAI151"})},
    {"SW302", Course("SW302", "User Interface Development", 3, {"SW251"})},
    {"SW401", Course("SW401", "Parallel and Distributed Computing", 3, {"CSAI151"})},
    {"SW402", Course("SW402", "Software Project Management", 3, {"CSAI203"})},
    {"SWAPD301", Course("SWAPD301", "Software Systems Requirements Development", 3, {"CSAI203"})},
    {"SWAPD351", Course("SWAPD351", "Software Architecture and Design", 3, {"SWAPD301"})},
    {"SWAPD352", Course("SWAPD352", "Web Applications Development", 3, {"CSAI202"})},
    {"SWAPD401", Course("SWAPD401", "Software Testing, Validation, and Quality Assurance", 3, {"SWAPD301"})},
    {"SWAPD402", Course("SWAPD402", "Mobile Application Development", 3, {"CSAI201"})},
    {"SWAPD451", Course("SWAPD451", "Software Maintenance", 3, {"CSAI203"})},
    {"SWAPD452", Course("SWAPD452", "Enterprise Application Development", 3, {"CSAI202"})},
    {"SWAPD453", Course("SWAPD453", "IoT Applications Development", 3, {"CSAI252"})},
    {"SWGCG301", Course("SWGCG301", "Computer Graphics and Multimedia Systems", 3, {"CSAI201"})},
    {"SWGCG351", Course("SWGCG351", "Game Design and Development", 3, {"CSAI251"})},
    {"SWGCG352", Course("SWGCG352", "Computer and Physics-Based Animation", 3, {"SWGCG301"})},
    {"SWGCG401", Course("SWGCG401", "Design and Geometric Modeling for Visualization and Communication", 3, {})},
    {"SWGCG402", Course("SWGCG402", "Visual Effects Production", 3, {"SWGCG352"})},
    {"SWGCG451", Course("SWGCG451", "Model Creation and Character Animation", 3, {"CSAI201"})},
    {"SWGCG452", Course("SWGCG452", "Physics-Based Vision and Rendering", 3, {"SWGCG301"})},
    {"SWGCG453", Course("SWGCG453", "Mobile and Casual Game Development", 3, {"CSAI201"})},
    {"SWHCI301", Course("SWHCI301", "Prototyping Algorithmic Experiences", 3, {"CSAI251"})},
    {"SWHCI351", Course("SWHCI351", "Statistical Graphics and Visualization", 3, {"MATH105"})},
    {"SWHCI352", Course("SWHCI352", "User-Focused Sensing Systems", 3, {"SW251"})},
    {"SWHCI401", Course("SWHCI401", "Human Information Processing and Artificial Intelligence", 3, {"CSAI301"})},
    {"SWHCI402", Course("SWHCI402", "AI Based Products and Services", 3, {"CSAI301"})},
    {"SWHCI451", Course("SWHCI451", "Cognitive Modeling for HCI", 3, {"SCH273"})},
    {"SWHCI452", Course("SWHCI452", "Designing Extended Reality Experience", 3, {"SW251"})},
    {"SWHCI453", Course("SWHCI453", "Human Factors", 3, {})}
};

Course::Course(std::string code, std::string title, int creditHours, std::vector<std::string> prerequisites)
    : code(std::move(code)), title(std::move(title)), creditHours(creditHours), prerequisites(std::move(prerequisites)) {}

const std::string& Course::getCode() const {
    return code;
}

const std::string& Course::getTitle() const {
    return title;
}

int Course::getCreditHours() const {
    return creditHours;
}

const std::vector<std::string>& Course::getPrerequisites() const {
    return prerequisites;
}

std::vector<std::string> Course::searchCourse(const std::string& courseCodePrefix) {
    std::vector<std::string> results;
    for (const auto& [courseCode, courseDetails] : courseCatalog) {
        if (courseCode.find(courseCodePrefix) == 0) {
            results.push_back(courseCode);
        }
    }
    return results;
}

//Yousef Hosam Ahmed