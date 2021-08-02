#include <iostream>
#include <random>

std::random_device rd; // Инициализируем случайное значение сида
std::mt19937 rnd(rd()); // Инициализируем рандомайзер
const short number = rnd() % 100 + 1; // Получаем случайное значение от 1 до 100

short get_value() {
  while (true) {
    std::cout << "Enter a number between 1 and 100: ";
    short ans;
    std::cin >> ans;
    std::cin.ignore(32767, '\n'); // Очищаем лишний буфер

    if (std::cin.fail()) { // Если cin вошел в решим отказа
      std::cin.clear(); // Очищаем cin
      std::cin.ignore(32767, '\n'); // Очищаем лишний буфер
      std::cout << "Incorrect input! Try again!" << std::endl;
      continue;
    } else if (ans >= 1 and ans <= 100) { // Если ответ в диапазоне [1; 100], то возвращаем его
      return ans;
    } else
      std::cout << "Incorrect input! Try again!" << std::endl;
  }
}

int main() {
  std::cout << "Hi-Lo game by HIlight3R." << std::endl;

  for (int i = 0; i < 7; ++i) {
    short value = get_value(); // Получаем значение пользовательского ввода

    if (value > number)
      std::cout << "To high (you have " << 7 - i - 1 << " attempts). Try again!" << std::endl;
    else if (value < number)
      std::cout << "To low (you have " << 7 - i - 1 << " attempts). Try again!" << std::endl;
    else {
      std::cout << "You win! The number was " << number << "!" << std::endl;
      return 0;
    }
  }

  std::cout << "You lose! The number was " << number << "!" << std::endl;

  return 0;
}
