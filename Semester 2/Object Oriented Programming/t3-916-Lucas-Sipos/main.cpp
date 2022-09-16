#include <QtWidgets/QApplication>
#include "Repository.h"
#include "gui.h"

int main(int argc, char* argv[]) {
    QApplication a{ argc, argv };
    Repository repo;
    GUI gui {repo};
    gui.show();
    return QApplication::exec();
}
