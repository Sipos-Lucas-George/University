#pragma once
#include "WatchList.h"
class CSVWatchList : public WatchList
{
public:
    CSVWatchList();
    ~CSVWatchList();

    void saveToFile() override;
    void openInApp() override;
};
