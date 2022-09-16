#include "UI.h"
#include <iostream>
#include <string>

UI::UI(Service &service) : service(service){
    this->service = service;
}

UI::~UI() = default;

void UI::start() {
//    this->initialization();
    while (true) {
        printStartMenu();
        std::string command;
        std::getline(std::cin, command);
        if (command == "exit")
            break;
        if (command == "admin"){
            system("cls");
            std::cout << "Now you are in Admin mode\n";
            runAdminMode();
            std::cout << "You are no more in Admin mode!\n";
            Sleep(1000);
            system("cls");
        }
        else if (command == "user"){
            system("cls");
            std::cout << "Now you are in User mode\n";
            runUserMode();
            std::cout << "You are no more in User mode!\n";
            Sleep(1000);
            system("cls");
        }
        else
            std::cout << "Invalid command!\n";
    }
}

void UI::runAdminMode()
{
    while (true)
    {
        printAdminMenu();
        std::string command;
        std::cout << ">> ";
        std::getline(std::cin, command);
        if (command == "exit")
            break;
        else if (command == "add") {
            addMovieService();
            std::cout << '\n';
        }
        else if (command == "delete")
        {
            deleteMovieService();
            std::cout << '\n';
        }
        else if (command == "update")
        {
            updateMovieService();
            std::cout << '\n';
        }
        else if (command == "list")
        {
            listAllMovies();
            std::cout << '\n';
        }
        else
            std::cout << "Invalid command!\n\n";
    }
}

void UI::runUserMode()
{
    while (true)
    {
        printUserMenu();
        std::string command;
        std::cout << ">> ";
        std::getline(std::cin, command);
        if (command == "exit")
            break;
        else if (command == "watch")
        {
            watchStart();
            std::cout << '\n';
        }
        else if (command == "show")
        {
            printWatchList();
            std::cout << '\n';
        }
        else if (command == "delete")
        {
            int var = userDelete();
            if (var == 0)
                std::cout << "Error!!!\n";
            std::cout << '\n';
        }
        else if (command == "save")
        {
            this->service.watchListSave();
        }
        else if (command == "open")
        {
            this->service.watchListOpen();
        }
        else
            std::cout << "Invalid command!\n\n";
    }
}

void UI::addMovieService() {
    std::string title, genre, year, likes, trailer;
    std::cout << "Enter title: ";
    std::getline(std::cin, title);
    std::cout << "Enter genre: ";
    std::getline(std::cin, genre);
    std::cout << "Enter year: ";
    std::getline(std::cin, year);
    std::cout << "Enter number of likes: ";
    std::getline(std::cin, likes);
    std::cout << "Enter trailer link: ";
    std::getline(std::cin, trailer);
    try
    {
        this->service.addRepository(Movie(title, genre, stoi(year), stoi(likes), trailer));
    }
    catch (MovieException& e)
    {
        for (const auto& string : e.getErrors())
            std::cout << string;
    }
    catch (RepositoryException& e)
    {
        std::cout << e.what() << '\n';
    }
    catch (FileException& e)
    {
        std::cout << e.what() << '\n';
    }
    catch (std::invalid_argument& e)
    {
        std::cout << "Insert numbers\n";
    }
}

void UI::deleteMovieService() {
    std::string position;
    std::cout << "Enter position: ";
    std::getline(std::cin, position);
    try
    {
        this->service.deleteRepository(stoi(position));
    }
    catch (MovieException& e)
    {
        for (const auto& string : e.getErrors())
            std::cout << string;
    }
    catch (RepositoryException& e)
    {
        std::cout << e.what() << '\n';
    }
    catch (FileException& e)
    {
        std::cout << e.what() << '\n';
    }
    catch (std::invalid_argument& e)
    {
        std::cout << "Insert numbers\n";
    }
}

void UI::updateMovieService() {
    std::string position;
    std::cout << "Enter position: ";
    std::getline(std::cin, position);
    std::string title, genre, year, likes, trailer;
    std::cout << "Enter title: ";
    std::getline(std::cin, title);
    std::cout << "Enter genre: ";
    std::getline(std::cin, genre);
    std::cout << "Enter year: ";
    std::getline(std::cin, year);
    std::cout << "Enter number of likes: ";
    std::getline(std::cin, likes);
    std::cout << "Enter trailer link: ";
    std::getline(std::cin, trailer);
    try
    {
        return this->service.updateRepository(stoi(position), Movie(title, genre, stoi(year), stoi(likes), trailer));
    }
    catch (MovieException& e)
    {
        for (const auto& string : e.getErrors())
            std::cout << string;
    }
    catch (RepositoryException& e)
    {
        std::cout << e.what() << '\n';
    }
    catch (FileException& e)
    {
        std::cout << e.what() << '\n';
    }
    catch (std::invalid_argument& e)
    {
        std::cout << "Insert numbers\n";
    }
}

void UI::listAllMovies() {
    std::vector<Movie> ls = this->service.getAllRepository();
    int i = -1;
    std::for_each(ls.begin(), ls.end(), [&i](Movie movie) { std::cout << "Movie " << ++i << movie.toString() << "\n\n"; });
}

void UI::watchStart() {
    std::cout << "Please insert the genre: ";
    std::string genre;
    std::getline(std::cin, genre);
    WatchList* ls = this->service.filterMoviesByGenre(genre, this->service.getType());
    Movie movie;
    std::string command;
    while(ls->getSize() != 0)
    {
        printWatchMenu();
        ls->play();
        movie = ls->getCurrentMovie();
        std::cout << movie.toString() << "\n>> ";
        std::getline(std::cin, command);
        if (command == "exit")
            break;
        else if (command == "add")
        {
            this->service.addWatchList(movie);
            ls->deleteMovie(movie);
        }
        else if (command == "next")
            ls->next();
    }
    if (ls->getSize() == 0)
        std::cout << "There are no movies!\n";

}

void UI::printWatchList() {
    std::vector<Movie> ls = this->service.getAllWatchList();
    int i = -1;
    std::for_each(ls.begin(), ls.end(), [&i](Movie movie) { std::cout << "Movie " << ++i << movie.toString() << "\n\n"; });
}

int UI::userDelete() {
    std::string position, like;
    int pos;
    std::cout << "Enter the position: ";
    std::getline(std::cin, position);
    std::cout << "Did you like the movie? yes/no: ";
    std::getline(std::cin, like);
    if (!verifyPositionType(position))
        return 0;
    pos = stoi(position);
    if (pos < 0 || pos >= this->service.getAllWatchList().size())
        return 0;
    if (like == "yes" || like == "y")
        this->service.incrementLikes(pos);
    return this->service.deleteWatchList(pos);
}

void UI::printStartMenu() {
    std::cout << "(Enter exit to shut down the program!)\n";
    std::cout << "Please select your mode: admin / user\n";
    std::cout << "Mode: ";
}

void UI::printAdminMenu() {
    std::cout << "add - Add a movie\n";
    std::cout << "delete - Delete a movie\n";
    std::cout << "update - Update a movie\n";
    std::cout << "list - List all movies\n";
    std::cout << "exit - exit admin mode\n\n";
}

void UI::printUserMenu() {
    std::cout << "watch - See the movies by genre\n";
    std::cout << "delete - Delete Movie from the WatchList by title\n";
    std::cout << "show - See the WatchList\n";
    std::cout << "save - Save the WatchList\n";
    std::cout << "open - Open csv/html the WatchList\n";
    std::cout << "exit - exit user mode\n\n";
}

void UI::printWatchMenu() {
    std::cout << "You can: \n";
    std::cout << "next - go to the next element\n";
    std::cout << "add - add to the WatchList\n";
    std::cout << "exit - to exit\n";
}

bool UI::verifyPositionType(const std::string& position) {
    std::string numbers = "1234567890";
    if (position.empty())
        return false;
    if (std::all_of(position.begin(), position.end(), [](char i) { return std::isdigit(i); }))
        return true;
    return false;
}

//void UI::initialization() {
//    Movie m = Movie("Bad Boys", "Action", 1995, 17796764, "https://www.youtube.com/watch?v=OLYENHi4IIc");
//    this->service.addRepository(m);
//    m = Movie("Harry Potter: Philosopher's Stone", "Fantasy", 2001, 921634, "https://www.youtube.com/watch?v=mNgwNXKBEW0");
//    this->service.addRepository(m);
//    m = Movie("Ride Along", "Comedy", 2014, 1345887, "https://www.youtube.com/watch?v=5klp6rkHIks");
//    this->service.addRepository(m);
//    m = Movie("American Sniper", "Action", 2014, 350230, "https://www.youtube.com/watch?v=99k3u9ay1gs");
//    this->service.addRepository(m);
//    m = Movie("Beauty and the Beast", "Romance", 2017, 79791, "https://www.youtube.com/watch?v=e3Nl_TCQXuw");
//    this->service.addRepository(m);
//    m = Movie("Minions", "Animation", 2015, 157889, "https://www.youtube.com/watch?v=SvKmSNxFHyQ");
//    this->service.addRepository(m);
//    m = Movie("Frozen", "Animation", 2013, 448325, "https://www.youtube.com/watch?v=TbQm5doF_Uc");
//    this->service.addRepository(m);
//}
