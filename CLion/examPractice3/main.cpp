#include <QApplication>
#include "ProgrammerRepo.h"
#include "TaskRepo.h"
#include "programmerwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    ProgrammerRepo pRepo;
    TaskRepo tRepo;
    for (auto p : pRepo.getAll()){
        auto* newW = new ProgrammerWindow(p, pRepo, tRepo);
        newW->show();
    }
    return QApplication::exec();
}
