#ifndef GRADE__HPP
#define GRADE__HPP

#include <iostream>

class Grade
{
    private:
        int GRADE_ID_;
        double GRADE_VALUE_;
        std::string GRADE_UP_DATE_;

    public:
        Grade(const int &gradeid, const double &gradevalue, const std::string &gradeupdate);
        Grade(const Grade &other);
        void swap(Grade &first, Grade &second) noexcept;
        Grade &operator=(Grade &other);
        ~Grade();

        const int &getGradeID() const;
        const double &getGradeValue() const;
        const std::string &getGradeUpDate() const;

        void setGradeID(const int &gradeid);
        void setGradeValue(const double &gradevalue);
        void setGradeUpDate(const std::string &gradeupdate);

};

#endif //GRADE__HPP