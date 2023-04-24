#pragma once
#include "Course.h"
using namespace std;
using namespace System;

ref class Admin
{
private:
	String^ name = "admin";
	String^ password = "admin";
public:
	//log in
	//add student
	//add course
	//enter course prerequisite
	//view list of all students in a specific course
	//add course grade for each student
	//view list of (finished - inProgress) courses for any student
	//edit all course data
	void editCourseData(Course^ c);
};

