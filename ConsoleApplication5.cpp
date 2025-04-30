#include <iostream>
#include <vector>

//Задание: "Каталог товаров"
//
//Цель: Закрепить навык работы со структурами и вектором.
//
//Условие:
//    Создай структуру Product, которая содержит информацию о товаре:
//
//  struct Product {
//      std::string name;
//      double price;
//      int quantity;
//  };
//
//1. Запроси у пользователя количество товаров, которые он хочет ввести.
//2. Для каждого товара введи :
//    - название,
//    - цену,
//    - количество на складе.
//3. Сохрани данные во вектор std::vector<Product>.
//4. После ввода всех данных :
//    - Выведи список всех товаров.
//    - Подсчитай и выведи общую стоимость всех товаров на складе(цена *количество для каждого товара).
//    - Выведи товары, у которых количество меньше 5 (нужно пополнить запас).

struct Product
{
    std::string name;
    double price;
    int quantity;
};

void printMenu()
{
    std::cout << "\nГлавное меню склада\n\n" <<
        "1. Показать список всех продуктов\n" <<
        "2. Заполнить список продуктов: \n" <<
        "3. Показать общую стоимость всех продуктов\n" <<
        "4. Показать товары требующие пополнения\n" <<
        "0. Закрыть программу" << std::endl;
}

void fillProductList(std::vector<Product>& products)
{
    int listSize = 0;

    std::cout << "\nВведите количество товаров в списке: ";

    std::cin >> listSize;
    std::cout << std::endl;

    for (int i = 0; i < listSize; ++i)
    {
        Product product;

        std::cout << "Введите название продукта: ";
        std::cin >> product.name;        
        std::cout << "Введите стоимость продукта: ";
        std::cin >> product.price;
        std::cout << "Введите количество: ";
        std::cin >> product.quantity;

        products.push_back(product);
        std::cout << std::endl;
    }
}

void printAllProducts(const std::vector<Product>& products)
{
    std::cout << std::endl;
    for (Product product : products)
    {
        std::cout << "Название продукта: " << product.name << std::endl;
        std::cout << "Стоимость продукта: " << product.price << std::endl;
        std::cout << "Количество: " << product.quantity << std::endl;

        std::cout << std::endl;
    }
}

void calcTotalCost(const std::vector<Product>& products)
{
    double totalCost = 0;

    for (Product product : products)
    {
        totalCost += product.price * product.quantity;
    }

    std::cout << "\nОбщая стоимость всех товаров: " << totalCost << std::endl;
}

void checkProductQty(const std::vector<Product>& products)
{
    std::cout << std::endl;
    for (Product product : products)
    {
        if (product.quantity < 5)
        {
            std::cout << product.name << " меньше 5 шт. Требуется пополнить запас.\n" << std::endl;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    std::vector<Product> products;
    
    int pointMenu = -1;

    while (pointMenu != 0)
    {
        printMenu();

        std::cout << "\nВведите пункт меню: ";
        std::cin >> pointMenu;

        switch (pointMenu)
        {
        case 1:
            printAllProducts(products);
            break;

        case 2:
            fillProductList(products);
            break;
        case 3:
            calcTotalCost(products);
            break;
        case 4:
            checkProductQty(products);
            break;
        case 0:
            std::cout << "\nЗавершение работы программы" << std::endl;
            break;
        default:
            std::cout << "\nВы ввели неправильный номер пункта меню! Повторите ввод.\n" << std::endl;
            break;
        }
    };
}