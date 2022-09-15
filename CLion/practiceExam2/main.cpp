#include <QApplication>
#include "QuestionRepo.h"
#include "ParticipantRepo.h"
#include "presenter.h"
#include "user.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QuestionRepo q;
    ParticipantRepo p;
    Presenter prez(q);
    prez.show();
    for (auto part : p.getAll()){
        auto* pItem = new User(q, p, part);
        pItem->show();
    }
    return QApplication::exec();
}
