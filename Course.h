#pragma once
#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;
using namespace System;
using namespace System::Collections::Generic;


ref class Course
{
private:
	String^ name;
	String^ code;
	String^ instructor;
	
	bool isRequirement;
	int maxNumberOfStudents;
	int hours;

public:
	//static adjacency list for course prerequirements
	//static unordered_map<string, vector<string>>* preRequires;
	//static List<List<int>^>^ preRequires;
	static Dictionary<String^, List<String^>^> ^preRequires;
	//constructor
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


