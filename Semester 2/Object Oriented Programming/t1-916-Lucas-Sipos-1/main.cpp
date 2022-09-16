#include "Player.h"
#include "Repository/Repository.h"
#include "Service/Service.h"
#include "UI/UI.h"

int main(){
    Player player1("Nora_Mork", "NOR", "Larvik", 83);
    Player player2("Isabelle", "SWE", "CSM_Bucuresti", 80);
    Player player3("Cristina", "ROU", "Buducnost", 63);
    Repository repository;
    repository.addPlayer(player1);
    repository.addPlayer(player2);
    repository.addPlayer(player3);
    Service service(repository);
    UI ui(service);
    ui.start();
    return 0;
}

