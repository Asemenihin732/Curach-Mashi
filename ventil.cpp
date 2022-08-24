#include "ventil.h"
using namespace std;


Ventil::~Ventil()
{

}



void Ventil::setVentil(const int lid, const QString &lPost, const QString &ltel, const QString &lcountry, const QString &larticul, const QString &lvid, const int lcost)
{
    id=lid;
    Post=lPost;
    tel=ltel;
    country=lcountry;
    articul=larticul;
    vid=lvid;
    cost=lcost;
}


Ventil Ventil::operator=(const Ventil &other)
{
    if(this == &other) return *this;
    id = other.id;
    Post=other.Post;
    tel=other.tel;
    country=other.country;
    articul=other.articul;
    vid=other.vid;
    cost=other.cost;
    return *this;
}

void Ventil::set_id(const int lid)
{
    id=lid;
}

void Ventil::set_Post(const QString lPost)
{
    Post=lPost;
}

void Ventil::set_tel(const QString ltel)
{
    tel=ltel;
}

void Ventil::set_country(const QString lcountry)
{
    country=lcountry;
}

void Ventil::set_articul(const QString larticul)
{
    articul=larticul;
}

void Ventil::set_vid(const QString lvid)
{
    vid=lvid;
}

void Ventil::set_cost(const int lcost)
{
    cost=lcost;
}

int Ventil::get_id() const
{
    return id;
}

QString Ventil::get_Post() const
{
    return Post;
}

QString Ventil::get_tel() const
{
    return tel;
}

QString Ventil::get_country() const
{
    return country;
}

QString Ventil::get_articul() const
{
    return articul;
}

QString Ventil::get_vid() const
{
    return vid;
}

int Ventil::get_cost() const
{
    return cost;
}

std::ostream &operator<<(std::ostream &os, const Ventil &vent)
{
    os << "ID: "           << vent.id    << "\n"
       << "Provider: "     << QString(vent.Post).toStdString() << "\n"
       << "Tel: "        << QString(vent.tel).toStdString() << "\n"
       << "Country: "        << QString(vent.country).toStdString() << "\n"
       << "Articul: "        << QString(vent.articul).toStdString() << "\n"
       << "Kind: "        << QString(vent.vid).toStdString() << "\n"
       << "Cost: " << vent.cost << std::endl;

    return os;
}

void Ventil::display() const
{
    std::cout << "ID: "           << id    << "\n"
              << "Provider: "     << QString(Post).toStdString() << "\n"
              << "Tel: "        << QString(tel).toStdString() << "\n"
              << "Country: "        << QString(country).toStdString() << "\n"
              << "Articul: "        << QString(articul).toStdString() << "\n"
              << "Kind: "        << QString(vid).toStdString() << "\n"
              << "Cost: " << cost << std::endl;
}






Ventil::Ventil()
{

}

Ventil::Ventil(const int lid,
               const QString &lPost,
               const QString &ltel,
               const QString &lcountry,
               const QString &larticul,
               const QString &lvid,
               const int lcost):
id(lid),
Post(lPost),
tel(ltel),
country(lcountry),
articul(larticul),
vid(lvid),
cost(lcost)
{

}

Ventil::Ventil(const Ventil &other):
    id(other.id),
    Post(other.Post),
    tel(other.tel),
    country(other.country),
    articul(other.articul),
    vid(other.vid),
    cost(other.cost)
{

}


