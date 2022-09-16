//
// Created by lukyl on 06/07/2022.
//

#ifndef MARTI_USERWINDOW_H
#define MARTI_USERWINDOW_H

#include <QWidget>
#include "RepoTopics.h"
#include "RepoPosts.h"
#include "User.h"

QT_BEGIN_NAMESPACE
namespace Ui { class UserWindow; }
QT_END_NAMESPACE

class UserWindow : public QWidget, public Observer{
Q_OBJECT

public:
    explicit UserWindow(User& user, RepoTopics& topics, RepoPosts& posts, QWidget *parent = nullptr);

    ~UserWindow() override;

private:
    Ui::UserWindow *ui;
    User& user;
    RepoTopics& topics;
    RepoPosts& posts;
    void populate();
    void connect();
    void update() override;
};


#endif //MARTI_USERWINDOW_H
