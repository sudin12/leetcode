class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        queue<int> qp;
        sort(deck.begin(),deck.end()); //sort the array
        for(int i = deck.size()-1;i>=0;i--){
            if(!qp.empty()){ 
                qp.push(qp.front()); // push the top element
                qp.pop(); // pop the element
            }
            qp.push(deck[i]); // then push new element
        }
        for(int i = deck.size()-1;i>=0;i--){
            deck[i] = qp.front(); 
            qp.pop();
        }
        return deck;
    }
};