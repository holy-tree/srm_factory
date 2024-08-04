//
// Created by 21909 on 2024/8/4.
//

#include "Factory.h"
singleton::FactoryManager *singleton::FactoryManager::getInstance() {
    static FactoryManager instance;
    return &instance;
}

products::Product *singleton::FactoryManager::createProduct(std::string name) {
    return factory::ProductFactory::makeProduct(name);
}

void singleton::FactoryManager::assignStrategy(products::Product *pro, std::string str) {
    pro->strategy_choice_=factory::StrategyFactory::setStrategy(str);
}

products::Product *factory::ProductFactory::makeProduct(const std::string& str) {
    if(str=="ProductA"){//可以使用配置文件实现，省去if-else结构
        return new products::ProductA();
    }else if(str=="ProductB"){
        return new products::ProductB();
    }else if(str=="ProductC") {
        return new products::ProductC();
    }else{
        std::cout<<"没有此产品"<<std::endl;
        exit(0);
    }
}

strategies::Strategy *factory::StrategyFactory::setStrategy(const std::string &str) {
    if(str=="Heating"){
        return new strategies::Heat();
    }else if(str=="Cooling"){
        return new strategies::Cool();
    }else if(str=="Mixing"){
        return new strategies::Mix();
    }else{
        std::cout<<"无此加工方式"<<std::endl;
        exit(0);
    }
}
