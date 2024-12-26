#include <iostream>
using namespace std;

void game()
{
   vector<int> dealer_cards = dealer::generate_dealer_cards();
    int dealer_total = dealer::get_card_values(dealer_cards);
    
    cout << "Твои карты :\n";
    vector<int> player_cards = {dealer::get_random_card(), dealer::get_random_card()};
    int player_total = dealer::get_card_values(player_cards);
    for (const int card : player_cards)
    {
        dealer::display_card_value(card);
    }
    cout << "Ваша общая сумма: " << player_total  << '\n';

}
