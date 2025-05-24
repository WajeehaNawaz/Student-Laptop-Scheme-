#include <iostream> 
#include <iomanip> 
#include <string> 
#include <limits> 
using namespace std;
// Structure to hold student information 
struct Student {
	string name;
	int nicnumber;
	string city;
	string fathername;
	string university;
	int regNumber;
	string department;
	int semester;
	int Academic_performance;
};
void displaymenu()
{

	cout << setw(85) << "************************************************* *****" << endl;
	cout << endl;
	cout << setw(85) << "___WELCOME TO THE STUDENT LAPTOP SCHEME  APPLICATION____" << endl;
	cout << endl;

	cout << setw(85) << "************************************************* *****" << endl;
}
void getStudentDetails(Student& student) {
	cout << "Enter student name: ";
	getline(cin, student.name);
	cout << "Enter student NIC number: ";
	cin >> student.nicnumber;
	cout << "Enter your city of residence: ";
	getline(cin >> ws, student.city);
	cout << "Enter your father name: ";
	getline(cin >> ws, student.fathername);
	cout << "Enter your university name: ";
	getline(cin, student.university);
	cout << "Enter roll number: ";
	cin >> student.regNumber;
	cout << "Enter department: ";
	getline(cin >> ws, student.department);
	cout << "Enter semester: ";
	cin >> student.semester;
	cout << "Enter Academic performance of the student(CGPA): ";  cin >> student.Academic_performance;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void displayStudentDetails(const Student& student) {

	cout << setw(70) << "**********************" << endl;
	cout << endl;
	cout << setw(70) << "____STUDENT DETAILS_____" << endl;  cout << endl;
	cout << setw(70) << "**********************" << endl;
	cout << "NAME: " << student.name << endl;
	cout << "STUDENT NIC NUMBER: " << student.nicnumber << endl;  cout << "STUDENT CITY: " << student.city << endl;
	cout << "FATHER NAME: " << student.fathername << endl;  cout << "UNIVERSITY NAME: " << student.university << endl;  cout << "REGISTRATION NUMBER: " << student.regNumber << endl;  cout << "STUDENT DEPARTMENT: " << student.department << endl;  cout << "SEMESTER: " << student.semester << endl;
}
bool isEligible(const Student& student) {
	if (student.department == "CS" && student.Academic_performance >= 3) {
		return true; // Student is eligible 
	}
	else {
		cout << "Student is ineligible due to one or more of the following  reasons:\n";
		if (student.department != "CS") {
			cout << "- Student does not belong to the CS department.\n";
		}
		if (student.Academic_performance < 3) {
			cout << "- Student has an Academic performance of less than 3  CGPA.\n";
		}
		return false; // Student is not eligible 
	}
}
void submitApplication(const Student& student) {

	cout << setw(70) << "*****************************************" << endl;  cout << endl;
	cout << setw(70) << "__APPLICATION SUBMITTED SUCCESSFULLY_____" << endl;  cout << endl;

	cout << setw(70) << "******************************************" << endl;
}
int main() {
	const int MAX_STUDENTS = 100;
	Student students[MAX_STUDENTS];
	int numStudents;
	displaymenu();
	cout << "_________________" << endl;
	cout << " " << endl;
	cout << "HOW MANY STUDENTS WANT TO APPLY FOR THE APPLICATION:";  cin >> numStudents;
	cout << "__________________";
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer 
	// total number of students allowed. 
	if (numStudents > MAX_STUDENTS) {

		cout << setw(70) << "_________________________________________________ _";
		cout << setw(70) << "___SORRY! YOUR APPLICATION CANNOT BE  PROCESSED____";
		cout << setw(70) << "______MAXIMUM NUMBER OF STUDENTS ALLOWED  IS_______ " << MAX_STUDENTS << endl;
		return 1;
	}
	// Get details for each student 
	for (int i = 0; i < numStudents; i++) {
		cout << "\nStudent " << i + 1 << ":" << endl;
		getStudentDetails(students[i]);
	}
	// Display details and submit applications for eligible students  
	cout<<setw(75)<<"____________________________"<<endl;  
	cout<<setw(75)<< "**** APPLICATION RESULTS***" <<endl; 
	cout<<setw(75)<<"_____________________________"<<endl;  
	for (int i = 0; i < numStudents; i++) { 
	cout << "\nStudent " << i + 1 << ":" << endl;
	displayStudentDetails(students[i]);
	if (isEligible(students[i])) {
		cout << endl;
		cout << endl;

		cout << setw(70) << "_____________________________________________" << endl;
		cout << setw(70) <<
			"*************CONGRATULATIONS***************" << endl;
		cout << setw(70) << "_YOU ARE ELLIGIBLE FOR THE LAPTOP  APPLICATION_" << endl;

		cout << setw(70) << "______________________________________________" << endl;
		cout << endl;
		cout << endl;
		submitApplication(students[i]);
	}
	else {
		cout << endl;
		cout << endl;

		cout << setw(70) << "********************************************" << endl;
		cout << setw(70) << "_____________WE ARE  SORRY____________________" << endl;
		cout << setw(70) << "__YOU ARE NOT ELLIGIBLE FOR THE  APPLICATION__" << endl;

		cout << setw(70) << "_____________________________________________" << endl;

		cout << setw(70) << "********************************************" << endl;
	}
}
return 0;
}