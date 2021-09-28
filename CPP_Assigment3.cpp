// PIKRIDAS MENELAOS 141291

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctime>
#include <stdlib.h>
#include <string>
#include <fstream>
#define SIZE 5

using namespace std;

class Mathima {
    private:
        string kwdikos;
        string onoma;
        unsigned int exsamino;
    public:
    //CONSTRUCTORS AND DESTRUCTOR
        Mathima();
        Mathima(string _kwdikos, string _onoma, unsigned int _exsamino);
        Mathima(const Mathima &m);

    //GETTERS
        string getKwdikos() { return kwdikos; }
        string getOnoma() { return onoma; }
        unsigned int getExsamino() { return exsamino; }

    // SETTERS
        void setKwdikos(string sKwdikos) { kwdikos = sKwdikos; }
        void setOnoma(string sOnoma) { onoma = sOnoma; }
        void setExsamino(unsigned int sExsamino) { exsamino = sExsamino; }
    // SYNARTHSEIS
        void print();
};

class Student {
    private:
        char *am;
        string name;
        unsigned int semester;
        unsigned int passed;
        unsigned int plithos;
        float *courses;
        Mathima **mathima;
    public:
    //CONSTRUCTORS AND DESTRUCTOR
        Student();
        Student(char *_am, string _name);
        Student(char *_am, string _name, unsigned int _semester);
        Student(char *_am, string _name, unsigned int _semester, unsigned int _passed, float *_courses);
        Student(const Student &s1);
        ~Student();

    // SYNARTHSEIS
        void addLesson(int number);
		void printInOneLine(ostream& channel);
		void printClasses(ostream& channel);

        void operator += (Mathima* m);
        void operator = (const Student &s);
        bool operator == (const Student &s);
        bool operator != (const Student &s);
        bool operator < (const Student &s);
        bool operator <= (const Student &s);
        bool operator > (const Student &s);
        bool operator >= (const Student &s);

    // GETTERS
        char* getAM() const { return am; }
        string getName() const { return name; }
        unsigned int getSemester() const { return semester; }
        unsigned int getPassed() const { return passed; }
        unsigned int getPlithos() const { return plithos; }
        float* getCourses() const { return courses; }
        Mathima** getMathima() const { return mathima; }

    // SETTERS
        void setAm(char* sAm) { am = sAm; }
        void setName(string sName) { name = sName; }
        void setSemester(unsigned int sSemester) { semester = sSemester; }
        void setPassed(unsigned int sPassed) { passed = sPassed; }
        void setPlithos(unsigned int sPlithos) { plithos = sPlithos; }
        void setCourses(float* sCourses) { courses = sCourses; }
};

//CONSTRUCTORS - DESTRUCTOR THS KLASHS MATHIMA

//DEFAULT CONSTRUCTOR
    Mathima::Mathima() {
      
    }

//CONSTRUCTOR ME OLA TA PEDIA THS KLASHS
    Mathima::Mathima(string _kwdikos, string _onoma, unsigned int _exsamino) {
        kwdikos = _kwdikos;
        onoma = _onoma;
        exsamino = _exsamino;
    }

//COPY CONSTRUCTOR
    Mathima::Mathima(const Mathima &m) {
        kwdikos = m.kwdikos;
        onoma = m.onoma;
        exsamino = m.exsamino;
    }

//SYNARTHSH EKTYPWSHS STOIXEIWN MATHIMATWN
void Mathima::print() {

    cout << endl;
    cout << "---------- STOIXEIA MATHIMATOS ----------" << endl;
    cout << "KWDIKOS: " << kwdikos << endl;
    cout << "ONOMA: " << onoma << endl;
    cout << "EXSAMINO MATHIMATOS: " << exsamino << endl;
    cout << endl;
}

//CONSTRUCTORS - DESTRUCTOR THS KLASHS STUDENT

//DEFAULT KENOS CONSTRUCTOR

Student::Student() {
    am = NULL;
	name = "N/A";
	semester = 0;
	passed = 0;
	plithos = 0;
	courses = NULL;
	mathima = NULL;
}

//CONSTRUCTOR ME AM KAI ONOMA FOITHTH

Student::Student(char *_am, string _name) {
   
   int l = strlen(_am);
    am = new char[l+1];
	memcpy(am,_am,l);
        name = _name;
        semester = 1;
        passed = 0;
        plithos = 0;
        courses = NULL;
        mathima = NULL;
}

//CONSTRUCTOR ME AM, ONOMA KAI EXSAMHNO FOITHTH

Student::Student(char *_am, string _name, unsigned int _semester) {
    
    int l = strlen(_am);
    am = new char[l+1];
	memcpy(am,_am,l);

    name = _name;
    semester = _semester;
    passed = 0;
    plithos = 0;
    courses = NULL;
    mathima = NULL;
}

//CONSTRUCTOR ME OLA TA PEDIA THS KLASHS

Student::Student(char *_am, string _name, unsigned int _semester, unsigned int _passed, float *_courses) {
    
    int l = strlen(_am);
    am = new char[l+1];
	memcpy(am,_am,l);

    name = _name;
    semester = _semester;
    passed = _passed;

    courses = new float[passed];
    for (int i=0; i<passed; i++)
    {
        courses[i] = _courses[i];
    }

    plithos = 0;
    mathima = NULL;
}

// COPY CONSTRUCTOR
  /*
        XRHSH COPY CONSTRUCTOR
        FTIAXNW KAINOURGIO ANTIKEIMENO THS KLASHS
        KAI TOU PERNAME SAN ORISMA ENA HDH YPARXWN 
        ANTIKEIMENO STO OPOIO YPARXOUN DEDOMENA.
    */

Student::Student(const Student &s1) {

    int i=0;

    int l = strlen(s1.am);
    am = new char[l+1];
	memcpy(am,s1.am,l);
    
    name = s1.name;
    semester = s1.semester;
    passed = s1.passed;
    plithos = s1.plithos;

    if (passed == 0)
    {
        courses = NULL;
    }

    else
    {
        courses = new float[s1.passed];
        for (i=0; i<s1.passed; i++)
        {
            courses[i] = s1.courses[i];
        }
    }

    if (plithos == 0 )
	{
		mathima = NULL;
	}

	else
	{
		mathima = new Mathima * [plithos];
		for (i=0; i < plithos; i++)
		{
			mathima[i] = s1.mathima[i];
		}
	}	
}

// DEFAULT DESTRUCTOR
Student::~Student() {

    int i;

    if( am != NULL)
	{
		delete[] am;
        cout << "DIAGRAFH AM" << endl;
	}

	if(courses != NULL)
	{
		delete[] courses;
        cout << "DIAGRAFH PERASMENWN MATHIMATWN" << endl;
	}

    if(mathima != NULL)
	{
		for (i=0; i<plithos; i++)
		{
			delete [] mathima[i];
            cout << "DIAGRAFH DILWMENWN MATHIMATWN" << endl;
		}
		delete[] mathima;
        cout << "DIAGRAFTHKAN OLA TA DHLWMENA MATHIMATA" << endl;	
	}
}

// SYNARTHSH H OPOIA PROSTHETEI ENA AKOMA PERASMENO MATHIMA

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

// YPERFORTWSEIS TELESTWN

void Student::operator += (Mathima* m) {
	plithos++;
	if (mathima == NULL)
	{
		mathima = (Mathima**)malloc(sizeof(Mathima*));
		mathima[0] = m;
	}
	else
	{
		mathima = (Mathima**)realloc(mathima, plithos * sizeof(Mathima*));
		mathima[plithos - 1] = m;
	}
}

void Student::operator = (const Student &s) {

    int i;

    delete[] am;
    int l = strlen(s.am);
    am = new char[l+1];
	memcpy(am,s.am,l);
    
    name = s.name;
    semester = s.semester;
    passed = s.passed;

    delete[] courses;
    courses = new float[s.passed];
    for (i=0; i<s.passed; i++)
    {
        courses[i] = s.courses[i];
    }

    if (s.plithos == 0)
	{
		mathima = NULL;
	}
	else
	{
		mathima = new Mathima * [s.plithos];
		for (i=0; i<s.plithos; i++)
		{
			mathima[i] = s.mathima[i];
		}
	}
}

bool Student::operator == (Student const &s) {
    
    if (semester == s.semester)
       return true;
    else
       return false;
}

bool Student::operator != (Student const &s) {
    
    if (semester != s.semester)
       return true;
    else
       return false;
}

bool Student::operator < (Student const &s) {
    
    if (semester < s.semester)
       return true;
    else
       return false;
}

bool Student::operator <= (Student const &s) {
    
    if (semester <= s.semester)
       return true;
    else
       return false;
}

bool Student::operator > (Student const &s) {
    
    if (semester > s.semester)
       return true;
    else
       return false;
}

bool Student::operator >= (Student const &s) {
    
    if (semester >= s.semester)
       return true;
    else
       return false;
}

ostream & operator << (ostream &channel, Student const &s) {
    int i;

    channel << "------------- STOIXEIA FOITHTH -------------" << endl;
    channel << "ONOMA FOITHTH: " << s.getName() << endl;
    channel << "AM FOITHTH: " << s.getAM() << endl;
    channel << "AKADIMAIKO EXSAMINO: " << s.getSemester() << endl;

    if (s.getPassed() > 0)
        channel << "ARITHMOS PERASMENWN MATHIMATWN: " << s.getPassed() << endl;
    {
        for (i=0; i<s.getPassed(); i++)
        {
            channel << i+1 <<"o MATHIMA: " << s.getCourses()[i] << endl;
        }

    }
    channel << endl;

    if (s.getPlithos() > 0)
        channel << "ARITHMOS DHLWMENWN MATHIMATWN: " << s.getPlithos() << endl;
    {
        for (i=0; i < s.getPlithos(); i++)
	    {
		    channel << s.getMathima()[i]->getKwdikos() << " ";
            channel << s.getMathima()[i]->getOnoma() << " ";
            channel << s.getMathima()[i]->getExsamino() << " ";
            channel << endl;
	    }
    }
    return channel;
}

int main()
{
    fstream file;
	file.open("output.txt",ios::in | ios::out | ios::app);

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
// EKTYPWSH ME YPERFORTWSH TELESTH <<
    Student s1("141291","MENELAOS PIKRIDAS");
    cout << s1;
    cout <<endl;

// KALOUME TON CONSTRUCTOR ME AM, ONOMA KAI EXSAMHNO.

    Student s2("141292","MANOS PIKRIDAS",6);
    cout << s2;
    cout <<endl;
  
// PINAKAS ME VATHMOUS [ 5 - 10 ] KAI ONOMATA PERASMENWN MATHIMATWN.

    srand(time(NULL)); // TYXAIOPOIHSH ARITHMWN PINAKA ME VASH TON XRONO.

    for (i=0;i<5;i++)
    {
        array[i] = rand() % 6 + 5;
    }

    cout << endl;

// KALOUME TON FULL CONSTRUCTOR.

    Student s3("141293","KITSOS PIKRIDAS",6,5,array);
    cout << s3;
    cout <<endl;

// PARADEIGMATA COPY CONSTRUCTOR
    
    cout << "COPY CONSTRUCTOR 1" << endl;

    Student s4(s1);
    cout << s4;
    cout <<endl;

    cout << "COPY CONSTRUCTOR 2" << endl;

    Student s5(s2);
    cout << s5;
    cout <<endl;

    cout << "COPY CONSTRUCTOR 3" << endl;

    Student s6(s3);
    cout << s6;
    cout <<endl;

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

// YLOPOIHSH TWN SYNARTHSEWN THS KLASHS STUDENT
    s3.addLesson(num);
    cout << s3;
    cout << endl;

    cout << "------------- EKTYPWSH STOIXEIWN FOITHTH SE MIA GRAMMH -------------" << endl;
    cout << endl;
    s3.printInOneLine(cout);
    cout << endl;

    cout << "---------- ANALYTIKH VATHMOLOGIA FOITHTH ----------" << endl;

	s3.printClasses(cout);
    cout << endl;

// DHMIOURGIA ANTIKEIMENWN MATHIMATWN
    Mathima m1("1","CPP",2);
    Mathima m2("2","JAVA",2);
    Mathima m3("3","MATHIMATIKA",3);


    cout << "---------- EKTYWPSH MATHIMATWN ----------" << endl;
    m1.print();
    m2.print();
    m3.print();

// YPERFORTWSH TELESTH +=
    cout << "----- FOITHTHS ME YPERFORTWSH TOU TELESTH += -----" << endl;
    s6 += &m1;
    s6 += &m2;
    s6 += &m3;

    file << s6;
    cout<<endl;

// YPERFORTWSH TELESTH =
    Student s7;

    s7 = s2;
    cout << "----- FOITHTHS ME YPERFORTWSH TOU TELESTH = -----" << endl;
    cout << s7;
    cout << endl;

// YPERFORTWSH TELESTH ==
   if ( s1 == s2 )
   {
       cout << "TA EXSAMINA TWN FOITHTWN EINAI ISA" << endl;
       cout << endl;
   }
   else
   {
       cout << "TA EXSAMINA TWN FOITHTWN DEN EINAI ISA" << endl;
       cout << endl;
   }

// YPERFORTWSH TELESTH !=
   if ( s1 != s2 )
   {
       cout << "TA EXSAMINA TWN FOITHTWN DEN EINAI ISA" << endl;
       cout << endl;
   }
   else
   {
       cout << "TA EXSAMINA TWN FOITHTWN EINAI ISA" << endl;
       cout << endl;
   }

// YPERFORTWSH TELESTH <
   if ( s1 < s2 )
   {
       cout << "TO EXSAMHNO TOU FOITHTH " << s1.getAM() << " EINAI MIKROTERO" << endl;
       cout << endl;
   }
   else
   {
       cout << "TO EXSAMHNO TOU FOITHTH " << s2.getAM() << " EINAI MIKROTERO" << endl;
       cout << endl;
   }

// YPERFORTWSH TELESTH <=
   if ( s1 <= s2 )
   {
       cout << "TO EXSAMHNO TOU FOITHTH " << s1.getAM() << " EINAI MIKROTERO H ISO" << endl;
       cout << endl;
   }
   else
   {
       cout << "TO EXSAMHNO TOU FOITHTH " << s2.getAM() << " EINAI MIKROTERO H ISO" << endl;
       cout << endl;
   }

// YPERFORTWSH TELESTH >
   if ( s1 > s2 )
   {
       cout << "TO EXSAMHNO TOU FOITHTH " << s1.getAM() << " EINAI MEGALYTERO" << endl;
       cout << endl;
   }
   else
   {
       cout << "TO EXSAMHNO TOU FOITHTH " << s2.getAM() << " EINAI MEGALYTERO" << endl;
       cout << endl;
   }

// YPERFORTWSH TELESTH >=
   if ( s1 >= s2 )
   {
       cout << "TO EXSAMHNO TOU FOITHTH " << s1.getAM() << " EINAI MEGALYTERO H ISO" << endl;
       cout << endl;
   }
   else
   {
       cout << "TO EXSAMHNO TOU FOITHTH " << s2.getAM() << " EINAI MEGALYTERO H ISO" << endl;
       cout << endl;
   }

    return 0;
}