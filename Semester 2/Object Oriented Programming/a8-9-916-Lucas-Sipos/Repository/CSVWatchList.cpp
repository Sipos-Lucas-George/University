#include "CSVWatchList.h"

CSVWatchList::CSVWatchList() = default;


CSVWatchList::~CSVWatchList() = default;

void CSVWatchList::saveToFile()
{
    std::ofstream f("watchlist.csv");
    for (const auto& movie : this->movies)
        f << movie << "\n";
    f.close();
}

void CSVWatchList::openInApp()
{
    system("notepad.exe watchlist.csv");
}
