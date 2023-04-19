#pragma once
#include<vector>
#include<iostream>
using namespace std;
using namespace System;

ref class Course
{
private:
	String^ name;
	String^ code;
	String^ instructor;
	
	bool isRequirement;
	int maxNumberOfStudents;
	int hours;
	vector<vector<Course>>*preRequires;
public:
	Course();
	Course(String^ name, String^ code, String^ instructor, bool isRequirement, int maxNumberOfStudents, int hours);

	//setters and getters

	void setName(String^ name);
	void setCode(String^ code);
	void setInstructor(String^ instructor);
	void setIsRequirement(bool isRequirement);
	void setMaxNumberOfStudents(int maxNumberOfStudents);
	void setHours(int hours);
	
	String^ getName();
	String^ getCode();
	String^ getInstructor();
	bool getIsRequirement();
	int getMaxNumberOfStudents();
	int getHours();
};


