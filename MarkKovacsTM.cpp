#include <iostream>
#include <fstream> 
#include <vector>
// current_state  current_tape_symbol new_state  new_tape_symbol  direction
//this isnt impressive sorry its all subjective
//Good from here ->
struct rule{
   char state;
   char tape_symbol;
   char new_state;
   char new_tape_symbol;
   char direction; 
};
//are  the stacks needed? No:)
int main(){
    std::ifstream file;
    std::string file_name;
    std::string line;
    std::vector<rule> rules;
    std::cout << "Um file please: ";
    std::cin >> file_name;
    file.open(file_name);
    while(!file){
        std::cout << "Um file please: ";
        std::cin >> file_name;
        file.open(file_name);
    }
    std::getline(file,line);
    while(file){
        while(line[0] == '/'){
            std::getline(file,line);
        }
        rule new_rule;
        new_rule.state = line[0];
        new_rule.tape_symbol = line[2];
        new_rule.new_state = line[4];
        new_rule.new_tape_symbol = line[6];
        new_rule.direction = line[8];
        rules.push_back(new_rule);
        std::getline(file,line);
    }
hyper_space_jump:
    std::string input_string;
    std::string tape_string; 
    bool rule_found = false;
    std::string yorn = "";
    int lookie = 0;
    int counter = 0;
    char THEE_symbol;//current symbol we are looking at
    char THEE_state = '0';//current state we are in starts at 0
    std::cout << "Step right up step right up and try your luck on the TM of Wonders\nTest your luck(for empty string put a B): ";
    std::cin >> input_string;
    std::cout << std::endl; // prints ID on new line
    //std::stack<char> left_stack;
    //std::stack<char> right_stack;
    //right_stack.push('B');
    //left_stack.push('B');
    // for(auto itr = input_string.begin() ; itr !=input_string.end(); ++itr){
    //     //good
    //     right_stack.push(*itr);
    // }
    
    while(THEE_state != 'f'){
        if(counter == 100){
            while(yorn != "Y" and yorn != "N"){
                std::cout << "Woah that was a lot of IDs you may wanna pace yourself\nDo you wan to continue?Y/N(has to be capital) ";
                std::cin >> yorn;
                std::cout << std::endl;
            }
        if(yorn == "Y" ){
            counter = 0;
        }
        if(yorn == "N"){
            goto hyper_space_jump;
        }
        }
        THEE_symbol = input_string[lookie];
        for(int i = 0; i < lookie;i++){
            //maybe
            std::cout << input_string[i];
        }
        std::cout << '[' << THEE_state << ']';//maybe
        for(int i = lookie; i < input_string.size();i++){
            //maybe
            std::cout << input_string[i];
        }
        std::cout << std::endl; //prints next ID on new line
        for(int i =0; i <= rules.size(); i++){
            if(rules[i].state == THEE_state){
                if(rules[i].tape_symbol == THEE_symbol){
                    rule_found = true;
                    input_string[lookie] = rules[i].new_tape_symbol;
                    THEE_state = rules[i].new_state;
                    if(rules[i].direction == 'R'){
                        //left_stack.push(right_stack.top());
                        //right_stack.pop();
                        lookie++;
                        counter++;
                        break;
                    }
                    else if(rules[i].direction == 'L'){
                        //right_stack.push(left_stack.top());
                        //left_stack.pop();
                        if(lookie > 0){
                            lookie--;
                        }
                        counter++;
                        break;
                    }
                }
            }            
        }
        if(!rule_found){
            std::cout << "Rejected!!!!!!!!!\n";
            goto hyper_space_jump;
            return 0;
        }
        rule_found = false;
        if(lookie == input_string.size()){
            //right_stack.push('B');
            input_string = input_string + 'B';
        }
        if(lookie == 0){
            lookie++;
            //left_stack.push('B');
            input_string = 'B' + input_string;
        }
    }
    for(int i = 0; i < lookie;i++){
        //good
        std::cout << input_string[i];
    }
    std::cout << '[' << THEE_state << ']';//good
    for(int i = lookie; i < input_string.size();i++){
        //good
        std::cout << input_string[i];
    }
    std::cout << "\nAccepted\n";
    goto hyper_space_jump;
    return 0;
}
//<- to here
