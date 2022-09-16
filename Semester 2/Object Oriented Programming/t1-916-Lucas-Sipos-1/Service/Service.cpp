#include "Service.h"

Service::Service(const Repository &repository) {
    this->repository = repository;
}

Service::~Service() = default;

void Service::addPlayerService(Player &player) {
    this->repository.addPlayer(player);
}

int Service::removePlayerService(const std::string& name) {
    return this->repository.removePlayer(name);
}


