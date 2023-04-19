#include "pch.h"
#include "Course.h"
Course::Course()
{
	name = "";
	code = "";
	instructor = "";
	isRequirement = true;
	maxNumberOfStudents = 1000;
	hours = 0;
}

Course::Course(String^ name, String^ code, String^ instructor, bool isRequirement, int maxNumberOfStudents, int hours)
{
	this->name = name;
	this->code = code;
	this->instructor = instructor;
	this->isRequirement = isRequirement;
	this->maxNumberOfStudents = maxNumberOfStudents;
	this->hours = hours;
	
}

void Course::setName(String^ name) {
	this->name = name;
}
void Course::setCode(String^ code) {
	this->code = code;
}
void Course::setInstructor(String^ instructor) {
	this->instructor = instructor;
}
void Course::setIsRequirement(bool isRequirement) {
	this->isRequirement = isRequirement;
}
void Course::setMaxNumberOfStudents( int maxNumberOfStudents) {
	this->maxNumberOfStudents = maxNumberOfStudents;
}
void Course::setHours( int hours) {
	this->hours= hours;
}
String^ Course::getName() {
	return name;
}
String^ Course::getCode()
{
	return code;
}
String^ Course::getInstructor() { 
	return instructor; 
}
bool Course::getIsRequirement() {
	return isRequirement;
}
int Course::getMaxNumberOfStudents() {
	return maxNumberOfStudents;
}
int Course::getHours() {
	return hours;
}