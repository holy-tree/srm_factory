//
// Created by 21909 on 2024/8/4.
//

#ifndef PROJECT_FACTORY_H
#define PROJECT_FACTORY_H
#include<iostream>
#include<memory>
#include<string>

namespace strategies{
    class Strategy{//���������
    public:
        std::string process_method_;
        std::string ProcessMethod(){return process_method_;}
    };

    class Heat:public Strategy{
    public:
        Heat(): Strategy(){
            process_method_="Heating";
        }
    };

    class Cool:public Strategy{
    public:
        Cool(): Strategy(){
            process_method_="Cooling";
        }
    };

    class Mix:public Strategy{
    public:
        Mix(): Strategy(){
            process_method_="Mixing";
        }
    };
}

namespace products{
    class Product{//�����Ʒ��
    public:
        strategies::Strategy* strategy_choice_;
        std::string product_name;
    public:
        void process(){std::cout<<product_name<<"�ļӹ���ʽΪ��"
        <<strategy_choice_->ProcessMethod()<<std::endl;};
    };

    class ProductA:public Product{
    public:
       ProductA(): Product(){
           product_name="ProductA";
       }
    };

    class ProductB:public Product{
    public:
        ProductB(): Product(){
            product_name="ProductB";
        }
    };

    class ProductC:public Product{
    public:
        ProductC(): Product(){
            product_name="ProductC";
        }
    };
}



namespace singleton{//��������ģʽ
    class FactoryManager{
    private:
        FactoryManager(){};
        FactoryManager(const FactoryManager&);
        FactoryManager& operator=(const FactoryManager&);
    public:
        static FactoryManager* getInstance();

        products::Product* createProduct(std::string name);
        void assignStrategy(products::Product*pro,std::string str);
    };
}

namespace factory{
    class ProductFactory{//��Ʒ������
    public:
        static products::Product* makeProduct(const std::string& str);
    };

    class StrategyFactory{
    public:
        static strategies::Strategy* setStrategy(const std::string& str);
    };
}

#endif //PROJECT_FACTORY_H
