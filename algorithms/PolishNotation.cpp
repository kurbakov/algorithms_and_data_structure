// more info:
// https://en.wikipedia.org/wiki/Polish_notation

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
T PolishNotation(std::string &str){
    std::vector<std::string> data = StringToVector(str, ' ');

    std::stack<char> operator_stack;
    std::stack<T> operand_stack;
    bool pending_operand;

    for(auto tocken : data){
        if(tocken.size() == 1 && (tocken == "+" || tocken == "-" || tocken == "*" || tocken == "/" )){
            operator_stack.push(tocken[0]);
            pending_operand = false;
        }
        else{
            T t_temp = StringToNumber<T>(tocken);
            if(pending_operand){
                while(!operand_stack.empty()){
                    T l = operand_stack.top();
                    operand_stack.pop();

                    char oper = operator_stack.top();
                    operator_stack.pop();

                    t_temp = Compute(oper, l, t_temp);
                }
            }
            operand_stack.push(t_temp);
            pending_operand = true;
        }
    }

    return operand_stack.top();
}

int main(){
    std::string input = "- * / 15 - 7 + 1 1 3 + 2 + 1 1";
    auto x = PolishNotation<int>(input);
    std::cout << x << "\n";

    return 0;
}