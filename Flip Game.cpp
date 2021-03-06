//You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, 
//you and your friend take turns to flip two consecutive "++" into "--". 
//The game ends when a person can no longer make a move and therefore the other person will be the winner.

Write a function to compute all possible states of the string after one valid move.

//For example, given s = "++++", after one move, it may become one of the following states:
[
  "--++",
  "+--+",
  "++--"
]
//If there is no valid move, return an empty list [].

vector<string> generatePossibleNextMoves(string s) {
  vector<string> move;
  for (int i=0; i<s.length()-1; i++) {
    if (s[i] == '+' && s[i+1] == '+') {
      s[i] = s[i+1] = '-';
      move.push_back(s);
      s[i]=s[i-1] = '+';
  }
  return move;
}
