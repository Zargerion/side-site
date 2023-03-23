// Vue ------------------------------------------------------

<!-- Меню -->
<nav id="menu">
  <ul>
    <li><a href="#">Главная</a></li>
    <li><a href="#">О нас</a></li>
    <li><a href="#">Контакты</a></li>
  </ul>
</nav>

<!-- Кнопка меню -->
<button id="menu-button">Меню</button>

<!-- Скрипт -->
<script>
  // Получаем элементы
  const menu = document.querySelector('#menu');
  const menuButton = document.querySelector('#menu-button');

  // При нажатии на кнопку меню
  menuButton.addEventListener('click', () => {
    // Переключаем класс "active" у меню
    menu.classList.toggle('active');
  });
</script>
/* Стили для меню */
#menu {
  /* Скрываем меню */
  transform: translateX(-100%);
  
  /* Добавляем анимацию */
  transition: transform .3s;
}

/* Стили для активного меню */
#menu.active {
  /* Показываем меню */
  transform: translateX(0);

  // Vue ----------------------------------------------------

  