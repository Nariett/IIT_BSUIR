#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");

	std::cout << "Hello World!\n";
	float x, y;
	while (true) {
		std::cout << "Введите координату x: ";
		std::cin >> x;

		if (std::cin.fail()) {
			std::cin.clear();  // Сбрасываем флаг ошибки
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
			std::cout << "Ошибка ввода! Пожалуйста, введите число с плавающей запятой: ";
		}
		else {
			break;  // Если ввод корректен, выходим из цикла
		}
	}
	while (true) {
		std::cout << "Введите координату y: ";
		std::cin >> y;

		if (std::cin.fail()) {
			std::cin.clear();
			while (std::cin.get() != '\n') {
			}
			std::cout << "Ошибка! Введите корректное число типа в формате x.xx." << std::endl;
		}
		else {
			break;
		}
	}
	if ((y >= abs(x) && y <= 1) || (y <= -abs(x) && y >= -1)) {
		std::cout << "Точка входит в заштрихованную область." << std::endl;
	}
	else {
		std::cout << "Точка не входит в заштрихованную область." << std::endl;
	}
}
