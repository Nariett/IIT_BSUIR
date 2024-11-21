#include <iostream>
#include <vector>

void showArray(const std::vector<int>& array)
{
	for (int i = 0; i < array.size(); i++)
	{
		if (i % 20 == 0 && i != 0)
		{
			std::cout << "\n";
		}
		std::cout << array[i] << " ";
	}
}

void showEvenSequences(std::vector<std::vector<int>>& allEvenSequences)
{
	std::vector<int> sequence;
	for (int i = 0; i < allEvenSequences.size(); i++) {
		std::cout << "[";
		sequence = allEvenSequences[i];
		for (int i = 0; i < sequence.size(); i++) {
			std::cout << sequence[i];
			if (i < sequence.size() - 1) {
				std::cout << ", ";
			}
		}
		std::cout << "]" << std::endl;
	}
}

void countingSort(std::vector<int>& array, int minValue, int maxValue)
{
	int range = maxValue - minValue + 1;
	std::vector<int> count(range, 0);

	for (int num : array)
	{
		count[num - minValue]++;
	}

	int index = 0;
	for (int i = 0; i < range; i++)
	{
		while (count[i] > 0)
		{
			array[index++] = i + minValue;
			count[i]--;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int flag;
	bool value = true;
	int minValue = 0, maxValue = 0;
	int arraySize;
	std::cout << "Введите размерность массива (от 1 до 100) \n";
	while (!((std::cin >> arraySize) && (arraySize <= 100 && arraySize > 0))) {
		std::cin.clear();
		while (std::cin.get() != '\n'); 
		std::cout << "Размерность введена неправильно!\n";
	}

	std::vector<int> array(arraySize);

	do
	{
		std::cout << "Выберите ввод:\n1 - Ручной ввод\n2 - Автоввод" << std::endl;
		while (!(std::cin >> flag)) {
			std::cin.clear();
			while (std::cin.get() != '\n');
			std::cout << "Некорректный ввод!\n";
		}
		switch (flag)
		{
		case 1:
			std::cout << "Заполните массив значениями:\n";
			for (int i = 0; i < arraySize; i++)
			{
				std::cout << "Введите значение для arr[" << i << "]: ";
				while (!(std::cin >> array[i])) {
					std::cin.clear();
					while (std::cin.get() != '\n');
					std::cout << "Некорректный ввод!\n";
				}
				if (i == 0 || array[i] < minValue)
					minValue = array[i];
				if (i == 0 || array[i] > maxValue)
					maxValue = array[i];
			}
			value = false;
			break;
		case 2:
		{
			int lowerBound, upperBound;
			std::cout << "Введите минимальное значение для ввода: ";
			std::cin >> lowerBound;
			std::cout << "Введите максимальное значение для ввода: ";
			std::cin >> upperBound;

			if (lowerBound > upperBound)
			{
				std::cout << "Минимальное значение больше максимального.\n";
				break;
			}

			minValue = lowerBound;
			maxValue = upperBound;

			for (int i = 0; i < arraySize; i++)
			{
				array[i] = rand() % (upperBound - lowerBound + 1) + lowerBound;
			}
			value = false;
			break;
		}
		default:
			std::cout << "Введите корректное значение" << std::endl;
			break;
		}
	} while (value);

	for (int num : array)
	{
		if (maxValue < num)
		{
			maxValue = num;
		}
	}

	std::cout << "Массив до сортировки:" << std::endl;
	showArray(array);

	std::vector<std::vector<int>> allEvenSequences;
	std::vector<int> currentSequence;

	for (int number : array) {
		if (number % 2 == 0) {
			currentSequence.push_back(number);
		}
		else if (!currentSequence.empty()) {
			allEvenSequences.push_back(currentSequence);
			currentSequence.clear();
		}
	}

	if (!currentSequence.empty()) {
		allEvenSequences.push_back(currentSequence);
	}

	for (int i = 0; i < allEvenSequences.size(); ++i) {
		for (int j = 0; j < allEvenSequences.size() - i - 1; ++j) {
			int maxA = *std::max_element(allEvenSequences[j].begin(), allEvenSequences[j].end());
			int maxB = *std::max_element(allEvenSequences[j + 1].begin(), allEvenSequences[j + 1].end());
			if (maxA < maxB) {
				std::swap(allEvenSequences[j], allEvenSequences[j + 1]);
			}
		}
	}

	std::cout << "\nОтсортированные последовательности четных чисел:" << std::endl;
	showEvenSequences(allEvenSequences);
	bool switchValue = true;
	int flagSort;
	countingSort(array, minValue, maxValue);
	std::cout << "Массив после сортировки:" << std::endl;
	showArray(array);
	return 0;
}
