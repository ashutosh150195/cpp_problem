/*
 * student_course.cpp
 *
 *  Created on: 31-May-2017
 *      Author: think-twice-code-once
 */
#include<iostream>
#include <cstring>

using namespace std;

static int c_index = 0;
static int s_index = 0;
static int s_c_index = 0;

class student_course{
	public:
	char student_id[40] ;
	char student_name[40] ;
	char course_code[40] ;
	char course_name[40] ;
	int marks ;

	void set_student_course(char *s_id , char *c_code , int mark){
		strcpy(course_code,c_code);
		strcpy(student_id, s_id);
		marks = mark;
	}

};

class course : public student_course{

	public:
		void set_course(char *c_code , char *c_name){
			strcpy(course_code,c_code);
			strcpy(course_name , c_name);
		}

		bool find_c_id(char *c_code){
			course course[30];
			bool status = false;
			int index = 0;
			for(index = 0 ; index <= c_index; index++){
				if(strcmp(course[index].course_code, c_code) == 0){
					status = true;
					break;
				}
			}
					return status;
		}
};

class student : public student_course{

	public:

		void set_student(char *s_id , char *s_name){
			strcpy(student_id , s_id);
			strcpy(student_name , s_name);
		}

		bool find_s_id(char *s_id){
			student student[30];
			bool status = false;
			int index = 0;
			for(index = 0 ; index <= c_index; index++){
				if(strcmp(student[index].student_id, s_id) == 0){
					status = true;
					break;
				}
			}
			return status;
		}

};

void add_course(){
	//cout<<"add a course"<<endl;
	course c[100];
	char c_code[30], c_name[30];
	char select ;

	cout<<"Please enter course code:";
	cin>>c_code;
	cout<<"Please enter course name:";
	cin>>c_name;


	c[c_index].set_course(c_code,c_name);
	++c_index;

	cout<<"Would you like to [A]dd a new course or [R]eturn to the previous menu?";
	cin>>select;

	if(select == 'A' || select == 'a')
		add_course();
	else
		return;
}

void add_student(){
	//cout<<"add a student"<<endl;

	char s_id[30], s_name[30];
	char select ;
	student s[30];

		cout<<"Please enter student id:";
		cin>>s_id;
		cout<<"Please enter student name:";
		cin>>s_name;

		s[s_index].set_student(s_id , s_name);
		++s_index;

		cout<<"Would you like to [A]dd a new student or [R]eturn to the previous menu?";
		cin>>select;

		if(select == 'A' || select == 'a')
			add_student();
		else
			return;
}


void add_result(){
	//cout<<"add a result"<<endl;
	char s_id[30];
	char c_code[30];
	bool s_status = true , c_status = true;
	student s ;
	course c ;
	student_course s_c[30];
	int marks;

	do {
		cout<<"Please enter student id:"<<endl;
		cin>>s_id;
		s_status = s.find_s_id(s_id);

		if(!s_status){
			cout<<"Student does not exist."<<endl;
		}
	} while (!s_status);

	do {
		cout<<"Please enter course code:"<<endl;
		cin>>c_code;
		c_status = c.find_c_id(c_code);
		if(!c_status){
				cout<<"Course does not exist."<<endl;
			}
		} while (!c_status);


	do {
		cout<<"Please enter final score:"<<endl;
		cin>>marks;

		if(!(marks >= 0 && marks <= 100)){
			cout<<"Score is not between 0.0 and 100.0 inclusive."<<endl;
		}
	} while (!(marks >= 0 && marks <= 100));

	s_c[s_c_index].set_student_course(s_id, c_code, marks);
	++s_c_index;
}

void minimum_score(){

}

void maximum_score(){

}

void iterate_course(){

	maximum_score();
	minimum_score();
}

void iterate_student(){

	maximum_score();
	minimum_score();
}

void view_result(){
	//cout<<"view result"<<endl;

	char select ;
	char c_code[30] , s_id[30];
	bool c_status = true , s_status = true;
	course c;
	student s;

	do {
		cout<<"Would you like to view [C]ourse results, [S]tudent results or [R]eturn?"<<endl;
		cin>>select;

		if((select == 'C' || select == 'c')){
			do {
					cout<<"Please enter course code:"<<endl;
					cin>>c_code;
					c_status = c.find_c_id(c_code);
					if(!c_status){
							cout<<"Course does not exist."<<endl;
						}
					} while (!c_status);

			cout<<"Results for course: "<<c_code;
			iterate_course();

		}if((select =='S' || select == 's')){
			do {
					cout<<"Please enter student id:"<<endl;
					cin>>s_id;
					s_status = s.find_s_id(s_id);

					if(!s_status){
						cout<<"Student does not exist."<<endl;
					}
				} while (!s_status);

			cout<<"Results for student: "<<s_id;
			iterate_student();
		}

	} while ((select == 'C' || select == 'c')||(select =='S' || select == 's'));

}

void message(){
	cout<<"Thanks for using FedUni Results Manager!"<<endl;
}

int main(int argc, char **argv){

	int selection = 0;
//
//	course c[40] ;
//	student s[40] ;

	cout<<"1.) Add a course\n2.) Add a student\n3.) Add a result\n4.) View results\n5.) Quit"<<endl;
	cin>>selection;

	switch(selection){
		case 1:
			add_course();
			break;

		case 2:
			add_student();
			break;

		case 3:
			add_result();
			break;

		case 4:
			view_result();
			break;

		case 5:
			message();
			break;

		default :
			cout<<"Invalid Options & Open your EYES"<<endl;
	}

	return 0;
}
