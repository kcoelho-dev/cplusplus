#include "../include/Subject.hpp"#include "Subject.hpp"

Subject::Subject(const int &subjectid, const std::string &subjectname, const int &subjectworload)
                :   SUBJECT_ID_(subjectid),
                    SUBJECT_NAME_(subjectname),
                    SUBJECT_WORKLOAD_(subjectworload)
{}

Subject::Subject(const Subject &other)
                :   SUBJECT_ID_(other.SUBJECT_ID_),
                    SUBJECT_NAME_(other.SUBJECT_NAME_),
                    SUBJECT_WORKLOAD_(other.SUBJECT_WORKLOAD_)
{}

void Subject::swap(const Subject &first, const Subject &second) noexcept
{
    std::swap(first.SUBJECT_ID_, second.SUBJECT_ID_);
    std::swap(first.SUBJECT_NAME_, second.SUBJECT_NAME_);
    std::swap(first.SUBJECT_WORKLOAD_, second.SUBJECT_WORKLOAD_);
}

Subject &Subject::operator=(const Subject &other)
{
    swap(*this, other);
    return (*this);
}

Subject::~Subject() {}

const int &Subject::getSubjectID() const
{
    return this->SUBJECT_ID_;
}

const std::string &Subject::getSubjectName() const
{
    return this->SUBJECT_NAME_;
}

const int &Subject::getSubjectWorkload() const
{
    return this->SUBJECT_WORKLOAD_;
}

void Subject::setSubjectID(const int &subjectid)
{
    this->SUBJECT_ID_ = subjectid;
}

void Subject::setSubjectName(const std::string &subjectname)
{
    this->SUBJECT_NAME_ = subjectname;
}

void Subject::setSubjectWorkload(const int &subjectworkload)
{
    this->SUBJECT_WORKLOAD_ = subjectworkload;
}
