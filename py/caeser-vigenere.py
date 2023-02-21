def caesar_cipher(text, keyword):
    # Вычисляем числовой ключ на основе суммы кодов символов в ключевом слове
    # ord() и chr() - номер в юникод таблице и обратно в char
    key = sum([ord(c) for c in keyword])

    # Создаем пустую строку для закодированного текста
    encoded_text = ""

    # Проходим по каждому символу в тексте
    for char in text:
        # Если символ является буквой, сдвигаем его на ключ позиций
        if char.isalpha():
            # Определяем начальный индекс буквы (0 для 'a', 1 для 'b', и т.д.)
            base = ord('a') if char.islower() else ord('A')
            # Вычисляем новый индекс буквы с учетом сдвига
            index = (ord(char) - base + key) % 26
            # Преобразуем индекс обратно в символ и добавляем его к закодированному тексту
            encoded_text += chr(base + index)
        # Если символ не является буквой, добавляем его без изменений
        else:
            encoded_text += char

    return encoded_text

def vigenere_cipher(text, keyword):
    # Приводим ключевое слово к нижнему регистру и удаляем все символы, кроме букв
    # filter(str.isalpha, keyword) фильтрует итератором не буквы f(bool-f()-filter, input)
    keyword = ''.join(filter(str.isalpha, keyword)).lower()

    # Создаем пустую строку для закодированного текста
    encoded_text = ""

    # Инициализируем переменную для отслеживания позиции символа в ключевом слове
    keyword_pos = 0

    # Проходим по каждому символу в тексте
    for char in text:
        # Если символ является буквой, сдвигаем его на соответствующий ключ в алфавите
        if char.isalpha():
            base = ord('a') if char.islower() else ord('A')
            # Получаем числовой ключ из позиции символа в ключевом слове
            key = ord(keyword[keyword_pos % len(keyword)]) - ord('a')
            # Вычисляем новый индекс буквы с учетом сдвига
            index = (ord(char) - base + key) % 26
            # Преобразуем индекс обратно в символ и добавляем его к закодированному тексту
            encoded_text += chr(base + index)
            # Увеличиваем позицию символа в ключевом слове для следующего символа
            keyword_pos += 1
        # Если символ не является буквой, добавляем его без изменений
        else:
            encoded_text += char

    return encoded_text

text = "Hello, world!"
keyword = "python"
encoded_text1 = caesar_cipher(text, keyword)
encoded_text2 = vigenere_cipher(text, keyword)
print(encoded_text1, "<- Caesar | Vigenere ->", encoded_text2)