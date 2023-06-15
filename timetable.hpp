#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
/*
The total number of lectures is at most 15.
The number of lectures for a single subject can be 0, 1, or 2.
The number of exercises for a single subject must be 0 or 1.
The total number of groups ranges from 4 to 6.
The total time per week for each group is 12, 13, or 14.
The total number of exercises is at most 30.
...
For group names, I recommend using only three-digit numbers. It will still work if you use other numbers, but the table boundaries might be shifted.
For subject names, I recommend using a maximum of 23 characters (assuming it's sufficient). It will still work if you use longer names, but the table boundaries might be shifted.
*/
using namespace std;

// This parameter cannot be changed as the program is still being tested :)
using value = int; // Use int if group names consist only of numbers. Use string for any group name.
// ...

class Lesson
{
public:                              // Class for individual Subjects
    vector<value> Groups;            // Groups attending this Subject
    string NameOFsubject;            // Name of the Subject
};

class Lecture 
{                             
public:                              // Class for individual lectures
    string NameOFsubject;            // Name of the lecture
    vector<value> Groups;            // Groups attending this lecture
};

class Seminar 
{
public:                              // Class for individual seminars
    vector<string> NameOFsubject;    // Names of seminars for each day and time
    vector<value> Groups;            // Groups attending this seminar
};

class Group
{
public:                               // Class for a group of students
    value NumberOFgroup;              // Group name or number
    vector<string> Subjects;          // Subjects associated with this group
    vector<string> OrderOFseminars;   // Seminars associated with this group
    vector<string> OrderOFlectures;   // Lectures associated with this group
};

class Course
{
public:                               // Main class for each course
    string NameOFsubject;             // Name of the subject
    vector<value> Groups;             // Groups enrolled in this course
    int AmountOFgroups;               // Number of groups
    int AmountOFlectures;             // Number of lectures
    int AmountOFseminars;             // Number of seminars
    Course(){};                       // Default constructor
};

class Time
{
public:                               // Class for individual hours in a day
    Lecture Lectures;                 // Lectures
    Seminar Seminars;                 // Seminars
};

class Day
{
public:                               // Class for each day of the week
    vector<Time> Hours;               // Individual hours in a day
    string NameOFday;                 // Name of the day in the week
};

stringstream ReadGroups(ifstream &INPUT);                                               // Function for reading all the groups

string loadCourseFile(vector<Course> &TempCourse, vector<value> &values, string fname); // Suitable function for loading other data

