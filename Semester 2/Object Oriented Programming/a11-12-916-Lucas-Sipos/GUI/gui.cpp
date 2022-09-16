#include <QMessageBox>
#include "gui.h"
#include "ui_GUI.h"


GUI::GUI(Service& service, QWidget *parent) :
        QWidget(parent), ui(new Ui::GUI), service(service) {
    ui->setupUi(this);
    this->populateList();
    this->connectSignals();
}

GUI::~GUI() {
    delete ui;
}

void GUI::populateList() {
    this->ui->movieListWidget->clear();

    std::vector<Movie> movies = this->service.getAllRepository();
    for (const auto &movie: movies)
        this->ui->movieListWidget->addItem(QString::fromStdString(
                movie.getTitle() + ", " + movie.getGenre() + ", " + std::to_string(movie.getYear()) + ", " +
                std::to_string(movie.getLikes()) + ", " + movie.getTrailer()));
}

void GUI::populateWatchList() {
    this->ui->watchListWidget->clear();

    std::vector<Movie> movies = this->service.getAllWatchList();
    for (const auto& movie : movies)
        this->ui->watchListWidget->addItem(QString::fromStdString(movie.getTitle() + ", " + movie.getGenre() + ", " + std::to_string(movie.getYear()) + ", " +
                                                                  std::to_string(movie.getLikes()) + ", " + movie.getTrailer()));

}

void GUI::connectSignals() {
    QObject::connect(this->ui->movieListWidget, &QListWidget::itemSelectionChanged, this, &GUI::listItemChange);
    QObject::connect(this->ui->searchLineEdit, &QLineEdit::textChanged, this, &GUI::searchMoviesGUI);
    QObject::connect(this->ui->addButton, &QPushButton::clicked, this, &GUI::addMovieGUI);
    QObject::connect(this->ui->deleteButton, &QPushButton::clicked, this, &GUI::deleteMovieGUI);
    QObject::connect(this->ui->updateButton, &QPushButton::clicked, this, &GUI::updateMovieGUI);
    QObject::connect(this->ui->transferButton, &QPushButton::clicked, this, &GUI::transferMovieGUI);
    QObject::connect(this->ui->openButton, &QPushButton::clicked, this, &GUI::openMovieGUI);
    QObject::connect(this->ui->playButton, &QPushButton::clicked, this, &GUI::playMovieGUI);
    QObject::connect(this->ui->deleteWatchedButton, &QPushButton::clicked, this, &GUI::deleteWatchGUI);
    QObject::connect(this->ui->likeButton, &QPushButton::clicked, this, &GUI::likeMovieGUI);
}

int GUI::getSelectedIndex() const {
    QModelIndexList selectedIndexes = this->ui->movieListWidget->selectionModel()->selectedIndexes();
    if (selectedIndexes.empty()){
        this->ui->titleLineEdit->clear();
        this->ui->genreLineEdit->clear();
        this->ui->yearLineEdit->clear();
        this->ui->likesLineEdit->clear();
        this->ui->trailerLineEdit->clear();
        return -1;
    }
//    return (int) *select =* selectedIndexes.at(0).row();
    std::string string = this->ui->movieListWidget->currentItem()->text().toStdString();
    std::vector<std::string> out;
    unsigned long long n = string.size();
    char stringToChar[n + 1];
    strcpy(stringToChar, string.c_str());
    char* token = std::strtok(stringToChar, ",");
    out.push_back((std::string)(token));
    token = strtok(nullptr, ",");
    while (token){
        out.push_back((std::string)(token + 1));
        token = strtok(nullptr, ",");
    }
    int selectedIndex = this->service.getIndexOfMovie(Movie(out[0], out[1], stoi(out[2]), stoi(out[3]), out[4]));
    return selectedIndex;
}

int GUI::getWatchListSelectedIndex() const {
    QModelIndexList selectedIndexes = this->ui->watchListWidget->selectionModel()->selectedIndexes();
    if (selectedIndexes.empty()){
        this->ui->titleLineEdit->clear();
        this->ui->genreLineEdit->clear();
        this->ui->yearLineEdit->clear();
        this->ui->likesLineEdit->clear();
        this->ui->trailerLineEdit->clear();
        return -1;
    }
    int selectedIndex = selectedIndexes.at(0).row();
    return selectedIndex;
}

void GUI::listItemChange() {
    int selectedIndex = this->getSelectedIndex();
    if (selectedIndex < 0 || selectedIndex >= this->service.getAllRepository().size()){
        this->ui->titleLineEdit->setText("");
        this->ui->genreLineEdit->setText("");
        this->ui->yearLineEdit->setText("");
        this->ui->likesLineEdit->setText("");
        this->ui->trailerLineEdit->setText("");
        return;
    }
    Movie movie = this->service.getAllRepository()[selectedIndex];
    this->ui->titleLineEdit->setText(QString::fromStdString(movie.getTitle()));
    this->ui->genreLineEdit->setText(QString::fromStdString(movie.getGenre()));
    this->ui->yearLineEdit->setText(QString::fromStdString(std::to_string(movie.getYear())));
    this->ui->likesLineEdit->setText(QString::fromStdString(std::to_string(movie.getLikes())));
    this->ui->trailerLineEdit->setText(QString::fromStdString(movie.getTrailer()));
}

void GUI::searchMoviesGUI() {
    std::string wordToSearch = this->ui->searchLineEdit->text().toStdString();
    if (wordToSearch.empty()){
        this->populateList();
        return;
    }
    this->ui->movieListWidget->clear();
    std::vector<Movie> movies = this->service.getAllRepository();
    for (const auto& movie : movies){
        std::string string = movie.getTitle() + ", " + movie.getGenre() + ", " + std::to_string(movie.getYear()) + ", " + std::to_string(movie.getLikes()) + ", " + movie.getTrailer();
        if (string.find(wordToSearch) != std::string::npos)
            this->ui->movieListWidget->addItem(QString::fromStdString(string));
    }
}

void GUI::addMovieGUI() {
    std::string title = this->ui->titleLineEdit->text().toStdString();
    std::string genre = this->ui->genreLineEdit->text().toStdString();
    std::string year = this->ui->yearLineEdit->text().toStdString();
    std::string likes = this->ui->likesLineEdit->text().toStdString();
    std::string trailer = this->ui->trailerLineEdit->text().toStdString();

    try {
        this->service.addRepository(Movie(title, genre, stoi(year), stoi(likes), trailer));
        this->searchMoviesGUI();
    }
    catch (MovieException& e) {
        std::string errors;
        for (const auto& string : e.getErrors())
             errors += string;
        QMessageBox::critical(this, "ERROR!!!", QString::fromStdString(errors));
    }
    catch (RepositoryException& e) {
        QMessageBox::critical(this, "ERROR!!!", QString::fromStdString(e.what()));
    }
    catch (FileException& e) {
        QMessageBox::critical(this, "ERROR!!!", QString::fromStdString(e.what()));
    }
    catch (std::invalid_argument& e) {
        QMessageBox::critical(this, "ERROR!!!", "Insert numbers!");
    }
}

void GUI::deleteMovieGUI() {
    int selectedIndex = this->getSelectedIndex();
    if (selectedIndex < 0){
        QMessageBox::critical(this, "ERROR!!!", "No movie selected!");
        return;
    }
    this->service.deleteRepository(selectedIndex);
    this->searchMoviesGUI();
}

void GUI::updateMovieGUI() {
    int selectedIndex = this->getSelectedIndex();
    if (selectedIndex < 0){
        QMessageBox::critical(this, "ERROR!!!", "No movie selected!");
        return;
    }
    std::string title = this->ui->titleLineEdit->text().toStdString();
    std::string genre = this->ui->genreLineEdit->text().toStdString();
    std::string year = this->ui->yearLineEdit->text().toStdString();
    std::string likes = this->ui->likesLineEdit->text().toStdString();
    std::string trailer = this->ui->trailerLineEdit->text().toStdString();

    try {
        this->service.updateRepository(selectedIndex, Movie(title, genre, stoi(year), stoi(likes), trailer));
        this->searchMoviesGUI();
    }
    catch (MovieException& e) {
        std::string errors;
        for (const auto& string : e.getErrors())
            errors += string;
        QMessageBox::critical(this, "ERROR!!!", QString::fromStdString(errors));
    }
    catch (RepositoryException& e) {
        QMessageBox::critical(this, "ERROR!!!", QString::fromStdString(e.what()));
    }
    catch (FileException& e) {
        QMessageBox::critical(this, "ERROR!!!", QString::fromStdString(e.what()));
    }
    catch (std::invalid_argument& e) {
        QMessageBox::critical(this, "ERROR!!!", "Insert numbers!");
    }
}

void GUI::transferMovieGUI() {
    int selectedIndex = this->getSelectedIndex();
    if (selectedIndex < 0){
        QMessageBox::critical(this, "ERROR!!!", "No movie selected!");
        return;
    }
    this->service.addWatchList(this->service.getAllRepository()[selectedIndex]);
    this->populateWatchList();
}

void GUI::openMovieGUI() {
    this->service.watchListSave();
    this->service.watchListOpen();
}

void GUI::playMovieGUI() {
    int selectedIndex = this->getWatchListSelectedIndex();
    if (selectedIndex < 0){
        QMessageBox::critical(this, "ERROR!!!", "No movie selected!");
        return;
    }
    this->service.play(selectedIndex);
}

void GUI::deleteWatchGUI() {
    int selectedIndex = this->getWatchListSelectedIndex();
    if (selectedIndex < 0){
        QMessageBox::critical(this, "ERROR!!!", "No movie selected!");
        return;
    }
    this->service.deleteWatchList(selectedIndex);
    this->populateWatchList();
}

void GUI::likeMovieGUI() {
    int selectedIndex = this->getWatchListSelectedIndex();
    if (selectedIndex < 0){
        QMessageBox::critical(this, "ERROR!!!", "No movie selected!");
        return;
    }
    this->service.incrementLikes(selectedIndex);
    this->populateWatchList();
    this->populateList();
}
