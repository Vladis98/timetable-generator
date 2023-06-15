# timetable-generator

 
User manual.



To use it, you need to create a .txt file where the data will be written in the following format:

The first line is reserved for groups whose name consists only of numbers separated by spaces.

The subsequent output lines for subjects are in the form: subject name, space, parentheses, number of lectures per week, space, number of exercises per week, parentheses,
then, after a space, specify the groups belonging to this course.

You need to write the file name in main.CPP, where #define FILE "file name" is defined.

Attention! If there is a space in the course name, it should be replaced with an underscore.

I recommend using only three-digit numbers for group names; otherwise, it will work, but the table boundaries will be shifted.

For the course name, I recommend using a maximum of 23 characters (assuming it's sufficient); otherwise, it will work, but the table boundaries will be shifted.



The program has several limitations:

a) The number of lectures per course (0, 1, 2).

b) The number of exercises per course is either 1 or 0.

c) The total number of lectures is at most 15 per week.

d) The total number of exercises is at most 30 (Total number of exercises = sum of (exercises for each course * number of groups belonging to that course)).

e) The total number of groups (4, 5, 6).

I assume that these limitations closely approximate reality.



When running the program, you can bring arguments:

--group "Group names" - provides the schedule for each group.

--subject "Course names" - provides the schedule for each course.

--statistics - prints some statistics just for interest.

Empty - Prints the resulting schedule.



My program is capable of capturing some errors:

Error 100: The program cannot find or open the file.

Error 101: Incorrect number of lectures for one course.

Error 102: Incorrect number of exercises for one course.

Error 103: Groups not listed in the first line were entered for a course.

Error 104: There are groups not recorded in any course.

Error 105: File format errors.

Error 106: Incorrect argument when running.

Error 107: Incorrect total number of lectures.

Error 108: Incorrect total number of exercises.

Error 109: Empty file.

Error 110: Empty list of courses in the file.



Feel free to contribute your optimization ideas and incorporate my code into your own projects, providing a link to my GitHub repository. 

Collaboration and the utilization of shared code are encouraged in the programming community.






