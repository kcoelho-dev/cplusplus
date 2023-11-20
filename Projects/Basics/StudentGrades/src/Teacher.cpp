#include "../include/Teacher.hpp"

Teacher::Teacher(const int &teacherid, const std::string &teachername, const Subject &teachersubject)
                :   TEACHER_ID_(teacherid),
                    TEACHER_NAME_(teachername),
                    TEACHER_SUBJECT_(teachersubject)
{}

Teacher::Teacher(const Teacher &other)
                :   TEACHER_ID_(other.TEACHER_ID_),
                    TEACHER_NAME_(other.TEACHER_NAME_),
                    TEACHER_SUBJECT_(other.TEACHER_SUBJECT_)
{}

void Teacher::swap(Teacher &first, Teacher &second) noexcept
{
    std::swap(first.TEACHER_ID_, second.TEACHER_ID_);
    std::swap(first.TEACHER_NAME_, second.TEACHER_NAME_);
    std::swap(first.TEACHER_SUBJECT_, second.TEACHER_SUBJECT_);
}


Teacher &Teacher::operator=(Teacher &other)
{
    swap(*this, other);
    return (*this);
}

Teacher::~Teacher() {}

const int &Teacher::getTeacherID() const
{
    return this->TEACHER_ID_;
}

const std::string &Teacher::getTeacherName() const
{
    return this->TEACHER_NAME_;
}

const Subject &Teacher::getTeacherSubject() const
{
    return this->TEACHER_SUBJECT_;
}

void Teacher::setTeacherID(const int &teacherid)
{
    this->TEACHER_ID_ = teacherid;
}

void Teacher::setTeacherName(const std::string &teachername)
{
    this->TEACHER_NAME_ = teachername;
}

void Teacher::setTeacherSubject(const Subject &teachersubject)
{
    this->TEACHER_SUBJECT_ = teachersubject;
}
