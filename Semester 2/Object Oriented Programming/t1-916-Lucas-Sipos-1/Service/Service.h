#pragma once
#include "../Repository/Repository.h"

class Service {
private:
    Repository repository;

public:
    explicit Service(const Repository& repository);
    ~Service();

    void addPlayerService (Player& player);
    int removePlayerService (const std::string& name);

    DynamicVector<Player> getAll() { return this->repository.getPlayers(); }
};
