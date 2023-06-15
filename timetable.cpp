#include "timetable.hpp"

using namespace std;

stringstream ReadGroups(ifstream &INPUT)
{
    string row;
    getline(INPUT, row);
    stringstream ss(row);
    return ss;
}

string loadCourseFile(vector<Course> &TempCourse, vector<value> &values, string fname)
{
    Course Course1;
    stringstream ss1;
    ifstream INPUT(fname);
    string Word, row;
    int it_1 = 0, it_2 = 0;
    if (INPUT.is_open())
    {
        ss1 = ReadGroups(INPUT);
        while (ss1 >> Word)
        {
            try
            {
                values.push_back(stoi(Word));
            }
            catch (...)
            {
                return "incorrect_data";
            }
            it_1++;
        }
        Word.clear();
        while (getline(INPUT, row))
        {
            stringstream ss(row);
            int p = 0;
            while (ss >> Word)
            {
                if (p == 0)
                {
                    replace(Word.begin(), Word.end(), '_', ' ');
                    Course1.NameOFsubject = Word;
                }
                else if (p == 2)
                {
                    try
                    {
                        Course1.AmountOFlectures = stoi(Word);
                    }
                    catch (...)
                    {
                        return "incorrect_data";
                    }
                }
                else if (p == 3)
                {
                    try
                    {
                        Course1.AmountOFseminars = stoi(Word);
                    }
                    catch (...)
                    {
                        return "incorrect_data";
                    }
                }
                else if (p >= 5)
                {
                    try
                    {
                        Course1.Groups.push_back(stoi(Word));
                    }
                    catch (...)
                    {
                        return "incorrect_data";
                    }
                }
                p++;
            }
            Course1.AmountOFgroups = (p - 5);
            TempCourse.push_back(Course1);
            Course1.NameOFsubject.clear();
            Course1.Groups.clear();
            row.clear();
            it_2++;
        }
        if (it_1 < 1 && it_2 < 1)
            return "empty_file";
        else if (it_1 > 1 && it_2 < 1)
            return "empty_list_of_subjects";
    }
    else
        return "cannot_open_file";
    return "open_file";
}
