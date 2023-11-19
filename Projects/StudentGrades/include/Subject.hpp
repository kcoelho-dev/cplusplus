#ifndef SUBJECT__HPP
#define SUBJECT__HPP

#include <iostream>

class Subject
{
    private:
        int SUBJECT_ID_;
        std::string SUBJECT_NAME_;
        int SUBJECT_WORKLOAD_;
    public:
        Subject(const int &subjectid, const std::string &subjectname, const int &subjectworload);
        Subject(const Subject &other);
        void swap(const Subject &first, const Subject &second) noexcept;
        Subject &operator=(const Subject &other);
        ~Subject();


        const int &getSubjectID() const;
        const std::string &getSubjectName() const;
        const int &getSubjectWorkload() const;

        void setSubjectID(const int &subjectid);
        void setSubjectName(const std::string &subjectname);
        void setSubjectWorkload(const int &subjectworkload);
};

#endif //SUBJECT__HPP