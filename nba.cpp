#include "nba.h"

Performance::Performance(size_t j, size_t m, size_t a) : points(j), rebounds(m), assists(a) {}

size_t Performance::getPoints() const {
    return points;
}

size_t Performance::getRebounds() const {
    return rebounds;
}

size_t Performance::getAssists() const {
    return assists;
}

void Performance::setPerformance(size_t j, size_t m, size_t a) {
    points = j;
    rebounds = m;
    assists = a;
}

bool operator<(const Performance &p1, const Performance &p2) {
    if (p1.getPoints() < p2.getPoints()) return true;
    if (p1.getPoints() > p2.getPoints()) return false;

    if (p1.getRebounds() < p2.getRebounds()) return true;
    if (p1.getRebounds() > p2.getRebounds()) return false;

    if (p1.getAssists() < p2.getAssists()) return true;
    if (p1.getAssists() > p2.getAssists()) return false;

    return false;
}

bool operator>(const Performance &p1, const Performance &p2) {
    return !(p1 < p2);
}

std::ostream &operator<<(std::ostream &f, const Performance &d) {
    f << d.getPoints() << " points, " << d.getRebounds()
      << " rebounds, " << d.getAssists() << " assists";
    return f;
}

void Player::setPerformancePlayoff(const Performance &p) {
    playoff = const_cast<Performance *>(&p);
}

Player::Player(const string &p, const string &n, const Performance &_regular, const Performance &_playoff) :
        Player(p, n, _regular) //nom(n), prenom(p), regular(nais) // alternative
{
    setPerformancePlayoff(_playoff);
}

void Player::setPerformancePlayoff(const Performance &_playoff) {
    playoff = new Performance(_playoff);
}

Player::Player(const Player &i) : prenoms(i.prenoms), nom(i.nom), regular(i.regular) {
    if (i.playoff) playoff = new Performance(*i.playoff);
}

Player &Player::operator=(const Player &i) {
    if (this != &i) {
        prenoms = i.prenoms;
        nom = i.nom;
        regular = i.regular;
        if (i.playoff) {
            if (!playoff) playoff = new Performance(*i.playoff);
            else *playoff = *i.playoff;
        } else {
            delete playoff;
            playoff = nullptr;
        }
    }
    return *this;
}

void Chemistry::ajouterBuddy(const Player &p, const Player &s) {
    if (nb == nbMax) enlargeTable();
    tab[nb++] = Buddy(p, s);
}

void Chemistry::enlargeTable() {
    Buddy *newtab = new Buddy[nbMax * 2 + 1];
    for (size_t i = 0; i < nb; i++) newtab[i] = tab[i];
    nbMax = nbMax * 2 + 1;
    auto old = tab;
    tab = newtab;
    delete[] old;
}

void Team::ajouterPlayer(const Player &i) {
    if (nb == nbMax) enlargeTable();
    players[nb++] = new Player(i);
}

const Player &Team::getPlayer(const string &p, const string &n) const {
    for (size_t i = 0; i < nb; i++)
        if (players[i]->getNom() == n && players[i]->getNom() == p)
            return *players[i];
    throw "erreur : player inexistant";
}

Player &Team::getPlayer(const string &p, const string &n) {
    for (size_t i = 0; i < nb; i++)
        if (players[i]->getNom() == n && players[i]->getNom() == p)
            return *players[i];
    throw "erreur : player inexistant";
}

Team::~Team() {
    for (size_t i = 0; i < nb; i++) delete players[i];
    delete[] players;
}

void Team::enlargeTable() {
    auto *newtab = new Player *[nbMax * 2 + 1];
    for (size_t i = 0; i < nb; i++) newtab[i] = players[i];
    nbMax = nbMax * 2 + 1;
    auto old = players;
    players = newtab;
    delete[] old;
}

void Team::addBuddies(const Player &p1, const Player &p2) {
    buddies.ajouterBuddy(p1, p2);
}
