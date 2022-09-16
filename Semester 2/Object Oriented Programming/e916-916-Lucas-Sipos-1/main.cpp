#include <QApplication>
#include "UserRepo.h"
#include "QuestionRepo.h"
#include "AnswerRepo.h"
#include "userwindow.h"
#include "search.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    UserRepo uRepo;
    AnswerRepo aRepo;
    QuestionRepo qRepo(aRepo);
    for (auto user : uRepo.getAll()){
        auto* newW = new UserWindow(user, qRepo, aRepo);
        newW->show();
    }
    Search search(qRepo, aRepo);
    search.show();
    return QApplication::exec();
}
