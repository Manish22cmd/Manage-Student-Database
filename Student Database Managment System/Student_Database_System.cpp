#include<bits/stdc++.h>
#include<string.h>
#include<stdio.h>
#include<iomanip>
#include<stdlib.h>
#include<unistd.h>
#include<windows.h>
#include<math.h>
#include<fstream>

using namespace std;

// defining all the functions required
void user_menu() ;
void teacher_login() ;
void student_login() ;

void teacher_menu() ;
void student_menu() ;

void add_student();
void delete_student();
void search_student();
void set_result();
void update_result();

void get_details();
void update_details();
void get_result();

// create a class that will add and tell the system 
// how to display the data
class new_students
{
	public:
		long int registration_no, mobile;
		int roll_no, sem;
		char fname[100], lname[100], email[100], section[5];
		char degree[30], branch[20], gender[10], father_name[30];
		char mother_name[30], addmission_category[10];
		
		void create_student()
		{
			// there can be repetition of char so use cin.ignore()
			cout << "\n Registration no.: ";
			cin.ignore();
			cin >> registration_no ;
			
			cout << "\n Mobile no.: " ;
			cin.ignore();
			cin >> mobile ;
			
			cout << "\n Roll no.: " ;
			cin.ignore();
			cin >> roll_no ;
			
			cout << "\n Semester: " ;
			cin.ignore();
			cin >> sem ;
			
			cout << "\n First name: " ;
			cin.ignore();
			cin >> fname ;
			
			cout << "\n Last name: " ;
			cin.ignore();
			cin >> lname ;
			
			cout << "\n Section: " ;
			cin.ignore();
			cin >> section ;
			
			cout << "\n Email ID: " ;
			cin.ignore();
			cin >> email ;
			
			cout << "\n Gender: " ;
			cin.ignore();
			cin >> gender ;
			
			cout << "\n Degree: " ;
			cin.ignore();
			cin >> degree ;
			
			cout << "\n Branch: " ;
			cin.ignore();
			cin >> branch ;
			
			cout << "\n Father name: " ;
			cin.ignore();
			cin >> father_name ;
			
			cout << "\n Mother name: " ;
			cin.ignore();
			cin >> mother_name ;
			
			cout << "\n Addmission Category: " ;
			cin.ignore();
			cin >> addmission_category ;
		}
		
		void view_students()
		{
			cout << "\n *************************************" ;
			cout << "\n *************************************" ;
			cout << "\n -------------------------------------" ;
			cout << "\n # Personal Details" ;
			cout << "\n First name: " << fname ;
			cout << "\n Last name: " << lname ;
			cout << "\n Registration no.: " << registration_no ;
			cout << "\n Section: " << section ;
			cout << "\n Roll no.: " << roll_no ;
			cout << "\n Gender: " << gender ;
			cout << "\n -------------------------------------" ;
			cout << "\n # Contact Details" ;
			cout << "\n Mobile no.: " << mobile ;
			cout << "\n Email ID: " << email ;
			cout << "\n -------------------------------------" ;
			cout << "\n # Educational Details" ;
			cout << "\n Degree: " << degree ;
			cout << "\n Branch: " << branch ;
			cout << "\n Current Semester: " << sem ;
			cout << "\n Addmission Category: " << addmission_category ;
			cout << "\n -------------------------------------" ;
			cout << "\n # Other Details" ;
			cout << "\n Father name: " << father_name ;
			cout << "\n Mother name: " << mother_name ;
			cout << "\n *************************************" ;
			cout << "\n *************************************" ; 
		}
		
		// get and return all the details
		long int getreg()
		{
			return registration_no ;
		}
		long int getmob()
		{
			return mobile;
		}
		int getroll()
		{
			return roll_no;
		}
		int getsem()
		{
			return sem;
		}
		char* getfname()
		{
			return fname;
		}
		char* getlname()
		{
			return lname;
		}
		char* getemail()
		{
			return email;
		}
		char* getsec()
		{
			return section;
		}
		char* getdegree()
		{
			return degree;
		}
		char* getbranch()
		{
			return branch;
		}
		char* getgender()
		{
			return gender;
		}
		char* getfather()
		{
			return father_name;
		}
		char* getmother()
		{
			return mother_name;
		}
		char* getaddcat()
		{
			return addmission_category;
		}
};

// class for result of a student
class student_result
{
	public:
		long int universal_no;
		float cgpa, percent;
		
		void result()
		{
			cout << "\n\n\n\t ADD STUDENT'S RESULT HERE";
			cout << "\n\n  Registration no. of the student: " ;
			cin.ignore();
			cin >> universal_no ;
			cout << "\n Current Semester CGPA: " ;
			cin.ignore();
			cin >> cgpa ;
			percent = cgpa*9.5 ;
			cout << "\n Equivalent percentage(%): " << percent ;
		}
		
		void view_results()
		{
			cout << "\n ============================================ " ;
			cout << "\n Registration/University no.: " << universal_no ;
			cout << "\n Current Semester CGPA: " << cgpa ;
			cout << "\n Equivalent percentage(%): " << percent ;
			cout << "\n ============================================ " ;
		}
		
		// return all the variables
		long int getuniv()
		{
			return universal_no ;
		}
		float getcgpa()
		{
			return cgpa ;
		}
		float getper()
		{
			return percent ;
		}
};

// create all the objects related
new_students ns;
student_result rs;
fstream f1;
fstream f2;

void user_menu()
{
	system("CLS");
	cout << "\n\n\n\t\t    ====================== STUDENT DATABASE MANAGEMENT SYSTEM ======================" << endl ;
	cout << "\n\n   Choose your login type " << endl;
	cout << "   1. Teacher" ;
	cout << "\n   2. Student" ;
	cout << "\n   3. Exit the system" ;
	int ch;
	cout << "\n\n  Choice: "; cin >> ch ;
	
	switch(ch) {
		case 1: 
			// call teacher login module
			teacher_login() ;
			break;
			
		case 2:
			student_login() ;
			break ;
			
		case 3:
			cout << "\n Exiting the SDBMS......";
			sleep(2);
			exit(0);
			
		default:
			cout << "\n Invalid choice!!";
			cout << "\n Choose among the options given." ;
			system("CLS");
			user_menu() ;
	}
}

// Teacher login module
void teacher_login()
{
	system("CLS");
	char username[] = "teacher", password[] = "2020", name[20], pass[20];
	int n = 3, a, b ;
	cout << "\n\n\n\t\t  ================= TEACHER LOGIN =================" << endl ;
	cout << "\n\n   Login with your credentials" << endl;
	while(n>=1) {
		cout << "\n\n  Username: " ; cin >> name ;
		cout << "\n  Password: "; cin >> pass ;
		a = strcmp(name, username) ;
		b = strcmp(pass, password) ;
		
		// check the conds
		if( a == 0 && b == 0 ) {
			cout << "\n Logged in successfully." ;
			cout << "\n\n Redirecting to the system....." ;
			sleep(2);
			// call the teacher's menu
			teacher_menu();
			break;
		}
		else {
			cout << "\n Invalid login!!!" ;
			n--;
			cout << "\n You have " << n << " chances left for login ";
		}
	}
	if (n == 0) {
		cout << "\n\n All chances are exhausted." ;
		cout << "\n To login again Restart the system." ;
		exit(0) ;
	}
}

// student login module
void student_login()
{
	system("CLS");
	char username[] = "student", password[] = "2021", name[20], pass[20];
	int n = 3, a, b ;
	cout << "\n\n\n\t\t  ================= STUDENT LOGIN =================" << endl ;
	cout << "\n\n   Login with your credentials" << endl;
	while(n>=1) {
		cout << "\n\n  Username: " ; cin >> name ;
		cout << "\n  Password: "; cin >> pass ;
		a = strcmp(name, username) ;
		b = strcmp(pass, password) ;
	
		// check the conds
		if( a == 0 && b == 0 ) {
			cout << "\n Logged in successfully." ;
			cout << "\n\n Redirecting to the system....." ;
			sleep(2);
			// call the student module
			student_menu();
			break;
		}
		else {
			cout << "\n Invalid login!!!" ;
			n--;
			cout << "\n You have " << n << " chances left for login ";
		}
	}
	if (n == 0) {
		cout << "\n\n All chances are exhausted." ;
		cout << "\n To login again Restart the system." ;
		exit(0) ;
	}
}

// now create the teachers's module
// that will be called after their successfull login
void teacher_menu()
{
	system("CLS");
	int i=3;
	cout << "\n\n\n\t\t =============== TEACHER MODULE ===============" ;
	cout << "\n\n\n  Teacher Menu" ;
	cout << "\n\n  1. Add a Student" ;
	cout << "\n  2. Delete a student's record" ;
	cout << "\n  3. Search for the details of the student" ;
	cout << "\n  4. Set the result of the student";
	cout << "\n  5. Update the result of a student" ;
	cout << "\n  6. Go back to user menu" ;
	int ch;
	cout << "\n\n  Choice: " ;
	cin >> ch;
	
	switch(ch)
	{
		case 1:
			// call create_student func
			system("CLS") ;
			add_student();
			break;
		case 2:
			// call delete_student module
			delete_student();
			break;
		case 3:
			// call search_student func
			search_student();
			break;
		case 4:
			// call set_result func
			set_result();
			break;
		case 5:
			// call update_result func
			update_result();
			break;
		case 6:
			user_menu();
			break;
		default:
			cout << "\n Wrong choice!!!!" ;
			cout << "\n Choose from the options given.";
			sleep(1);
			while(i>=1) {
				cout << "\n\n Choice: " ;
				cin >> ch ;
				i-- ;
			}
			if(i==0) {
				cout << "\n\n Repetition of wrong choice!!!" ;
				cout << "\n Exiting the module......" ;
				sleep(2);
				exit(0);
			}
	}
}

// student_menu
void student_menu()
{
	system("CLS");
	int i=2;
	cout << "\n\n\n\t\t =============== STUDENT MODULE ===============" ;
	cout << "\n\n\n  Student Menu" <<endl;
	cout << "\n  1. View your details" ;
	cout << "\n  2. Update your details";
	cout << "\n  3. Get your result" ;
	cout << "\n  4. Go back to user menu" << endl;
	int ch;
	cout << "\n  Choice: " ; cin >> ch ;
	
	switch(ch)
	{
		case 1:
			// call view_details func
			get_details();
			break;
		case 2:
			// call update_details func
			update_details();
			break;
		case 3:
			// call result func
			get_result();
			break;
		case 4:
			user_menu();
			break;
		default:
			cout << "\n Wrong choice made!!!" ;
			cout << "\n Choice from the options given" ;
			cout << "\n Calling the module again......."; sleep(2);
			student_menu();
	}
}

// add a student
void add_student()
{
	cout << "\n                 ************************************* " ;
	cout << "\n\t\t           Add a Student Module " <<endl;
	cout << "                 ************************************* " ;
	cout << endl;
	cout << endl;
	// open the file to write the details of the student
	f1.open("students_list.txt", ios::out|ios::app|ios::binary);
	ns.create_student();
	// now get the entries in the file
	f1.write((char*)&ns,sizeof(new_students)) ;
	// close the file
	f1.close();
	// print the confirmation msg
	cout << "\n\n Student is added to the database." ;
	getchar();
	
	cout << "\n\n\n Want to perform more actions? ";
	char chs;
	cin >> chs;
	if(chs=='Y'|| chs=='y'){
		teacher_menu();
	}
	else {
		exit(0);
	}
}

// delete a studnt's details from db
void delete_student()
{
	system("CLS") ;
	cout << endl ;
	cout << "                 ************************************* " ;
	cout << "\n\t\t        Delete Student's Details " <<endl;
	cout << "                 ************************************* " ;
	
	// serach for the student by his/her registration no
	long int reg_no;
	cout << "\n\n  Registration/University no.: ";
	cin >> reg_no;
	int found = 0 ;
	
	f1.open("students_list.txt", ios::in|ios::out|ios::binary) ;
	// create a temporary file where rest of the students will be
	// entered
	f2.open("temp_students_list.txt",ios::out|ios::binary);
	f1.seekg(0, ios::beg) ;
	while(f1.read((char*)&ns,sizeof(new_students))) {
		if(ns.getreg() == reg_no) {
			found = 1;
			cout << "\n\n Record found." ;
			cout << "\n Deleting the record of the student requested......." ;
			sleep(2);
			cout << "\n\n Record deleted successfully." ;
		}
		else if(ns.getreg()!=reg_no) {
			f2.write((char*)&ns,sizeof(new_students)) ;
		}
	}
	if(found == 0) {
		cout << "\n\n Voilation of deletion operation." ;
		cout << "\n No Record of {" << reg_no << "} found in our database." ;
		cout << "\n Or it may have been deleted already." ;
		cout << "\n Therefore, deletion can't be done." ;
	}
	f1.close();
	f2.close();
	// remove the previous file
	remove("students_list.txt");
	// rename the new file
	rename("temp_students_list.txt", "students_list.txt");
	
	cout << "\n\n\n Want to perform more actions? ";
	char chs;
	cin >> chs;
	if(chs=='Y'|| chs=='y'){
		teacher_menu();
	}
	else {
		exit(0);
	}
}

// search for a new student
void search_student()
{
	system("CLS") ;
	cout << endl ;
	cout << "                 ************************************* " ;
	cout << "\n\t\t        Search Student's Details " << endl;
	cout << "                 ************************************* " ;
	cout << "\n\n Registration/University no.: ";
	long int reg ;
	cin >> reg ;

	bool found = 0 ;
	f1.open("students_list.txt",ios::in);
	while(f1.read((char*)&ns,sizeof(new_students))) {
		if(ns.getreg() == reg) {
			cout << "\n Record found." << endl;
			cout << "\n Extracting the details from the database......" << endl;
			sleep(2);
			ns.view_students() ;
			// make found 1
			found = 1 ;
		}
	}
	f1.close();
	if (found == 0) {
		cout << "\n Record not found or have been deleted!!!" << endl;
	}
	getchar();
	
	cout << "\n\n\n Want to perform more actions? ";
	char chs;
	cin >> chs;
	if(chs=='Y'|| chs=='y'){
		teacher_menu();
	}
	else {
		exit(0);
	}
}

// set result of a student
void set_result()
{
	system("CLS") ;
	cout << "                 -------------------------------- " ;
	cout << "\n \t\t    SET RESULT MODULE " <<endl;
	cout << "                 -------------------------------- " ;
	// open the file
	f1.open("students_results.txt",ios::out|ios::app|ios::binary) ;
	rs.result();
	// now we have to write in the file
	f1.write((char*)&rs,sizeof(student_result)) ;
	// now after successfully writing close the file
	f1.close();
	cout << "\n\n Result of the student is added in the database." ;
	getchar();
	
	cout << "\n\n\n Want to perform more actions? ";
	char chs;
	cin >> chs;
	if(chs=='Y'|| chs=='y'){
		teacher_menu();
	}
	else {
		exit(0);
	}
}

// update the student's current sem result
// update_result func
void update_result()
{
	system("CLS");
	cout << endl;
	cout << "               ----------------------------- " ;
	cout << "\n \t\t    MODIFY THE RESULT " <<endl;
	cout << "               ----------------------------- " ;
	cout << endl ;
	
	bool flag = 0 ;
	long int register_no ;
	cout << "\n\n Registration no. of the student:  " ;
	cin >> register_no ;
	// now open the file to search and return the result
	// and allow the teacher to update the result
	f1.open("students_results.txt",ios::in|ios::out) ;
	while(f1.read((char*)&rs, sizeof(student_result)) && flag == 0) {
		if(rs.getuniv()==register_no) {
			cout << "\n OLD RESULT OF {" << register_no << "}" << " is: " << endl;
			rs.view_results();
			cout << "\n Update the result as per the sequence." << endl;
			// need to call the student_result func so that 
			// we can update the result
			rs.result();
			int pos=-1*sizeof(rs);
			f1.seekp(pos,ios::cur);
			f1.write((char*)&rs,sizeof(rs));
			cout << "\n\n The result of {" << register_no << "} is updated.";
			// increment flag
			flag = 1; 
		}
	}
	f1.close();
	if(flag == 0) {
		cout << "\n Student with {" << register_no << "} is not in our database.";
		cout << "\n Therefore, terminating this operation and redirecting to the menu........." ;
		sleep(2);
		teacher_menu();
	}
}

// now work on students menu
// get your details
void get_details()
{
	system("CLS") ;
	cout << endl ;
	cout << "                 ************************************* " ;
	cout << "\n\t\t          View Your Details " <<endl;
	cout << "                 ************************************* " ;
	cout << "\n\n Registration/University no.: ";
	long int reg_no;
	cin >> reg_no;
	bool flag = 0;
	f1.open("students_list.txt",ios::in);
	while(f1.read((char*)&ns,sizeof(new_students))) {
		if(ns.getreg()==reg_no) {
			cout << "\n\n Details of {" << reg_no << "} found.";
			cout << "\n Getting the details from the database........" << endl ;
			sleep(3) ;
			ns.view_students();
			flag = 1;
		}
	}
	f1.close();
	if(flag == 0) {
		cout << "\n\n No record found for {" << reg_no << "} !!!" ;
		cout << "\n Contact to your Department head." ;
	}
	getchar();
	
	cout << "\n\n Want to perform more actions? ";
	char chs;
	cin >> chs;
	if(chs=='Y'|| chs=='y'){
		student_menu();
	}
	else {
		exit(0);
	}
}

// if want to update your details
void update_details()
{
	system("CLS");
	cout << endl;
	cout << "               ----------------------------- " ;
	cout << "\n \t\t    Modify Your Details " <<endl;
	cout << "               ----------------------------- " ;
	cout << endl ;
	
	bool flag = 0;
	long int regno;
	cout << "\n Your Registeration/University no.: " ;
	cin >> regno;
	
	// now opening the file that has your details
	f1.open("students_list.txt",ios::in|ios::out);
	// now read the file to get the search process done
	while(f1.read((char*)&ns,sizeof(new_students)) && flag == 0) {
		if(ns.getreg()==regno) {
			cout << "\n\n Your OLD are being extracted from the database........." ;
			sleep(2);
			cout << "\n\n Your OLD Details are " ;
			ns.view_students();
			cout << "\n\n Kindly update your details as per the sequence asked." << endl;
			ns.create_student();
			int pos=-1*sizeof(ns);
			f1.seekp(pos,ios::cur);
			f1.write((char*)&ns,sizeof(ns));
			cout << "\n\n Your details are modified.";
			flag = 1;	
		}
	}
	f1.close();
	if(flag == 0) {
		cout << "\n\n Your record is not in our database !!!" ;
		cout << "\n Kindly contact to your Department head." ;
	}
	
	cout << "\n\n\n Want to perform more actions? ";
	char chs;
	cin >> chs;
	if(chs=='Y' || chs=='y'){
		student_menu();
	}
	else {
		exit(0);
	}
}

// know your result
void get_result()
{
	system("CLS") ;
	cout << endl ;
	cout << "                 ************************************* " ;
	cout << "\n\t\t               RESULT " <<endl;
	cout << "                 ************************************* " ;
	cout << "\n\n Registration/University no.: ";
	long int regs;
	cin >> regs;
	cout << endl;
	bool found = 0;
	// open the file that contains result
	f1.open("students_results.txt",ios::in);
	while(f1.read((char*)&rs,sizeof(student_result))) {
		if(rs.getuniv()==regs) {
			cout << "\n Record found.";
			rs.view_results();
			found = 1 ;
		}
	}
	f1.close();
	if(found == 0) {
		cout << "\n\n No record found!!!" ;
		cout << "\n Contact to your respective head." ;
		exit(0);
	}
	getchar();
	
	cout << "\n\n\n Want to perform more actions? ";
	char chs;
	cin >> chs;
	if(chs=='Y'|| chs=='y'){
		student_menu();
	}
	else {
		exit(0);
	}
}

int main()
{
	// call login system
	user_menu();
	return 0;
}
