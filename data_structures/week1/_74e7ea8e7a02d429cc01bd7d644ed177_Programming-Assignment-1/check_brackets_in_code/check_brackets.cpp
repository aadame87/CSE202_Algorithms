//ALAN ADAME 3FEB17 CSE202

#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);

    std::stack <Bracket> opening_brackets_stack;

    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (position ==0 && text.length()==1) {
          std::cout << '1' << '\n';
          return 1;}

        if (next == '(' || next == '[' || next == '{') {

            opening_brackets_stack.push(Bracket(next,position));

        }
        //ignore all other characters that are not brackets/parens
        else if (next!=')' && next!=']'&& next!='}') ;

        //hand close brackets
        else {
          if (opening_brackets_stack.empty()){
              std::cout << position+1<<'\n';
              return position;}
          Bracket top = opening_brackets_stack.top();
          opening_brackets_stack.pop();
          if ( next== ')' || next == ']' || next == '}') {
              if (!top.Matchc(next)){
              std::cout << position+1<<'\n';
              return position;}
        }
      }
    }
    if (opening_brackets_stack.empty()){
    std::cout << "Success"<<'\n';
    return 0;}
    //if the stack is not empty print our the position of the character still in the stack
    std::cout << opening_brackets_stack.top().position+1 <<'\n' ;
    return 0;

}
