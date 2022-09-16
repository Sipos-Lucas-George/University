#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>

int main(int argc, char* argv[])
{
    QApplication a{ argc, argv };
    QLabel label{ "Hello world!" };
    label.show();
    return a.exec();
}

//#include "UI/UI.h"
//#include "Tests/Tests.h"
//#include "Repository/CSVWatchList.h"
//#include "Repository/HTMLWatchList.h"
//#include <Windows.h>
//
//int main() {
////    Tests::testAll();
//    std::string command;
//    system("cls");
//    while(true) {
//        std::cout << "Choose file type (csv/html) or exit: ";
//        std::getline(std::cin, command);
//        if (command == "e" || command == "exit") {
//            std::cout << "Program end!";
//            Sleep(1000);
//            break;
//        }
//        system("cls");
//        if (command == "csv" || command == "html") {
//            Repository repository{ "Movies.txt" };
//            WatchList* watchList;
//            if (command == "csv") {
//                watchList = new CSVWatchList();
//                watchList->setType("csv");
//            }
//            else {
//                watchList = new HTMLWatchList();
//                watchList->setType("html");
//            }
//            Service service{ repository, watchList };
//            UI ui{ service };
//            ui.start();
//            system("cls");
//            continue;
//        }
//        std::cout << "ERROR!!\n";
//    }
//    return 0;
//}
