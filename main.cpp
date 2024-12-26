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

    bool bust = false;

    while (bust == false)
    {   

        if (player_total == 21)
        {
            break;
        }

         cout << "взять еще (y) или стоп(n)?  " << player_total  << '\n';
        char answer;
        cin >> answer;

        if (answer == 'n')
        {
            break;
        }
        else if (answer == 'y')
        {
            int card = dealer::get_random_card();

            cout << "Ваша карта: ";
            dealer::display_card_value(card);

            player_cards.push_back(card);
            player_total = dealer::get_card_values(player_cards);
            cout << "Ваша общая сумма сейчас составляет: " << player_total  << '\n';
            
            if (player_total > 21)
            {
                bust = true;
            }
        }
        else if (answer != 'y' || answer != 'n')
        {
            cout << "Ответьте буквой y(если хотите взять) или n(если хотите стопнуть)!\n";
        }
    }
}
