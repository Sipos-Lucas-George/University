#include "HTMLWatchList.h"
#include <Windows.h>
#include <shellapi.h>

HTMLWatchList::HTMLWatchList() = default;


HTMLWatchList::~HTMLWatchList() = default;

void HTMLWatchList::saveToFile()
{
    std::ofstream f("watchlist.html");

    f << "<!DOCTYPE html>" << "\n";
    f << "<html>" << "\n";

    f << "<head>" << "\n";
    f << "<title>Movie Playlist</title>" << "\n";
    f << "</head>" << "\n";

    f << "<body>" << "\n";

    f << "<table border=\"1\">" << "\n";

    f << "<tr>" << "\n";
    f << "<td>Title</td>" << "\n";
    f << "<td>Genre</td>" << "\n";
    f << "<td>Year</td>" << "\n";
    f << "<td>Likes</td>" << "\n";
    f << "<td>Trailer</td>" << "\n";
    f << "</tr>" << "\n";

    for (const auto& movie : this->movies)
    {
        f << "<tr>" << "\n";

        f << "<td>" << movie.getTitle() << "</td>" << "\n";
        f << "<td>" << movie.getGenre() << "</td>" << "\n";
        f << "<td>" << movie.getYear() << "</td>" << "\n";
        f << "<td>" << movie.getLikes() << "</td>" << "\n";
        f << "<td><a href =" << movie.getTrailer() << ">Link</a></td>";

        f << "</tr>" << "\n";
    }

    f << "</table>" << "\n";

    f << "</body>" << "\n";

    f << "</html>" << "\n";
    f.close();

}

void HTMLWatchList::openInApp()
{
    ShellExecuteA(nullptr, nullptr, "chrome.exe", "file:///D:/CLion/a8-9-916-Lucas-Sipos/cmake-build-debug-coverage/watchlist.html", nullptr, SW_SHOWMAXIMIZED);
    system("PAUSE");
}