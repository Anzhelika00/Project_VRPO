using namespace std;
{
    int get_random_card()
    {
        return 1 + (rand() % 10);
    }
     vector<int> generate_dealer_cards()
    {
        vector<int> cards = { get_random_card(), get_random_card() };

        while (get_card_values(cards) < 17)
        {
            cards.push_back(get_random_card());
        }

        return cards;
    }
    int get_card_values(vector<int> cards)
    {
        int total = 0;

        for (const int card : cards)
        {
            total += card;
        }

        return total;
    }
}
