#include "Event.h"

int main()
{
    Event events;
    char pick;
    events.ReadingData();
    events.ReadingDoneData();
    //events.TimeUp();

    cout << "\n\t\t\t\t\t|->) Welcome To Events' scheduler system (<-|\n\n\n";

    if (events.getSize() > 0)
    {
        cout << "You have these events.\n";
        events.Display();
    }

    while (true)
    {
        cout << "\n\n\nEnter number 1 to add a new event.\t\t\t Enter number 2 to update an existing event.\n"
            << "Enter number 3 to display the existing events.\t\t Enter number 4 to display the existing events ordered by their importance.\n"
            << "Enter number 5 to display the done events.\t\t Enter number 6 to delete an existing event. \n"
            << "Enter number 7 to search for an existing event.\t\t Enter number 8 to close the program.\n";

        cin >> pick;
        switch (pick)
        {
        case '1':
            events.Add();
            break;
        case '2':
            events.Update();
            break;
        case '3':
            events.Display();
            break;
        case '4':
            events.DisplayByImportanceRate();
            break;
        case '5':
            events.DisplayDeletedEvents();
            break;
        case '6':
            events.Delete();
            break;
        case '7':
            events.Search();
            break;
        case '8':
            return 0;
        default:
            cout << "Enter a valid number.";
            break;
        }
    }
}