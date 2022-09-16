#include <QtWidgets/QApplication>
#include "Repository/CSVWatchList.h"
#include "Repository/HTMLWatchList.h"
#include "GUI/gui.h"
#include "GUI/startgui.h"

int main(int argc, char* argv[]) {
    QApplication a{ argc, argv };
    Repository repository{ "Movies.txt" };
    startGUI startGui;
    startGui.show();
    QApplication::exec();
    WatchList* watchList;
    if (startGui.csvOrHtml())
        watchList = new CSVWatchList();
    else
        watchList = new HTMLWatchList();
    Service service(repository, watchList);
    GUI gui{service};
    gui.show();
    return QApplication::exec();
}
