#include "Tests.h"

void Tests::testAll() {
    testDomain();
    testDynamicVector();
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

void Tests::testDynamicVector() {
    DynamicVector<Movie> dynamicVector;
    DynamicVector<Movie> dynamicVector1(dynamicVector);
    DynamicVector<Movie> dynamicVector2(1);

    dynamicVector.addItem(Movie("a","b",10,2,"link"));
    assert(dynamicVector.getSize() == 1);
    assert(dynamicVector[0].getYear() == dynamicVector.getElement(0).getYear());
    assert(dynamicVector.getCapacity() == 10);
    dynamicVector.deleteItem(0);
    assert(dynamicVector.getSize() == dynamicVector1.getSize());
    dynamicVector.addItem(Movie("a","b",10,2,"link"));
    Movie updateMovie("c","d",20,3,"linker");
    dynamicVector.updateItem(0, updateMovie);
    assert(dynamicVector[0].getYear() == 20);
    assert(dynamicVector[0].getLikes() == 3);
    assert(dynamicVector[0].getTitle() == "c");
    assert(dynamicVector[0].getGenre() == "d");
    assert(dynamicVector[0].getTrailer() == "linker");

    assert(dynamicVector2.getCapacity() == 1);
    dynamicVector2.addItem(Movie("a","b",10,2,"link"));
    assert(dynamicVector2.getCapacity() == 1);
    dynamicVector2.addItem(Movie("c","d",20,3,"linker"));
    assert(dynamicVector2.getCapacity() == 2);

}

void Tests::testRepository() {
    Repository repository;
    assert(repository.addMovie(Movie("a","b",10,2,"link")) == 1);
    assert(repository.addMovie(Movie("a","b",10,2,"link")) == 0);
    assert(repository.addMovie(Movie("c","d",10,2,"linker")) == 1);

    assert(repository.findPositionOfMovie(Movie("c","d",10,2,"linker")) == 1);
    assert(repository.findPositionOfMovie(Movie("c","b",10,2,"link")) == -1);

    Movie updateMovieFalse("a","b",10,3,"link");
    Movie updateMovieTrue("d","c",10,2,"m");
    assert(repository.updateMovie(0, updateMovieFalse) == 0);
    assert(repository.updateMovie(0, updateMovieTrue) == 1);

    assert(repository.deleteMovie(0));
    assert(repository.getSize() == 1);
    assert(repository[0].getTitle() == "c");
}

void Tests::testWatchList() {
    WatchList watchList;
    assert(watchList.addMovie(Movie("b", "b", 10, 2, "link")) == 1);
    assert(watchList.addMovie(Movie("b", "b", 10, 2, "link")) == 0);
    assert(watchList.addMovie(Movie("c", "d", 10, 2, "linker")) == 1);
    assert(watchList.addMovie(Movie("a", "a", 20, 3, "xLinker")) == 1);


    Movie m = Movie("c", "d", 10, 2, "linker");
    Movie b = watchList.getCurrentMovie();
    watchList.next();
    watchList.next();
    watchList.next();
    watchList.next();
    assert(watchList.deleteMovieByPos(0));
    assert(watchList.getSize() == 2);
    assert(watchList[0].getTitle() == "c");
    watchList.deleteMovie(m);
    watchList.deleteMovie(m);
    assert(watchList.getSize() == 1);
}

void Tests::testService() {
    Repository repository;
    WatchList watchList;
    Movie movie1("a","b",10,2,"link"), movie2("c", "d", 10, 2, "linker");
    assert(repository.addMovie(movie1) == 1);
    Service service{ repository, watchList };
    assert(service.addRepository(movie2) == 1);

    Movie updateMovieFalse("c", "d", 10, 2, "linker");
    Movie updateMovieTrue("d","c",10,2,"m");
    assert(service.updateRepository(10, updateMovieFalse) == 0);
    assert(service.updateRepository(0, updateMovieTrue) == 1);

    assert(service.deleteRepository(10) == 0);
    assert(service.deleteRepository(0) == 1);

    Movie movie3("c", "d", 10, 2, "linker"), movie4("q", "w", 20, 3, "polly");
    assert(service.addWatchList(movie3) == 1);
    assert(service.addWatchList(movie4) == 1);
    assert(service.deleteWatchList(10) == 0);
    assert(service.deleteWatchList(0) == 1);

    assert(service.filterMoviesByGenre("")[0].getTitle() == "c");
    assert(service.filterMoviesByGenre("different")[0].getTitle().empty());
    assert(service.filterMoviesByGenre("d")[0].getTitle() == "c");

    assert(service.getAllRepository()[0].getTitle() == "c");
    assert(service.getAllWatchList()[0].getTitle() == "q");

    assert(service.getRepository().getSize() == 1);
    assert(service.getWatchList().getSize() == 1);
}

