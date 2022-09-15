#include <QApplication>
#include "RepoPosts.h"
#include "RepoTopics.h"
#include "RepoUsers.h"
#include "userwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    RepoUsers uRepo;
    RepoTopics tRepo;
    RepoPosts pRepo;
    for(auto user : uRepo.getAll()){
        auto* newW = new UserWindow(user, tRepo, pRepo);
        newW->show();
    }
    return QApplication::exec();
}
