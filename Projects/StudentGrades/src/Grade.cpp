#include "../include/Grade.hpp"

Grade::Grade(const int &gradeid, const double &gradevalue, const std::string &gradeupdate)
            :   GRADE_ID_(gradeid),
                GRADE_VALUE_(gradevalue),
                GRADE_UP_DATE_(gradeupdate)
{}

Grade::Grade(const Grade &other)
            :   GRADE_ID_(other.GRADE_ID_),
                GRADE_VALUE_(other.GRADE_VALUE_),
                GRADE_UP_DATE_(other.GRADE_UP_DATE_)
{}

/**
 * The function swaps the values of two Grade objects.
 * 
 * @param first The first parameter is a reference to a Grade object.
 * @param second The "second" parameter is a reference to a Grade object.
 */
void Grade::swap(Grade &first, Grade &second) noexcept
{
    std::swap(first.GRADE_ID_, second.GRADE_ID_);
    std::swap(first.GRADE_VALUE_, second.GRADE_VALUE_);
    std::swap(first.GRADE_UP_DATE_, second.GRADE_UP_DATE_);
}

Grade &Grade::operator=(Grade &other)
{
    swap(*this, other);
    return (*this);
}


/**
 * The above function is a destructor for the Grade class in C++.
 */
Grade::~Grade() {}

/**
 * The function returns the grade ID as a constant reference.
 * 
 * @return a reference to a constant integer, which is the grade ID.
 */
const int &Grade::getGradeID() const
{
    return this->GRADE_ID_;
}

/**
 * The function "getGradeValue" returns the value of the grade.
 * 
 * @return the value of the variable `GRADE_VALUE_`.
 */
const double &Grade::getGradeValue() const
{
    return this->GRADE_VALUE_;
}

/**
 * The function "getGradeUpDate" returns the value of the "GRADE_UP_DATE_" variable.
 * 
 * @return the value of the variable "GRADE_UP_DATE_".
 */
const std::string &Grade::getGradeUpDate() const
{
    return this->GRADE_UP_DATE_;
}

/**
 * The function sets the grade ID for a Grade object.
 * 
 * @param gradeid The parameter "gradeid" is an integer that represents the ID of a grade.
 */
void Grade::setGradeID(const int &gradeid)
{
    this->GRADE_ID_ = gradeid;
}

/**
 * The function sets the value of the grade.
 * 
 * @param gradevalue The parameter "gradevalue" is a double that represents the value of a grade.
 */
void Grade::setGradeValue(const double &gradevalue)
{
    this->GRADE_VALUE_ = gradevalue;
}

/**
 * The function sets the grade update date for a Grade object.
 * 
 * @param gradeupdate The parameter "gradeupdate" is a string that represents the date of the grade
 * update.
 */
void Grade::setGradeUpDate(const std::string &gradeupdate)
{
    this->GRADE_UP_DATE_ = gradeupdate;
}

