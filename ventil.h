#ifndef VENTIL_H
#define VENTIL_H
#include <QString>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;
/**
 * @brief Конструктор класса Ventil
 */
class Ventil
{
public:
    int id;
    QString Post;
    QString tel;
    QString country;
    QString articul;
    QString vid;
    int cost;
public:

    Ventil();
    /**
        * @brief Ventil конструктор класса инициализирует значения
        * @param lid идентификатор
        * @param lPost поставщик
        * @param ltel телефон
        * @param lcountry страна
        * @param larticul артикул
        * @param lvid вид
        * @param lcost цена
        */
    Ventil(const int lid,
           const QString &lPost,
           const QString &ltel,
           const QString &lcountry,
           const QString &larticul,
           const QString &lvid,
           const int lcost);
    Ventil(const Ventil &other);
    ~Ventil();

    Ventil operator=(const Ventil &other);
    /**
     * @brief setVentil
     * @param lid идентификатор
     * @param lPost поставщик
     * @param ltel телефон
     * @param lcountry страна
     * @param larticul артикул
     * @param lvid вид
     * @param lcost цена
     */
    void setVentil(const int lid,
                   const QString &lPost,
                   const QString &ltel,
                   const QString &lcountry,
                   const QString &larticul,
                   const QString &lvid,
                   const int lcost);
    /**
     * @brief set_id устанавливает идентификатор
     * @param lid идентификатор
     */
    void set_id(const int lid);
    /**
     * @brief set_Post устанавливает поставщика
     * @param lPost поставщик
     */
    void set_Post(const QString lPost);
    /**
     * @brief set_tel устанавливает телефон
     * @param ltel телефон
     */
    void set_tel(const QString ltel);
    /**
     * @brief set_country устанавливает страну
     * @param lcountry страна
     */
    void set_country(const QString lcountry);
    /**
     * @brief set_articul устанавливает артикул
     * @param larticul артикул
     */
    void set_articul(const QString larticul);
    /**
     * @brief set_vid устанавливает вид
     * @param lvid вид
     */
    void set_vid(const QString lvid);
    /**
     * @brief set_cost устанавливает цену
     * @param lcost цена
     */
    void set_cost(const int lcost);

    /**
     * @brief
     * @return get_id возвращает идентификатор
     */
    int get_id() const;
    /**
     * @brief
     * @return get_Post возвращает поставщика
     */
    QString get_Post() const;
    /**
     * @brief
     * @return get_tel возвращает телефон
     */
    QString get_tel() const;
    /**
     * @brief
     * @return get_country возвращает страну
     */
    QString get_country() const;
    /**
     * @brief
     * @return get_articul возвращает артикул
     */
    QString get_articul() const;
    /**
     * @brief
     * @return get_vid возвращает вид
     */
    QString get_vid() const;
    /**
     * @brief
     * @return get_cost возвращает цену
     */
    int get_cost() const;
    /**
     * @brief display
     */
    void display() const;
    /**
     * @brief operator <<
     * @param os
     * @param vent
     * @return
     */
    friend std::ostream &operator<<(std::ostream &os, const Ventil &vent);

};

#endif // VENTIL_H
