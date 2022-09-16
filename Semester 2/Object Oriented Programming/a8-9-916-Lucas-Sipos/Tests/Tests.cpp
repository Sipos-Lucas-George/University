#include "Tests.h"

void Tests::testAll() {
    testDomain();
    testRepository();
    testWatchList();
    testService();
}

void Tests::testDomain() {
    Movie movie;

    assert(movie.getTitle().empty());
    assert(movie.getGenre().empty());
    assert(movie.getTrailer().empty());
    assert(movie.getLikes() == 0);
    assert(movie.getYear() == 0);

    Movie movie1("a","b",10,2,"link");
    Movie movie2("a","b",10,3,"link");

    movie1.incrementLikes();
    movie1.incrementLikes();
    assert(movie1.getLikes() == 3);
    assert(movie1.toString() == movie2.toString());
}

void Tests::testRepository() {
    Repository repository { "test.txt" };
    repository.addMovie(Movie("Asd","Csd", 2002, 123,"www.google.com"));
    assert(repository.getSize() == 1);
    try {
        repository.addMovie(Movie("Asd","Csd", 2002, 123,"www.google.com"));
        assert(false);
    }
    catch (DuplicateMovieException& e) {
        assert(true);
    }
    try {
        repository.updateMovie(0, Movie("Asd","Csd", 2002, 123,"www.google.com"));
        assert(false);
    }
    catch (DuplicateMovieException& e) {
        assert(true);
    }
    repository.updateMovie(0, Movie("Asl", "Csm", 2000, 1234, "www.email.com"));
    assert(repository.getSize() == 1);
    assert(repository[0].getLikes() == 1234);
    repository.deleteMovie(0);
    assert(repository.getSize() == 0);
}

void Tests::testWatchList() {
    WatchList* watchList = new CSVWatchList();
    WatchList* watch = new HTMLWatchList();
    watchList->setType("csv");
    assert(watchList->getType() == "csv");
    assert(watchList->addMovie(Movie("Asl", "Csm", 2000, 1234, "www.email.com")) == 1);
    assert(watchList->addMovie(Movie("Asl", "Csm", 2000, 1234, "www.email.com")) == 0);
    std::vector<Movie> vector;
    vector.emplace_back("Asl", "Csm", 2000, 1234, "www.email.com");
    watch->setMovies(vector);
    assert(watchList->getCurrentMovie().getLikes() == watchList->getMovies()[0].getLikes());
    assert(watchList->addMovie(Movie("Asd","Csd", 2002, 123,"www.google.com")) == 1);
    assert(watch->addMovie(Movie("Asd","Csd", 2002, 123,"www.google.com")) == 1);
    watchList->next();
    watch->next();
    assert(watchList->getCurrentMovie().getLikes() == watch->getCurrentMovie().getLikes());
    watchList->next();
    watch->next();
    assert(watchList->getCurrentMovie().getLikes() == watch->getCurrentMovie().getLikes());
    watchList->deleteMovie(Movie("Asd","Csd", 2002, 123,"www.google.com"));
    assert(watchList->getSize() == 1);
    watch->deleteMovieByPos(0);
    assert(watchList->getSize() == watch->getSize());
    watch->deleteMovieByPos(0);
    watchList->deleteMovieByPos(0);
    assert(watchList->getSize() == watch->getSize());
}

void Tests::testService() {
    Repository repository { "test.txt" };
    WatchList *watchList;
    watchList->setType("csv");
    Service service{repository, watchList};
    service.addRepository(Movie("Asd","Csd", 2002, 123,"www.google.com"));
    try{
        service.updateRepository(1, Movie("Asd","Csd", 2002, 123,"www.google.com"));
        assert(false);
    }
    catch (IncorrectPosition &e) {
        assert(true);
    }
    try{
        service.deleteRepository(1);
        assert(false);
    }
    catch (IncorrectPosition& e){
        assert(true);
    }
    service.updateRepository(0, Movie("Asl", "Csm", 2000, 1234, "www.email.com"));
    service.incrementLikes(0);
    assert(service.getAllRepository()[0].getLikes() == 1235);

    assert(service.addWatchList(Movie("Asl", "Csm", 2000, 1234, "www.email.com")) == 1);
    assert(service.filterMoviesByGenre("", "csv")->getCurrentMovie().getLikes() == service.filterMoviesByGenre("Csm", "html")->getCurrentMovie().getLikes());
    assert(service.deleteWatchList(1) == 0);
    assert(service.deleteWatchList(0) == 1);

    service.deleteRepository(0);
    assert(service.getAllRepository().empty());
}
