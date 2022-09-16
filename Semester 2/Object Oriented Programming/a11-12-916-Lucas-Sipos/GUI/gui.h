#pragma once
#include <QWidget>
#include "../Service/Service.h"


QT_BEGIN_NAMESPACE
namespace Ui { class GUI; }
QT_END_NAMESPACE

class GUI : public QWidget {
Q_OBJECT

public:
    explicit GUI(Service& service, QWidget *parent = nullptr);

    ~GUI() override;

private:
    Service& service;
    Ui::GUI *ui;

    void populateList();
    void populateWatchList();
    void connectSignals();
    [[nodiscard]] int getSelectedIndex() const;
    [[nodiscard]] int getWatchListSelectedIndex() const;
    void listItemChange();

    void searchMoviesGUI();
    void addMovieGUI();
    void deleteMovieGUI();
    void updateMovieGUI();
    void transferMovieGUI();
    void openMovieGUI();
    void playMovieGUI();
    void deleteWatchGUI();
    void likeMovieGUI();
};
