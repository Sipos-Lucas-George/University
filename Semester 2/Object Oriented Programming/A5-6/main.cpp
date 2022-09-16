#include "UI/UI.h"
#include "Tests/Tests.h"

int main() {
    Tests::testAll();
    Repository repository{};
    WatchList watchList{};
    Service service{ repository, watchList };
    UI ui{ service };
    ui.start();
    return 0;
}
