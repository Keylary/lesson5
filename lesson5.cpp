
#include <iostream>
#include <vector>
#include <utility>
// 1. Реализовать шаблон класса Pair1, который позволяет пользователю передавать данные одного типа парами. Следующий код должен производить результат:
    //  Pair: 6 9
    //  Pair : 3.4 7.8

//template <class T> 
//class Pair1 {
//public:
//    Pair1(T first, T second) { fst = first; sec = second; }
//    T first() const{
//        return fst;
//    };
//    T second() const{
//        return sec;
//    };
//private:
//    T fst, sec;
//};
//
//int main() {
//    Pair1<int> p1(6, 9);
//    std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';
//
//    const Pair1<double> p2(3.4, 7.8);
//    std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
//
//    return o;
//}


// 2. Реализовать класс Pair, который позволяет использовать разные типы данных в передаваемых парах. Следующий код должен производить следующий результат:
    // Pair: 6 7.8
    // Pair : 3.4 5

//
//template <class T1, class T2>
//class Pair {
//public:
//    Pair(T1 first, T2 second) { fst = first; sec = second; }
//    T1 first() const {
//        return fst;
//    };
//    T2 second() const {
//        return sec;
//    };
//private:
//    T1 fst;
//    T2 sec;
//};
//
//int main() {
//    Pair<int, double> p1(6, 7.8);
//    std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';
//
//    const Pair<double, int> p2(3.4, 5);
//    std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
//
//    return 0;
//}


// 3. Написать шаблон класса StringValuePair, в котором первое значение всегда типа string, а второе — любого типа. Этот шаблон класса должен наследовать
// частично специализированный класс Pair, в котором первый параметр — string, а второй — любого типа данных. Следующий код должен производить следующий результат:
    //// Pair: Amazing 7
    //// Подсказка : при вызове конструктора класса Pair из конструктора класса StringValuePair не забудьте указать, что параметры относятся к классу Pair.

//
//template <class T>
//class Pair {
//public:
//    Pair () {}
//    Pair(std::string first, T second) { fst = first; sec = second; }
//    std::string first() const {
//        return fst;
//    };
//    T second() const {
//        return sec;
//    };
//private:
//    std::string fst;
//    T sec=0;
//};
//  
//
//template <class T>
//class StringValuePair : public Pair<T>
//{
//    public:
//    StringValuePair(std::string first, T second) { fst = first; sec = second; }
//    std::string first() const {
//        return fst;
//    };
//    T second() const {
//        return sec;
//    };
//private:
//    std::string fst;
//    T sec;
//};
//
//
//int main() {
//
//   StringValuePair<int> svp("Amazing", 7);
//   std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
//   return 0;
//
//}

// 4. Согласно иерархии классов, которая представлена в методичке к уроку 3, от класса Hand наследует класс GenericPlayer, который обобщенно представляет игрока, 
// ведь у нас будет два типа игроков - человек и компьютер. Создать класс GenericPlayer, в который добавить поле name - имя игрока. Также добавить 3 метода:
    // IsHitting() - чисто виртуальная функция, возвращает информацию, нужна ли игроку еще одна карта.
    // IsBoosted() - возвращает bool значение, есть ли у игрока перебор
    // Bust() - выводит на экран имя игрока и объявляет, что у него перебор.

//class Card
//{
//public:
//    friend std::ostream& operator<<(std::ostream& os, const Card& aCard);
//    enum rank {
//        ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
//        JACK, QUEEN, KING
//    };
//    enum suit { CLUBS, DIAMONDS, HEARTS, SPADES };
//
//    Card(rank r = ACE, suit s = SPADES, bool ifu = true);
//    int GetValue() const;
//    void Flip();
//
//private:
//    rank m_Rank;
//    suit m_Suit;
//    bool m_IsFaceUp;
//
//};
//
//Card::Card(rank r, suit s, bool ifu) : m_Rank(r), m_Suit(s), m_IsFaceUp(ifu)
//{}
//
//int Card::GetValue() const
//{
//    int value = 0;
//    if (m_IsFaceUp)
//    {
//        value = m_Rank;
//        if (value > 10)
//        {
//            value = 10;
//        }
//    }
//    return value;
//}
//
//void Card::Flip()
//{
//    m_IsFaceUp = !(m_IsFaceUp);
//}
//
//std::ostream& operator<<(std::ostream& os, const Card& aCard)
//{
//    const std::string RANKS[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9","10", "J", "Q", "K" };
//    const std::string SUITS[] = { "c", "d", "h", "s" };
//
//    if (aCard.m_IsFaceUp)
//    {
//        os << RANKS[aCard.m_Rank] << SUITS[aCard.m_Suit];
//    }
//    else
//    {
//        os << "XX";
//    }
//
//    return os;
//}
//
//class Hand
//{
//public:
//    Hand();
//    virtual ~Hand();
//
//    void Add(Card* pCard);
//    void Clear();
//    int GetTotal() const;
//
//protected:
//    std::vector<Card*> m_Cards;
//};
//
//Hand::Hand()
//{
//    m_Cards.reserve(7);
//}
//
//Hand::~Hand()
//{
//    Clear();
//}
//
//void Hand::Add(Card* pCard)
//{
//    m_Cards.push_back(pCard);
//}
//
//void Hand::Clear()
//{
//    std::vector<Card*>::iterator iter = m_Cards.begin();
//    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
//    {
//        delete* iter;
//        *iter = 0;
//    }
//    m_Cards.clear();
//}
//
//
//int Hand::GetTotal() const
//{
//    if (m_Cards.empty())
//    {
//        return 0;
//    }
//
//    int total = 0;
//    std::vector<Card*>::const_iterator iter;
//    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
//    {
//        total += (*iter)->GetValue();
//    }
//
//    bool containsAce = false;
//    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
//    {
//        if ((*iter)->GetValue() == Card::ACE)
//        {
//            containsAce = true;
//        }
//    }
//
//    if (containsAce && total <= 11)
//    {
//        total += 10;
//    }
//
//    return total;
//}
//
//
//
//class GenericPlayer : public Hand
//{
//    friend std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer);
//
//public:
//    GenericPlayer(const std::string& name = "");
//
//    virtual ~GenericPlayer();
//    virtual bool IsHitting() const = 0;
//    bool IsBusted() const;
//    void Bust() const;
//
//protected:
//    std::string m_Name;
//};
//
//bool GenericPlayer::IsBusted() const
//{
//    return (GetTotal() > 21);
//}
//
//void GenericPlayer::Bust() const
//{
//    std::cout << m_Name << " busts.\n";
//}
//
//class Player : public GenericPlayer
//{
//public:
//    Player(const std::string& name = "");
//
//    virtual ~Player();
//
//    // показывает, хочет ли игрок продолжать брать карты
//    virtual bool IsHitting() const;
//
// 
//};
//
//bool Player::IsHitting() const
//{
//   std:: cout << m_Name << ", do you want a hit? (Y/N): ";
//    char response;
//    std::cin >> response;
//    return (response == 'y' || response == 'Y');
//}


