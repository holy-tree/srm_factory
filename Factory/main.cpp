#include <iostream>
#include"Factory.h"

int main() {
    singleton::FactoryManager& manager = *singleton::FactoryManager::getInstance();

    // ������ƷA��ָ�����Ȳ���
    std::unique_ptr<products::Product> productA(manager.createProduct("ProductA"));
    if (productA) {
        manager.assignStrategy(productA.get(), "Heating");
        productA->process();
    }

    // ������ƷB��ָ����ȴ����
    std::unique_ptr<products::Product> productB(manager.createProduct("ProductB"));
    if (productB) {
        manager.assignStrategy(productB.get(), "Cooling");
        productB->process();
    }

    // ������ƷC��ָ����ϲ���
    std::unique_ptr<products::Product> productC(manager.createProduct("ProductC"));
    if (productC) {
        manager.assignStrategy(productC.get(), "Mixing");
        productC->process();
    }

    return 0;
}
