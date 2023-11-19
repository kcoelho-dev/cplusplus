#include "../include/Student.hpp"


Student::Student(const int &studentid, const std::string &studentname, const std::string &studentbirthdate, const std::string &studentlevel)
{}
Student::Student(const Student &other)
        :   STUDENT_ID_(other.STUDENT_ID_),
            STUDENT_NAME_(other.STUDENT_NAME_),
            STUDENT_BIRTH_DATE_(other.STUDENT_BIRTH_DATE_),
            STUDENT_LEVEL_(other.STUDENT_LEVEL_)
{}

void Student::swap(Student &first, Student &second)
{
    std::swap(first.STUDENT_ID_, second.STUDENT_ID_);
    std::swap(first.STUDENT_NAME_, second.STUDENT_NAME_);
    std::swap(first.STUDENT_BIRTH_DATE_, second.STUDENT_BIRTH_DATE_);
    std::swap(first.STUDENT_LEVEL_, second.STUDENT_LEVEL_);
}

Student &Student::operator=(Student &other)
{
    swap(*this, other);
    return (*this);
}

Student::~Student() {}

const int &Student::getStudentID() const
{
    return this->STUDENT_ID_;
}

const std::string &Student::getStudentName() const
{
    return this->STUDENT_NAME_;
}

const std::string &Student::getStudentBirthDate() const
{
    return this->STUDENT_BIRTH_DATE_;
}

const std::string &Student::getStudentLevel() const
{
    return this->STUDENT_LEVEL_;
}

void Student::setStudentID(const int &studentid)
{
    this->STUDENT_ID_ = studentid;
}

void Student::setStudentName(const std::string &studentname)
{
    this->STUDENT_NAME_ = studentname;
}

void Student::setStudentBirthDate(const std::string &studentbirthdate)
{
    this->STUDENT_BIRTH_DATE_ = studentbirthdate;
}

void Student::setStudentLevel(const std::string &studentlevel)
{
    this->STUDENT_LEVEL_ = studentlevel;
}

