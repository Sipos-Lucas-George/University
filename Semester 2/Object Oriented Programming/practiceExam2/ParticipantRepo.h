#pragma once
#include <vector>
#include "Participant.h"
#include "Observer.h"

class ParticipantRepo : public Subject {
private:
    std::vector<Participant> repo;

public:
    ParticipantRepo();
    ~ParticipantRepo() = default;
    void addParticipant(const Participant& participant) { repo.push_back(participant); }
    std::vector<Participant> getAll() { return this->repo; }

    void readFile();
    void writeFile();
};
