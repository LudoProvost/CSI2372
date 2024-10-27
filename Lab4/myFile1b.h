/*myFile1b.h, Ex1 a4 CSI2372A*/


#include <iostream>
using namespace std;

class Student {
	int numID;
	int nbCourses;
	int maxCourses;
	int* List_grades;
	Course** List_courses;
public:
	Student(int, int);// Constructor initializing all private: variables
	~Student();		  // Destructor deleting the list of grades and courses
	double average(); // Calculate the average of the students grade
	int totalHours(); // Calculate the total number of course hours the student took
	bool addCourse(Course*, int); // Add a course to List_course array
};

// Constructor
Student::Student(int id, int courses) : numID(courses), maxCourses(courses), nbCourses(0) { 
	// Create a pointer pointing to an array of integers that are a list of the grades of a student
	List_grades = new int[maxCourses];

	// Create a pointer pointing to an array of pointers that point to a different course
	List_courses = new Course*[maxCourses];
}

Student::~Student(){ // Destructor
	delete[] List_grades; 
	delete[] List_courses; 
}

double Student::average(){
	int avg = 0;
	double double_nbCourses = static_cast<double>(nbCourses); 

	if (nbCourses == 0){
		return 0.0;
	}
	// Sum up all the grades in List_grades
	for (int i = 0; i < nbCourses; i++){
		avg += List_grades[i];
	}
	return static_cast<double>(avg)/double_nbCourses;
}

int Student::totalHours(){
	int total = 0;

	// Sum up all the hours for each of the hours in the list of courses
	for (int i = 0; i < nbCourses; i++){
		total += List_courses[i]->getHours();
	}
	return total;
}

bool Student::addCourse(Course* c, int name){
	
	// Check if we've exceeded the max number of courses
	if (nbCourses >= maxCourses){
		return false;
	} // If not, add the course as the next pointer in List_courses
	List_courses[nbCourses] = c;
	List_grades[nbCourses] = name;
	nbCourses++;
	return true;
	
}