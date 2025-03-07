/*
 * @Author: solomon 13586037+solomonzw@user.noreply.gitee.com
 * @Date: 2025-03-07 12:51:46
 * @LastEditors: solomon 13586037+solomonzw@user.noreply.gitee.com
 * @LastEditTime: 2025-03-07 17:48:40
 * @FilePath: \task track\mian.cpp
 * @Description: ??????????,??????customMade`, ???koroFileHeader?????? ???????: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <vector>
#include <fstream>

std::vector<std::string> tasks;
void show_help() {
    std::cout << "Usage: task [command] [arguments]" << std::endl;
    std::cout << "Commands:" << std::endl;
    std::cout << "  add     Add a new task" << std::endl;
    std::cout << "  list    List all tasks" << std::endl;
    std::cout << "  done    Mark a task as done" << std::endl;
    std::cout<< "  delete  Delete a task " << std::endl;
}
int main() {
    
    std::string command;
    std::cout << "first point!" << std::endl;
    while (true/* condition */)
    { 
    std::getline(std::cin, command);
    if (command == "help") {
        show_help();
    } else if(command.substr(0,3)=="add"){
        if(command.length()>4){
        tasks.push_back(command.substr(4));
        std::cout<<"add task success!\n"<<std::endl;
        }else{
            std::cout<<"add task fail!\n"<<std::endl;
        }
    } else if(command.substr(0,4) == "list"){
        if (tasks.empty()/* condition */)
        {
            std::cout<<"no task!\n"<<std::endl;
            /* code */
        } else {
            for (int i = 0; i < tasks.size(); i++)
            {
                std::cout<<i+1<<"."<<tasks[i]<<std::endl;
                
            }
            
        } 
    }else if(command.substr(0,6) == "delete"){
        try{
        int index = std::stoi(command.substr(6,command.size()-6));
        if(index>=0 && index<tasks.size()){
        tasks.erase(tasks.begin()+index-1);
        std::cout<<"delete success!\n"<<std::endl;
        }else{
            std::cout<<"no task!\n"<<std::endl;
        }
        }catch(...){
            std::cout<<"no you xiao task!\n"<<std::endl;
        }
    }else if(command.substr(0,4) == "save"){
        std::ofstream filew("tasks.txt");
        for(auto &task:tasks){
            filew<<task<<std::endl;
        }
        std::cout<<"save success!\n"<<std::endl;
    }else if(command.substr(0,4) == "load"){

        std::ifstream filer("tasks.txt");
        std::string task;
        while(std::getline(filer,task)){
            tasks.push_back(task);
        }
        std::cout<<"load success!\n"<<std::endl;
           
    }else if(command.substr(0,4) == "exit"){
        std::cout<<"exit success!\n"<<std::endl;
        exit(0);
    }

    }

    }
