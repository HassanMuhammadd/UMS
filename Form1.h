#pragma once
#using <mscorlib.dll>
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
void saveCourseDataToFile() {
	/*
	TO DO = > Maya and Farah:

    add the data to the file in the following format:
	key of the Dictionary , then "-" , then the preRequirements separated by "," .
	ex: Archi-Logic Design,Electronics

	*/
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
	private: System::Windows::Forms::Button^ addCourse;


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
			this->addCourse = (gcnew System::Windows::Forms::Button());
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
			this->label1->Location = System::Drawing::Point(30, 30);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(62, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Add Course";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// addCourse
			// 
			this->addCourse->Location = System::Drawing::Point(189, 281);
			this->addCourse->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->addCourse->Name = L"addCourse";
			this->addCourse->Size = System::Drawing::Size(104, 45);
			this->addCourse->TabIndex = 1;
			this->addCourse->Text = L"ADD";
			this->addCourse->UseVisualStyleBackColor = true;
			this->addCourse->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(52, 83);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(74, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Course Name:";
			// 
			// nameTextBox
			// 
			this->nameTextBox->Location = System::Drawing::Point(132, 80);
			this->nameTextBox->Name = L"nameTextBox";
			this->nameTextBox->Size = System::Drawing::Size(100, 20);
			this->nameTextBox->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(68, 113);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(38, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Hours:";
			// 
			// hoursTextBox
			// 
			this->hoursTextBox->Location = System::Drawing::Point(132, 113);
			this->hoursTextBox->Name = L"hoursTextBox";
			this->hoursTextBox->Size = System::Drawing::Size(100, 20);
			this->hoursTextBox->TabIndex = 5;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(51, 150);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(75, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Max Students:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(68, 181);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(54, 13);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Instructor:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(56, 217);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(70, 13);
			this->label6->TabIndex = 8;
			this->label6->Text = L"Prerequisites:";
			// 
			// maxStudentsTextBox
			// 
			this->maxStudentsTextBox->Location = System::Drawing::Point(132, 150);
			this->maxStudentsTextBox->Name = L"maxStudentsTextBox";
			this->maxStudentsTextBox->Size = System::Drawing::Size(100, 20);
			this->maxStudentsTextBox->TabIndex = 9;
			// 
			// instructorTextBox
			// 
			this->instructorTextBox->Location = System::Drawing::Point(132, 181);
			this->instructorTextBox->Name = L"instructorTextBox";
			this->instructorTextBox->Size = System::Drawing::Size(100, 20);
			this->instructorTextBox->TabIndex = 10;
			// 
			// prereqTextBox
			// 
			this->prereqTextBox->Location = System::Drawing::Point(132, 217);
			this->prereqTextBox->Name = L"prereqTextBox";
			this->prereqTextBox->Size = System::Drawing::Size(100, 20);
			this->prereqTextBox->TabIndex = 11;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(632, 402);
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
			this->Controls->Add(this->addCourse);
			this->Controls->Add(this->label1);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
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



	}
	};
}
