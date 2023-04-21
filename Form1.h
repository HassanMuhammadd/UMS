#pragma once
//#using <mscorlib.dll>
#include"Course.h"
#include<string>
#include<fstream>
#include<iostream>
using namespace std;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace std;

vector<string>coursesList;

void loadCourseDataFromFile() {
	
	//loading data from file
	ifstream coursesData("coursesData.txt");
	string wholeLine;
	
	while (getline(coursesData,wholeLine))
	{
		string cName;
		int i = 0;
		//getting the key of the adj list (Course)
		for ( i = 0; i < wholeLine.size(); i++)
		{
			if (wholeLine[i] == '-')
			{
				i++;
				break;
			}
			cName+=wholeLine[i];
		}
		List<String^> ^preReq = gcnew List<String^>();
		string preReqName;
		//getting the vector of values of the adj list of each course (pre Requirements)
		while (i < wholeLine.size())
		{
			if (wholeLine[i] == ',')
			{
				i++;
				String^ mo3akReq = gcnew String(preReqName.c_str());
				preReq->Add(mo3akReq);
				preReqName = "";
			}
			preReqName += wholeLine[i];
			i++;
		}

		String^ mo3ak = gcnew String(cName.c_str());
		//Course::preRequires->Add(mo3ak,preReq);
		
	}

	
}

void addCourse(Course^ newCourse) { //farah and maya

	String^ courseName = newCourse->getName();
	List<String^>^ prerequisites = newCourse->getPrerequisites();

	// If the course already exists in the dictionary, do nothing
	if (Course::preRequires->ContainsKey(courseName))
	{
		return;
	}
	// Add the new course to the dictionary with an empty list of prerequisites
	Course::preRequires->Add(courseName, prerequisites);

}

void saveCourseDataToFile() {//Maya and Farah:

	// Open the output file
	ofstream outFile("coursesData.txt");

	// Loop through each course in the dictionary
	for each (auto i in Course::preRequires) 
	{
		// Get the course name and prerequisites for the current course
		String^ courseName = i.Key;
		List<String^>^ prerequisites = i.Value;

		// Convert course name to std::string
		std::string courseNameStr;
		for each (wchar_t c in courseName)
		{
			courseNameStr += static_cast<char>(c);
		}

		// Convert prerequisites to std::string
		std::string prereqsStr;
		for each (String ^ prereq in prerequisites)
		{
			// Separate prerequisites with commas
			if (!prereqsStr.empty())
			{
				prereqsStr += ",";
			}
			std::string prereqStr;
			for each (wchar_t c in prereq)
			{
				prereqStr += static_cast<char>(c);
			}
			prereqsStr += prereqStr;

		}

		// Construct the output string
		std::string outputStr = courseNameStr + "-" + prereqsStr + "\n";

		// Write the output string to the file
		outFile << outputStr;
	}

	// Close the output file
	outFile.close();


}

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	/// <summary>
	/// Summary for Form1
	/// </summary>
	///
	
	public ref class Form1 : public System::Windows::Forms::Form
	{

	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{

			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ addCourseBtn;



	protected:

	private:
		/// <summary>
		/// Required designer variable.
			List<String^>v;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ nameTextBox;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ hoursTextBox;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ maxStudentsTextBox;
	private: System::Windows::Forms::TextBox^ instructorTextBox;
	private: System::Windows::Forms::TextBox^ prereqTextBox;




		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->addCourseBtn = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->nameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->hoursTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->maxStudentsTextBox = (gcnew System::Windows::Forms::TextBox());
			this->instructorTextBox = (gcnew System::Windows::Forms::TextBox());
			this->prereqTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(40, 37);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(78, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Add Course";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// addCourseBtn
			// 
			this->addCourseBtn->Location = System::Drawing::Point(252, 346);
			this->addCourseBtn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->addCourseBtn->Name = L"addCourseBtn";
			this->addCourseBtn->Size = System::Drawing::Size(139, 55);
			this->addCourseBtn->TabIndex = 1;
			this->addCourseBtn->Text = L"ADD";
			this->addCourseBtn->UseVisualStyleBackColor = true;
			this->addCourseBtn->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(69, 102);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(93, 16);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Course Name:";
			// 
			// nameTextBox
			// 
			this->nameTextBox->Location = System::Drawing::Point(176, 98);
			this->nameTextBox->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->nameTextBox->Name = L"nameTextBox";
			this->nameTextBox->Size = System::Drawing::Size(132, 22);
			this->nameTextBox->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(91, 139);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(46, 16);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Hours:";
			// 
			// hoursTextBox
			// 
			this->hoursTextBox->Location = System::Drawing::Point(176, 139);
			this->hoursTextBox->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->hoursTextBox->Name = L"hoursTextBox";
			this->hoursTextBox->Size = System::Drawing::Size(132, 22);
			this->hoursTextBox->TabIndex = 5;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(68, 185);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(90, 16);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Max Students:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(91, 223);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(63, 16);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Instructor:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(75, 267);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(89, 16);
			this->label6->TabIndex = 8;
			this->label6->Text = L"Prerequisites:";
			// 
			// maxStudentsTextBox
			// 
			this->maxStudentsTextBox->Location = System::Drawing::Point(176, 185);
			this->maxStudentsTextBox->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->maxStudentsTextBox->Name = L"maxStudentsTextBox";
			this->maxStudentsTextBox->Size = System::Drawing::Size(132, 22);
			this->maxStudentsTextBox->TabIndex = 9;
			// 
			// instructorTextBox
			// 
			this->instructorTextBox->Location = System::Drawing::Point(176, 223);
			this->instructorTextBox->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->instructorTextBox->Name = L"instructorTextBox";
			this->instructorTextBox->Size = System::Drawing::Size(132, 22);
			this->instructorTextBox->TabIndex = 10;
			// 
			// prereqTextBox
			// 
			this->prereqTextBox->Location = System::Drawing::Point(176, 267);
			this->prereqTextBox->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->prereqTextBox->Name = L"prereqTextBox";
			this->prereqTextBox->Size = System::Drawing::Size(132, 22);
			this->prereqTextBox->TabIndex = 11;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(843, 495);
			this->Controls->Add(this->prereqTextBox);
			this->Controls->Add(this->instructorTextBox);
			this->Controls->Add(this->maxStudentsTextBox);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->hoursTextBox);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->nameTextBox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->addCourseBtn);
			this->Controls->Add(this->label1);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
		
		String^ x1;
		for each (String^ y in Course::preRequires["Archi"])
		{
			 x1 = y;
		}
		label1->Text = x1;
	}
	
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		// get the course information from the text boxes
		String^ courseName = nameTextBox->Text;
		int hours = System::Convert::ToInt32(hoursTextBox->Text);
		int maxStudents = System::Convert::ToInt32(maxStudentsTextBox->Text);
		String^ instructor = instructorTextBox->Text;
		String^ prereqStr = prereqTextBox->Text;

		cli::array<String^>^ prerequisiteArray = prereqStr->Split(',');
		List<String^>^ prerequisitesList = gcnew List<String^>();

		for each (String ^ str in prerequisiteArray) {
			prerequisitesList->Add(str);
		}

		// Create a new instance of the Course class
		Course^ newCourse = gcnew Course();

		// Set the properties using the setters
		newCourse->setName(courseName);
		newCourse->setHours(hours);
		newCourse->setMaxNumberOfStudents(maxStudents);
		newCourse->setInstructor(instructor);
		newCourse->setPrerequisites(prerequisitesList);
		
		addCourse(newCourse);
	}
	};
}
