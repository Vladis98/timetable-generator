#include "timetable.hpp"

#define FILE "example_1.txt" //You can change the file name from which the data is loaded

using namespace std;

namespace table
{
    string line1()
    {
        stringstream ss;
        ss << "+" << string(266, '-') << "+" << endl;
        return ss.str();
    }
    string line2()
    {
        stringstream ss;
        ss << "+" << string(291, '-') << "+" << endl;
        return ss.str();
    }
}

int main(int argc, char **argv)
{
    
    vector<Day> Week(5);
    vector<Time> Hours(5);
    vector<value> Groups, Order_of_groups, groups_from_argument, groups_unused;
    vector<Course> My_course;
    vector<string> Order_of_lectures, Order_of_seminars, Hour(5), lessons_from_argument;
    string status, flag_in;
    int Amount_of_lectures = 0, Amount_of_seminars = 0;

    status = loadCourseFile(My_course, Groups, FILE);  

    if (status == "cannot_open_file")
    {
        cerr << status << endl;
        return 100;
    }

    if (status == "incorrect_data")
    {
        cerr << status << endl;
        return 105;
    }

    if(status == "empty_file"){
        cerr << status << endl;
        return 109;
    }

    if (status == "empty_list_of_subjects"){
        cerr << status << endl;
        return 110;
    }

    vector<Group> Vector_of_groups((int)Groups.size());

    sort(My_course.begin(), My_course.end(), [](const Course &dot1, const Course &dot2) -> bool {
        if (dot1.AmountOFlectures == dot2.AmountOFlectures)
        {
            if (dot1.AmountOFseminars == dot2.AmountOFseminars)
                return dot1.AmountOFgroups > dot2.AmountOFgroups;
            else
                return dot1.AmountOFseminars > dot2.AmountOFseminars;
        }
        else
            return dot1.AmountOFlectures > dot2.AmountOFlectures;
    });
    
    for (unsigned long int j = 0; j < My_course.size(); j++)
    {
        if ((My_course.at(j).AmountOFlectures == 0) || (My_course.at(j).AmountOFlectures == 1) || (My_course.at(j).AmountOFlectures == 2))
            Amount_of_lectures += My_course.at(j).AmountOFlectures;
        else
        {
            cerr << "lectures_out_of_size" << endl;
            return 101;
        }
        if ((My_course.at(j).AmountOFseminars == 0) || (My_course.at(j).AmountOFseminars == 1))
            Amount_of_seminars += (My_course.at(j).AmountOFseminars * (int)My_course.at(j).Groups.size());
        else
        {
            cerr << "practices_out_of_size" << endl;
            return 102;
        }
    }

    for (int i = 0; i < (int)My_course.size(); i++)
    {
        if (My_course.at(i).Groups.size() > Groups.size())
        {
            cerr << "unusually_large_size" << endl;
            return 103;
        }
    }

    for (int j = 0; j < (int)Groups.size(); j++)
    {
        bool check = 1;
        for (int i = 0; i < (int)My_course.size(); i++)
        {
            for (int p = 0; p < (int)My_course.at(i).Groups.size(); p++)
            {
                if (My_course.at(i).Groups.at(p) == Groups.at(j))
                    check = 0;
            }
        }
        if (check == 1)
            groups_unused.push_back(Groups.at(j));
    }

    if (groups_unused.size() > 0){
        cerr << "unused_groups: ";
        for(int i = 0; i < (int)groups_unused.size(); i++){
            cerr << groups_unused.at(i) << " ";
        }
        cerr << endl;
        return 104;
    }

    Week.at(0).NameOFday = "Monday";
    Week.at(1).NameOFday = "Tuesday";
    Week.at(2).NameOFday = "Wednesday";
    Week.at(3).NameOFday = "Thursday";
    Week.at(4).NameOFday = "Friday";
    for (int i = 0; i < 5; i++)
    {
        Week.at(i).Hours = Hours;
    }
    Hour.at(0) = "9:15 - 10:45";
    Hour.at(1) = "11:00 - 12:30";
    Hour.at(2) = "12:45 - 14:15";
    Hour.at(3) = "14:30 - 16:00";
    Hour.at(4) = "16:15 - 17:45";
    
    for (int i = 0; i < (int)My_course.size(); i++)
    {
        if (My_course.at(i).AmountOFlectures == 1)
            Order_of_lectures.push_back(My_course.at(i).NameOFsubject);
        else if (My_course.at(i).AmountOFlectures == 2)
        {
            Order_of_lectures.push_back(My_course.at(i).NameOFsubject);
            Order_of_lectures.push_back(My_course.at(i).NameOFsubject);
        }
        else if (My_course.at(i).AmountOFlectures == 0)
            continue;
    }

    for (int i = 0; i < (int)My_course.size(); i++)
    {
        if (My_course.at(i).AmountOFseminars == 1)
        {
            for (int j = 0; j < (int)My_course.at(i).Groups.size(); j++)
            {
                Order_of_seminars.push_back(My_course.at(i).NameOFsubject);
            }
        }
        else if (My_course.at(i).AmountOFseminars == 0)
            continue;
    }

    for (int i = 0; i < (int)My_course.size(); i++)
    {
        if (My_course.at(i).AmountOFseminars == 1)
        {
            for (int j = 0; j < (int)My_course.at(i).Groups.size(); j++)
            {
                Order_of_groups.push_back(My_course.at(i).Groups.at(j));
            }
        }
        else if (My_course.at(i).AmountOFseminars == 0)
            continue;
    }

    int tee = 0;
    do
    {
        for (int k = 0; k < (int)Order_of_lectures.size(); k++)
        {
            int r = k + rand() % (Amount_of_lectures - k);
            swap(Order_of_lectures.at(r), Order_of_lectures.at(k));
        }
        for (int i = 0; i < (int)Order_of_lectures.size(); i++)
        {
            for (int j = 1; j < ((int)Order_of_lectures.size() - 1); j++)
            {
                if ((Order_of_lectures.at(j) != Order_of_lectures.at(j - 1)) && (Order_of_lectures.at(j) != Order_of_lectures.at(j + 1)))
                    tee++;
                else
                    tee = 0;
            }
        }
    } while (tee < ((int)Order_of_lectures.size() - 2));

    int temp = 0, tem1 = 0; 
    unsigned long int Amount_of_iterations = 0;
    do
    {
        for (int k = 0; k < (int)Order_of_seminars.size(); k++)
        {
            int r = k + rand() % ((int)Order_of_seminars.size() - k);
            swap(Order_of_seminars.at(r), Order_of_seminars.at(k));
            swap(Order_of_groups.at(r), Order_of_groups.at(k));
            Amount_of_iterations++;
        }
        for (int i = 0; i < (int)Order_of_seminars.size(); i++)
        {
            for (int j = 1; j < ((int)Order_of_seminars.size() - 1); j++)
            {
                if ((Order_of_seminars.at(j) != Order_of_seminars.at(j - 1)) && (Order_of_seminars.at(j) != Order_of_seminars.at(j + 1)))
                    temp++;
                else
                    temp = 0;
                if ((Order_of_groups.at(j) != Order_of_groups.at(j - 1)) && (Order_of_groups.at(j) != Order_of_groups.at(j + 1)))
                    tem1++;
                else
                    tem1 = 0;
            }
        }
    } while ((temp < ((int)Order_of_seminars.size() - 2)) || (tem1 < ((int)Order_of_groups.size() - 2)));

    for (int i = 0; i < (int)Groups.size(); i++)
    {
        Vector_of_groups.at(i).NumberOFgroup = Groups.at(i);
        for (int j = 0; j < (int)My_course.size(); j++)
        {
            for (int p = 0; p < (int)My_course.at(j).Groups.size(); p++)
            {
                if (Groups.at(i) == My_course.at(j).Groups.at(p))
                {
                    Vector_of_groups.at(i).Subjects.push_back(My_course.at(j).NameOFsubject);
                    if (My_course.at(j).AmountOFlectures == 1)
                        Vector_of_groups.at(i).OrderOFlectures.push_back(My_course.at(j).NameOFsubject);
                    else if (My_course.at(j).AmountOFlectures == 2)
                    {
                        Vector_of_groups.at(i).OrderOFlectures.push_back(My_course.at(j).NameOFsubject);
                        Vector_of_groups.at(i).OrderOFlectures.push_back(My_course.at(j).NameOFsubject);
                    }
                    else if (My_course.at(j).AmountOFlectures == 0)
                        continue;
                    if (My_course.at(j).AmountOFseminars == 0)
                        continue;
                    else if (My_course.at(j).AmountOFseminars == 1)
                        Vector_of_groups.at(i).OrderOFseminars.push_back(My_course.at(j).NameOFsubject);
                }
            }
        }
    }

    if (Amount_of_lectures > 15)
    {
        cerr << "too_many_lectures" << endl;
        return 107;
    }
    if (Amount_of_seminars > 30)
    {
        cerr << "too_many_practices" << endl;
        return 108;
    }

    if (Amount_of_lectures > 10 && Amount_of_lectures <= 15)
    {
        int i = 0;
        for (int j = 0; j < 5; j++)
        {
            for (int p = 0; p < 5; p += 2)
            {
                if (i < Amount_of_lectures)
                {
                    Week.at(j).Hours.at(p).Lectures.NameOFsubject = Order_of_lectures.at(i);
                    for (int o = 0; o < (int)Vector_of_groups.size(); o++)
                    {
                        for (int u = 0; u < (int)Vector_of_groups.at(o).Subjects.size(); u++)
                        {
                            if (Order_of_lectures.at(i) == Vector_of_groups.at(o).Subjects.at(u))
                                Week.at(j).Hours.at(p).Lectures.Groups.push_back(Vector_of_groups.at(o).NumberOFgroup);
                        }
                    }
                    i++;
                }
                else
                    break;
            }
        }
    }

    else if (Amount_of_lectures <= 10)
    {
        int i = 0;
        for (int j = 0; j < 5; j++)
        {
            for (int p = 0; p < 5; p += 3)
            {
                if (i < Amount_of_lectures)
                {
                    Week.at(j).Hours.at(p).Lectures.NameOFsubject = Order_of_lectures.at(i);
                    for (int o = 0; o < (int)Vector_of_groups.size(); o++)
                    {
                        for (int u = 0; u < (int)Vector_of_groups.at(o).Subjects.size(); u++)
                        {
                            if (Order_of_lectures.at(i) == Vector_of_groups.at(o).Subjects.at(u))
                                Week.at(j).Hours.at(p).Lectures.Groups.push_back(Vector_of_groups.at(o).NumberOFgroup);
                        }
                    }
                    i++;
                }
                else
                    break;
            }
        }
    }

    int temp0 = 0;
    for (int j = 0; j < 5; j++)
    {
        if (temp0 >= (int)Order_of_seminars.size())
            break;
        for (int p = 0; p < 5; p++)
        {
            if (temp0 >= (int)Order_of_seminars.size())
                break;
            if (temp0 < (int)Order_of_seminars.size())
            {
                if ((int)Week.at(j).Hours.at(p).Lectures.NameOFsubject.size() < 1)
                {
                    Week.at(j).Hours.at(p).Seminars.NameOFsubject.push_back(Order_of_seminars.at(temp0));
                    Week.at(j).Hours.at(p).Seminars.Groups.push_back(Order_of_groups.at(temp0));
                    temp0++;
                    if (temp0 >= (int)Order_of_seminars.size())
                        break;
                }
                else
                    continue;
                if (temp0 < (int)Order_of_seminars.size())
                {
                    if ((int)Week.at(j).Hours.at(p).Lectures.NameOFsubject.size() < 1)
                    {
                        Week.at(j).Hours.at(p).Seminars.NameOFsubject.push_back(Order_of_seminars.at(temp0));
                        Week.at(j).Hours.at(p).Seminars.Groups.push_back(Order_of_groups.at(temp0));
                        temp0++;
                        if (temp0 >= (int)Order_of_seminars.size())
                            break;
                    }
                }
                else
                    continue;
            }
            else if (temp0 >= (int)Order_of_seminars.size())
                break;
        }
    }

    if (argc > 1)
        flag_in = string(argv[1]);
    else
    {
        for (int tel = 0; tel < (int)Groups.size(); tel++)
        {
            cout << table::line1();
            cout << "|   " << Groups.at(tel) << ":" << string(259, ' ') << "|" << endl;
            for (int j = 0; j < 5; j++)
            {
                int Space4 = 0;
                cout << table::line1();
                cout << "| ";
                cout << left << setw(10) << Week.at(j).NameOFday << " |";
                for (int i = 0; i < 5; i++)
                {
                    cout << left << Hour.at(i) << "| ";
                    for (int p = 0; p < (int)Week.at(j).Hours.at(i).Lectures.Groups.size(); p++)
                    {
                        if (Week.at(j).Hours.at(i).Lectures.Groups.at(p) == Groups.at(tel))
                        {
                            cout << left << setw(25) << Week.at(j).Hours.at(i).Lectures.NameOFsubject << "(Lecture) ";
                            Space4++;
                        }
                    }
                    for (int p = 0; p < (int)Week.at(j).Hours.at(i).Seminars.Groups.size(); p++)
                    {
                        if (Week.at(j).Hours.at(i).Seminars.Groups.at(p) == Groups.at(tel))
                        {
                            cout << left << setw(25) << Week.at(j).Hours.at(i).Seminars.NameOFsubject.at(p) << "(Practic) ";
                            Space4++;
                        }
                    }
                    if (Space4 == 0)
                        cout << string(35, ' ');
                    cout << "|";
                    Space4 = 0;
                }
                cout << endl;
            }
        }
        cout << table::line1();
        for (int tel = 0; tel < (int)My_course.size(); tel++)
        {
            if (tel != 0)
            {
                if (Vector_of_groups.size() != 6)
                    cout << table::line1();
                else if (Vector_of_groups.size() == 6)
                    cout << table::line2();
            }
            cout << "|   " << My_course.at(tel).NameOFsubject << ":" << endl;
            for (int j = 0; j < 5; j++)
            {
                int Space = 0, ter = 0;
                if (Vector_of_groups.size() != 6)
                    cout << table::line1();
                else if (Vector_of_groups.size() == 6)
                    cout << table::line2();
                cout << "| ";
                cout << left << setw(10) << Week.at(j).NameOFday << " |";
                for (int i = 0; i < 5; i++)
                {
                    cout << left << Hour.at(i) << "| ";
                    if (Week.at(j).Hours.at(i).Lectures.NameOFsubject == My_course.at(tel).NameOFsubject)
                    {
                        for (int p = 0; p < (int)Week.at(j).Hours.at(i).Lectures.Groups.size(); p++)
                        {
                            cout << left << setw(5) << Week.at(j).Hours.at(i).Lectures.Groups.at(p);
                            Space++;
                        }
                        cout << "(Lecture) ";
                    }
                    for (int p = 0; p < (int)Week.at(j).Hours.at(i).Seminars.NameOFsubject.size(); p++)
                    {
                        if (Week.at(j).Hours.at(i).Seminars.NameOFsubject.at(p) == My_course.at(tel).NameOFsubject)
                        {
                            cout << left << setw(5) << Week.at(j).Hours.at(i).Seminars.Groups.at(p);
                            Space++;
                            ter++;
                        }
                    }
                    if (ter != 0)
                        cout << "(Practic) ";
                    ter = 0;
                    for (int u = 0; u < (((int)Groups.size() * 5) - (Space * 5)); u++)
                    {
                        cout << " ";
                    }
                    if (Space == 0)
                        cout << string(10, ' ');
                    if (i == 4 && Vector_of_groups.size() == 4)
                        cout << string(25, ' ');
                    cout << "|";
                    Space = 0;
                }
                cout << endl;
            }
        }
        if (Vector_of_groups.size() != 6)
            cout << table::line1();
        else if (Vector_of_groups.size() == 6)
            cout << table::line2();
    }
    if ((!flag_in.compare("--group")))
    {
        if (argc > 2)
        {
            for (int i = 2; i < argc; i++)
            {
                groups_from_argument.push_back(stoi(argv[i]));
            }
        }
        else
        {
            cerr << "Missing_argument" << endl;
            return 106;
        }
        for (int y = 0; y < (int)groups_from_argument.size(); y++)
        {
            cout << table::line1();
            cout << "|   " << groups_from_argument.at(y) << ":" << string(259, ' ') << "|" << endl;
            for (int j = 0; j < 5; j++)
            {
                int Space2 = 0;
                cout << table::line1();
                cout << "| ";
                cout << left << setw(10) << Week.at(j).NameOFday << " |";
                for (int i = 0; i < 5; i++)
                {
                    cout << left << Hour.at(i) << "| ";
                    for (int p = 0; p < (int)Week.at(j).Hours.at(i).Lectures.Groups.size(); p++)
                    {
                        if (Week.at(j).Hours.at(i).Lectures.Groups.at(p) == groups_from_argument.at(y))
                        {
                            cout << left << setw(25) << Week.at(j).Hours.at(i).Lectures.NameOFsubject << "(Lecture) ";
                            Space2++;
                        }
                    }
                    for (int p = 0; p < (int)Week.at(j).Hours.at(i).Seminars.Groups.size(); p++)
                    {
                        if (Week.at(j).Hours.at(i).Seminars.Groups.at(p) == groups_from_argument.at(y))
                        {
                            cout << left << setw(25) << Week.at(j).Hours.at(i).Seminars.NameOFsubject.at(p) << "(Practic) ";
                            Space2++;
                        }
                    }
                    if (Space2 == 0)
                        cout << string(35, ' ');
                    cout << "|";
                    Space2 = 0;
                }
                cout << endl;
            }
            cout << table::line1();
        }
    }

    else if ((!flag_in.compare("--subject")))
    {
        if (argc > 2)
        {
            for (int i = 2; i < argc; i++)
            {
                string temp = argv[i];
                replace(temp.begin(), temp.end(), '_', ' ');
                lessons_from_argument.push_back(temp);
            }
        }
        else
        {
            cerr << "Missing_argument" << endl;
            return 106;
        }
        for (int y = 0; y < (int)lessons_from_argument.size(); y++)
        {
            if (Vector_of_groups.size() != 6)
                cout << table::line1();
            else if (Vector_of_groups.size() == 6)
                cout << table::line2();
            cout << "|   " << lessons_from_argument.at(y) << ":" << endl;
            for (int j = 0; j < 5; j++)
            {
                int Space3 = 0, ter = 0;
                if (Vector_of_groups.size() != 6)
                    cout << table::line1();
                else if (Vector_of_groups.size() == 6)
                    cout << table::line2();
                cout << "| ";
                cout << left << setw(10) << Week.at(j).NameOFday << " |";
                for (int i = 0; i < 5; i++)
                {
                    cout << left << Hour.at(i) << "| ";
                    if (Week.at(j).Hours.at(i).Lectures.NameOFsubject == lessons_from_argument.at(y))
                    {
                        for (int p = 0; p < (int)Week.at(j).Hours.at(i).Lectures.Groups.size(); p++)
                        {
                            cout << left << setw(5) << Week.at(j).Hours.at(i).Lectures.Groups.at(p);
                            Space3++;
                        }
                        cout << "(Lecture) ";
                    }
                    for (int p = 0; p < (int)Week.at(j).Hours.at(i).Seminars.NameOFsubject.size(); p++)
                    {
                        if (Week.at(j).Hours.at(i).Seminars.NameOFsubject.at(p) == lessons_from_argument.at(y))
                        {
                            cout << left << setw(5) << Week.at(j).Hours.at(i).Seminars.Groups.at(p);
                            Space3++;
                            ter++;
                        }
                    }
                    if (ter != 0)
                        cout << "(Practic) ";
                    ter = 0;
                    for (int u = 0; u < (((int)Groups.size() * 5) - (Space3 * 5)); u++)
                    {
                        cout << " ";
                    }
                    if (Space3 == 0)
                        cout << string(10, ' ');
                    if (i == 4 && Vector_of_groups.size() == 4)
                        cout << string(25, ' ');
                    cout << "|";
                    Space3 = 0;
                }
                cout << endl;
            }
            if (Vector_of_groups.size() != 6)
                cout << table::line1();
            else if (Vector_of_groups.size() == 6)
                cout << table::line2();
        }
    }
    else if ((!flag_in.compare("--statistics"))){
        cout << "The number of groups: " << Groups.size() << endl;
        cout << "The number of subjects: " << My_course.size() << endl;
        cout << "The number of lectures per week: " << Amount_of_lectures << endl;
        cout << "The number of seminars per week: " << Amount_of_seminars << endl;
        cout << "The number of iterations to find a suitable schedule: " << Amount_of_iterations << endl;
    }

    return 0;
}
