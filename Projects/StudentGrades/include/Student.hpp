#ifndef STUDENT__HPP
#define STUDENT__HPP

#include <iostream>

class Student
{
    private:
        int STUDENT_ID_;
        std::string STUDENT_NAME_;
        std::string STUDENT_BIRTH_DATE_;
        std::string STUDENT_LEVEL_;
        //Grades Student_Grades_;

    public:
        Student(const int &studentid, const std::string &studentname, const std::string &studentbirthdate, const std::string &studentlevel);
        Student(const Student &other);
        void swap(Student &first, Student &second) noexcept;
        Student &operator=(Student &other);
        ~Student();

        const int &getStudentID() const;
        const std::string &getStudentName() const;
        const std::string &getStudentBirthDate() const;
        const std::string &getStudentLevel() const;

        void setStudentID(const int &studentid);
        void setStudentName(const std::string &studentname);
        void setStudentBirthDate(const std::string &studentbirthdate);
        void setStudentLevel(const std::string &studentlevel);



};


#endif //STUDENT__HPP