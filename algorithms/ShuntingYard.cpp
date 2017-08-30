#include <iostream>
#include <vector>

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

bool isOperator(std::string str){
    if(str[0]=='+') return true;
    if(str[0]=='-') return true;
    if(str[0]=='*') return true;
    if(str[0]=='/') return true;
    if(str[0]=='^') return true;
    return false;
}


std::vector<std::string> ShuntingYard(std::string str_input)
{
    std::vector<std::string> vec = StringToVector(str_input, ' ');

    std::vector<std::string> stack_operators;
    std::vector<std::string> queue_values;

    while(!vec.empty()){
        std::string curr_value = vec[0];

        // operators:
        if(isOperator(curr_value))
        {
            if(curr_value.compare("*") == 0 && stack_operators.back().compare("/") == 0){
                queue_values.push_back("/");
                stack_operators[stack_operators.size()-1] = "*";
            }
            else if(curr_value.compare("/") == 0 && stack_operators.back().compare("*") == 0){
                queue_values.push_back("*");
                stack_operators[stack_operators.size()-1] = "/";
            }
            else {
                stack_operators.push_back(curr_value);
            }
        }
        // cases for "(" and ")"
        else if(vec.front().compare("(") == 0)
        {
            stack_operators.push_back(curr_value);
        }
        else if(vec.front().compare(")") == 0)
        {
            while(stack_operators.back() != "("){
                std::string str = stack_operators[stack_operators.size()-1];
                queue_values.push_back(str);
                stack_operators.pop_back();
            }
            stack_operators.pop_back();
        }
        // rest of cases
        else
        {
            queue_values.push_back(curr_value);
        }

        vec.erase(vec.begin());
    }

    std::reverse(stack_operators.begin(), stack_operators.end());
    queue_values.insert(queue_values.end(), stack_operators.begin(), stack_operators.end());
    return queue_values;
}


int main(){
    std::string str = "3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3";

    std::vector<std::string> res = ShuntingYard(str);
    for(auto el : res){
        std::cout << el << " ";
    }
    std::cout << "\n";

    return 0;
}