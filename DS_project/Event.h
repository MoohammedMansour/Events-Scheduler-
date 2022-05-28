#pragma once

#include <list>
#include <string>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <set>
#include <fstream>
#include <time.h>
#include <stdio.h>

using namespace std;

struct EventInfo
{
    string name,
        place,
        startDate,
        endDate,
        startTime,
        reminderTime,
        endTime;

    int importanceRate = 0;
    bool isDone = false;
};

class Event
{
public:
    int getSize();
    void Add();
	void Display();
    void DisplayEvent();
    void DisplayDeletedEvents();
    void Update();
    void Delete();
    void MoveTo();
    void Search();
    void Time();
    void TimeUp();
    bool is_number(const string& s);
    bool is_time(const string& s);
    bool is_date(string s);
    bool is_endDate(string s);
    void ReadingData();
    void ReadingDoneData();
    void DeleteData(EventInfo event);
    void Storing(EventInfo event);
    void DoneData(EventInfo event);
    void DisplayByImportanceRate();
    void SearchByName(string name);
    void SearchByPlace(string place);
    void SearchByStartDate(string startDate);
    void SearchByEndDate(string endDate);
    void SearchByStartTime(string startTime);
    void SearchByEndTime(string endTime);
    void SearchByReminderTime(string reminderTime);
    void SearchByImportanceRate(int importance);
    ofstream deletedFile;
    ofstream WriteDoneFile;
    ifstream ReadDoneFile;
    ofstream WriteDataFile;
    ifstream ReadDataFile;

private:
    set<EventInfo> events;
    set<EventInfo>::iterator it;
    list<EventInfo> deletedEventList;
    list<EventInfo>::iterator itt;
    EventInfo event;
    char continuee, 
        choice, 
        buffer[32];
    bool available;
    int eventNumber = 1, 
        atributeNumber = 1,
        counter = 0, 
        i = 0,
        freq[11];
    struct tm newtime;
    __time32_t aclock;
    string time,
        date,
        temp,
        x,
        deleteLine = "", 
        importance;
};
