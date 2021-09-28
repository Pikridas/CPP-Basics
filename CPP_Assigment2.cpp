//PIKRIDAS MENELAOS 141291

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctime>
#include <stdlib.h>
#include <string>
#include <new>

using namespace std;

class Student{
    private:
        char *am;
        string name;
        unsigned int semester;
        unsigned int passed;
        float *courses;
    public:
    //CONSTRUCTORS AND DESTRUCTOR
        Student();
        Student(char *_am, string _name);
        Student(char *_am, string _name, unsigned int _semester);
        Student(char *_am, string _name, unsigned int _semester,unsigned int _passed, float *_courses);
        Student(const Student &s1);
        ~Student();

    // SYNARTHSEIS
        void print();
        void addLesson(int number);
		void printInOneLine(ostream& channel);
		void printClasses(ostream& channel);

    // GETTERS
        char* getAM() { return am; }
        string getName() { return name; }
        unsigned int getSemester() { return semester; }
        unsigned int getPassed() { return passed; }
        float* getCourses() { return courses; }

    // SETTERS
        void setAm(char *sAm) { am = sAm; }
        void setName(string sName) { name = sName; }
        void setSemester(unsigned int sSemester) { semester = sSemester; }
        void setPassed(unsigned int sPassed) { passed = sPassed; }
        void setCourses(float* sCourses) { courses = sCourses; }

};

//DEFAULT EMPTY CONSTRUCTOR

Student::Student() {

}

//CONSTRUCTOR ME AM KAI ONOMA FOITHTH

Student::Student(char *_am, string _name) {
   
   int l = strlen(_am);
    am = new char[l+1];
	strcpy(am,_am);
        name = _name;
        semester = 1;
        passed = 0;
}

//CONSTRUCTOR ME AM, ONOMA KAI EXSAMHNO FOITHTH

Student::Student(char *_am, string _name, unsigned int _semester) {
    
    int l = strlen(_am);
    am = new char[l+1];
	strcpy(am,_am);

    name = _name;
    semester = _semester;
    passed = 0;
}

//CONSTRUCTOR ME OLA TA PEDIA THS KLASHS

Student::Student(char *_am, string _name, unsigned int _semester, unsigned int _passed, float *_courses) {
    
    int l = strlen(_am);
    am = new char[l+1];
	strcpy(am,_am);

    name = _name;
    semester = _semester;
    passed = _passed;

    courses = new float[passed];
    for (int i=0; i<passed; i++)
    {
        courses[i] = _courses[i];
    }
}

// COPY CONSTRUCTOR
  /*
        XRHSH COPY CONSTRUCTOR
        FTIAXNW KAINOURGIO ANTIKEIMENO THS KLASHS
        KAI TOU PERNAME SAN ORISMA ENA HDH YPARXWN 
        ANTIKEIMENO STO OPOIO YPARXOUN DEDOMENA.
    */

Student::Student(const Student &s1) {

    int l = strlen(s1.am);
    am = new char[l+1];
	strcpy(am,s1.am);
    
    am = s1.am;
    name = s1.name;
    semester = s1.semester;
    passed = s1.passed;

    courses = new float[s1.passed];
    for (int i=0; i<s1.passed; i++)
    {
        courses[i] = s1.courses[i];
    }

}
// DEFAULT DESTRUCTOR
    Student::~Student() {

	cout<< "DIAGRAFH AM KAI MATHMATWN "<<endl;
	delete[] am;
	if(courses!=NULL)
	{
		delete[] courses;	
	}
}

// SYNARTHSH H OPOIA EKTYPWNEI TA DEDOMENA TWN PEDIWN THS KLASHS
// TA DEDOMENA TA VAZOUME STHN MAIN

void Student::print() {

    cout << "------------- STOIXEIA FOITHTH -------------" << endl;
    cout << "ONOMA FOITHTH: " << name << endl;
    cout << "AM FOITHTH: " << am << endl;
    cout << "AKADIMAIKO EXSAMINO: " << semester << endl;
    cout << "ARITHMOS PERASMENWN MATHIMATWN: " << passed << endl;
    if (passed > 0)
    {
        for (int i=0; i<passed; i++)
        {
            cout << i+1 <<"o MATHIMA: " << courses[i] << endl;
        }

    }
    cout << endl;
}

// SYNARTHSH H OPOIA PROSTHETEI ENA AKOMA PERASMENO MATHIMA
/* 
   FTIAXNOUME PROSWRINO PINAKA +1 THESHS APO AYTON POU EXOYME
   DHLWSEI STHN MAIN KAI VAZOUME TO PARAPANW MATHIMA
   META KANOUME ANTIGRAFH TON NEO PINAKA STON PALIO,
   STON OPOIO VAZOUME +1 THESI.
*/

void Student::addLesson(int number) {
    int i;
	
	float* grades = new float[passed+1];
	
	for(i=0; i<=passed; i++)
	{		
		if(i == passed)
		{
			grades[i] = number;
            cout<<endl;
			break;
		}
		grades[i] = courses[i];	
	}
    
    passed += 1;
	delete[] courses;
    courses = grades;
}

void Student::printInOneLine(ostream& channel) {

    cout << "-------------- STOIXEIA FOITHTH --------------" << endl;
	
	channel  << name << " "<< am << " "<< semester << endl;

}

void Student::printClasses(ostream& channel) {
		
		float sum = 0;
		float mo = 0;
		
		for(int i=0; i<passed; i++)
		{
			//cout <<"ΜΑΘΗΜΑ " << i+1 <<"o: "<< courses[i] << endl; Δεν μου εμφανίζει τα ελληνικά.
            cout <<"MATHIMA " << i+1 <<"o: "<< courses[i] << endl;
			sum += courses[i];
		}
		mo = sum/passed;	
		cout << "MESOS OROS MATHIMATWN: " << mo << endl;
}

int main()
{
    system ("chcp 1253");
    int i;
    float array[5];
    float num = rand() % 6 + 5;

    // METAVLITES GETTERS
    char* gAm;
    string gName;
    unsigned int gSemester;
    unsigned int gPassed;
    float* gCourses;

    // KALOUME TON CONSTRUCTOR ME AM KAI ONOMA.
    
    Student s1("141291","MENELAOS PIKRIDAS");
    s1.print();

   // KALOUME TON CONSTRUCTOR ME AM, ONOMA KAI EXSAMHNO.

    Student s2("141292","MANOS PIKRIDAS",6);
    s2.print();
  
   // PINAKAS ME VATHMOUS [ 5 - 10 ] KAI ONOMATA PERASMENWN MATHIMATWN.

    srand(time(NULL)); // TYXAIOPOIHSH ARITHMWN PINAKA ME VASH TON XRONO.

    for (i=0;i<5;i++)
    {
        array[i] = rand() % 6 + 5;
    }

    cout << endl;

    // KALOUME TON FULL CONSTRUCTOR.

    Student s3("141293","KITSOS PIKRIDAS",6,5,array);
    s3.print();

    // PARADEIGMATA COPY CONSTRUCTOR
    
    cout << "COPY CONSTRUCTOR 1" << endl;

    Student s4(s1);
    s4.print();

    cout << "COPY CONSTRUCTOR 2" << endl;

    Student s5(s2);
    s5.print();

    cout << "COPY CONSTRUCTOR 3" << endl;

    Student s6(s3);
    s6.print();

    // YLOPOIHSHS GETTERS - SETTERS
    cout << "---------- GETTERS ----------" << endl;
    gAm = s3.getAM();
    gName = s3.getName();
    gSemester = s3.getSemester();
    gPassed = s3.getPassed();
    gCourses = s3.getCourses();

    cout << "ONOMA FOITHTH: " << gName << endl;
    cout << "AM FOITHTH: " << gAm << endl;
    cout << "AKADIMAIKO EXSAMINO: " << gSemester << endl;
    cout << "ARITHMOS PERASMENWN MATHIMATWN: " << gPassed << endl;
    if (gPassed > 0)
    {
        for (i=0; i<gPassed; i++)
        {
            cout << i+1 <<"o MATHIMA: " << gCourses[i] << endl;
        }

    }
    cout << endl;

    cout << "---------- SETTERS ----------" << endl;

    Student sStudent;
    sStudent.setName("JOHN DOE");
    sStudent.setAm("000001");
    sStudent.setSemester(99);
    sStudent.setPassed(1);
    sStudent.setCourses(array);

    cout << "ONOMA FOITHTH: " << sStudent.getName() << endl;
    cout << "AM FOITHTH: " << sStudent.getAM() << endl;
    cout << "AKADIMAIKO EXSAMINO: " << sStudent.getSemester() << endl;
    cout << "ARITHMOS PERASMENWN MATHIMATWN: " << sStudent.getPassed() << endl;
    if (sStudent.getPassed() > 0)
    {
        for (i=0; i<sStudent.getPassed(); i++)
        {
            cout << i+1 <<"o MATHIMA: " << sStudent.getCourses()[i] << endl;
        }

    }
    cout << endl;

    cout << "---------- NEOS PINAKAS PERASMENWN MATHIMATWN ----------" << endl;

    // YLOPOIHSH TWN SYNARTHSEWN
    s3.addLesson(num);
    s3.print();
    cout << endl;

    cout << "------------- EKTYPWSH STOIXEIWN FOITHTH SE MIA GRAMMH -------------" << endl;
    cout << endl;
    s3.printInOneLine(cout);
    cout << endl;

    cout << "---------- ANALYTIKH VATHMOLOGIA FOITHTH ----------" << endl;

	s3.printClasses(cout);
    cout << endl;

    return 0;
}