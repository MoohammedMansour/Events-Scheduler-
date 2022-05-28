#include "Event.h"

inline bool operator<(const EventInfo& lhs, const EventInfo& rhs)
{
    return (lhs.startDate + lhs.reminderTime <= rhs.startDate + rhs.reminderTime);
}

bool Event::is_number(const string& s)
{
    string::const_iterator it = s.begin();
    while (it != s.end())
    {
        if (isdigit(*it) || *it == '/')
        {
            ++it;

        }
        else
        {
            break;
        }

    }
    return !s.empty() && it == s.end();
}

bool Event::is_time(const string& s)
{

    int valide = true;
    if (s[0] == '2' && s[1] > '3')
    {
        valide = false;
    }
    else if (s[0] < '2' && s[1] > '9')
    {
        valide = false;
    }
    else if (s[0] > '2')
    {
        valide = false;
    }
    else if (s[3] < '5' && s[4]>'9')
    {
        valide = false;
    }
    else if (s[3] > '5')
    {
        valide = false;
    }
    string::const_iterator it = s.begin();
    while (it != s.end())
    {
        if (isdigit(*it) || *it == ':')
        {
            ++it;

        }
        else
        {
            break;
        }

    }
    return !s.empty() && it == s.end() && valide;
}

bool Event::is_date(string s)
{
    Time();
    string d = date;
    bool valide = true;
    if (s[6] < '2' || s[6]>'3' || s[8] < '2' || s[6] < '2')
    {
        valide = false;
    }
    else if (s[6] == d[6] && s[7] == d[7] && s[8] == d[8] && s[9] == d[9])
    {
        if (s[3] == d[3] && s[4] == d[4])
        {
            if (s[0] == d[0] && s[1] < d[1])
            {
                valide = false;
            }
            else if (s[0] < d[0])
            {
                valide = false;
            }
        }
        else if (s[3] == d[3] && s[4] < d[4])
        {
            valide = false;
        }
        else if (s[3] < d[3])
        {
            valide = false;
        }
    }

    else if (s[0] == '3' && s[1] > '1')
    {
        valide = false;
    }
    else if (s[0] < '3' && s[1] > '9')
    {
        valide = false;
    }
    else if (s[0] > '3')
    {
        valide = false;
    }
    else if (s[3] == '1' && s[4] > '2')
    {
        valide = false;
    }

    else if (s[3] < '1' && s[4]>'9')
    {
        valide = false;
    }
    else if (s[3] > '1')
    {
        valide = false;
    }

    return valide;
}

bool Event::is_endDate(string s)			
{

    bool valide = true;

    if (s[6] == event.startDate[6] && s[7] == event.startDate[7] && s[8] == event.startDate[8] && s[9] == event.startDate[9])
    {
        if (s[3] == event.startDate[3] && s[4] == event.startDate[4])
        {
            if (s[0] == event.startDate[0] && s[1] < event.startDate[1])
            {
                valide = false;
            }
            else if (s[0] < event.startDate[0])
            {
                valide = false;
            }
        }
        else if (s[3] == event.startDate[3] && s[4] < event.startDate[4])
        {
            valide = false;
        }
        else if (s[3] < event.startDate[3])
        {
            valide = false;
        }
    }
    else if (s[6] == event.startDate[6] && s[7] == event.startDate[7] && s[8] == event.startDate[8] && s[9] < event.startDate[9])
    {
        valide = false;
    }
    else if (s[6] == event.startDate[6] && s[7] == event.startDate[7] && s[8] < event.startDate[8])
    {
        valide = false;
    }
    else if (s[6] == event.startDate[6] && s[7] < event.startDate[7])
    {
        valide = false;
    }
    else if (s[6] < event.startDate[6])
    {
        valide = false;
    }

    return valide;
}

void Event::Add()
{
    do
    {
        bool redundant = false;
        available = true;
        cout << "Enter the event name (If you want to add more than one word you can you - or _ ) : ";
        cin >> event.name;

        cout << "Enter the event place (If you want to add more than one word you can you - or _ ) : ";
        cin >> event.place;

        cout << "Enter the event start date (DD/MM/YYYY) : ";
        cin >> event.startDate;
        while (event.startDate.size() != 10 || !is_number(event.startDate) || !is_date(event.startDate) || event.startDate[2] != '/' || event.startDate[5] != '/')
        {
            cout << "Please enter a valid Date" << endl;
            cout << "Enter the event start date (DD/MM/YYYY) : ";
            cin >> event.startDate;
        }

        cout << "Enter the event end date (DD/MM/YYYY) : ";
        cin >> event.endDate;
        while (event.endDate.size() != 10 || !is_number(event.endDate) || !is_date(event.endDate) || event.endDate[2] != '/' || event.endDate[5] != '/' || !is_endDate(event.endDate))
        {
            cout << "Please enter a valid Date" << endl;
            cout << "Enter the event end date (DD/MM/YYYY) : ";
            cin >> event.endDate;
        }

        cout << "Enter the event start time (HH:MM) : ";
        cin >> event.startTime;
        while (event.startTime.size() != 5 || !is_time(event.startTime) || event.startTime[2] != ':')
        {
            cout << "Please enter a valid time" << endl;
            cout << "Enter the event start time (HH:MM) : ";
            cin >> event.startTime;
        }

        cout << "Enter the event end time (HH:MM) : ";
        cin >> event.endTime;
        while (event.endTime.size() != 5 || !is_time(event.endTime) || event.endTime[2] != ':' || event.endTime <= event.startTime)
        {
            cout << "Please enter a valid time" << endl;
            cout << "Enter the event end time (HH:MM) : ";
            cin >> event.endTime;
        }

        cout << "Enter the event reminder time (HH:MM) : ";
        cin >> event.reminderTime;
        while (event.reminderTime.size() != 5 || !is_time(event.reminderTime) || event.reminderTime[2] != ':' || event.reminderTime > event.startTime)
        {
            cout << "Please enter a valid time" << endl;
            cout << "Enter the event reminder time (HH:MM) : ";
            cin >> event.reminderTime;
        }

        do
        {
            cout << "Enter the importance rate for this event. (1 : 10) : ";
            cin >> event.importanceRate;
        } while (event.importanceRate > 10 || event.importanceRate < 0);
        freq[event.importanceRate]++;

        for (it = events.begin(); it != events.end(); it++)
        {
            if (events.size() == 0)
            {
                events.insert(event);
                Storing(event);
            }
            else
            {
                if (it->startDate == event.startDate)
                {
                    if (it->endDate >= event.endDate)
                    {
                        if (event.startTime < it->startTime && event.endTime > it->startTime)
                        {
                            available = false;
                        }
                        else if (event.startTime<it->endTime && event.endTime>it->endTime)
                        {
                            available = false;
                        }
                        else if (event.startTime >= it->startTime && event.endTime <= it->endTime)
                        {
                            available = false;
                        }
                        else if (event.startTime > it->startTime && event.startTime < it->endTime)
                        {
                            available = false;
                        }
                        else if (it->startDate == event.startDate)
                        {
                            if (it->endDate == event.endDate)
                            {
                                if (it->startTime == event.startTime)
                                {

                                    if (it->endTime == event.endTime)
                                    {
                                        if (it->reminderTime == event.reminderTime)
                                        {
                                            available = false;
                                        }

                                    }

                                }
                                else if (it->reminderTime == event.reminderTime)
                                {
                                    available = false;
                                    redundant = true;
                                }
                            }
                        }

                    }
                }
                else
                {
                    if (event.startDate > it->startDate && event.startDate < it->endDate)
                    {
                        if (event.startTime > it->startTime || event.endTime < it->endTime)
                        {
                            available = false;
                        }
                    }
                    else if (event.startDate<it->startDate && event.endDate>it->startDate)
                    {
                        if (event.startTime > it->startTime || event.endTime < it->endTime)
                        {
                            available = false;
                        }
                    }
                }
            }
        }

        if (available)
        {
            events.insert(event);
            Storing(event);
        }
        else if (!available && !redundant)
        {
            cout << "You already have an event in that time." << endl;
        }
        else if (redundant)
        {
            cout << "You can't have 2 events with the same reminder time in the same day." << endl;
        }

        while (true)
        {
            cout << "Do you want to add another event?(y/n) : ";
            cin >> continuee;
            cout << "\n\n";
            continuee = toupper(continuee);
            if (continuee == 'Y')
            {
                break;
            }
            else if (continuee == 'N')
            {
                break;
            }
            else
            {
                cout << "Please enter a valid choice." << endl;
            }
        }
    } while (continuee != 'N');
    cout << "\n\n\n\n\t\t\t\t\tThe Event(s) were added successfully. :)" << endl;
}

void Event::Storing(EventInfo event)
{
    ReadDataFile.open("dataFile.txt", ios::in);
    WriteDataFile.open("dataFile.txt", ios::out | ios::app);

    WriteDataFile << event.name << "$" << event.place << "$" << event.startDate << "$" << event.endDate
        << "$" << event.startTime << "$" << event.endTime << "$" << event.reminderTime << "$" << event.importanceRate << "$";
    WriteDataFile << endl;

    WriteDataFile.close();
    ReadDataFile.close();
}

void Event::Display()
{
    eventNumber = 1;
    for (it = events.begin(); it != events.end(); it++, eventNumber++)
    {
        cout << "Event number : " << eventNumber << endl;
        DisplayEvent();
    }
}

void Event::DisplayEvent()
{
    cout << "Event's name is : " << it->name << endl;
    cout << "Event's place is : " << it->place << endl;
    cout << "Event's start date is : " << it->startDate << endl;
    cout << "Event's end date is : " << it->endDate << endl;
    cout << "Event's start time is : " << it->startTime << endl;
    cout << "Event's end time is : " << it->endTime << endl;
    cout << "Event's reminder time is : " << it->reminderTime << endl;
    cout << "Event's importance rate is : " << it->importanceRate << endl;
    if (event.isDone)
        cout << "This event is done." << endl;
    else
        cout << "This event is not done keep an eye on the reminder time." << endl;
    cout << "\n\n";
}

void Event::DisplayByImportanceRate()
{
    counter = 10;
    while (counter > 0)
    {
        if (freq[counter] > 0)
        {
            cout << "The events with " << counter << " as their importance rate.\n";
            for (it = events.begin(); it != events.end(); it++)
            {
                if (it->importanceRate == counter)
                {
                    DisplayEvent();
                }
            }
        }
        counter--;
    }
}

void Event::DisplayDeletedEvents()
{
    eventNumber = 1;
    for (itt = deletedEventList.begin(); itt != deletedEventList.end(); itt++, eventNumber++)
    {
        cout << "Event number " << eventNumber << endl;
        cout << "Event's name is : " << itt->name << endl;
        cout << "Event's place is : " << itt->place << endl;
        cout << "Event's start date is : " << itt->startDate << endl;
        cout << "Event's end date is : " << itt->endDate << endl;
        cout << "Event's start time is : " << itt->startTime << endl;
        cout << "Event's end time is : " << itt->endTime << endl;
        cout << "Event's reminder time is : " << itt->reminderTime << endl;
        cout << "Event's importance rate is : " << itt->importanceRate << endl;
        cout << "This event is Done.";
        cout << "\n\n";
    }
}

void Event::Update()
{
    if (!events.size())
    {
        cout << "You have to add at least one event first to update it.";
        return;
    }

    Display();

    while (true)
    {
        cout << "Enter the number of event you want to update :\t";
        cin >> eventNumber;

        if (eventNumber > events.size())
        {
            cout << "Enter a valid event number.\nIf you want to continue press y, exit press n :\t";
            cin >> continuee;
            if (continuee == 'n')
                return;
        }
        else
        {
            break;
        }
    }

    int i = 1;
    for (it = events.begin(); i < eventNumber; it++, i++);

    event.name = it->name;
    event.place = it->place;
    event.endDate = it->endDate;
    event.startDate = it->startDate;
    event.startTime = it->startTime;
    event.endTime = it->endTime;
    event.reminderTime = it->reminderTime;
    event.importanceRate = it->importanceRate;

    DeleteData(event);
    freq[event.importanceRate]--;

    while (true)
    {
        cout << "Enter the number of the attribute that you want to change.\n";
        cout << "(1) Name. \t\t(2) Place. \t\t(3) Start Date. \n"
            "(4) End Date. \t\t(5) Start Time. \t(6) End Time.\n"
            "(7) Reminder Time. \t(8) If the event is done. \t(9) Importance rate.\n";
        cin >> choice;
        switch (choice)
        {
        case '1':
            cout << "Enter new event name : ";
            cin >> event.name;
            break;
        case '2':
            cout << "Enter new event place : ";
            cin >> event.place;
            break;
        case '3':
            cout << "Enter the event start date (DD/MM/YYYY) : ";
            cin >> event.startDate;
            while (event.startDate.size() != 10 || !is_number(event.startDate) || !is_date(event.startDate) || event.startDate[2] != '/' || event.startDate[5] != '/')
            {
                cout << "Please enter a valid Date" << endl;
                cout << "Enter the event start date (DD/MM/YYYY) : ";
                cin >> event.startDate;
            }
            break;
        case '4':
            cout << "Enter the event end date (DD/MM/YYYY) : ";
            cin >> event.endDate;
            while (event.endDate.size() != 10 || !is_number(event.endDate) || !is_date(event.endDate) || event.endDate[2] != '/' || event.endDate[5] != '/' || !is_endDate(event.endDate))
            {
                cout << "Please enter a valid Date" << endl;
                cout << "Enter the event end date (DD/MM/YYYY) : ";
                cin >> event.endDate;
            }
            break;
        case '5':
            cout << "Enter the event start time (HH:MM) : ";
            cin >> event.startTime;
            while (event.startTime.size() != 5 || !is_time(event.startTime) || event.startTime[2] != ':')
            {
                cout << "Please enter a valid time" << endl;
                cout << "Enter the event start time (HH:MM) : ";
                cin >> event.startTime;
            }
            break;
        case '6':
            cout << "Enter the event end time (HH:MM) : ";
            cin >> event.endTime;
            while (event.endTime.size() != 5 || !is_time(event.endTime) || event.endTime[2] != ':' || event.endTime <= event.startTime)
            {
                cout << "Please enter a valid time" << endl;
                cout << "Enter the event end time (HH:MM) : ";
                cin >> event.endTime;
            }
        case '7':
            cout << "Enter the event reminder time (HH:MM) : ";
            cin >> event.reminderTime;
            while (event.reminderTime.size() != 5 || !is_time(event.reminderTime) || event.reminderTime[2] != ':' || event.reminderTime > event.startTime)
            {
                cout << "Please enter a valid time" << endl;
                cout << "Enter the event reminder time (HH:MM) : ";
                cin >> event.reminderTime;
            }
            break;
        case '8':
            cout << "Enter y if the event is done :\t";
            cin >> continuee;
            if (continuee == 'y')
            {
                MoveTo();
                return;
            }
            else
            {
                cout << "Invalid entry.\n";
            }
            break;
        case '9':
            do
            {
                cout << "Enter the importance rate for this event. (1 : 10) : ";
                cin >> event.importanceRate;
            } while (event.importanceRate > 10 || event.importanceRate < 0);
            freq[event.importanceRate]++;
            break;
        default:
            cout << "Enter a valid number from 1 to 9.\n";
            break;
        }

        cout << "Do you want to update another attribute? (y/n)\t";
        cin >> continuee;
        if (continuee == 'n')
        {
            break;
        }
    }

    events.erase(it);
    events.insert(event);
    freq[event.importanceRate]++;
    Storing(event);

    cout << "Do you want to change another event? (y/n)  ";
    cin >> continuee;
    if (continuee == 'n')
    {
        return;
    }
    else
    {
        Update();
    }
}

void Event::MoveTo()
{ 
    DoneData(event);
    deletedEventList.push_back(event);
    events.erase(it);
}

void Event::Delete()
{
    while (true)
    {
        Display();

        cout << "Enter the number of event you want to delete :\t";
        cin >> eventNumber;

        if (eventNumber > events.size())
        {
            cout << "This event does not exist, enter a valid event number." << endl;
            continue;
        }

        int i = 1;
        for (it = events.begin(); i < eventNumber; it++, i++);

        event.name = it->name;
        event.place = it->place;
        event.startDate = it->startDate;
        event.endDate = it->endDate;
        event.startTime = it->startTime;
        event.endTime = it->endTime;
        event.reminderTime = it->reminderTime;
        event.isDone = it->isDone;
        event.importanceRate = it->importanceRate;

        DeleteData(event);
        events.erase(it);

        cout << "Do you want to delete another event? (y/n)\t";
        cin >> continuee;
        if (continuee == 'n')
        {
            break;
        }
    }
}

void Event::DeleteData(EventInfo event)
{
    ReadDataFile.open("dataFile.txt", ios::in);
    WriteDataFile.open("dataFile.txt", ios::out | ios::app);
    deletedFile.open("deletedData.txt", ios::out);

    deleteLine = event.name + "$" + event.place + "$" + event.startDate + "$" +
        event.endDate + "$" + event.startTime + "$" + event.endTime + "$" +
        event.reminderTime + "$" + to_string(event.importanceRate) + "$";

    while (getline(ReadDataFile, x))
    {
        if (x != deleteLine)
        {
            deletedFile << x << endl;
        }
    }

    WriteDataFile.close();
    ReadDataFile.close();
    deletedFile.close();
    remove("dataFile.txt");
    rename("deletedData.txt", "dataFile.txt");
}

void Event::DoneData(EventInfo event)
{
    WriteDoneFile.open("doneData.txt",ios::out | ios::app);

    WriteDoneFile << event.name << "$" << event.place << "$" << event.startDate << "$" 
        << event.endDate << "$" << event.startTime << "$" << event.endTime << "$" 
        << event.reminderTime << "$" << event.importanceRate << "$";
    WriteDoneFile << endl;
  
    WriteDoneFile.close();
}

void Event::Time()
{
    _time32(&aclock);
    _localtime32_s(&newtime, &aclock);
    asctime_s(buffer, 32, &newtime);

    for (int i = 11; i < 16; i++)
    {
        time += buffer[i];
    }

    for (int i = 8; i < 10; i++)
    {
        date += buffer[i];
    }
    date += '/';
    
    for (int i = 4; i < 7; i++)
    {
        temp += buffer[i];
    }

    if (temp == "Jan")
    {
        date += "01";
    }
    else if (temp == "Feb")
    {
        date += "02";
    }
    else if (temp == "Mar")
    {
        date += "03";
    }
    else if (temp == "Apr")
    {
        date += "04";
    }
    else if (temp == "May")
    {
        date += "05";
    }
    else if (temp == "Jun")
    {
        date += "06";
    }
    else if (temp == "Jul")
    {
        date += "07";
    }
    else if (temp == "Aug")
    {
        date += "08";
    }
    else if (temp == "Sep")
    {
        date += "09";
    }
    else if (temp == "Oct")
    {
        date += "10";
    }
    else if (temp == "Nov")
    {
        date += "11";
    }
    else if (temp == "Dec")
    {
        date += "12";
    }

    date += '/';

    for (int i = 20; i < 24; i++)
    {
        date += buffer[i];
    }
}

void Event::TimeUp()
{
    Time();

    cout << date << "\n\n";

    while (true)
    {
        //0123456789
        //01/02/2002
        counter = 0;
        for (it = events.begin(); it != events.end(); it++, counter++)
        {
            string m = it->endDate;
            bool done = false;
            cout << m[0] << m[1] << m[3] << m[4] << m[6] << m[7] << m[8] << m[9]  << endl;
            if (m[6] + m[7] + m[8] + m[9] < date[6] + date[7] + date[8] + date[9])
            {
                cout << "Year < now" << endl;
                done = true;
            }
            else if (m[6] + m[7] + m[8] + m[9] == date[6] + date[7] + date[8] + date[9])
            {
                cout << "Years are equal" << endl;
                if (m[3] + m[4] < date[3] + date[4])
                {
                    cout << "Month < now" << endl;
                    //cout << m[3] + m[4] << " " << date[3] + date[4] << " ";
                    // cout << "End date" << it->endDate << endl;
                    done = true;
                }
                else if ((m[3] + m[4] == date[3] + date[4]))
                {
                    cout << "Months are equal" << endl;
                    if (m[0] + m[1] < date[0] + date[1])
                    {
                        cout << "Day < now" << endl;
                        done = true;
                    }
                    else if (m[0] + m[1] == date[0] + date[1])
                    {
                        cout << "Days are equal" << endl;
                        if (it->endTime <= time)
                        {
                            cout << "Now " << endl;
                            done = true;
                        }
                        else
                            done = false;

                    }
                    else
                    {
                        done = false;

                    }
                }
                else
                {
                    cout << "l.shahr l.gayyyy" << endl;
                    done = false;
                    cout << "shahr kbeeerrrrr" << endl << " ";
                   // cout << m[3] + m[4] << " " << date[3] + date[4] << " ";

                }

            }
            else
            {
                cout << "Law lessa henna :)" << endl;
                done = false;
            }
            
            //if (!done)
            //{
            //    cout << "NOT DONE";
            //    break;
            //}

            if (done)
            {
                event.name = it->name;
                event.place = it->place;
                event.endDate = it->endDate;
                event.startDate = it->startDate;
                event.startTime = it->startTime;
                event.endTime = it->endTime;
                event.reminderTime = it->reminderTime;
                cout << event.name << endl;
                MoveTo();

                break;
            }
            
           /* else
            {
                 cout << "M3mltsh 7aga";
                break;
            }*/
        }
        if(counter == events.size())
        break;
    }
}

void Event::ReadingData()
{
    ReadDataFile.open("dataFile.txt", ios::in);
    WriteDataFile.open("dataFile.txt", ios::out | ios::app);

    while (getline(ReadDataFile,x))
    {
        i = 0;
 
        event.name = event.place = event.startDate = 
            event.endDate = event.startTime = event.endTime =  
            event.reminderTime = importance = "";
        
        for (; x[i] != '$'; i++)
        {
            event.name += x[i];
        }
        i++;
        for (; x[i] != '$'; i++)
        {
            event.place += x[i];
        }
        i++;
        for (; x[i] != '$'; i++)
        {
            event.startDate += x[i];
        }
        i++;
        for (; x[i] != '$'; i++)
        {
            event.endDate += x[i];
        }
        i++;
        for (; x[i] != '$'; i++)
        {
            event.startTime += x[i];
        }
        i++;
        for (; x[i] != '$'; i++)
        {
            event.endTime += x[i];
        }
        i++;
        for (; x[i] != '$'; i++)
        {
            event.reminderTime += x[i];
        }
        i++;
        for (; x[i] != '$'; i++)
        {
            importance += x[i];
        }
        event.importanceRate = stoi(importance);
        freq[event.importanceRate]++;

        event.isDone = false;
        events.insert(event);
    }

    WriteDataFile.close();
    ReadDataFile.close();
}

void Event::ReadingDoneData()
{
    ReadDoneFile.open("doneData.txt", ios::in);
    WriteDoneFile.open("doneData.txt", ios::out | ios::app);

    while (getline(ReadDoneFile,x))
    {
        i = 0;
        event.name = event.place = event.startDate =
            event.endDate = event.startTime = event.endTime =
            event.reminderTime = importance = "";

        for (; x[i] != '$'; i++)
        {
            event.name += x[i];
        }
        i++;
        for (; x[i] != '$'; i++)
        {
            event.place += x[i];
        }
        i++;
        for (; x[i] != '$'; i++)
        {
            event.startDate += x[i];
        }
        i++;
        for (; x[i] != '$'; i++)
        {
            event.endDate += x[i];
        }
        i++;
        for (; x[i] != '$'; i++)
        {
            event.startTime += x[i];
        }
        i++;
        for (; x[i] != '$'; i++)
        {
            event.endTime += x[i];
        }
        i++;
        for (; x[i] != '$'; i++)
        {
            event.reminderTime += x[i];
        }
        i++;
        for (; x[i] != '$'; i++)
        {
            importance += x[i];
        }
        event.importanceRate = stoi(importance);

        deletedEventList.push_back(event);
    }
    WriteDoneFile.close();
    ReadDoneFile.close();
}

int Event::getSize()
{
    return events.size();
}

void Event::Search()
{
    while (true)
    {
        available = false;

        cout << "Enter the number of the attribute that you want to know to about.\n";
        cout << "(1) Name. \t\t(2) Place. \t\t(3) Start Date. \n"
            "(4) End Date. \t\t(5) Start Time. \t\t(6) End Time. \t\t\n"
            "(7) Reminder Time. \t\t(8) Importance rate.\n";

        cin >> choice;
        switch (choice)
        {
        case '1':
            cout << "Enter event name : ";
            cin >> event.name;
            SearchByName(event.name);
            break;
        case '2':
            cout << "Enter event place : ";
            cin >> event.place;
            SearchByPlace(event.place);
            break;
        case '3':
            cout << "Enter the event start date (DD/MM/YYYY) : ";
            cin >> event.startDate;
            while (!is_number(event.startDate) || event.startDate.size() != 10 || event.startDate[2] != '/' || event.startDate[5] != '/')
            {
                cout << "Please enter a valid Date." << endl;
                cout << "Enter the event start date (DD/MM/YYYY) : ";
                cin >> event.startDate;
            }
            SearchByStartDate(event.startDate);
            break;
        case '4':
            cout << "Enter the event end date (DD/MM/YYYY) : ";
            cin >> event.endDate;
            while (!is_number(event.endDate) || event.endDate.size() != 10 || event.endDate[2] != '/' || event.endDate[5] != '/')
            {
                cout << "Please enter a valid Date." << endl;
                cout << "Enter the event end date (DD/MM/YYYY) : ";
                cin >> event.endDate;
            }
            SearchByEndDate(event.endDate);
            break;
        case '5':
            cout << "Enter the event start time (HH:MM) : ";
            cin >> event.startTime;
            while (!is_time(event.startTime) || event.startTime.size() != 5 || event.startTime[2] != ':')
            {
                cout << "Please enter a valid time." << endl;
                cout << "Enter the event start time (HH:MM) : ";
                cin >> event.startTime;
            }
            SearchByStartTime(event.startTime);
            break;
        case '6':
            cout << "Enter the event end time (HH:MM) : ";
            cin >> event.endTime;
            while (!is_time(event.endTime) || event.endTime.size() != 5 || event.endTime[2] != ':')
            {
                cout << "Please enter a valid time." << endl;
                cout << "Enter the event end time (HH:MM) : ";
                cin >> event.endTime;
            }
            SearchByEndTime(event.endTime);
            break;
        case '7':
            cout << "Enter the event reminder time (HH:MM) : ";
            cin >> event.reminderTime;
            while (!is_time(event.reminderTime) || event.reminderTime.size() != 5 || event.reminderTime[2] != ':')
            {
                cout << "Please enter a valid time." << endl;
                cout << "Enter the event reminder time (HH:MM) : ";
                cin >> event.reminderTime;
            }
            SearchByReminderTime(event.reminderTime);
            break;
        case '8':
            do
            {
                cout << "Enter the importance rate for this event. (1 : 10) : ";
                cin >> event.importanceRate;
            } while (event.importanceRate > 10 || event.importanceRate < 0);
            SearchByImportanceRate(event.importanceRate);
            break;
        default:
            cout << "Enter a valid number from 1 to 8.\n";
            break;
        }


        cout << "Do you want to know about another event ? (y/n)\t";
        cin >> continuee;
        if (continuee != 'y')
        {
            break;
        }
    }
}

void Event::SearchByName(string name)
{
    available = false;

    for (it = events.begin(); it != events.end(); it++)
    {
        if (name == it->name)
        {
            available = true;
            DisplayEvent();
        }
    }

    if (!available)
    {
        cout << "This event is not found, try again." << endl;
    }
}

void Event::SearchByPlace(string place)
{
    available = false;

    for (it = events.begin(); it != events.end(); it++)
    {
        if (place == it->place)
        {
            available = true;
            DisplayEvent();
        }
    }

    if (!available)
    {
        cout << "This event is not found, try again." << endl;
    }
}

void Event::SearchByStartDate(string startDate)
{
    available = false;

    for (it = events.begin(); it != events.end(); it++)
    {
        if (startDate == it->startDate)
        {
            available = true;
            DisplayEvent();
        }
    }

    if (!available)
    {
        cout << "This event is not found, try again." << endl;
    }
}

void Event::SearchByEndDate(string endDate)
{
    available = false;

    for (it = events.begin(); it != events.end(); it++)
    {
        if (endDate == it->endDate)
        {
            available = true;
            DisplayEvent();
        }
    }

    if (!available)
    {
        cout << "This event is not found, try again." << endl;
    }
}

void Event::SearchByStartTime(string startTime)
{
    available = false;

    for (it = events.begin(); it != events.end(); it++)
    {
        if (startTime == it->startTime)
        {
            available = true;
            DisplayEvent();
        }
    }

    if (!available)
    {
        cout << "This event is not found, try again." << endl;
    }
}

void Event::SearchByEndTime(string endTime)
{
    available = false;

    for (it = events.begin(); it != events.end(); it++)
    {
        if (endTime == it->endTime)
        {
            available = true;
            DisplayEvent();
        }
    }

    if (!available)
    {
        cout << "This event is not found, try again." << endl;
    }
}

void Event::SearchByReminderTime(string reminderTime)
{
    available = false;

    for (it = events.begin(); it != events.end(); it++)
    {
        if (reminderTime == it->reminderTime)
        {
            available = true;
            DisplayEvent();
        }
    }

    if (!available)
    {
        cout << "This event is not found, try again." << endl;
    }
}

void Event::SearchByImportanceRate(int importance)
{
    available = false;

    for (it = events.begin(); it != events.end(); it++)
    {
        if (importance == it->importanceRate)
        {
            available = true;
            DisplayEvent();
        }
    }

    if (!available)
    {
        cout << "This event is not found, try again." << endl;
    }
}
