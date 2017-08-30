// more info:
// https://en.wikipedia.org/wiki/Reverse_Polish_notation

#include <iostream>
#include <stack>
#include <vector>
#include <sstream>

std::vector<std::string> StringToVector(std::string str, char ch){
    std::vector<std::string> data;
    int idx = 0;
    std::string str_temp;
    for(int i=0; i<str.size(); i++){
        if(str[i] == ' '){
            str_temp = str.substr(idx, i-idx);
            data.push_back(str_temp);
            idx = i+1;
        }
    }
    str_temp = str.substr(idx, str.size()-idx);
    data.push_back(str_temp);

    return data;
}

template <class T>
T Compute(char Oper, T l, T r){
    switch(Oper){
        case '+':
            return l+r;
        case '-':
            return l-r;
        case '*':
            return l*r;
        case '/':
            return l/r;
        default:
            return l;
    }
}

template <class T>
T StringToNumber(std::string input)
{
   std::istringstream ss(input);
   T result;
   return ss >> result ? result : 0;
}

template<typename T>
T PolishNotationReverse(std::string &str){
    std::vector<std::string> data = StringToVector(str, ' ');

    std::stack<T> operand_stack;
    T t_temp, l ,r;
    for(auto tocken : data){
        if(tocken.size() == 1 && (tocken[0] == '+' || tocken[0] == '-' || tocken[0] == '*' || tocken[0] == '/' )){
            r = operand_stack.top();
            operand_stack.pop();

            l = operand_stack.top();
            operand_stack.pop();

            t_temp = Compute(tocken[0], l, r);
            operand_stack.push(t_temp);
        }
        else{
            t_temp = StringToNumber<T>(tocken);
            operand_stack.push(t_temp);
        }
    }

    return operand_stack.top();
}

int main(){
    std::string input = "15 7 1 1 + - / 3 * 2 1 1 + + -";
    auto x = PolishNotationReverse<int>(input);
    std::cout << x << "\n";

    return 0;
}