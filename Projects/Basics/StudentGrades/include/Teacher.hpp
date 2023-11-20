#ifndef TEACHER__HPP
#define TEACHER__HPP

#include "Subject.hpp"
#include <iostream>

class Teacher
{
    private:
        int TEACHER_ID_;
        std::string TEACHER_NAME_;
        Subject TEACHER_SUBJECT_;
    public:
        Teacher(const int &teacherid, const std::string &teachername, const Subject &teachersubject);
        Teacher(const Teacher &other);
        void swap(Teacher &first, Teacher &second) noexcept;
        Teacher &operator=(Teacher &other);
        ~Teacher();

        const int &getTeacherID() const;
        const std::string &getTeacherName() const;
        const Subject &getTeacherSubject() const;

        void setTeacherID(const int &teacherid);
        void setTeacherName(const std::string &teachername);
        void setTeacherSubject(const Subject &teachersubject);


};


#endif //TEACHER__HPP